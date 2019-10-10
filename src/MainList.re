open Utils;
open Utils.Assets;

requireStyle("styles/MainList.css");

[@react.component]
let make = () =>
  <main className="mainList">
    <header className="listHeader">
      <RoundButton asset=uncheckedIcon roundness="12px" />
      <RoundButton asset=dropdownIcon roundness="12px" />
      <RoundButton asset=realoadIcon />
      <RoundButton asset=moreIcon />
    </header>
    <body>
      <ul>
        <li> "Tweet"->str </li>
        <li> "Tweet"->str </li>
        <li> "Tweet"->str </li>
        <li> "Tweet"->str </li>
        <li> "Tweet"->str </li>
        <li> "Tweet"->str </li>
        <li> "Tweet"->str </li>
        <li> "Tweet"->str </li>
        <li> "Tweet"->str </li>
        <li> "Tweet"->str </li>
      </ul>
    </body>
    <footer> "footer"->str </footer>
  </main>;
