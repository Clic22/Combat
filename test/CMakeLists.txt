include(CTest)

enable_testing()

file(GLOB_RECURSE sources
    ${CMAKE_CURRENT_SOURCE_DIR}/**/*.cpp)

add_executable(
  tests
  ${sources}
)

target_link_libraries(
  tests
  warrior
  traitFactory
  veteran
  vicious
  trait
  object
  objectFactory
  sword
  greatSword
  armor
  buckler
  axe
  viking
  swordsman
  highlander
  gcov
  gtest_main
)

add_definitions(-fprofile-arcs -ftest-coverage)
include(GoogleTest)
gtest_discover_tests(tests)