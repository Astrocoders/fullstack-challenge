open Utils;

requireStyle("styles/RoundButton.css");

[@react.component]
let make = (~asset: asset=?) => {
  let url = "url(" ++ getURI(asset) ++ ")";
  <input
    style={ReactDOMRe.Style.make(
      ~backgroundImage=url,
      ~backgroundRepeat="no-repeat",
      ~backgroundPosition="center",
      (),
    )}
    className="roundButton"
    type_="button"
  />;
};
