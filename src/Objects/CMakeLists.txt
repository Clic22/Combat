add_subdirectory(Attack)
add_subdirectory(Defense)

add_library(object Object.cpp)
target_include_directories (object PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(objectFactory ObjectFactory.cpp)
target_include_directories (objectFactory PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_definitions(-fprofile-arcs --coverage)

include_directories(../Warriors)
include_directories(../Traits)
include_directories(Attack)
include_directories(Defense)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})