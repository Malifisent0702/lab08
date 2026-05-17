cmake_minimum_required(VERSION 3.10)
project(print)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" OFF)

add_library(print STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)
target_include_directories(print PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(third-party/gtest)
    file(GLOB TEST_SOURCES tests/*.cpp)
    add_executable(check ${TEST_SOURCES})
    target_link_libraries(check print gtest_main)
    add_test(NAME check COMMAND check)
endif()
add_subdirectory(banking)


if(BUILD_TESTS)
    file(GLOB BANKING_TEST_SOURCES tests/banking/*.cpp)
    list(APPEND TEST_SOURCES ${BANKING_TEST_SOURCES})
    target_link_libraries(check banking)
endif()
