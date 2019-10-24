import { GraphQLServer } from 'graphql-yoga';

const typeDefs = `
  type Query {
    hello: String!
  }
`;

const resolvers = {
  Query: {
    hello: () => 'Hello, this is the astrocoders challenge!'
  }
};

const server = new GraphQLServer({
  typeDefs,
  resolvers,
})

server.start(() => console.log('Server start in http://localhost:4000'));
