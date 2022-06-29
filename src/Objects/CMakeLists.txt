add_library(object Object.cpp)
target_include_directories (object PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(buckler Buckler.cpp)
target_include_directories (buckler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(sword Sword.cpp)
target_include_directories (sword PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(axe Axe.cpp)
target_include_directories (axe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(greatSword GreatSword.cpp)
target_include_directories (greatSword PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(armor Armor.cpp)
target_include_directories (armor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(objectFactory ObjectFactory.cpp)
target_include_directories (objectFactory PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_definitions(-fprofile-arcs --coverage)

include_directories(../Warriors)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})