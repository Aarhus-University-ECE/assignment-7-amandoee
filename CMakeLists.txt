cmake_minimum_required(VERSION 3.10)
project(template)
include(CTest)

set(CMAKE_CXX_STANDARD 14)

# static checks
# if(MSVC)
#   add_compile_options(/W4 /WX)
# else()
#   add_compile_options(-Wall -Wextra -pedantic -Werror)
# endif()

# set(CMAKE_CXX_CLANG_TIDY
#   clang-tidy;
#   -checks=*;
# )

# set(CMAKE_CXX_CPPCHECK
#   cppcheck;
#   --error-exitcode=1;
# )


# define library called queue that can imported into other targets via
# 'target_link_libraries'
add_library(mymath src/stack.c src/taylor_sine.c )
target_include_directories(mymath PUBLIC include)

# define executable named main for experimenting and debugging code
add_executable(main src/main.cpp)
target_link_libraries(main mymath)

# tests are added by declaring a target, in this case 'tests'. additional tests
# can be added by expanding the test cases in 'src/tests.cpp' or an additional
# target via 'add_executable'
enable_testing()
add_subdirectory(tests)

