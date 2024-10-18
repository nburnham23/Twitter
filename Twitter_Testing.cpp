//
// Created by Noah Burnham on 10/4/24.
//
#include <iostream>
#include "Tweet.h"
#include "User.h"
#include "Feed.h"
using namespace std;

bool test_tweet();
bool test_user();
bool test_feed();

int main(){
    if(test_tweet()){
        cout << "Passed all Tweet tests!" << endl;
    }
    if(test_user()){
        cout << "Passed all User tests!" << endl;
    }
    if(test_feed()){
        cout << "Passed all Feed tests!" << endl;
    }
    return 0;
}

bool test_tweet(){
    bool passed = true;
    User user1("nono", "email", "dob");
    Tweet tweet1;
    Tweet tweet2 (user1, "body", "post time");

    if(!(tweet2.get_user() == user1)){
        cout << "FAILED: test case tweet2.get_user" << endl;
        passed = false;
    }

    if(tweet2.get_body() != "body"){
        cout << "FAILED: test case tweet2.get_body()" << endl;
        passed = false;
    }
    if(tweet2.get_post_time() != "post time"){
        cout << "FAILED: test case tweet2.get_post_time()" << endl;
        passed = false;
    }

    tweet1.set_user(user1);
    if(!(tweet1.get_user() == user1)){
        cout << "FAILED: test case tweet1.set_user()" << endl;
        passed = false;
    }
    tweet1.set_body("test body tweet1");
    if(tweet1.get_body() != "test body tweet1"){
        cout << "FAILED test case tweet1.set_body()" << endl;
        passed = false;
    }
    tweet1.set_post_time("october 6");
    if(tweet1.get_post_time() != "october 6"){
        cout << "FAILED test case tweet1.set_post_time()" << endl;
        passed = false;
    }
    return passed;
}

bool test_user(){
    bool passed = true;

    User user1;
    User user2("nono", "email", "dob");

    // Getters
    if(user2.get_username() != "nono"){
        cout << "FAILED test case user2.get_username()" << endl;
        passed = false;
    }
    if(user2.get_email() != "email"){
        cout << "FAILED test case user2.get_email()" << endl;
        passed = false;
    }
    if(user2.get_date_of_birth() != "dob"){
        cout << "FAILED test case user2.get_date_of_birth()" << endl;
        passed = false;
    }

    // Setters
    user1.set_username("username");
    user1.set_email("email");
    user1.set_date_of_birth("dob");
    if(user1.get_username() != "username"){
        cout << "FAILED test case user1.set_username()" << endl;
        passed = false;
    }
    if(user1.get_email() != "email"){
        cout << "FAILED test case user1.set_email()" << endl;
        passed = false;
    }
    if(user1.get_date_of_birth() != "dob"){
        cout << "FAILED test case user1.set_date_of_birth()" << endl;
        passed = false;
    }

    return passed;
}

bool test_feed(){
    bool passed = true;
    User nono("nono", "nono email", "nono dob");
    User momo("momo", "momo email", "momo dob");
    User coco("coco", "coco email", "coco dob");

    Tweet tweet1 (nono, "nono body", "nono post time");
    Tweet tweet2 (momo, "momo body", "momo post time");
    Tweet tweet3 (coco, "coco body", "coco post time");

    vector<Tweet> tweets = {tweet1, tweet2, tweet3};

    User bobo("bobo", "bobo email", "bobo dob");
    User dodo("dodo", "dodo email", "dodo dob");
    User lolo("lolo", "lolo email", "lolo dob");

    Tweet altered_tweet_1 (bobo, "bobo body", "bobo post time");
    Tweet altered_tweet_2 (dodo, "dodo body", "dodo post time");
    Tweet altered_tweet_3 (lolo, "lolo body", "lolo post time");

    vector<Tweet> alteredTweets = {altered_tweet_1, altered_tweet_2, altered_tweet_3};

    Feed feed1;
    Feed feed2(tweets);

    vector<Tweet> test_vec = feed2.get_tweets();
    for(int i = 0; i < tweets.size(); ++i){
        if(!(tweets[i] == test_vec[i])){
            cout << "FAILED test case feed2.getTweets()" << endl;
            passed = false;
        }
    }

    feed1.set_tweets(tweets);
    vector<Tweet> test_feed1_vec = feed1.get_tweets();
    for(int i = 0; i < tweets.size(); ++i){
        if(!(tweets[i] == test_feed1_vec[i])){
            cout << "FAILED test case feed1.setTweets()" << endl;
            passed = false;
        }
    }

    feed2.tweet(altered_tweet_1);
    test_vec = feed2.get_tweets();
    for(int i = 0; i < tweets.size(); ++i){
        if(!(tweets[i] == test_vec[i])){
            cout << "FAILED test case feed2.getTweets()" << endl;
            passed = false;
        }
    }
    return passed;
}
