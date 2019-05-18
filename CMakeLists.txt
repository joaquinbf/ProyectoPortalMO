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

# Including SDL2
INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})

# Executables
add_executable(client ${COMMON_SRCS} ${CLIENT_SRCS})
TARGET_LINK_LIBRARIES(client ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})


add_executable(server ${COMMON_SRCS} ${SERVER_SRCS} ${BOX2D_SRCS})
