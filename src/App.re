open Utils;

requireStyle("styles/App.css");

let logo = requireAssetURI("assets/logoGmail.png");

[@react.component]
let make = () => <> <img src={getURI(logo)} /> <h1> "App"->str </h1> </>;
