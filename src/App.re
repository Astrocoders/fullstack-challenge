open Utils;
open Client;

requireStyle("styles/App.css");

[@react.component]
let make = () => {
  let url = ReasonReact.Router.useUrl();

  switch (url.path) {
  | [] =>
    <a className="oauthLink" href=oauthInitUrl>
      {j|Autenticação via OneGraph|j}->str
    </a>
  | ["app"] => <> <NavBar /> <SideMenu /> <MainList /> </>
  | _ => <p> {"Caminho nao encontrado" |> ReasonReact.string} </p>
  };
};
