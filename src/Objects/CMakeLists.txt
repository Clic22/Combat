add_library(object Object.cpp)
target_include_directories (object PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-fprofile-arcs --coverage)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})