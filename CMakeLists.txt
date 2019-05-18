cmake_minimum_required(VERSION 3.10.2)
project(portal)

# std c++11
set (CMAKE_CXX_STANDARD 11)

# Flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -Werror -pedantic")
# debugging flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -DDEBUG -fno-inline")
# threads
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# CLIENT - SERVER - COMMON
file(GLOB_RECURSE COMMON_SRCS ./common/src/*.cpp)
file(GLOB_RECURSE CLIENT_SRCS ./client/src/*.cpp)
file(GLOB_RECURSE SERVER_SRCS ./server/src/*.cpp)

# Including CxxTest
file(GLOB_RECURSE TEST_HEADERS ./test/*.h)
file(GLOB_RECURSE ALL_SRCS ${COMMON_SRCS} ${CLIENT_SRCS} ${SERVER_SRCS})
# Se quitan los main de client y server porque runner.cpp es el main del test
list(REMOVE_ITEM ALL_SRCS ./client/src/main.cpp ./server/src/main.cpp)

find_package(CxxTest)
if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()
    CXXTEST_ADD_TEST(unittest runner.cc ${TEST_HEADERS})
endif()

# Including Box2D
include_directories(./libs/Box2D-master)
file(GLOB_RECURSE BOX2D_SRCS ./libs/Box2D-master/Box2D/*.cpp)

# Executables
add_executable(client ${COMMON_SRCS} ${CLIENT_SRCS})
add_executable(server ${COMMON_SRCS} ${SERVER_SRCS} ${BOX2D_SRCS})
