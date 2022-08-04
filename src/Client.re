
/* Create an InMemoryCache */
let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

let wslink = ApolloLinks.webSocketLink({
    uri:"wss://graphql-lt5.bandchain.org/v1/graphql",
    options:{
      reconnect:true,
      connectionParams:None
    }
  });

let instance = ReasonApollo.createApolloClient(~link=wslink, ~cache=inMemoryCache, ());

