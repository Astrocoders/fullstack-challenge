open Utils;
open Utils.Assets;
open Types;

requireStyle("styles/ListItem.css");

[@react.component]
let make = (~data: dataRecord=?, ~onClickCallback: (_, 'a) => unit) =>
  <li className="listItem">
    <ToogleButton asset=uncheckedIcon toogled=checkedIcon />
    <ToogleButton asset=unfavoritedIcon toogled=starIcon />
    <RoundButton asset=flagIcon />
    <div className="listInfo" onClick={onClickCallback(data)}>
      <span className="info infoAuthor"> data.number->str </span>
      <span className="info infoTitle"> data.name->str </span>
      <span className="info infoContent"> data.classification->str </span>
      <span className="info infoData"> "Data"->str </span>
    </div>
  </li>;
