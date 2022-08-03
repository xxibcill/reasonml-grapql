/* Create a GraphQL Query by using the graphql_ppx */
module GetPokemon = [%graphql
  {|
  query getPokemon{
    allPokemon {
        name
    }
  }
|}
];

module GetPokemonQuery = ReasonApollo.CreateQuery(GetPokemon);

[@react.component]
let make = () => {
  let userNameQuery = GetPokemon.make(());
  <GetPokemonQuery variables=userNameQuery##variables>
    ...{({result}) =>
      switch (result) {
      | Loading => <div> {ReasonReact.string("Loading")} </div>
      | Error(error) => <div> {error.message |> React.string} </div>
      | Data(response) =>
        <div>
          {/* Handles a deeply nested optional response */
            
            switch(Js.Json.stringifyAny(Belt.Option.getExn(response##allPokemon))){
                | None => React.null
                | Some(str) => str |> React.string 
            }
          }
        </div>
      }
    }
  </GetPokemonQuery>;
};
