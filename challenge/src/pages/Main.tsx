import * as React from "react";
import Topbar from "../components/Topbar";
import Sidebar from "../components/Sidebar";
import Tweets from "../components/Tweets";
import styled from "styled-components";

const Input = styled.input.attrs({
  type: "text"
})`
  border: 0;
  outline: 0;
  background-color: #f2f3f5;
  width: 40rem;
  padding: 1rem;
  font-size: 1rem;
  color: #000107;
  border-radius: 0.5rem;
  margin: auto 2rem;
  transition: box-shadow 0.2s;
  transition: background-color 0.2s;

  :focus {
    background-color: #ffffff;
    -webkit-box-shadow: 0px 1px 3px 0px rgba(0, 0, 0, 0.3);
    -moz-box-shadow: 0px 1px 3px 0px rgba(0, 0, 0, 0.3);
    box-shadow: 0px 1px 3px 0px rgba(0, 0, 0, 0.3);
  }
`;

const Layout = styled.div`
  display: flex;
`;

const Main: React.FC = () => {
  const [query, setQuery] = React.useState<string>("#mars");

  return (
    <>
      <Topbar>
        <Input value={query} onChange={e => setQuery(e.target.value)} />
      </Topbar>
      <Layout>
        <Sidebar />
        <Tweets query={query} />
      </Layout>
    </>
  );
};

export default Main;
