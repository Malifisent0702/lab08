cmake_minimum_required(VERSION 3.10)
project(hello_world)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hello_world hello_world.cpp)

target_link_libraries(hello_world
    ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_ex_lib/build/Release/formatter_ex.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_lib/build/Release/formatter.lib
)

target_include_directories(hello_world PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_ex_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_lib
)
