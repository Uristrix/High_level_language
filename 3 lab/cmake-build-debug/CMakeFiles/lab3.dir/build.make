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
CMAKE_SOURCE_DIR = "C:\Users\mrlux\Desktop\High_level_language\3 lab"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\mrlux\Desktop\High_level_language\3 lab\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/lab3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab3.dir/flags.make

CMakeFiles/lab3.dir/main.c.obj: CMakeFiles/lab3.dir/flags.make
CMakeFiles/lab3.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\mrlux\Desktop\High_level_language\3 lab\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab3.dir/main.c.obj"
	C:\PROGRA~2\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\lab3.dir\main.c.obj   -c "C:\Users\mrlux\Desktop\High_level_language\3 lab\main.c"

CMakeFiles/lab3.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab3.dir/main.c.i"
	C:\PROGRA~2\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\mrlux\Desktop\High_level_language\3 lab\main.c" > CMakeFiles\lab3.dir\main.c.i

CMakeFiles/lab3.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab3.dir/main.c.s"
	C:\PROGRA~2\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\mrlux\Desktop\High_level_language\3 lab\main.c" -o CMakeFiles\lab3.dir\main.c.s

CMakeFiles/lab3.dir/lab3.c.obj: CMakeFiles/lab3.dir/flags.make
CMakeFiles/lab3.dir/lab3.c.obj: ../lab3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\mrlux\Desktop\High_level_language\3 lab\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lab3.dir/lab3.c.obj"
	C:\PROGRA~2\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\lab3.dir\lab3.c.obj   -c "C:\Users\mrlux\Desktop\High_level_language\3 lab\lab3.c"

CMakeFiles/lab3.dir/lab3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab3.dir/lab3.c.i"
	C:\PROGRA~2\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\mrlux\Desktop\High_level_language\3 lab\lab3.c" > CMakeFiles\lab3.dir\lab3.c.i

CMakeFiles/lab3.dir/lab3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab3.dir/lab3.c.s"
	C:\PROGRA~2\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\mrlux\Desktop\High_level_language\3 lab\lab3.c" -o CMakeFiles\lab3.dir\lab3.c.s

# Object files for target lab3
lab3_OBJECTS = \
"CMakeFiles/lab3.dir/main.c.obj" \
"CMakeFiles/lab3.dir/lab3.c.obj"

# External object files for target lab3
lab3_EXTERNAL_OBJECTS =

lab3.exe: CMakeFiles/lab3.dir/main.c.obj
lab3.exe: CMakeFiles/lab3.dir/lab3.c.obj
lab3.exe: CMakeFiles/lab3.dir/build.make
lab3.exe: CMakeFiles/lab3.dir/linklibs.rsp
lab3.exe: CMakeFiles/lab3.dir/objects1.rsp
lab3.exe: CMakeFiles/lab3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\mrlux\Desktop\High_level_language\3 lab\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable lab3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab3.dir/build: lab3.exe

.PHONY : CMakeFiles/lab3.dir/build

CMakeFiles/lab3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab3.dir/clean

CMakeFiles/lab3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\mrlux\Desktop\High_level_language\3 lab" "C:\Users\mrlux\Desktop\High_level_language\3 lab" "C:\Users\mrlux\Desktop\High_level_language\3 lab\cmake-build-debug" "C:\Users\mrlux\Desktop\High_level_language\3 lab\cmake-build-debug" "C:\Users\mrlux\Desktop\High_level_language\3 lab\cmake-build-debug\CMakeFiles\lab3.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/lab3.dir/depend

