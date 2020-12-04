cmake_minimum_required(VERSION 3.17)
project(NcursesClock)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
set(SOURCE_FILES Clock.cpp Clock.h Timer.cpp Timer.h)
add_executable(NcursesClock main.cpp Time.h Time12.cpp Time12.h Date.h DateNum.cpp DateNum.h DateText.cpp DateText.h GUIClock.h Time24.cpp Time24.h GUITimer.cpp GUITimer.h Menu.cpp Menu.h Date.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(NcursesClock ${CURSES_LIBRARIES} core)