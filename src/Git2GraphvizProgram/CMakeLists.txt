project(Git2GraphvizProgram VERSION 1.0)

#print_variables()

set(HEADERS
    
)

set(SOURCES
    main.cpp
)

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