open Utils;
open Utils.Assets;
open Types;
open Belt;

requireStyle("styles/MainList.css");

type state = {
  renderedList: bool,
  toogledFunction: bool,
  dataIndetail: dataRecord,
  listOnDisplay: dataList,
};

let initialState = {
  renderedList: true,
  toogledFunction: false,
  dataIndetail: {
    name: "",
    homepage: "",
    description: "",
  },
  listOnDisplay: [|{name: "", homepage: "", description: ""}|],
};

type action =
  | ReRenderList
  | ShowDetail(bool)
  | SetDetail(dataRecord)
  | SetList(dataList);

let reducer = (state, action) =>
  switch (action) {
  | ReRenderList => {...state, renderedList: true}
  | ShowDetail(bool) => {...state, toogledFunction: !state.toogledFunction}
  | SetDetail(dataRecord) => {...state, dataIndetail: dataRecord}
  | SetList(dataList) => {...state, listOnDisplay: dataList}
  };

module ApiQueryConfig = [%graphql
  {|
{
  npm {
    package(name: "graphql") @bsRecord{
      name @bsDecoder(fn: "Option.getExn")
      homepage @bsDecoder(fn: "Option.getExn")
      description @bsDecoder(fn: "Option.getExn")
    }
  }
}
|}
];

module ListQuery = ReasonApolloHooks.Query.Make(ApiQueryConfig);

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);
  let (simple, _full) = ListQuery.use();

  <main className="mainList">
    <header className="listHeader">
      <ToogleButton asset=uncheckedIcon toogled=checkedIcon roundness="12px" />
      <RoundButton asset=dropdownIcon roundness="12px" />
      <RoundButton asset=realoadIcon />
      <RoundButton asset=moreIcon />
    </header>
    {state.toogledFunction
       ? <div
           className="dataDetailCard"
           onClick={_ => dispatch(ShowDetail(false))}>
           <h3> state.dataIndetail.name->str </h3>
           <h1> state.dataIndetail.homepage->str </h1>
           <h3> state.dataIndetail.description->str </h3>
         </div>
       : <div className="listBody">
           <ul className="list">
             {switch (simple) {
              | Loading => <h2> "Loading..."->str </h2>
              | Data(data) =>
                  <ListItem
                    key="1"
                    data={Option.getExn(data##npm##package)}
                    onClickCallback={(value, evt) => {
                      dispatch(SetDetail(value));
                      dispatch(ShowDetail(true));
                    }}
                  />

                // data##[whatever list]
                // ->Option.getExn
                // ->Array.map(dataRecord => dataRecord->Option.getExn)
                // ->Array.map(dataRecord =>
                //     <ListItem
                //       key={dataRecord.number}
                //       data=dataRecord
                //       onClickCallback={(value, evt) => {
                //         dispatch(SetDetail(value));
                //         dispatch(ShowDetail(true));
                //       }}
                //     />
                //   )
                // ->React.array
              | NoData
              | Error(_) => <h2> "Error..."->str </h2>
              }}
           </ul>
         </div>}
    <footer className="listFooter">
      "something about avaliable space in memory"->str
    </footer>
  </main>;
};
