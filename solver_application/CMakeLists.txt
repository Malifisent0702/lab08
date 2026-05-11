cmake_minimum_required(VERSION 3.10)
project(solver)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(solver equation.cpp)

find_library(FORMATTER_LIB formatter PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_lib/build)
find_library(FORMATTER_EX_LIB formatter_ex PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_ex_lib/build)
find_library(SOLVER_LIB solver_lib PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../solver_lib/build)

target_link_libraries(solver ${FORMATTER_EX_LIB} ${FORMATTER_LIB} ${SOLVER_LIB})

target_include_directories(solver PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_ex_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../solver_lib
)
