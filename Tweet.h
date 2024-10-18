//
// Created by Noah Burnham on 9/30/24.
//

#ifndef M2OEP_NBURNHAM_TWEET_H
#define M2OEP_NBURNHAM_TWEET_H

#include "User.h"
#include <string>
#include <iostream>
#include <fstream>
using std::string, std::ostream, std::endl;

class Tweet {
private:
    User user;
    string body;
    string post_time;
public:
    // Constructors
    Tweet();
    Tweet(User user, string body, string post_time);

    //Getters
    /**
     * the get_user method returns the User object of a tweet
     * @return a User object
     */
    User get_user();
    /**
     * the get_body method returns the body of a Tweet, a string
     * @return the body of the Tweet
     */
    string get_body();
    /**
     * the get_post_time method returns the post time of a tweet, a string
     * @return the post time of a tweet
     */
    string get_post_time();

    // Setters
    /**
     * the set_user method changes the User object of a Tweet
     * @param user the new User of the tweet
     */
    void set_user(User user);
    /**
     * the set_body method changes the body of the tweet
     * @param body a string representing the new body of the tweet
     */
    void set_body(string body);
    /**
     * the set_post_time method changes the post time of the tweet
     * @param post_time a string representing the post time of the tweet
     */
    void set_post_time(string post_time);

    /**
     * prints out the Tweet with the User, post time, and body all on separate lines.
     * @param outs
     * @param tweet
     * @return
     */
    friend ostream& operator << (ostream& outs, const Tweet tweet){
        outs << tweet.user << endl;
        outs << tweet.post_time << endl;
        outs << tweet.body << endl;
        return outs;
    }
    /**
     * compares two Tweets to check for equality.
     * Equal if the User, post time, and body are the same.
     * @param tweet1
     * @param tweet2
     * @return a boolean representing if the two Tweets are equal
     */
    friend bool operator == (Tweet& tweet1, Tweet& tweet2){
        if(tweet1.get_body() == tweet2.get_body() && tweet1.get_post_time() == tweet2.get_post_time() && tweet1.get_user() == tweet2.get_user()){
            return true;
        }else{
            return false;
        }
    }
};


#endif //M2OEP_NBURNHAM_TWEET_H