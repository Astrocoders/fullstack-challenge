open Utils;
open Utils.Assets;

requireStyle("styles/SearchBar.css");

[@react.component]
let make = () =>
  <div className="searchBar">
    <RoundButton asset=searchIcon />
    <input
      className="searchInput"
      type_="search"
      placeholder="Search tweets"
    />
    <RoundButton asset=closeIcon />
    <RoundButton asset=dropdownIcon />
  </div>;
