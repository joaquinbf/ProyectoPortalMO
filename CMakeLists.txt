cmake_minimum_required(VERSION 3.10.2)

project(portal)

set(CMAKE_CXX_STANDARD 11)
# flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Werror -pthread")

## Qt
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)

# Sources
file(GLOB_RECURSE MODEL_SRCS "model/src/*.cpp")
file(GLOB_RECURSE VIEW_SRCS "view/src/*.cpp")

# Tell CMake to create executable
add_executable(portal ${MODEL_SRCS} ${VIEW_SRCS})

# Use the Widgets module from Qt 5
target_link_libraries(portal Qt5::Widgets)
