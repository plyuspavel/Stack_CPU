# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2016.3.5\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2016.3.5\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\plyus\ClionProjects\Stack_CPU\Stack_CPU

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\plyus\ClionProjects\Stack_CPU\Stack_CPU\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Stack_CPU.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Stack_CPU.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Stack_CPU.dir/flags.make

CMakeFiles/Stack_CPU.dir/main.cpp.obj: CMakeFiles/Stack_CPU.dir/flags.make
CMakeFiles/Stack_CPU.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\plyus\ClionProjects\Stack_CPU\Stack_CPU\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Stack_CPU.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Stack_CPU.dir\main.cpp.obj -c C:\Users\plyus\ClionProjects\Stack_CPU\Stack_CPU\main.cpp

CMakeFiles/Stack_CPU.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stack_CPU.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\plyus\ClionProjects\Stack_CPU\Stack_CPU\main.cpp > CMakeFiles\Stack_CPU.dir\main.cpp.i

CMakeFiles/Stack_CPU.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stack_CPU.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\plyus\ClionProjects\Stack_CPU\Stack_CPU\main.cpp -o CMakeFiles\Stack_CPU.dir\main.cpp.s

CMakeFiles/Stack_CPU.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Stack_CPU.dir/main.cpp.obj.requires

CMakeFiles/Stack_CPU.dir/main.cpp.obj.provides: CMakeFiles/Stack_CPU.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Stack_CPU.dir\build.make CMakeFiles/Stack_CPU.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Stack_CPU.dir/main.cpp.obj.provides

CMakeFiles/Stack_CPU.dir/main.cpp.obj.provides.build: CMakeFiles/Stack_CPU.dir/main.cpp.obj


# Object files for target Stack_CPU
Stack_CPU_OBJECTS = \
"CMakeFiles/Stack_CPU.dir/main.cpp.obj"

# External object files for target Stack_CPU
Stack_CPU_EXTERNAL_OBJECTS =

Stack_CPU.exe: CMakeFiles/Stack_CPU.dir/main.cpp.obj
Stack_CPU.exe: CMakeFiles/Stack_CPU.dir/build.make
Stack_CPU.exe: CMakeFiles/Stack_CPU.dir/linklibs.rsp
Stack_CPU.exe: CMakeFiles/Stack_CPU.dir/objects1.rsp
Stack_CPU.exe: CMakeFiles/Stack_CPU.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\plyus\ClionProjects\Stack_CPU\Stack_CPU\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Stack_CPU.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Stack_CPU.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Stack_CPU.dir/build: Stack_CPU.exe

.PHONY : CMakeFiles/Stack_CPU.dir/build

CMakeFiles/Stack_CPU.dir/requires: CMakeFiles/Stack_CPU.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Stack_CPU.dir/requires

CMakeFiles/Stack_CPU.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Stack_CPU.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Stack_CPU.dir/clean

CMakeFiles/Stack_CPU.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\plyus\ClionProjects\Stack_CPU\Stack_CPU C:\Users\plyus\ClionProjects\Stack_CPU\Stack_CPU C:\Users\plyus\ClionProjects\Stack_CPU\Stack_CPU\cmake-build-debug C:\Users\plyus\ClionProjects\Stack_CPU\Stack_CPU\cmake-build-debug C:\Users\plyus\ClionProjects\Stack_CPU\Stack_CPU\cmake-build-debug\CMakeFiles\Stack_CPU.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Stack_CPU.dir/depend

