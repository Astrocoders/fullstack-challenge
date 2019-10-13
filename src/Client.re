let appID = "8ac7246c-668e-4331-9c2a-dd7f9ee17f06";

let apiService = "github";

// this should be random for security reasons. Im using a fixed lenght to facilitate extracting the code down the road
let apiState = "s123";

let oauthInitUrl =
  "https://serve.onegraph.com/oauth/start?service="
  ++ apiService
  ++ "&app_id="
  ++ appID
  ++ "&response_type=code"
  ++ "&state="
  ++ apiState
  ++ "&redirect_origin=http://localhost:8000&redirect_path=/app";

let oauthTokenRequestUrl = (urlArgs: ReasonReactRouter.url) =>
  "https://serve.onegraph.com/oauth/token?"
  ++ "grant_type=authorization_code"
  ++ "&service="
  ++ apiService
  ++ "&app_id="
  ++ appID
  ++ "&redirect_uri=http://localhost:8000/app"
  ++ "&code="
  ++ Js.String.substr(~from=16, urlArgs.search); // Problably there is a better way to extract this code

let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

let httpLink =
  ApolloLinks.createHttpLink(~uri="https://serve.onegraph.com/dynamic?app_id=" ++ appID, ());

let client =
  ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());
