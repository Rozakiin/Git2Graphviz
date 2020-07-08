project(Git2GraphvizLibrary VERSION 1.0)

#print_variables()

set(HEADERS
    Git2Graphviz.hpp
)

set(SOURCES
    Git2Graphviz.cpp
)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    link_directories(${Boost_LIBRARY_DIRS})

    add_library(${PROJECT_NAME} STATIC 
        ${HEADERS}
        ${SOURCES}
    )

    target_link_libraries(${PROJECT_NAME} PUBLIC 
        git2
        ${Boost_LIBRARIES}
    )
endif()