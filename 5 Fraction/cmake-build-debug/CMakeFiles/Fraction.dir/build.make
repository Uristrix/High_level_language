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
CMAKE_SOURCE_DIR = "C:\Users\mrlux\Desktop\High_level_language\5 Fraction"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\mrlux\Desktop\High_level_language\5 Fraction\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Fraction.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Fraction.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Fraction.dir/flags.make

CMakeFiles/Fraction.dir/main.cpp.obj: CMakeFiles/Fraction.dir/flags.make
CMakeFiles/Fraction.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\mrlux\Desktop\High_level_language\5 Fraction\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Fraction.dir/main.cpp.obj"
	C:\PROGRA~2\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Fraction.dir\main.cpp.obj -c "C:\Users\mrlux\Desktop\High_level_language\5 Fraction\main.cpp"

CMakeFiles/Fraction.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fraction.dir/main.cpp.i"
	C:\PROGRA~2\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\mrlux\Desktop\High_level_language\5 Fraction\main.cpp" > CMakeFiles\Fraction.dir\main.cpp.i

CMakeFiles/Fraction.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fraction.dir/main.cpp.s"
	C:\PROGRA~2\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\mrlux\Desktop\High_level_language\5 Fraction\main.cpp" -o CMakeFiles\Fraction.dir\main.cpp.s

CMakeFiles/Fraction.dir/Fraction.cpp.obj: CMakeFiles/Fraction.dir/flags.make
CMakeFiles/Fraction.dir/Fraction.cpp.obj: ../Fraction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\mrlux\Desktop\High_level_language\5 Fraction\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Fraction.dir/Fraction.cpp.obj"
	C:\PROGRA~2\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Fraction.dir\Fraction.cpp.obj -c "C:\Users\mrlux\Desktop\High_level_language\5 Fraction\Fraction.cpp"

CMakeFiles/Fraction.dir/Fraction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fraction.dir/Fraction.cpp.i"
	C:\PROGRA~2\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\mrlux\Desktop\High_level_language\5 Fraction\Fraction.cpp" > CMakeFiles\Fraction.dir\Fraction.cpp.i

CMakeFiles/Fraction.dir/Fraction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fraction.dir/Fraction.cpp.s"
	C:\PROGRA~2\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\mrlux\Desktop\High_level_language\5 Fraction\Fraction.cpp" -o CMakeFiles\Fraction.dir\Fraction.cpp.s

# Object files for target Fraction
Fraction_OBJECTS = \
"CMakeFiles/Fraction.dir/main.cpp.obj" \
"CMakeFiles/Fraction.dir/Fraction.cpp.obj"

# External object files for target Fraction
Fraction_EXTERNAL_OBJECTS =

Fraction.exe: CMakeFiles/Fraction.dir/main.cpp.obj
Fraction.exe: CMakeFiles/Fraction.dir/Fraction.cpp.obj
Fraction.exe: CMakeFiles/Fraction.dir/build.make
Fraction.exe: CMakeFiles/Fraction.dir/linklibs.rsp
Fraction.exe: CMakeFiles/Fraction.dir/objects1.rsp
Fraction.exe: CMakeFiles/Fraction.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\mrlux\Desktop\High_level_language\5 Fraction\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Fraction.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Fraction.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Fraction.dir/build: Fraction.exe

.PHONY : CMakeFiles/Fraction.dir/build

CMakeFiles/Fraction.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Fraction.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Fraction.dir/clean

CMakeFiles/Fraction.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\mrlux\Desktop\High_level_language\5 Fraction" "C:\Users\mrlux\Desktop\High_level_language\5 Fraction" "C:\Users\mrlux\Desktop\High_level_language\5 Fraction\cmake-build-debug" "C:\Users\mrlux\Desktop\High_level_language\5 Fraction\cmake-build-debug" "C:\Users\mrlux\Desktop\High_level_language\5 Fraction\cmake-build-debug\CMakeFiles\Fraction.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Fraction.dir/depend

