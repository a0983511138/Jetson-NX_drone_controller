# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/uav/code/controller

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/uav/code/controller/build

# Include any dependencies generated for this target.
include util/util1/CMakeFiles/mortor_control.dir/depend.make

# Include the progress variables for this target.
include util/util1/CMakeFiles/mortor_control.dir/progress.make

# Include the compile flags for this target's objects.
include util/util1/CMakeFiles/mortor_control.dir/flags.make

util/util1/CMakeFiles/mortor_control.dir/main.cpp.o: util/util1/CMakeFiles/mortor_control.dir/flags.make
util/util1/CMakeFiles/mortor_control.dir/main.cpp.o: ../util/util1/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uav/code/controller/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object util/util1/CMakeFiles/mortor_control.dir/main.cpp.o"
	cd /home/uav/code/controller/build/util/util1 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mortor_control.dir/main.cpp.o -c /home/uav/code/controller/util/util1/main.cpp

util/util1/CMakeFiles/mortor_control.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mortor_control.dir/main.cpp.i"
	cd /home/uav/code/controller/build/util/util1 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uav/code/controller/util/util1/main.cpp > CMakeFiles/mortor_control.dir/main.cpp.i

util/util1/CMakeFiles/mortor_control.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mortor_control.dir/main.cpp.s"
	cd /home/uav/code/controller/build/util/util1 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uav/code/controller/util/util1/main.cpp -o CMakeFiles/mortor_control.dir/main.cpp.s

util/util1/CMakeFiles/mortor_control.dir/main.cpp.o.requires:

.PHONY : util/util1/CMakeFiles/mortor_control.dir/main.cpp.o.requires

util/util1/CMakeFiles/mortor_control.dir/main.cpp.o.provides: util/util1/CMakeFiles/mortor_control.dir/main.cpp.o.requires
	$(MAKE) -f util/util1/CMakeFiles/mortor_control.dir/build.make util/util1/CMakeFiles/mortor_control.dir/main.cpp.o.provides.build
.PHONY : util/util1/CMakeFiles/mortor_control.dir/main.cpp.o.provides

util/util1/CMakeFiles/mortor_control.dir/main.cpp.o.provides.build: util/util1/CMakeFiles/mortor_control.dir/main.cpp.o


# Object files for target mortor_control
mortor_control_OBJECTS = \
"CMakeFiles/mortor_control.dir/main.cpp.o"

# External object files for target mortor_control
mortor_control_EXTERNAL_OBJECTS =

util/util1/mortor_control: util/util1/CMakeFiles/mortor_control.dir/main.cpp.o
util/util1/mortor_control: util/util1/CMakeFiles/mortor_control.dir/build.make
util/util1/mortor_control: deps/deps1/libdeps1.a
util/util1/mortor_control: lib/libi2c.a
util/util1/mortor_control: util/util1/CMakeFiles/mortor_control.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/uav/code/controller/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mortor_control"
	cd /home/uav/code/controller/build/util/util1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mortor_control.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
util/util1/CMakeFiles/mortor_control.dir/build: util/util1/mortor_control

.PHONY : util/util1/CMakeFiles/mortor_control.dir/build

util/util1/CMakeFiles/mortor_control.dir/requires: util/util1/CMakeFiles/mortor_control.dir/main.cpp.o.requires

.PHONY : util/util1/CMakeFiles/mortor_control.dir/requires

util/util1/CMakeFiles/mortor_control.dir/clean:
	cd /home/uav/code/controller/build/util/util1 && $(CMAKE_COMMAND) -P CMakeFiles/mortor_control.dir/cmake_clean.cmake
.PHONY : util/util1/CMakeFiles/mortor_control.dir/clean

util/util1/CMakeFiles/mortor_control.dir/depend:
	cd /home/uav/code/controller/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/uav/code/controller /home/uav/code/controller/util/util1 /home/uav/code/controller/build /home/uav/code/controller/build/util/util1 /home/uav/code/controller/build/util/util1/CMakeFiles/mortor_control.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : util/util1/CMakeFiles/mortor_control.dir/depend

