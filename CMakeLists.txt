cmake_minimum_required(VERSION 3.17)
project(NcursesClock)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
set(SOURCE_FILES Clock.cpp Clock.h Timer.cpp Timer.h)
add_executable(NcursesClock main.cpp TimeGetter.h Time12Getter.cpp Time12Getter.h DateGetter.h DateNumGetter.cpp DateNumGetter.h DateTextGetter.cpp DateTextGetter.h
        GUIClock.h Time24Getter.cpp Time24Getter.h GUITimer.cpp GUITimer.h Menu.cpp Menu.h DateGetter.cpp GUIClock.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(NcursesClock ${CURSES_LIBRARIES} core)
