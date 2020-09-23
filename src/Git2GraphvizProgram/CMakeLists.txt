project(Git2GraphvizProgram VERSION 1.0)

#print_variables()

set(HEADERS
    
)

set(SOURCES
    main.cpp
)

message("Boost include directory is ${Boost_INCLUDE_DIR}")
message("Boost library directory is ${Boost_LIBRARY_DIRS}")
message("Boost libs are ${Boost_LIBRARIES}")

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    link_directories(${Boost_LIBRARY_DIRS})

    add_executable(${PROJECT_NAME} 
        ${HEADERS}
        ${SOURCES}
    )

    target_link_libraries(${PROJECT_NAME} PUBLIC
        Git2GraphvizLibrary
        ${Boost_LIBRARIES}
    )
endif()