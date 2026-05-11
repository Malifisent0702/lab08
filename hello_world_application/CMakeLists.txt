cmake_minimum_required(VERSION 3.10)
project(hello_world)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hello_world hello_world.cpp)

find_library(FORMATTER_LIB formatter PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_lib/build)
find_library(FORMATTER_EX_LIB formatter_ex PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_ex_lib/build)

target_link_libraries(hello_world ${FORMATTER_EX_LIB} ${FORMATTER_LIB})

target_include_directories(hello_world PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_ex_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_lib
)
