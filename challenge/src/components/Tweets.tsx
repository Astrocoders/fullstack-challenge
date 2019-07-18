import * as React from "react";
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
  username: string;
  user: TwitterUser;
}

const FETCH_TWEETS = gql`
  query searchTweets($q: String!) {
    twitter {
      search(q: $q, result_type: recent, count: 5) {
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
    const onSearch = () => {
      setTweetsList(data.twitter.search);
    };

    if (!loading && data) {
      onSearch();
    }
  }, [data, loading]);

  console.log(tweetsList);

  return (
    <>
      <Wrapper>
        {loading ? (
          <>loading...</>
        ) : (
          <div>
            {tweetsList.map(t => (
              <p key={t.id}>{t.text}</p>
            ))}
          </div>
        )}
      </Wrapper>
    </>
  );
};

export default Tweets;
