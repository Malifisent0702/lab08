cmake_minimum_required(VERSION 3.10)
project(solver)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(solver equation.cpp)

target_link_libraries(solver
    ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_ex_lib/build/Release/formatter_ex.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_lib/build/Release/formatter.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../solver_lib/build/Release/solver_lib.lib
)

target_include_directories(solver PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_ex_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../solver_lib
)
