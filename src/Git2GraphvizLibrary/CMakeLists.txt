project(Git2GraphvizLibrary VERSION 1.0)

#print_variables()

set(HEADERS
    Git2Graphviz.hpp
)

set(SOURCES
    Git2Graphviz.cpp
)

message("Boost include directory is ${Boost_INCLUDE_DIR}")
message("Boost library directory is ${Boost_LIBRARY_DIRS}")
message("Boost libs are ${Boost_LIBRARIES}")

if (Boost_FOUND)

    include_directories(SYSTEM ${Boost_INCLUDE_DIR}) #treats boost as system to suppress warnings
    link_directories(${Boost_LIBRARY_DIRS})

    add_library(${PROJECT_NAME} STATIC 
        ${HEADERS}
        ${SOURCES}
    )

    target_link_libraries(${PROJECT_NAME} PUBLIC 
        git2
        ${Boost_LIBRARIES}
    )

    # enable compiler options for msvc, gccc, and clang
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
            -Werror
            -Wall
            -pedantic-errors
            -Wextra
            -Wconversion
            -Wsign-conversion
            >
        $<$<CXX_COMPILER_ID:MSVC>:
            /WX
            /W4
            >
    )
endif()