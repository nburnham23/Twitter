cmake_minimum_required(VERSION 3.15)
project(Twitter)

set(CMAKE_CXX_STANDARD 17)

add_executable(Twitter Feed.cpp Tweet.cpp User.cpp main.cpp )
add_executable(Twitter-Testing Feed.cpp Tweet.cpp User.cpp Twitter_Testing.cpp)