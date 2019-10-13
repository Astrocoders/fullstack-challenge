open Utils;
open Client;

requireStyle("styles/App.css");

type state = {token: string};

let initialState = {token: ""};

type action =
  | SetToken(string);

let reducer = (_, action) =>
  switch (action) {
  | SetToken(tokenValue) => {token: tokenValue}
  };

[@react.component]
let make = () => {
  let url = ReasonReact.Router.useUrl();
  let (state, dispatch) = React.useReducer(reducer, initialState);

  let tokenPromisse = requestUrl =>
    Js.Promise.(
      Fetch.fetchWithInit(
        oauthTokenRequestUrl(requestUrl),
        Fetch.RequestInit.make(~method_=Post, ~mode=NoCORS, ()),
      )
      ->then_(Fetch.Response.json, _)
      ->then_(
          json => dispatch(SetToken(Js.Json.stringify(json)))->resolve,
          _,
        )
    );

  switch (url.path) {
  | [] =>
    <a className="oauthLink" href=oauthInitUrl>
      <ComposeButton title={j|Autenticação via OneGraph|j} />
    </a>
  | ["app"] =>
    ignore(tokenPromisse(url));
    state.token->str;
    <> <NavBar /> <SideMenu /> <MainList /> </>;
  | _ => <p> {"Caminho nao encontrado" |> ReasonReact.string} </p>
  };
};
