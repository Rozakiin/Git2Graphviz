project(Git2GraphvizTests VERSION 1.0)

set(SOURCES
    Git2GraphvizTests.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC
    gtest_main
    Git2GraphvizLibrary
)

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)
