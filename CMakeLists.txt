cmake_minimum_required(VERSION 3.10.2)
project(portal)

# std c++11
set (CMAKE_CXX_STANDARD 11)

# Flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -Werror -pedantic")
# debugging flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -DDEBUG -fno-inline")

# Including CxxTest
file(GLOB TEST_HEADERS ./test/*.h)
file(GLOB ALL_SRCS ./common/src/*.cpp ./client/src/*.cpp  ./server/src/*.cpp)
# Se quitan los main de client y server porque runner.cpp es el main del test
list(REMOVE_ITEM ALL_SRCS ./client/main.cpp ./server/main.cpp)

find_package(CxxTest)
if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()
    CXXTEST_ADD_TEST(unittest runner.cc ${TEST_HEADERS})
endif()
