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
include deps/deps1/CMakeFiles/deps1.dir/depend.make

# Include the progress variables for this target.
include deps/deps1/CMakeFiles/deps1.dir/progress.make

# Include the compile flags for this target's objects.
include deps/deps1/CMakeFiles/deps1.dir/flags.make

deps/deps1/CMakeFiles/deps1.dir/deps1.c.o: deps/deps1/CMakeFiles/deps1.dir/flags.make
deps/deps1/CMakeFiles/deps1.dir/deps1.c.o: ../deps/deps1/deps1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uav/code/controller/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object deps/deps1/CMakeFiles/deps1.dir/deps1.c.o"
	cd /home/uav/code/controller/build/deps/deps1 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/deps1.dir/deps1.c.o   -c /home/uav/code/controller/deps/deps1/deps1.c

deps/deps1/CMakeFiles/deps1.dir/deps1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/deps1.dir/deps1.c.i"
	cd /home/uav/code/controller/build/deps/deps1 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/uav/code/controller/deps/deps1/deps1.c > CMakeFiles/deps1.dir/deps1.c.i

deps/deps1/CMakeFiles/deps1.dir/deps1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/deps1.dir/deps1.c.s"
	cd /home/uav/code/controller/build/deps/deps1 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/uav/code/controller/deps/deps1/deps1.c -o CMakeFiles/deps1.dir/deps1.c.s

deps/deps1/CMakeFiles/deps1.dir/deps1.c.o.requires:

.PHONY : deps/deps1/CMakeFiles/deps1.dir/deps1.c.o.requires

deps/deps1/CMakeFiles/deps1.dir/deps1.c.o.provides: deps/deps1/CMakeFiles/deps1.dir/deps1.c.o.requires
	$(MAKE) -f deps/deps1/CMakeFiles/deps1.dir/build.make deps/deps1/CMakeFiles/deps1.dir/deps1.c.o.provides.build
.PHONY : deps/deps1/CMakeFiles/deps1.dir/deps1.c.o.provides

deps/deps1/CMakeFiles/deps1.dir/deps1.c.o.provides.build: deps/deps1/CMakeFiles/deps1.dir/deps1.c.o


# Object files for target deps1
deps1_OBJECTS = \
"CMakeFiles/deps1.dir/deps1.c.o"

# External object files for target deps1
deps1_EXTERNAL_OBJECTS =

deps/deps1/libdeps1.a: deps/deps1/CMakeFiles/deps1.dir/deps1.c.o
deps/deps1/libdeps1.a: deps/deps1/CMakeFiles/deps1.dir/build.make
deps/deps1/libdeps1.a: deps/deps1/CMakeFiles/deps1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/uav/code/controller/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libdeps1.a"
	cd /home/uav/code/controller/build/deps/deps1 && $(CMAKE_COMMAND) -P CMakeFiles/deps1.dir/cmake_clean_target.cmake
	cd /home/uav/code/controller/build/deps/deps1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/deps1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
deps/deps1/CMakeFiles/deps1.dir/build: deps/deps1/libdeps1.a

.PHONY : deps/deps1/CMakeFiles/deps1.dir/build

deps/deps1/CMakeFiles/deps1.dir/requires: deps/deps1/CMakeFiles/deps1.dir/deps1.c.o.requires

.PHONY : deps/deps1/CMakeFiles/deps1.dir/requires

deps/deps1/CMakeFiles/deps1.dir/clean:
	cd /home/uav/code/controller/build/deps/deps1 && $(CMAKE_COMMAND) -P CMakeFiles/deps1.dir/cmake_clean.cmake
.PHONY : deps/deps1/CMakeFiles/deps1.dir/clean

deps/deps1/CMakeFiles/deps1.dir/depend:
	cd /home/uav/code/controller/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/uav/code/controller /home/uav/code/controller/deps/deps1 /home/uav/code/controller/build /home/uav/code/controller/build/deps/deps1 /home/uav/code/controller/build/deps/deps1/CMakeFiles/deps1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : deps/deps1/CMakeFiles/deps1.dir/depend
