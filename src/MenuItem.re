open Utils;

requireStyle("styles/MenuItem.css");

[@react.component]
let make =
    (~name: string, ~asset: asset=?, ~colorBG: string=?, ~colorFG: string=?) => {
  let url = "url(" ++ getURI(asset) ++ ")";
  Js.log(url);
  <li
    className="menuItem"
    style={ReactDOMRe.Style.make(
      ~backgroundColor=colorBG,
      ~color=colorFG,
      (),
    )}>
    <div
      role="icon"
      style={ReactDOMRe.Style.make(
        ~height="24px",
        ~width="24px",
        ~backgroundRepeat="no-repeat",
        ~backgroundPosition="center",
        ~backgroundImage=url,
        (),
      )}
    />
    <span className="menuItemTitle"> name->str </span>
    <span className="menuItemCount"> "qnt"->str </span>
  </li>;
};
