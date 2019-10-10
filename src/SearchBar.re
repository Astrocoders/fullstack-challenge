open Utils;

requireStyle("styles/SearchBar.css");

let searchIcon = requireAsset("assets/magnifyingGlass.png");
let closeIcon = requireAsset("assets/closeIcon.png");

[@react.component]
let make = () =>
  <div className="searchBar">
    <RoundButton asset=searchIcon />
    <input className="searchInput" type_="search" value="Search tweets" />
    <RoundButton asset=closeIcon />
  </div>;
