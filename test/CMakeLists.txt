include(CTest)

enable_testing()

add_executable(
  tests
  tests.cpp
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