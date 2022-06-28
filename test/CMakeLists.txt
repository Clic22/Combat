include(CTest)

enable_testing()

add_executable(
  tests
  tests.cpp
)

target_link_libraries(
  tests
  hello
  gcov
  gtest_main
)

add_definitions(-fprofile-arcs -ftest-coverage)
include(GoogleTest)
gtest_discover_tests(tests)