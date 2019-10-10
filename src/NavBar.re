open Utils;
open Utils.Assets;

requireStyle("styles/NavBar.css");

[@react.component]
let make = () =>
  <nav className="navBar">
    <div className="menuArea">
      <RoundButton asset=sndwichMenu />
      <a href="/" title="inbox">
        <img className="logo" src={getURI(logo)} />
      </a>
    </div>
    <SearchBar />
    <div className="userArea">
      <RoundButton asset=appMenu />
      <RoundButton asset=appMenu />
      <RoundButton asset=appMenu />
    </div>
  </nav>;
