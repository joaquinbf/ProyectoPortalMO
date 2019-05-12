cmake_minimum_required (VERSION 3.10.2)
project(client-server)
set(CMAKE_CXX_STANDARD 11)

# flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Werror -pthread")

# common sources
file(GLOB_RECURSE COMMON_SRC "common/src/*.cpp")

# client executable
file(GLOB_RECURSE CLIENT_SRC "client/src/*.cpp")
add_executable(client ${CLIENT_SRC} ${COMMON_SRC})

# server executable
file(GLOB_RECURSE SERVER_SRC "server/src/*.cpp")
add_executable(server ${SERVER_SRC} ${COMMON_SRC})
