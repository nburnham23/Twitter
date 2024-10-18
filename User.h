//
// Created by Noah Burnham on 9/30/24.
//

#include "User.h"
// Constructors
User::User(){
    username = "";
    email = "noname@gmail.com";
    date_of_birth = "January 1, 1900";
}
User::User(string username, string email, string date_of_birth){
    this->username = username;
    this->email = email;
    this->date_of_birth = date_of_birth;
}


// Getters
string User::get_username(){
    return username;
}
string User::get_email(){
    return email;
}
string User::get_date_of_birth(){
    return date_of_birth;
}

// Setters
void User::set_username(string username){
    this->username = username;
}
void User::set_email(string email){
    this->email = email;
}
void User::set_date_of_birth(string date_of_birth){
    this->date_of_birth = date_of_birth;
}