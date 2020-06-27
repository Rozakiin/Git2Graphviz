cmake_minimum_required(VERSION 3.16)
project(Git2Graphviz C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_IMDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(lib/googletest)
add_subdirectory(lib/libgit2)

set(Boost_INCLUDE_DIR /lib/boost)
set(Boost_LIBRARY_DIR /lib/boost/libs)

find_package(Boost 0.0.0 REQUIRED COMPONENTS graph)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    add_library(Git2Graphviz SHARED src/Git2Graphviz.hpp src/Git2Graphviz.cpp)
endif()


target_link_libraries(Git2Graphviz LINK_PUBLIC ${Boost_LIBRARIES})


add_executable(Git2Graphvizmain src/main.cpp)

target_link_libraries(Git2Graphvizmain PRIVATE Git2Graphviz)

add_subdirectory(tests)

