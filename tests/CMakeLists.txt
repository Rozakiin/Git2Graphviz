cmake_minimum_required(VERSION 3.16)

set(ThisProgram Git2GraphvizTests)

set(SOURCES
    Git2GraphvizTests.cpp
)

add_executable(Git2GraphvizTests Git2GraphvizTests.cpp)

target_link_libraries(Git2GraphvizTests PUBLIC
    gtest_main
    Git2Graphviz
)

add_test(
    NAME Git2GraphvizTests
    COMMAND Git2GraphvizTests
)

