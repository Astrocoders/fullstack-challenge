open Client;

ReactDOMRe.renderToElementWithId(
  <ReasonApollo.Provider client>
    <ReasonApolloHooks.ApolloProvider client>
      <App />
    </ReasonApolloHooks.ApolloProvider>
  </ReasonApollo.Provider>,
  "root",
);
