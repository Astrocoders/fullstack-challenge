open Utils;

requireStyle("styles/RoundButton.css");

type state = {toogled: bool};

type action =
  | Toogle;

[@react.component]
let make =
    (
      ~asset: asset,
      ~toogled: asset,
      ~roundness: string="50%",
      ~onClick: 'a => unit=?,
    ) => {
  let url = asset => "url(" ++ getURI(asset) ++ ")";
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | Toogle => {toogled: !state.toogled}
        },
      {toogled: false},
    );
  <input
    style={ReactDOMRe.Style.make(
      ~backgroundImage={
        state.toogled ? url(toogled) : url(asset);
      },
      ~backgroundRepeat="no-repeat",
      ~backgroundPosition="center",
      ~borderRadius=roundness,
      (),
    )}
    className="roundButton"
    type_="button"
    onClick={_ => {
      onClick;
      dispatch(Toogle);
    }}
  />;
};
