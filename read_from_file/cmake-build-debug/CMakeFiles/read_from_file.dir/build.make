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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/shubhamjain/CLionProjects/read_from_file

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shubhamjain/CLionProjects/read_from_file/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/read_from_file.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/read_from_file.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/read_from_file.dir/flags.make

CMakeFiles/read_from_file.dir/main.c.o: CMakeFiles/read_from_file.dir/flags.make
CMakeFiles/read_from_file.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shubhamjain/CLionProjects/read_from_file/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/read_from_file.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/read_from_file.dir/main.c.o   -c /Users/shubhamjain/CLionProjects/read_from_file/main.c

CMakeFiles/read_from_file.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/read_from_file.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/shubhamjain/CLionProjects/read_from_file/main.c > CMakeFiles/read_from_file.dir/main.c.i

CMakeFiles/read_from_file.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/read_from_file.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/shubhamjain/CLionProjects/read_from_file/main.c -o CMakeFiles/read_from_file.dir/main.c.s

CMakeFiles/read_from_file.dir/main.c.o.requires:

.PHONY : CMakeFiles/read_from_file.dir/main.c.o.requires

CMakeFiles/read_from_file.dir/main.c.o.provides: CMakeFiles/read_from_file.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/read_from_file.dir/build.make CMakeFiles/read_from_file.dir/main.c.o.provides.build
.PHONY : CMakeFiles/read_from_file.dir/main.c.o.provides

CMakeFiles/read_from_file.dir/main.c.o.provides.build: CMakeFiles/read_from_file.dir/main.c.o


# Object files for target read_from_file
read_from_file_OBJECTS = \
"CMakeFiles/read_from_file.dir/main.c.o"

# External object files for target read_from_file
read_from_file_EXTERNAL_OBJECTS =

read_from_file: CMakeFiles/read_from_file.dir/main.c.o
read_from_file: CMakeFiles/read_from_file.dir/build.make
read_from_file: CMakeFiles/read_from_file.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shubhamjain/CLionProjects/read_from_file/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable read_from_file"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/read_from_file.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/read_from_file.dir/build: read_from_file

.PHONY : CMakeFiles/read_from_file.dir/build

CMakeFiles/read_from_file.dir/requires: CMakeFiles/read_from_file.dir/main.c.o.requires

.PHONY : CMakeFiles/read_from_file.dir/requires

CMakeFiles/read_from_file.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/read_from_file.dir/cmake_clean.cmake
.PHONY : CMakeFiles/read_from_file.dir/clean

CMakeFiles/read_from_file.dir/depend:
	cd /Users/shubhamjain/CLionProjects/read_from_file/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shubhamjain/CLionProjects/read_from_file /Users/shubhamjain/CLionProjects/read_from_file /Users/shubhamjain/CLionProjects/read_from_file/cmake-build-debug /Users/shubhamjain/CLionProjects/read_from_file/cmake-build-debug /Users/shubhamjain/CLionProjects/read_from_file/cmake-build-debug/CMakeFiles/read_from_file.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/read_from_file.dir/depend

