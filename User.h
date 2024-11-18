//
// Created by Noah Burnham on 9/30/24.
//

#ifndef TWITTER_USER_H
#define TWITTER_USER_H
#include <string>
#include <vector>
#include <iostream>

using std::string, std::vector, std::ostream, std::endl;

class User {
private:
    string username;
    string email;
    string date_of_birth;

public:
    // Constructors
    User();
    User(string username, string email, string date_of_birth);

    // Getters
    /**
     * the get_username method returns the username of the user
     * @return the username, a string
     */
    string get_username();
    /**
     * the get_email method returns the email of the user
     * @return email of the user, a string
     */
    string get_email();
    /**
     * the get_date_of_birth returns the date of birth of the user
     * @return date_of_birth, a string
     */
    string get_date_of_birth();

    // Setters
    /**
     * the set_username method changes the username
     * @param username
     */
    void set_username(string username);
    /**
     * the set_email method changes the email
     * @param email
     */
    void set_email(string email);
    /**
     * the set_date_of_birth method changes teh User's date of birth
     * @param date_of_birth
     */
    void set_date_of_birth(string date_of_birth);

    /**
     * check for equality of two tweets
     * equal if they have the same username
     * @param user1
     * @param user2
     * @return boolean representing equality of two Users
     */
    friend bool operator == (const User user1, const User user2){
        if(user1.username == user2.username){
            return true;
        }
        return false;
    }
    /**
     * prints out a User
     * username, email, date of birth on separate lines.
     * @param outs
     * @param user
     * @return
     */
    friend ostream& operator << (ostream& outs, const User user){
        outs << user.username << endl;
        outs << user.email << endl;
        outs << user.date_of_birth << endl;
        return outs;
    }
};


#endif //TWITTER_USER_H