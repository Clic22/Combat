add_library(vicious Vicious.cpp)
target_include_directories (vicious PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(veteran Veteran.cpp)
target_include_directories (veteran PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_definitions(-fprofile-arcs --coverage)

include_directories(../../Warriors)
include_directories(../../Traits)
include_directories(../../Objects)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})