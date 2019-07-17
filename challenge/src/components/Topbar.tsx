import * as React from "react";
import styled from "styled-components";
import { Menu } from "styled-icons/material/Menu";
import {Tweets} from './Tweets'

const Wrapper = styled.header`
  height: 4rem;
  border-bottom: 1px solid #edeef0;
  display: flex;
  flex-direction: row;
  align-items: center;
  justify-content: flex-start;
`;

const Gmail = styled.img.attrs({
  src: "https://logodownload.org/wp-content/uploads/2018/03/gmail-logo.png"
})`
  height: 1.6rem;
  margin-left: 1rem;
`;

const MenuIcon = styled(Menu)`
  background-color: #feffff;
  height: 1.5rem;
`;

const SearchBox = styled.input.attrs({
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

const LogoWrapper = styled.div`
  box-sizing: border-box;
  display: flex;
  flex-direction: row;
  justify-content: center;
  width: 15rem;
`;

const Topbar: React.FC = () => {
  return (
    <>
      <Wrapper>
        <LogoWrapper>
          <MenuIcon />
          <Gmail />
        </LogoWrapper>
        <SearchBox placeholder="#mars" />
      </Wrapper>
      <Tweets />
    </>
  );
};

export default Topbar;
