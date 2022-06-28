add_subdirectory(Objects)
add_subdirectory(Warriors)

add_executable (main.exe main.cpp) 
target_include_directories (main.exe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_definitions(-fprofile-arcs --coverage)
target_link_libraries(main.exe object viking swordsman warrior -fprofile-arcs --coverage)