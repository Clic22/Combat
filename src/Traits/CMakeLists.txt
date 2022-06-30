add_subdirectory(Bonus)

add_library(trait Trait.cpp)
target_include_directories (trait PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(traitFactory TraitFactory.cpp)
target_include_directories (traitFactory PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_definitions(-fprofile-arcs --coverage)

include_directories(../Warriors)
include_directories(../Objects)
include_directories(Bonus)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})