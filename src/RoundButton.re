open Utils;

requireStyle("styles/RoundButton.css");

[@react.component]
let make =
    (
      ~asset: asset=?,
      ~roundness: string="50%",
      ~onClick: ReactEvent.Mouse.t => unit=?,
    ) => {
  let url = "url(" ++ getURI(asset) ++ ")";
  <input
    style={ReactDOMRe.Style.make(
      ~backgroundImage=url,
      ~backgroundRepeat="no-repeat",
      ~backgroundPosition="center",
      ~borderRadius=roundness,
      (),
    )}
    className="roundButton"
    type_="button"
    onClick
  />;
};
