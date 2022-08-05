module Styles = {
    open Css;

    let root =
        style([
            display(`flex),
            justifyContent(`center),
            alignItems(`center),
            width(`vw(100.)), 
            height(`vh(100.)), 
            backgroundColor(Colors.white),
            position(`relative)
        ]);
};

/* Create a GraphQL Query by using the graphql_ppx */
module GetBlocks = [%graphql
  {j|
    subscription Subscription_root($limit: Int, $orderBy: [blocks_order_by!]) {
      blocks(limit: $limit, order_by: $orderBy) {
        hash
        height
        timestamp
        transactions_aggregate {
          aggregate {
            count
          }
        }
      }
    }
  |j}
];

module GetBlocksQuery = ReasonApollo.CreateSubscription(GetBlocks);
open Types

let processBlocksData = (array) => {
  let getHash = (hash) => hash |> Js.Json.decodeString |> Belt.Option.getExn |> Js.String.sliceToEnd(~from=2) |> String.uppercase_ascii
  array |> Js.Array.map(data =>  {
    height: data##height,
    hash: getHash(data##hash),
    timestamp: data##timestamp |> Js.Json.decodeString |> Belt.Option.getExn ,
    txn: (data##transactions_aggregate##aggregate |> Belt.Option.getExn)##count |> Belt.Option.getExn
  })
};

[@react.component]
let make = () => {
  let variables = Js.Json.parseExn({|
    {
      "limit": 10,
      "orderBy": [
        {
          "height": "desc"
        }
      ]
    }
  |});

  <div className=Styles.root>
    <GetBlocksQuery variables=variables>
      ...{({result}) =>
        switch (result) {
        | Loading => <div> {ReasonReact.string("Loading")} </div>
        | Error(error) => <div> {error.message |> React.string} </div>
        | Data(response) =>
          <BlockTable data=processBlocksData(response##blocks)/>
        }
      }
    </GetBlocksQuery>
  </div>
};
