open Utils;

let logo = requireAssetURI("assets/logoGmail.png");

[@react.component]
let make = () => <> <img src=getURI(logo) /> <h1> "App"->str </h1> </>;
