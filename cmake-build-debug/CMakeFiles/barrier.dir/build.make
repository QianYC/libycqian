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
CMAKE_COMMAND = /home/yc_qian/clion-2018.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/yc_qian/clion-2018.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yc_qian/CLionProjects/libycqian

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yc_qian/CLionProjects/libycqian/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/barrier.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/barrier.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/barrier.dir/flags.make

CMakeFiles/barrier.dir/examples/barrier.cpp.o: CMakeFiles/barrier.dir/flags.make
CMakeFiles/barrier.dir/examples/barrier.cpp.o: ../examples/barrier.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yc_qian/CLionProjects/libycqian/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/barrier.dir/examples/barrier.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/barrier.dir/examples/barrier.cpp.o -c /home/yc_qian/CLionProjects/libycqian/examples/barrier.cpp

CMakeFiles/barrier.dir/examples/barrier.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/barrier.dir/examples/barrier.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yc_qian/CLionProjects/libycqian/examples/barrier.cpp > CMakeFiles/barrier.dir/examples/barrier.cpp.i

CMakeFiles/barrier.dir/examples/barrier.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/barrier.dir/examples/barrier.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yc_qian/CLionProjects/libycqian/examples/barrier.cpp -o CMakeFiles/barrier.dir/examples/barrier.cpp.s

# Object files for target barrier
barrier_OBJECTS = \
"CMakeFiles/barrier.dir/examples/barrier.cpp.o"

# External object files for target barrier
barrier_EXTERNAL_OBJECTS =

barrier: CMakeFiles/barrier.dir/examples/barrier.cpp.o
barrier: CMakeFiles/barrier.dir/build.make
barrier: CMakeFiles/barrier.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yc_qian/CLionProjects/libycqian/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable barrier"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/barrier.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/barrier.dir/build: barrier

.PHONY : CMakeFiles/barrier.dir/build

CMakeFiles/barrier.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/barrier.dir/cmake_clean.cmake
.PHONY : CMakeFiles/barrier.dir/clean

CMakeFiles/barrier.dir/depend:
	cd /home/yc_qian/CLionProjects/libycqian/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yc_qian/CLionProjects/libycqian /home/yc_qian/CLionProjects/libycqian /home/yc_qian/CLionProjects/libycqian/cmake-build-debug /home/yc_qian/CLionProjects/libycqian/cmake-build-debug /home/yc_qian/CLionProjects/libycqian/cmake-build-debug/CMakeFiles/barrier.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/barrier.dir/depend

