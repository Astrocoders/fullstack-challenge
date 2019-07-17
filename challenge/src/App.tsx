import React from "react";
import GlobalStyle from "./styles/global";
import Main from './pages/Main'

const App: React.FC = () => {
  return (
    <div className="App">
      <GlobalStyle />
      <Main />
    </div>
  );
};

export default App;
