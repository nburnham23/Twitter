//
// Created by Noah Burnham on 9/30/24.
//

#ifndef TWITTER_FEED_H
#define TWITTER_FEED_H
#include <vector>
#include "Tweet.h"
#include <iostream>
using std::string;
/*
 * The feed class will hold a vector of tweets
 * It will print tweets to a file
 */
class Feed {
private:
    vector<Tweet> tweets;
public:
    // Constructors
    Feed();
    Feed(vector<Tweet> tweets);

    // Getter
    /**
     * the get_tweets method returns the vector of tweets in the Feed
     * @return vector of Tweets
     */
    vector<Tweet> get_tweets();

    // Setter
    /**
     * changes the vector of Tweets that the Feed has
     * @param tweets the new vector of Tweets for the Feed
     */
    void set_tweets(vector<Tweet> tweets);
    /**
     * the addTweet method adds a tweet to the tweets vector
     * @param tweet
     */
    void tweet(Tweet tweet);

    /**
     * The showFeed method prints out the entire feed of Tweets to a file
     */
    void print_feed(string filename);
};


#endif //TWITTER_FEED_H