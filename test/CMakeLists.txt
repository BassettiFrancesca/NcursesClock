cmake_minimum_required(VERSION 3.5)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp ClockFixture.cpp TimerTest.cpp)
add_executable(runClockTests ${TEST_SOURCE_FILES})
target_link_libraries(runClockTests gtest gtest_main core)