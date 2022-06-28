add_library(hello hello.cpp)
target_include_directories (hello PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable (main.exe main.cpp) 
target_include_directories (main.exe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-fprofile-arcs --coverage)
target_link_libraries(main.exe hello -fprofile-arcs --coverage)