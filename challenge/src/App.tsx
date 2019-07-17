import React from 'react';
import GlobalStyle from './styles/global'
import Topbar from './components/Topbar'

const App: React.FC = () => {
  return (
    <div className="App">
      <GlobalStyle />
      <Topbar />
      <h1>react app</h1>
    </div>
  );
}

export default App;
