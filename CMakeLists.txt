cmake_minimum_required(VERSION 3.17)
project(NcursesClock)

set(CMAKE_CXX_STANDARD 11)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(NcursesClock main.cpp Clock.cpp Clock.h Date.h Time.h Time12.cpp Time12.h DateNum.cpp DateNum.h DateText.cpp DateText.h GUIClock.cpp GUIClock.h Time24.cpp Time24.h Timer.cpp Timer.h Menu.cpp Menu.h Date.cpp)
target_link_libraries(NcursesClock ${CURSES_LIBRARIES})