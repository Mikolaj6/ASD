# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/mikoaj/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.4284.156/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/mikoaj/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.4284.156/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mikoaj/Pulpit/Coding/ASD/ZAJECIA_1/Par

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mikoaj/Pulpit/Coding/ASD/ZAJECIA_1/Par/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Par.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Par.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Par.dir/flags.make

CMakeFiles/Par.dir/main.cpp.o: CMakeFiles/Par.dir/flags.make
CMakeFiles/Par.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mikoaj/Pulpit/Coding/ASD/ZAJECIA_1/Par/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Par.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Par.dir/main.cpp.o -c /home/mikoaj/Pulpit/Coding/ASD/ZAJECIA_1/Par/main.cpp

CMakeFiles/Par.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Par.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mikoaj/Pulpit/Coding/ASD/ZAJECIA_1/Par/main.cpp > CMakeFiles/Par.dir/main.cpp.i

CMakeFiles/Par.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Par.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mikoaj/Pulpit/Coding/ASD/ZAJECIA_1/Par/main.cpp -o CMakeFiles/Par.dir/main.cpp.s

# Object files for target Par
Par_OBJECTS = \
"CMakeFiles/Par.dir/main.cpp.o"

# External object files for target Par
Par_EXTERNAL_OBJECTS =

Par: CMakeFiles/Par.dir/main.cpp.o
Par: CMakeFiles/Par.dir/build.make
Par: CMakeFiles/Par.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mikoaj/Pulpit/Coding/ASD/ZAJECIA_1/Par/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Par"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Par.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Par.dir/build: Par

.PHONY : CMakeFiles/Par.dir/build

CMakeFiles/Par.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Par.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Par.dir/clean

CMakeFiles/Par.dir/depend:
	cd /home/mikoaj/Pulpit/Coding/ASD/ZAJECIA_1/Par/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mikoaj/Pulpit/Coding/ASD/ZAJECIA_1/Par /home/mikoaj/Pulpit/Coding/ASD/ZAJECIA_1/Par /home/mikoaj/Pulpit/Coding/ASD/ZAJECIA_1/Par/cmake-build-debug /home/mikoaj/Pulpit/Coding/ASD/ZAJECIA_1/Par/cmake-build-debug /home/mikoaj/Pulpit/Coding/ASD/ZAJECIA_1/Par/cmake-build-debug/CMakeFiles/Par.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Par.dir/depend

