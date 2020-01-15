import { createGlobalStyle } from 'styled-components'

export default createGlobalStyle`
    * {
        margin: 0;
        padding: 0;
        outline: 0;
        box-sizing: border-box;
    }
    body {
        @import url('https://fonts.googleapis.com/css?family=Open+Sans&display=swap');
        font-family: 'Open Sans', sans-serif;
        font-size: 12px;
        background: #ffffff;
        color: #4e4e4e;
        text-rendering: optimizeLegibility;
        -webkit-font-smoothing: antialiased;
    }
    html, border-style, #root {
        height: 100%;
    }
`;  