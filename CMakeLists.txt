cmake_minimum_required(VERSION 3.00)
project(KnapsackProblem)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)

include_directories(include)

set(TEST_FILES
        tests/TestAll.cpp
)

add_executable(UnboundedKnapsack src/UnboundedKnapsack.cpp)
add_executable(BoundedKnapsack src/BoundedKnapsack.cpp)
add_executable(ZeroOneKnapsack src/ZeroOneKnapsack.cpp)

add_executable(Tests ${TEST_FILES})

target_link_libraries(Tests PRIVATE GTest::GTest GTest::Main pthread)

add_test(NAME UnboundedKnapsackTests COMMAND Tests)
add_test(NAME BoundedKnapsackTests COMMAND Tests)