import * as React from "react";
import styled from "styled-components";
import { Menu } from "styled-icons/material/Menu";
import Tweets from "./Tweets";

const Wrapper = styled.header`
  height: 4rem;
  border-bottom: 1px solid #edeef0;
  display: flex;
  flex-direction: row;
  align-items: center;
  justify-content: flex-start;
  width: 100%;
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

const LogoWrapper = styled.div`
  box-sizing: border-box;
  display: flex;
  flex-direction: row;
  justify-content: center;
  width: 15rem;
`;

const Topbar: React.FC = ({ children }) => {
  return (
    <>
      <Wrapper>
        <LogoWrapper>
          <MenuIcon />
          <Gmail />
        </LogoWrapper>
        {children}
      </Wrapper>
      <Tweets />
    </>
  );
};

export default Topbar;
