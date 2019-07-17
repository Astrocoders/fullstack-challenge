import * as React from "react";
import styled from 'styled-components'

const Wrapper = styled.div`
  right: 0;
  top: 0;
  z-index: 999;
`;

interface Props {
    query: string;
}

const Tweets: React.FC<Props>= ({query}: Props) => {
  return <><Wrapper><h1>{query}</h1></Wrapper></>;
};

export default Tweets;
