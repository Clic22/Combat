add_library(sword Sword.cpp)
target_include_directories (sword PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(axe Axe.cpp)
target_include_directories (axe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(greatSword GreatSword.cpp)
target_include_directories (greatSword PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_definitions(-fprofile-arcs --coverage)

include_directories(../../Warriors)
include_directories(../../Objects)
include_directories(../../Traits)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})