# CMake build script for the CompareCommits project TODO
#
# Building (out of source build):
# > mkdir build && cd build
# > cmake .. [-DSETTINGS=VALUE]
# > cmake --build .
#
# Testing:
# > ctest -V
#
# Install:
# > cmake --build . --target install

cmake_minimum_required(VERSION 3.16)
project(Git2Graphviz VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_IMDEPENDENT_CODE ON)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

include(cmake/PrintVariables.cmake)

print_variables()

enable_testing()

# Build googletest
add_subdirectory(lib/googletest)

# Set libgit2 options (e.g. disable shared lib) TODO
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

# Build libgit2
add_subdirectory(lib/libgit2)

# add includes
include_directories(lib/libgit2/include)
include_directories(src)

# Set Boost options
set(BOOST_ROOT lib/boost)
set(BOOST_LIBRARYDIR lib/boost/stage/lib)
#set(Boost_DEBUG ON)  #<---------- Real life saver

# linking of Boost options
set(Boost_USE_STATIC_LIBS        ON) 
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     OFF)
set(BOOST_ALL_DYN_LINK           OFF) # force dynamic linking for all libraries

# Find Boost
find_package(Boost 1.73 REQUIRED COMPONENTS graph program_options)
message(status "** Boost Include: ${Boost_INCLUDE_DIR}")
message(status "** Boost Libraries: ${Boost_LIBRARY_DIRS}")
message(status "** Boost Libraries: ${Boost_LIBRARIES}")

# Build Git2Graphviz Library
add_subdirectory(src/Git2GraphvizLibrary)

# Build Git2Graphviz Program
add_subdirectory(src/Git2GraphvizProgram)

# Build tests
add_subdirectory(tests)
