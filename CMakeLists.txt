cmake_minimum_required(VERSION 3.15)
project(M2OEP-nburnham)

set(CMAKE_CXX_STANDARD 17)

add_executable(M2OEP-nburnham Feed.cpp Tweet.cpp User.cpp main.cpp )
add_executable(M2OEP-Testing Feed.cpp Tweet.cpp User.cpp Twitter_Testing.cpp)