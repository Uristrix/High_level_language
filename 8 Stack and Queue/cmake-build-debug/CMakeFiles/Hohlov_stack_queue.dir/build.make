# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\mrlux\Desktop\High_level_language\8 Stack and Queue"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\mrlux\Desktop\High_level_language\8 Stack and Queue\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Hohlov_stack_queue.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Hohlov_stack_queue.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Hohlov_stack_queue.dir/flags.make

CMakeFiles/Hohlov_stack_queue.dir/main.cpp.obj: CMakeFiles/Hohlov_stack_queue.dir/flags.make
CMakeFiles/Hohlov_stack_queue.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\mrlux\Desktop\High_level_language\8 Stack and Queue\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Hohlov_stack_queue.dir/main.cpp.obj"
	C:\PROGRA~2\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Hohlov_stack_queue.dir\main.cpp.obj -c "C:\Users\mrlux\Desktop\High_level_language\8 Stack and Queue\main.cpp"

CMakeFiles/Hohlov_stack_queue.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hohlov_stack_queue.dir/main.cpp.i"
	C:\PROGRA~2\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\mrlux\Desktop\High_level_language\8 Stack and Queue\main.cpp" > CMakeFiles\Hohlov_stack_queue.dir\main.cpp.i

CMakeFiles/Hohlov_stack_queue.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hohlov_stack_queue.dir/main.cpp.s"
	C:\PROGRA~2\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\mrlux\Desktop\High_level_language\8 Stack and Queue\main.cpp" -o CMakeFiles\Hohlov_stack_queue.dir\main.cpp.s

# Object files for target Hohlov_stack_queue
Hohlov_stack_queue_OBJECTS = \
"CMakeFiles/Hohlov_stack_queue.dir/main.cpp.obj"

# External object files for target Hohlov_stack_queue
Hohlov_stack_queue_EXTERNAL_OBJECTS =

Hohlov_stack_queue.exe: CMakeFiles/Hohlov_stack_queue.dir/main.cpp.obj
Hohlov_stack_queue.exe: CMakeFiles/Hohlov_stack_queue.dir/build.make
Hohlov_stack_queue.exe: CMakeFiles/Hohlov_stack_queue.dir/linklibs.rsp
Hohlov_stack_queue.exe: CMakeFiles/Hohlov_stack_queue.dir/objects1.rsp
Hohlov_stack_queue.exe: CMakeFiles/Hohlov_stack_queue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\mrlux\Desktop\High_level_language\8 Stack and Queue\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Hohlov_stack_queue.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Hohlov_stack_queue.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Hohlov_stack_queue.dir/build: Hohlov_stack_queue.exe

.PHONY : CMakeFiles/Hohlov_stack_queue.dir/build

CMakeFiles/Hohlov_stack_queue.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Hohlov_stack_queue.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Hohlov_stack_queue.dir/clean

CMakeFiles/Hohlov_stack_queue.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\mrlux\Desktop\High_level_language\8 Stack and Queue" "C:\Users\mrlux\Desktop\High_level_language\8 Stack and Queue" "C:\Users\mrlux\Desktop\High_level_language\8 Stack and Queue\cmake-build-debug" "C:\Users\mrlux\Desktop\High_level_language\8 Stack and Queue\cmake-build-debug" "C:\Users\mrlux\Desktop\High_level_language\8 Stack and Queue\cmake-build-debug\CMakeFiles\Hohlov_stack_queue.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Hohlov_stack_queue.dir/depend

