# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ibohun/CLionProjects/42-fdf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ibohun/CLionProjects/42-fdf/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FdF.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FdF.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FdF.dir/flags.make

CMakeFiles/FdF.dir/src/main.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ibohun/CLionProjects/42-fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/FdF.dir/src/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/src/main.c.o   -c /Users/ibohun/CLionProjects/42-fdf/src/main.c

CMakeFiles/FdF.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/src/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ibohun/CLionProjects/42-fdf/src/main.c > CMakeFiles/FdF.dir/src/main.c.i

CMakeFiles/FdF.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/src/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ibohun/CLionProjects/42-fdf/src/main.c -o CMakeFiles/FdF.dir/src/main.c.s

CMakeFiles/FdF.dir/src/read.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/src/read.c.o: ../src/read.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ibohun/CLionProjects/42-fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/FdF.dir/src/read.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/src/read.c.o   -c /Users/ibohun/CLionProjects/42-fdf/src/read.c

CMakeFiles/FdF.dir/src/read.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/src/read.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ibohun/CLionProjects/42-fdf/src/read.c > CMakeFiles/FdF.dir/src/read.c.i

CMakeFiles/FdF.dir/src/read.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/src/read.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ibohun/CLionProjects/42-fdf/src/read.c -o CMakeFiles/FdF.dir/src/read.c.s

CMakeFiles/FdF.dir/src/fill.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/src/fill.c.o: ../src/fill.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ibohun/CLionProjects/42-fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/FdF.dir/src/fill.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/src/fill.c.o   -c /Users/ibohun/CLionProjects/42-fdf/src/fill.c

CMakeFiles/FdF.dir/src/fill.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/src/fill.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ibohun/CLionProjects/42-fdf/src/fill.c > CMakeFiles/FdF.dir/src/fill.c.i

CMakeFiles/FdF.dir/src/fill.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/src/fill.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ibohun/CLionProjects/42-fdf/src/fill.c -o CMakeFiles/FdF.dir/src/fill.c.s

CMakeFiles/FdF.dir/src/view.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/src/view.c.o: ../src/view.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ibohun/CLionProjects/42-fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/FdF.dir/src/view.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/src/view.c.o   -c /Users/ibohun/CLionProjects/42-fdf/src/view.c

CMakeFiles/FdF.dir/src/view.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/src/view.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ibohun/CLionProjects/42-fdf/src/view.c > CMakeFiles/FdF.dir/src/view.c.i

CMakeFiles/FdF.dir/src/view.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/src/view.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ibohun/CLionProjects/42-fdf/src/view.c -o CMakeFiles/FdF.dir/src/view.c.s

# Object files for target FdF
FdF_OBJECTS = \
"CMakeFiles/FdF.dir/src/main.c.o" \
"CMakeFiles/FdF.dir/src/read.c.o" \
"CMakeFiles/FdF.dir/src/fill.c.o" \
"CMakeFiles/FdF.dir/src/view.c.o"

# External object files for target FdF
FdF_EXTERNAL_OBJECTS =

FdF: CMakeFiles/FdF.dir/src/main.c.o
FdF: CMakeFiles/FdF.dir/src/read.c.o
FdF: CMakeFiles/FdF.dir/src/fill.c.o
FdF: CMakeFiles/FdF.dir/src/view.c.o
FdF: CMakeFiles/FdF.dir/build.make
FdF: CMakeFiles/FdF.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ibohun/CLionProjects/42-fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable FdF"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FdF.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FdF.dir/build: FdF

.PHONY : CMakeFiles/FdF.dir/build

CMakeFiles/FdF.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FdF.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FdF.dir/clean

CMakeFiles/FdF.dir/depend:
	cd /Users/ibohun/CLionProjects/42-fdf/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ibohun/CLionProjects/42-fdf /Users/ibohun/CLionProjects/42-fdf /Users/ibohun/CLionProjects/42-fdf/cmake-build-debug /Users/ibohun/CLionProjects/42-fdf/cmake-build-debug /Users/ibohun/CLionProjects/42-fdf/cmake-build-debug/CMakeFiles/FdF.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FdF.dir/depend

