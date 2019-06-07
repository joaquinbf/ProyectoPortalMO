cmake_minimum_required(VERSION 3.10.2)
project(portal)

# std c++11
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

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

# Including Box2D
include_directories(./libs/Box2D-master)
file(GLOB_RECURSE BOX2D_SRCS ./libs/Box2D-master/Box2D/*.cpp)

# Including SDL2
#INCLUDE(FindPkgConfig)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS})


# Including CxxTest
file(GLOB_RECURSE TEST_CLIENT_HEADERS ./test/client/*.h)
file(GLOB_RECURSE TEST_SERVER_HEADERS ./test/server/*.h)
file(GLOB_RECURSE TEST_COMMON_HEADERS ./test/common/*.h)

# Se quitan los main de client y server porque runner.cpp es el main del test,
#  sino da error porque  se encuentra dos veces main().
list(FILTER CLIENT_SRCS EXCLUDE REGEX "main.cpp")
list(FILTER SERVER_SRCS EXCLUDE REGEX "main.cpp")


# Libraries
add_library(libbox2d SHARED ${BOX2D_SRCS})
add_library(libcommon SHARED ${COMMON_SRCS})
add_library(libserver SHARED ${SERVER_SRCS})
add_library(libclient SHARED ${CLIENT_SRCS})
TARGET_LINK_LIBRARIES(libserver libcommon libbox2d)
target_link_libraries(libclient libcommon avformat avcodec avutil swscale ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_MIXER_LIBRARIES})

find_package(CxxTest)
if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()
    CXXTEST_ADD_TEST(unittest-client runner-client.cpp ${TEST_CLIENT_HEADERS})
    TARGET_LINK_LIBRARIES(unittest-client libclient)

    CXXTEST_ADD_TEST(unittest-server runner-server.cpp ${TEST_SERVER_HEADERS} )
    TARGET_LINK_LIBRARIES(unittest-server libserver)

    CXXTEST_ADD_TEST(unittest-common runner-common.cpp ${TEST_COMMON_HEADERS})
    TARGET_LINK_LIBRARIES(unittest-common libcommon)
endif()

# Executables
add_executable(client "client/src/main.cpp")
TARGET_LINK_LIBRARIES(client libclient)

add_executable(server "server/src/main.cpp")
TARGET_LINK_LIBRARIES(server libserver)
