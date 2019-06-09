cmake_minimum_required(VERSION 2.6)
project(OptiCrib)

set(CURSES_NEED_WIDE TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

file(GLOB OptiCrib_SRC
        "src/*.h"
        "src/*.cpp")

add_executable(OptiCrib ${OptiCrib_SRC})
target_link_libraries(OptiCrib ${CURSES_LIBRARIES})
