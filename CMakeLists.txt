cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    connect-four
    VERSION 0.1.0
    DESCRIPTION "Connect four"
    HOMEPAGE_URL "https://127.0.0.1"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    connect-four_lib OBJECT
    src/board.cpp
    src/computer.cpp
    src/player.cpp
    src/game.cpp
)

target_include_directories(
    connect-four_lib ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>"
)

target_compile_features(connect-four_lib PUBLIC cxx_std_20)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(connect-four_lib PRIVATE fmt::fmt)

# ---- Declare executable ----

add_executable(connect-four_exe src/main.cpp)
add_executable(connect-four::exe ALIAS connect-four_exe)

set_property(TARGET connect-four_exe PROPERTY OUTPUT_NAME connect-four)

target_compile_features(connect-four_exe PRIVATE cxx_std_20)

target_link_libraries(connect-four_exe PRIVATE connect-four_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT connect-four_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of connect-four"
  )
endif()

include(cmake/dev-mode.cmake)
