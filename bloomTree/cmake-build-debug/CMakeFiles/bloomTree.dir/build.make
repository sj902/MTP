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
CMAKE_SOURCE_DIR = /Users/shubhamjain/CLionProjects/bloomTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shubhamjain/CLionProjects/bloomTree/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/bloomTree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bloomTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bloomTree.dir/flags.make

CMakeFiles/bloomTree.dir/bloom.c.o: CMakeFiles/bloomTree.dir/flags.make
CMakeFiles/bloomTree.dir/bloom.c.o: ../bloom.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shubhamjain/CLionProjects/bloomTree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/bloomTree.dir/bloom.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bloomTree.dir/bloom.c.o   -c /Users/shubhamjain/CLionProjects/bloomTree/bloom.c

CMakeFiles/bloomTree.dir/bloom.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bloomTree.dir/bloom.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/shubhamjain/CLionProjects/bloomTree/bloom.c > CMakeFiles/bloomTree.dir/bloom.c.i

CMakeFiles/bloomTree.dir/bloom.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bloomTree.dir/bloom.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/shubhamjain/CLionProjects/bloomTree/bloom.c -o CMakeFiles/bloomTree.dir/bloom.c.s

CMakeFiles/bloomTree.dir/bloom.c.o.requires:

.PHONY : CMakeFiles/bloomTree.dir/bloom.c.o.requires

CMakeFiles/bloomTree.dir/bloom.c.o.provides: CMakeFiles/bloomTree.dir/bloom.c.o.requires
	$(MAKE) -f CMakeFiles/bloomTree.dir/build.make CMakeFiles/bloomTree.dir/bloom.c.o.provides.build
.PHONY : CMakeFiles/bloomTree.dir/bloom.c.o.provides

CMakeFiles/bloomTree.dir/bloom.c.o.provides.build: CMakeFiles/bloomTree.dir/bloom.c.o


CMakeFiles/bloomTree.dir/bestLevel.c.o: CMakeFiles/bloomTree.dir/flags.make
CMakeFiles/bloomTree.dir/bestLevel.c.o: ../bestLevel.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shubhamjain/CLionProjects/bloomTree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/bloomTree.dir/bestLevel.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bloomTree.dir/bestLevel.c.o   -c /Users/shubhamjain/CLionProjects/bloomTree/bestLevel.c

CMakeFiles/bloomTree.dir/bestLevel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bloomTree.dir/bestLevel.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/shubhamjain/CLionProjects/bloomTree/bestLevel.c > CMakeFiles/bloomTree.dir/bestLevel.c.i

CMakeFiles/bloomTree.dir/bestLevel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bloomTree.dir/bestLevel.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/shubhamjain/CLionProjects/bloomTree/bestLevel.c -o CMakeFiles/bloomTree.dir/bestLevel.c.s

CMakeFiles/bloomTree.dir/bestLevel.c.o.requires:

.PHONY : CMakeFiles/bloomTree.dir/bestLevel.c.o.requires

CMakeFiles/bloomTree.dir/bestLevel.c.o.provides: CMakeFiles/bloomTree.dir/bestLevel.c.o.requires
	$(MAKE) -f CMakeFiles/bloomTree.dir/build.make CMakeFiles/bloomTree.dir/bestLevel.c.o.provides.build
.PHONY : CMakeFiles/bloomTree.dir/bestLevel.c.o.provides

CMakeFiles/bloomTree.dir/bestLevel.c.o.provides.build: CMakeFiles/bloomTree.dir/bestLevel.c.o


# Object files for target bloomTree
bloomTree_OBJECTS = \
"CMakeFiles/bloomTree.dir/bloom.c.o" \
"CMakeFiles/bloomTree.dir/bestLevel.c.o"

# External object files for target bloomTree
bloomTree_EXTERNAL_OBJECTS =

bloomTree: CMakeFiles/bloomTree.dir/bloom.c.o
bloomTree: CMakeFiles/bloomTree.dir/bestLevel.c.o
bloomTree: CMakeFiles/bloomTree.dir/build.make
bloomTree: CMakeFiles/bloomTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shubhamjain/CLionProjects/bloomTree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable bloomTree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bloomTree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bloomTree.dir/build: bloomTree

.PHONY : CMakeFiles/bloomTree.dir/build

CMakeFiles/bloomTree.dir/requires: CMakeFiles/bloomTree.dir/bloom.c.o.requires
CMakeFiles/bloomTree.dir/requires: CMakeFiles/bloomTree.dir/bestLevel.c.o.requires

.PHONY : CMakeFiles/bloomTree.dir/requires

CMakeFiles/bloomTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bloomTree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bloomTree.dir/clean

CMakeFiles/bloomTree.dir/depend:
	cd /Users/shubhamjain/CLionProjects/bloomTree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shubhamjain/CLionProjects/bloomTree /Users/shubhamjain/CLionProjects/bloomTree /Users/shubhamjain/CLionProjects/bloomTree/cmake-build-debug /Users/shubhamjain/CLionProjects/bloomTree/cmake-build-debug /Users/shubhamjain/CLionProjects/bloomTree/cmake-build-debug/CMakeFiles/bloomTree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bloomTree.dir/depend
