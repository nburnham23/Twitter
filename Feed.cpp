//
// Created by Noah Burnham on 9/30/24.
//

#include "Feed.h"
#include <fstream>
using namespace std;
Feed::Feed(){
    tweets = {};
}
Feed::Feed(vector<Tweet> tweets){
    this->tweets = tweets;
}

vector<Tweet> Feed::get_tweets(){
    return tweets;
}

void Feed::set_tweets(vector<Tweet> tweets){
    this->tweets = tweets;
}
void Feed::tweet(Tweet tweet){
    tweets.push_back(tweet);
}

void Feed::print_feed(string filename){
    ofstream feedFile(filename);
    for(Tweet tweet : tweets){
        feedFile << tweet << endl << endl;
    }
    feedFile.close();
}