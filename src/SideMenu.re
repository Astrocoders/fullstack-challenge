open Utils;

requireStyle("styles/SideMenu.css");

let inboxIcon = requireAsset("assets/inboxIcon.png");
let snoozedIcon = requireAsset("assets/clockIcon.png");
let starIcon = requireAsset("assets/starIcon.png");
let flagIcon = requireAsset("assets/flagIcon.png");
let sentIcon = requireAsset("assets/sentIcon.png");
let draftIcon = requireAsset("assets/draftIcon.png");
let markIcon = requireAsset("assets/flagIcon.png");

[@react.component]
let make = () =>
  <asside className="sideMenu">
    <div className="topSideMenu"> <ComposeButton /> </div>
    <ul className="listSideMenu">
      <MenuItem
        name="Inbox"
        asset=inboxIcon
        colorFG="#c42315"
        colorBG="#fce8e6"
      />
      <MenuItem name="Starred" asset=starIcon />
      <MenuItem name="Snoozed" asset=snoozedIcon />
      <MenuItem name="Important" asset=flagIcon />
      <MenuItem name="Sent" asset=sentIcon />
      <MenuItem name="Drafts" asset=draftIcon />
      <MenuItem name="Categories" asset=markIcon />
      <MenuItem name="Github-notificant" asset=markIcon />
      <MenuItem name="GROW SHIT" asset=markIcon />
      <MenuItem name="Guilhermex2" asset=markIcon />
      <MenuItem name="Meteor" asset=markIcon />
      <MenuItem name="Meteor Hacks" asset=markIcon />
      <MenuItem name="Notes" asset=markIcon />
      <MenuItem name="More" asset=markIcon />
    </ul>
  </asside>;
