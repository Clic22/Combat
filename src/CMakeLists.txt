add_subdirectory(Objects)
add_subdirectory(Warriors)

add_executable (main main.cpp) 
target_include_directories (main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
    main
    warrior
    objectFactory 
    sword
    object
    buckler
    axe
    viking
    swordsman 
    -fprofile-arcs 
    --coverage
)