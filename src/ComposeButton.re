open Utils;

requireStyle("styles/ComposeButton.css");
let creatMailIcon = requireAsset("assets/createMailIcon.png");

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
