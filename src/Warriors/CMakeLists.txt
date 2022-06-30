add_library(warrior Warrior.cpp)
target_include_directories (warrior PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(swordsman Swordsman.cpp)
target_include_directories (swordsman PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(viking Viking.cpp)
target_include_directories (viking PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(highlander Highlander.cpp)
target_include_directories (highlander PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(../Objects)
include_directories(../Traits)
add_definitions(-fprofile-arcs --coverage)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})