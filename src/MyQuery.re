/* Create a GraphQL Query by using the graphql_ppx */
module GetPokemon = [%graphql
  {|
    subscription Subscription_root($limit: Int, $orderBy: [blocks_order_by!]) {
      blocks(limit: $limit, order_by: $orderBy) {
        hash
        height
      }
    }
  |}
];

module GetPokemonQuery = ReasonApollo.CreateSubscription(GetPokemon);


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

  <GetPokemonQuery variables=variables>
    ...{({result}) =>
      switch (result) {
      | Loading => <div> {ReasonReact.string("Loading")} </div>
      | Error(error) => <div> {error.message |> React.string} </div>
      | Data(response) =>
        <BlockTable data=response##blocks />
      }
    }
  </GetPokemonQuery>;
};
