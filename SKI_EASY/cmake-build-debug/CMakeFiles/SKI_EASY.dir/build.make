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
CMAKE_SOURCE_DIR = /home/mikoaj/Pulpit/Coding/ASD/SKI_EASY

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mikoaj/Pulpit/Coding/ASD/SKI_EASY/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SKI_EASY.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SKI_EASY.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SKI_EASY.dir/flags.make

CMakeFiles/SKI_EASY.dir/main.cpp.o: CMakeFiles/SKI_EASY.dir/flags.make
CMakeFiles/SKI_EASY.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mikoaj/Pulpit/Coding/ASD/SKI_EASY/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SKI_EASY.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SKI_EASY.dir/main.cpp.o -c /home/mikoaj/Pulpit/Coding/ASD/SKI_EASY/main.cpp

CMakeFiles/SKI_EASY.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SKI_EASY.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mikoaj/Pulpit/Coding/ASD/SKI_EASY/main.cpp > CMakeFiles/SKI_EASY.dir/main.cpp.i

CMakeFiles/SKI_EASY.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SKI_EASY.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mikoaj/Pulpit/Coding/ASD/SKI_EASY/main.cpp -o CMakeFiles/SKI_EASY.dir/main.cpp.s

# Object files for target SKI_EASY
SKI_EASY_OBJECTS = \
"CMakeFiles/SKI_EASY.dir/main.cpp.o"

# External object files for target SKI_EASY
SKI_EASY_EXTERNAL_OBJECTS =

SKI_EASY: CMakeFiles/SKI_EASY.dir/main.cpp.o
SKI_EASY: CMakeFiles/SKI_EASY.dir/build.make
SKI_EASY: CMakeFiles/SKI_EASY.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mikoaj/Pulpit/Coding/ASD/SKI_EASY/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SKI_EASY"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SKI_EASY.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SKI_EASY.dir/build: SKI_EASY

.PHONY : CMakeFiles/SKI_EASY.dir/build

CMakeFiles/SKI_EASY.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SKI_EASY.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SKI_EASY.dir/clean

CMakeFiles/SKI_EASY.dir/depend:
	cd /home/mikoaj/Pulpit/Coding/ASD/SKI_EASY/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mikoaj/Pulpit/Coding/ASD/SKI_EASY /home/mikoaj/Pulpit/Coding/ASD/SKI_EASY /home/mikoaj/Pulpit/Coding/ASD/SKI_EASY/cmake-build-debug /home/mikoaj/Pulpit/Coding/ASD/SKI_EASY/cmake-build-debug /home/mikoaj/Pulpit/Coding/ASD/SKI_EASY/cmake-build-debug/CMakeFiles/SKI_EASY.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SKI_EASY.dir/depend

