cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)

project(plugit LANGUAGES CXX)

include_directories(include)
add_library(${PROJECT_NAME} src/shared_library.cpp)

option(CODE_COVERAGE "Enable coverage reporting" OFF)

if(CODE_COVERAGE)
    message(STATUS "Enabling coverage flags")
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()

option(BUILD_TESTS "Build tests executables" OFF)

if(BUILD_TESTS)
    enable_testing()
    include_directories(example/include)
    add_subdirectory(example)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    FetchContent_MakeAvailable(googletest)
    include(GoogleTest)
    add_executable(test_${PROJECT_NAME} test/test_shared_library.cpp)
    target_link_libraries(test_${PROJECT_NAME} gtest_main ${PROJECT_NAME} ${PROJECT_NAME}_example)
    gtest_discover_tests(test_${PROJECT_NAME})
endif()

if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_custom_target(coverage
        COMMAND lcov --directory . --zerocounters
        COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
        COMMAND lcov --directory . --capture --output-file coverage.info --ignore-errors mismatch
        COMMAND lcov --remove coverage.info '/usr/*' '*gtest*' '*CMakeFiles*' --output-file coverage.filtered.info --ignore-errors unused
        COMMAND genhtml coverage.filtered.info --output-directory coverage-report
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Generating code coverage report"
    )
endif()