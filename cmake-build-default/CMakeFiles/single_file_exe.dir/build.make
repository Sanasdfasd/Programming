# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Sandeep\CLionProjects\Programming

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Sandeep\CLionProjects\Programming\cmake-build-default

# Include any dependencies generated for this target.
include CMakeFiles/single_file_exe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/single_file_exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/single_file_exe.dir/flags.make

CMakeFiles/single_file_exe.dir/dp/cf_round_ed_39_D.cpp.obj: CMakeFiles/single_file_exe.dir/flags.make
CMakeFiles/single_file_exe.dir/dp/cf_round_ed_39_D.cpp.obj: ../dp/cf_round_ed_39_D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Sandeep\CLionProjects\Programming\cmake-build-default\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/single_file_exe.dir/dp/cf_round_ed_39_D.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\single_file_exe.dir\dp\cf_round_ed_39_D.cpp.obj -c C:\Users\Sandeep\CLionProjects\Programming\dp\cf_round_ed_39_D.cpp

CMakeFiles/single_file_exe.dir/dp/cf_round_ed_39_D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/single_file_exe.dir/dp/cf_round_ed_39_D.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Sandeep\CLionProjects\Programming\dp\cf_round_ed_39_D.cpp > CMakeFiles\single_file_exe.dir\dp\cf_round_ed_39_D.cpp.i

CMakeFiles/single_file_exe.dir/dp/cf_round_ed_39_D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/single_file_exe.dir/dp/cf_round_ed_39_D.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Sandeep\CLionProjects\Programming\dp\cf_round_ed_39_D.cpp -o CMakeFiles\single_file_exe.dir\dp\cf_round_ed_39_D.cpp.s

CMakeFiles/single_file_exe.dir/dp/cf_round_ed_39_D.cpp.obj.requires:

.PHONY : CMakeFiles/single_file_exe.dir/dp/cf_round_ed_39_D.cpp.obj.requires

CMakeFiles/single_file_exe.dir/dp/cf_round_ed_39_D.cpp.obj.provides: CMakeFiles/single_file_exe.dir/dp/cf_round_ed_39_D.cpp.obj.requires
	$(MAKE) -f CMakeFiles\single_file_exe.dir\build.make CMakeFiles/single_file_exe.dir/dp/cf_round_ed_39_D.cpp.obj.provides.build
.PHONY : CMakeFiles/single_file_exe.dir/dp/cf_round_ed_39_D.cpp.obj.provides

CMakeFiles/single_file_exe.dir/dp/cf_round_ed_39_D.cpp.obj.provides.build: CMakeFiles/single_file_exe.dir/dp/cf_round_ed_39_D.cpp.obj


# Object files for target single_file_exe
single_file_exe_OBJECTS = \
"CMakeFiles/single_file_exe.dir/dp/cf_round_ed_39_D.cpp.obj"

# External object files for target single_file_exe
single_file_exe_EXTERNAL_OBJECTS =

../single_file_exe.exe: CMakeFiles/single_file_exe.dir/dp/cf_round_ed_39_D.cpp.obj
../single_file_exe.exe: CMakeFiles/single_file_exe.dir/build.make
../single_file_exe.exe: CMakeFiles/single_file_exe.dir/linklibs.rsp
../single_file_exe.exe: CMakeFiles/single_file_exe.dir/objects1.rsp
../single_file_exe.exe: CMakeFiles/single_file_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Sandeep\CLionProjects\Programming\cmake-build-default\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\single_file_exe.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\single_file_exe.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/single_file_exe.dir/build: ../single_file_exe.exe

.PHONY : CMakeFiles/single_file_exe.dir/build

CMakeFiles/single_file_exe.dir/requires: CMakeFiles/single_file_exe.dir/dp/cf_round_ed_39_D.cpp.obj.requires

.PHONY : CMakeFiles/single_file_exe.dir/requires

CMakeFiles/single_file_exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\single_file_exe.dir\cmake_clean.cmake
.PHONY : CMakeFiles/single_file_exe.dir/clean

CMakeFiles/single_file_exe.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Sandeep\CLionProjects\Programming C:\Users\Sandeep\CLionProjects\Programming C:\Users\Sandeep\CLionProjects\Programming\cmake-build-default C:\Users\Sandeep\CLionProjects\Programming\cmake-build-default C:\Users\Sandeep\CLionProjects\Programming\cmake-build-default\CMakeFiles\single_file_exe.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/single_file_exe.dir/depend

