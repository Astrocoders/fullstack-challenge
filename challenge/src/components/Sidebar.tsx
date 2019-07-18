import * as React from "react";
import styled from "styled-components";
import { Plus } from "styled-icons/feather/Plus";

const Wrapper = styled.div`
  display: flex;
  flex-direction: column;
  justify-content: flex-start;
  align-items: center;
  height: calc(100vh - 4rem);
  background-color: #ffffff;
  width: 17rem;
  flex: 1;
`;

const WriteButton = styled.button`
  width: 9rem;
  padding: 0.5rem;
  border: 0;
  border-radius: 2rem;
  outline: 0;
  font-size: 1rem;
  background-color: white;
  -webkit-box-shadow: 0px 1px 3px 0px rgba(0, 0, 0, 0.3);
  -moz-box-shadow: 0px 1px 3px 0px rgba(0, 0, 0, 0.3);
  box-shadow: 0px 1px 3px 0px rgba(0, 0, 0, 0.3);
  margin: 1rem;
  align-self: flex-start;
  color: #5c5253; 
  font-size: .8rem;

  transition: box-shadow 0.2s;

  :hover {
    cursor: pointer;
    -webkit-box-shadow: 0px 3px 5px 3px rgba(205, 205, 205, 1);
    -moz-box-shadow: 0px 3px 5px 3px rgba(205, 205, 205, 1);
    box-shadow: 0px 3px 5px 3px rgba(205, 205, 205, 1);
  }
`;

const PlusIcon = styled(Plus)`
  height: 2rem;
`;

const Sidebar: React.FC = () => {
  return (
    <Wrapper>
      <WriteButton>
        <PlusIcon />
        Compose
      </WriteButton>
    </Wrapper>
  );
};

export default Sidebar;
