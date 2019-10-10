open Utils;
open Utils.Assets;

requireStyle("styles/SideMenu.css");

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
