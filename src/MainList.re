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
    <body className="listBody">
      <ul className="list">
        <ListItem />
        <ListItem />
        <ListItem />
        <ListItem />
        <ListItem />
        <ListItem />
      </ul>
    </body>
    <footer className="listFooter">
      "something about avaliable space in memory"->str
    </footer>
  </main>;
