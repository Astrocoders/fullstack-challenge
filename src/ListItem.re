open Utils;
open Utils.Assets;

requireStyle("styles/ListItem.css");

[@react.component]
let make = () =>
  <li className="listItem">
    <RoundButton asset=uncheckedIcon />
    <RoundButton asset=unfavoritedIcon />
    <RoundButton asset=flagIcon />
    <div className="listInfo">
      <span className="info infoAuthor"> "Autor"->str </span>
      <span className="info infoTitle"> "Titulo"->str </span>
      <span className="info infoContent"> "Conteudo"->str </span>
      <span className="info infoData"> "Data"->str </span>
    </div>
  </li>;
