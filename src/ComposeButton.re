open Utils;
open Utils.Assets;

requireStyle("styles/ComposeButton.css");

[@react.component]
let make = () => {
  let url = "url(" ++ getURI(creatMailIcon) ++ ")";
  <input
    style={ReactDOMRe.Style.make(
      ~backgroundImage=url,
      ~backgroundRepeat="no-repeat",
      ~backgroundPosition="8px",
      (),
    )}
    className="composeButton"
    type_="button"
    value="Compose"
  />;
};
