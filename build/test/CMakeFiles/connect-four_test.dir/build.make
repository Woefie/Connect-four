# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Projects/connect-four

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Projects/connect-four/build

# Include any dependencies generated for this target.
include test/CMakeFiles/connect-four_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/connect-four_test.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/connect-four_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/connect-four_test.dir/flags.make

test/CMakeFiles/connect-four_test.dir/src/connect-four_test.cpp.o: test/CMakeFiles/connect-four_test.dir/flags.make
test/CMakeFiles/connect-four_test.dir/src/connect-four_test.cpp.o: ../test/src/connect-four_test.cpp
test/CMakeFiles/connect-four_test.dir/src/connect-four_test.cpp.o: test/CMakeFiles/connect-four_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Projects/connect-four/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/connect-four_test.dir/src/connect-four_test.cpp.o"
	cd /mnt/c/Projects/connect-four/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/connect-four_test.dir/src/connect-four_test.cpp.o -MF CMakeFiles/connect-four_test.dir/src/connect-four_test.cpp.o.d -o CMakeFiles/connect-four_test.dir/src/connect-four_test.cpp.o -c /mnt/c/Projects/connect-four/test/src/connect-four_test.cpp

test/CMakeFiles/connect-four_test.dir/src/connect-four_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/connect-four_test.dir/src/connect-four_test.cpp.i"
	cd /mnt/c/Projects/connect-four/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Projects/connect-four/test/src/connect-four_test.cpp > CMakeFiles/connect-four_test.dir/src/connect-four_test.cpp.i

test/CMakeFiles/connect-four_test.dir/src/connect-four_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/connect-four_test.dir/src/connect-four_test.cpp.s"
	cd /mnt/c/Projects/connect-four/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Projects/connect-four/test/src/connect-four_test.cpp -o CMakeFiles/connect-four_test.dir/src/connect-four_test.cpp.s

# Object files for target connect-four_test
connect__four_test_OBJECTS = \
"CMakeFiles/connect-four_test.dir/src/connect-four_test.cpp.o"

# External object files for target connect-four_test
connect__four_test_EXTERNAL_OBJECTS = \
"/mnt/c/Projects/connect-four/build/CMakeFiles/connect-four_lib.dir/src/board.cpp.o" \
"/mnt/c/Projects/connect-four/build/CMakeFiles/connect-four_lib.dir/src/computer.cpp.o" \
"/mnt/c/Projects/connect-four/build/CMakeFiles/connect-four_lib.dir/src/player.cpp.o" \
"/mnt/c/Projects/connect-four/build/CMakeFiles/connect-four_lib.dir/src/game.cpp.o"

test/connect-four_test: test/CMakeFiles/connect-four_test.dir/src/connect-four_test.cpp.o
test/connect-four_test: CMakeFiles/connect-four_lib.dir/src/board.cpp.o
test/connect-four_test: CMakeFiles/connect-four_lib.dir/src/computer.cpp.o
test/connect-four_test: CMakeFiles/connect-four_lib.dir/src/player.cpp.o
test/connect-four_test: CMakeFiles/connect-four_lib.dir/src/game.cpp.o
test/connect-four_test: test/CMakeFiles/connect-four_test.dir/build.make
test/connect-four_test: vcpkg_installed/x64-linux/lib/manual-link/libCatch2Main.a
test/connect-four_test: vcpkg_installed/x64-linux/lib/libfmt.a
test/connect-four_test: vcpkg_installed/x64-linux/lib/libCatch2.a
test/connect-four_test: test/CMakeFiles/connect-four_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Projects/connect-four/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable connect-four_test"
	cd /mnt/c/Projects/connect-four/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/connect-four_test.dir/link.txt --verbose=$(VERBOSE)
	cd /mnt/c/Projects/connect-four/build/test && /usr/bin/cmake -D TEST_TARGET=connect-four_test -D TEST_EXECUTABLE=/mnt/c/Projects/connect-four/build/test/connect-four_test -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/mnt/c/Projects/connect-four/build/test -D TEST_SPEC= -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_LIST=connect-four_test_TESTS -D TEST_REPORTER= -D TEST_OUTPUT_DIR= -D TEST_OUTPUT_PREFIX= -D TEST_OUTPUT_SUFFIX= -D TEST_DL_PATHS= -D CTEST_FILE=/mnt/c/Projects/connect-four/build/test/connect-four_test_tests-b12d07c.cmake -P /mnt/c/Projects/connect-four/build/vcpkg_installed/x64-linux/share/Catch2/CatchAddTests.cmake

# Rule to build all files generated by this target.
test/CMakeFiles/connect-four_test.dir/build: test/connect-four_test
.PHONY : test/CMakeFiles/connect-four_test.dir/build

test/CMakeFiles/connect-four_test.dir/clean:
	cd /mnt/c/Projects/connect-four/build/test && $(CMAKE_COMMAND) -P CMakeFiles/connect-four_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/connect-four_test.dir/clean

test/CMakeFiles/connect-four_test.dir/depend:
	cd /mnt/c/Projects/connect-four/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Projects/connect-four /mnt/c/Projects/connect-four/test /mnt/c/Projects/connect-four/build /mnt/c/Projects/connect-four/build/test /mnt/c/Projects/connect-four/build/test/CMakeFiles/connect-four_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/connect-four_test.dir/depend
