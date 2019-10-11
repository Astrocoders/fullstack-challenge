type asset;
[@bs.val] external requireAsset: string => asset = "require";

[@bs.val] external requireStyle: string => unit = "require";

external getURI: asset => string = "%identity";

external str: string => React.element = "%identity";

module Assets = {
  let creatMailIcon = requireAsset("assets/createMailIcon.png");
  let inboxIcon = requireAsset("assets/inboxIcon.png");
  let snoozedIcon = requireAsset("assets/clockIcon.png");
  let starIcon = requireAsset("assets/starIcon.png");
  let flagIcon = requireAsset("assets/flagIcon.png");
  let sentIcon = requireAsset("assets/sentIcon.png");
  let draftIcon = requireAsset("assets/draftIcon.png");
  let markIcon = requireAsset("assets/flagIcon.png");
  let realoadIcon = requireAsset("assets/realoadIcon.png");
  let moreIcon = requireAsset("assets/moreIcon.png");
  let logo = requireAsset("assets/logoGmail.png");
  let sndwichMenu = requireAsset("assets/sandwichMenuIcon.png");
  let appMenu = requireAsset("assets/appMenuIcon.png");
  let searchIcon = requireAsset("assets/magnifyingGlass.png");
  let closeIcon = requireAsset("assets/closeIcon.png");
  let dropdownIcon = requireAsset("assets/dropdowIcon.png");
  let uncheckedIcon = requireAsset("assets/uncheckedIcon.png");
  let unfavoritedIcon = requireAsset("assets/unfavoritedIcon.png");
};
