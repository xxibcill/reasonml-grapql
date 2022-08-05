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
  {|
    subscription Subscription_root($limit: Int, $orderBy: [blocks_order_by!]) {
      blocks(limit: $limit, order_by: $orderBy) {
        hash
        height
      }
    }
  |}
];

module GetBlocksQuery = ReasonApollo.CreateSubscription(GetBlocks);


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
          <BlockTable data=response##blocks />
        }
      }
    </GetBlocksQuery>
  </div>
};
