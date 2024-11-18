# Twitter

I coded this project for my advanced programming class in C++. The program functions similarly to Twitter and writes
the User's Tweets to a file called ```feed.txt```.
The Twitter project has three classes: User, Tweet, and Feed. The User has a username, email, and a date of birth. 
A Tweet has a user, a body, and a post time. Lastly, a Feed has a vector of Tweet object. The user has four 
options: they can tweet, read the feed, create an account, or exit. When using Twitter, the user can only Tweet 
if they have a registered account. If the user doesn't have an account, the program prompts the user to create
one. When the user wants to read the feed, it gets written to the feed.txt file. The third option is to create
an account. Any input needed from the user gets validated. The program shows a number of programming practices:
* Has-A relationships
  * Feed has a Tweet
  * Tweet has a User
* Writing to files
* User input validation
* An extensive testing suite
* Style
  * Everything is separated into header and implementation files, with descriptive comments wherever appropriate. 

I could expand this project by saving the user's account information to a database and making it into an actual 
website instead of running it from the console. 