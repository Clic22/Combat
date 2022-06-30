add_library(buckler Buckler.cpp)
target_include_directories (buckler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(armor Armor.cpp)
target_include_directories (armor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_definitions(-fprofile-arcs --coverage)

include_directories(../../Warriors)
include_directories(../../Objects)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})