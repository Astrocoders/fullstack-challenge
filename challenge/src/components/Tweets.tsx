import * as React from "react";
import * as R from "ramda";
import styled from "styled-components";
import { useQuery } from "@apollo/react-hooks";
import gql from "graphql-tag";

const Wrapper = styled.div``;

interface Props {
  query: string;
}

interface TwitterUser {
  name: string;
}

interface Tweet {
  id: string;
  text: string;
  created_at: string;
  user: TwitterUser;
}

const FETCH_TWEETS = gql`
  query searchTweets($q: String!) {
    twitter {
      search(q: $q, result_type: recent, count: 40) {
        id
        text
        created_at
        user {
          name
        }
      }
    }
  }
`;

const Tweets: React.FC<Props> = ({ query }: Props) => {
  const [tweetsList, setTweetsList] = React.useState<Array<Tweet>>([]);

  const { data, loading } = useQuery(FETCH_TWEETS, {
    variables: { q: query }
  });

  React.useEffect(() => {
    const isDone = R.ifElse(
      R.has("twitter"),
      () => setTweetsList(data.twitter.search),
      () => null
    );

    isDone(data);
  }, [data, loading]);

  const twts = R.map((tw: Tweet) => (
    <div key={tw.id}>
      <span>{tw.user.name}</span>
      <span>{tw.text}</span>
      <span>{tw.created_at}</span>
    </div>
  ));

  const Loading = R.always("Loading...");

  return (
    <>
      <Wrapper>{loading ? Loading() : <div>{twts(tweetsList)}</div>}</Wrapper>
    </>
  );
};

export default Tweets;
