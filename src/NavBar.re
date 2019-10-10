open Utils;

requireStyle("styles/NavBar.css");
let logo = requireAsset("assets/logoGmail.png");
let sndwichMenu = requireAsset("assets/sandwichMenuIcon.png");
let appMenu = requireAsset("assets/appMenuIcon.png");

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
