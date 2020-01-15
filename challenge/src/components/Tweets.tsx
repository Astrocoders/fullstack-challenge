import * as React from "react";
import * as R from "ramda";
import styled from "styled-components";
import { Square } from "styled-icons/boxicons-regular/Square";
import { Star } from "styled-icons/boxicons-regular/Star";
import { useQuery } from "@apollo/react-hooks";
import gql from "graphql-tag";

const Wrapper = styled.div`
  box-sizing: border-box;
  width: 100%;
  max-width: 100%;
  flex: 6;
`;

const TweetWrapper = styled.div`
  font-size: 0.9rem;
  border-bottom: 1px solid #e3e7e8;
  padding: 0.8rem;
  display: flex;
  flex-direction: row;
  box-sizing: border-box;

  :hover {
    cursor: pointer;
    -webkit-box-shadow: 0px 1px 3px 0px rgba(0, 0, 0, 0.3);
    -moz-box-shadow: 0px 1px 3px 0px rgba(0, 0, 0, 0.3);
    box-shadow: 0px 1px 3px 0px rgba(0, 0, 0, 0.3);
  }
`;

const UserWrapper = styled.div`
  flex: 2;
  overflow: hidden;
  display: flex;
  justify-content: flex-start;
`;

const TextWrapper = styled.div`
  flex: 8;
  overflow: hidden;
`;

const DateWrapper = styled.div`
  flex: 2;
`;

const CheckBox = styled(Square)`
  color: #cbcfd0;
  width: 1.2rem;
  height: 1.2rem;
`;

const Fav = styled(Star)`
  color: #cbcfd0;
  width: 1.2rem;
  height: 1.2rem;
`;

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
    <TweetWrapper key={tw.id}>
      <UserWrapper>
        <CheckBox />
        <Fav />
        <strong>{tw.user.name}</strong>
      </UserWrapper>
      <TextWrapper>{tw.text}</TextWrapper>
      <DateWrapper>{tw.created_at}</DateWrapper>
    </TweetWrapper>
  ));

  const Loading = R.always("Loading...");

  return (
    <>
      <Wrapper>{loading ? Loading() : twts(tweetsList)}</Wrapper>
    </>
  );
};

export default Tweets;
