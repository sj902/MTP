# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_SOURCE_DIR = /Users/shubhamjain/CLionProjects/pThreads

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shubhamjain/CLionProjects/pThreads/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pThreads.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pThreads.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pThreads.dir/flags.make

CMakeFiles/pThreads.dir/main.c.o: CMakeFiles/pThreads.dir/flags.make
CMakeFiles/pThreads.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shubhamjain/CLionProjects/pThreads/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pThreads.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pThreads.dir/main.c.o   -c /Users/shubhamjain/CLionProjects/pThreads/main.c

CMakeFiles/pThreads.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pThreads.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/shubhamjain/CLionProjects/pThreads/main.c > CMakeFiles/pThreads.dir/main.c.i

CMakeFiles/pThreads.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pThreads.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/shubhamjain/CLionProjects/pThreads/main.c -o CMakeFiles/pThreads.dir/main.c.s

CMakeFiles/pThreads.dir/main.c.o.requires:

.PHONY : CMakeFiles/pThreads.dir/main.c.o.requires

CMakeFiles/pThreads.dir/main.c.o.provides: CMakeFiles/pThreads.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/pThreads.dir/build.make CMakeFiles/pThreads.dir/main.c.o.provides.build
.PHONY : CMakeFiles/pThreads.dir/main.c.o.provides

CMakeFiles/pThreads.dir/main.c.o.provides.build: CMakeFiles/pThreads.dir/main.c.o


# Object files for target pThreads
pThreads_OBJECTS = \
"CMakeFiles/pThreads.dir/main.c.o"

# External object files for target pThreads
pThreads_EXTERNAL_OBJECTS =

pThreads: CMakeFiles/pThreads.dir/main.c.o
pThreads: CMakeFiles/pThreads.dir/build.make
pThreads: CMakeFiles/pThreads.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shubhamjain/CLionProjects/pThreads/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable pThreads"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pThreads.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pThreads.dir/build: pThreads

.PHONY : CMakeFiles/pThreads.dir/build

CMakeFiles/pThreads.dir/requires: CMakeFiles/pThreads.dir/main.c.o.requires

.PHONY : CMakeFiles/pThreads.dir/requires

CMakeFiles/pThreads.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pThreads.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pThreads.dir/clean

CMakeFiles/pThreads.dir/depend:
	cd /Users/shubhamjain/CLionProjects/pThreads/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shubhamjain/CLionProjects/pThreads /Users/shubhamjain/CLionProjects/pThreads /Users/shubhamjain/CLionProjects/pThreads/cmake-build-debug /Users/shubhamjain/CLionProjects/pThreads/cmake-build-debug /Users/shubhamjain/CLionProjects/pThreads/cmake-build-debug/CMakeFiles/pThreads.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pThreads.dir/depend

