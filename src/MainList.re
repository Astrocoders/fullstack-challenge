open Utils;
open Utils.Assets;

requireStyle("styles/MainList.css");

module UserQueryConfig = [%graphql
  {|
{
  pokemons(first:40) {
    number
    name
    classification
  }
}
|}
];

module UserQuery = ReasonApolloHooks.Query.Make(UserQueryConfig);

[@react.component]
let make = () => {
  let (simple, _full) = UserQuery.use();
  <main className="mainList">
    <header className="listHeader">
      <RoundButton asset=uncheckedIcon roundness="12px" />
      <RoundButton asset=dropdownIcon roundness="12px" />
      <RoundButton asset=realoadIcon />
      <RoundButton asset=moreIcon />
    </header>
    <div className="listBody">
      <ul className="list">
        {switch (simple) {
         | Loading => <p> {React.string("Loading...")} </p>
         | Data(data) =>
           Js.log(data);
           <ListItem />;
         | NoData
         | Error(_) => <p> {React.string("Get off my lawn!")} </p>
         }}
      </ul>
    </div>
    <footer className="listFooter">
      "something about avaliable space in memory"->str
    </footer>
  </main>;
};
