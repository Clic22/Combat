add_subdirectory(Objects)
add_subdirectory(Traits)
add_subdirectory(Warriors)

add_executable (main main.cpp) 
target_include_directories (main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
    main
    warrior
    traitFactory
    vicious
    veteran
    trait
    objectFactory 
    sword
    greatSword
    object
    armor
    buckler
    axe
    viking
    swordsman
    highlander
    -fprofile-arcs 
    --coverage
    -g
)