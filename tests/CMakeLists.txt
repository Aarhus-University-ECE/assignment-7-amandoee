project(tests)

include_directories(include)
add_executable(tests src/tests.cpp)
target_link_libraries(tests mymath)
add_test(usage_test tests)