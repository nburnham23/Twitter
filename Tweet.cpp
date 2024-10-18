//
// Created by Noah Burnham on 9/30/24.
//

#include "Tweet.h"
Tweet::Tweet(){
    user = User();
    body = "default tweet";
    post_time = "January 1, 1900";
}
Tweet::Tweet(User user, string body, string post_time){
    this->user = user;
    this->body = body;
    this->post_time = post_time;
}

//Getters
User Tweet::get_user(){
    return user;
}
string Tweet::get_body(){
    return body;
}
string Tweet::get_post_time(){
    return post_time;
}

// Setters
void Tweet::set_user(User user){
    this->user = user;
}
void Tweet::set_body(string body){
    this->body = body;
}
void Tweet::set_post_time(string post_time){
    this->post_time = post_time;
}