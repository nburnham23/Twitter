//
// Created by Noah Burnham on 9/30/24.
//

#include "User.h"
#include "Tweet.h"
#include "Feed.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int get_menu_choice_from_user();
string get_word_from_user();
string get_sentence_from_user();
string get_date_from_user();
int main(){
    vector<User> users;
    Feed feed;
    cout << "Welcome to Twitter!" << endl;
    cout << "What would you like to do today?" << endl;
    cout << "1. Tweet what's on my mind!" << endl;
    cout << "2. I just want to read some tweets!" << endl;
    cout << "3. I would like to make an account!" << endl;
    cout << "4. I am done with Twitter for the day... :(" << endl;

    int user_input = get_menu_choice_from_user();

    while(user_input != 4){
        if(user_input == 1){
            string username, body, post_time;
            User user;
            bool found;

            cout << "Enter your username: ";
            username = get_word_from_user();
            // go through users and check their username, if they are in the vector then proceed. otherwise, make an account.
            for(int i = 0; i < users.size(); ++i){
                if(users[i].get_username() == username){
                    cout << "user found!" << endl;
                    found = true;
                    user = users[i];
                }
            }
            if(found == false){
                cout << "User not found." << endl;
                cout << "Enter your account information:" << endl;
                string user_username, email, date_of_birth;
                cout << "Username: ";
                user_username = get_word_from_user();
                cout << endl;
                cout << "email: ";
                email = get_word_from_user();
                cout << endl;
                cout << "date of birth: ";
                date_of_birth = get_date_from_user();
                cout << endl;
                User user1(user_username, email, date_of_birth);
                cout << "User information: " << endl;
                cout << user1 << endl;
                users.push_back(user1);
                user = user1;
            }
            // have the user create a tweet, add it to the feed, and write it to the feed file
            cout << "What is the body of the tweet?" << endl;
            body = get_sentence_from_user();
            cout << "What is the post time? " << endl;
            post_time = get_sentence_from_user();
            Tweet tweet(user, body, post_time);
            feed.tweet(tweet);
        }
        if(user_input == 2){
            feed.print_feed("../feed.txt");
            cout << "Check out the feed.txt file to see the feed!" << endl;
        }
        if(user_input == 3){
            cout << "Enter your account information:" << endl;
            string username, email, date_of_birth;
            cout << "Username: ";
            username = get_word_from_user();
            cout << endl;
            cout << "email: ";
            email = get_word_from_user();
            cout << endl;
            cout << "date of birth: ";
            date_of_birth = get_sentence_from_user();
            cout << endl;
            User user(username, email, date_of_birth);
            cout << "User information: " << endl;
            cout << user << endl;
            users.push_back(user);
        }
        cout << "What would you like to do now?" << endl;
        cout << "1. Tweet what's on my mind!" << endl;
        cout << "2. I just want to read some tweets!" << endl;
        cout << "3. I would like to make an account!" << endl;
        cout << "4. I am done with Twitter for the day... :(" << endl;
        user_input = get_menu_choice_from_user();
    }
    cout << "Bye Bye! Thanks for using Twitter! Tweet ya later!" << endl;
    return 0;
}

int get_menu_choice_from_user() {
    string userInputString;
    int userInputInt;
    bool badInput;
    stringstream ss;
    int dashCounter;
    string errorType;

    do{
        badInput = false;
        dashCounter = 0;
        if(errorType == "NO INPUT"){
            cout << "No input. Enter your choice 1-4: ";
        }
        else if (errorType == "INVALID INPUT"){
            cout << "Invalid Input. Enter your choice 1-4: ";
        }
        else{
            cout << "Enter your choice 1-4: ";
        }
        getline(cin, userInputString);
        // go through the string and make sure the only characters in the input are 0-4
        for(int i = 0; i < userInputString.length(); ++i){
            if(!((userInputString[i]== '1') || (userInputString[i]== '2') ||
                 (userInputString[i]== '3') || (userInputString[i]== '4') )){
                badInput = true;
                errorType = "INVALID INPUT";
            }
        }
        if(userInputString.length() > 1){
            badInput = true;
            errorType = "INVALID INPUT";
        }
        if(userInputString.empty()){
            badInput = true;
            errorType = "NO INPUT";
        }
    }while(badInput);
    // Now the input is valid and can be stored in a variable of type int
    ss << userInputString;
    ss >> userInputInt;
    return userInputInt;
}
string get_word_from_user() {
    string userInputWord;
    bool badInput;
    string errorType;
    do{
        badInput = false;
        if(errorType == "NO INPUT"){
            cout << "No input. Enter a single word. ";
        }
        else if (errorType == "INVALID INPUT"){
            cout << "Invalid Input. Enter a single word. ";
        }
        else{
            cout << "Enter a word: ";
        }
        getline(cin, userInputWord);
        // check if the input is empty
        if(userInputWord.empty()){
            badInput = true;
            errorType = "NO INPUT";
        }
        // check if input contains whitespace
        for(int i = 0; i < userInputWord.length(); ++i){
            if(userInputWord[i] == ' '){
                badInput = true;
                errorType = "INVALID INPUT";
            }
        }
    }while(badInput);

    return userInputWord;
}
string get_sentence_from_user() {
    string userInputSentence;
    cout << "Enter a sentence: ";
    getline(cin, userInputSentence);
    while(userInputSentence.empty()){
        cout << "No input. Please enter a sentence. ";
        getline(cin, userInputSentence);
    }
    return userInputSentence;
}
string get_date_from_user() {
    string userInputSentence;
    cout << "Enter a date: ";
    getline(cin, userInputSentence);
    while(userInputSentence.empty()){
        cout << "No input. Please enter a date. ";
        getline(cin, userInputSentence);
    }
    return userInputSentence;
}