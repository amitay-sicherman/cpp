# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /cygdrive/c/Users/asicherm/.CLion2019.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/asicherm/.CLion2019.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/asicherm/private/cpp3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/asicherm/private/cpp3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cpp3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cpp3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpp3.dir/flags.make

CMakeFiles/cpp3.dir/SpamDetector.cpp.o: CMakeFiles/cpp3.dir/flags.make
CMakeFiles/cpp3.dir/SpamDetector.cpp.o: ../SpamDetector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/asicherm/private/cpp3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cpp3.dir/SpamDetector.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp3.dir/SpamDetector.cpp.o -c /cygdrive/c/Users/asicherm/private/cpp3/SpamDetector.cpp

CMakeFiles/cpp3.dir/SpamDetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp3.dir/SpamDetector.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/asicherm/private/cpp3/SpamDetector.cpp > CMakeFiles/cpp3.dir/SpamDetector.cpp.i

CMakeFiles/cpp3.dir/SpamDetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp3.dir/SpamDetector.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/asicherm/private/cpp3/SpamDetector.cpp -o CMakeFiles/cpp3.dir/SpamDetector.cpp.s

CMakeFiles/cpp3.dir/HashMap.cpp.o: CMakeFiles/cpp3.dir/flags.make
CMakeFiles/cpp3.dir/HashMap.cpp.o: ../HashMap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/asicherm/private/cpp3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cpp3.dir/HashMap.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp3.dir/HashMap.cpp.o -c /cygdrive/c/Users/asicherm/private/cpp3/HashMap.cpp

CMakeFiles/cpp3.dir/HashMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp3.dir/HashMap.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/asicherm/private/cpp3/HashMap.cpp > CMakeFiles/cpp3.dir/HashMap.cpp.i

CMakeFiles/cpp3.dir/HashMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp3.dir/HashMap.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/asicherm/private/cpp3/HashMap.cpp -o CMakeFiles/cpp3.dir/HashMap.cpp.s

# Object files for target cpp3
cpp3_OBJECTS = \
"CMakeFiles/cpp3.dir/SpamDetector.cpp.o" \
"CMakeFiles/cpp3.dir/HashMap.cpp.o"

# External object files for target cpp3
cpp3_EXTERNAL_OBJECTS =

cpp3.exe: CMakeFiles/cpp3.dir/SpamDetector.cpp.o
cpp3.exe: CMakeFiles/cpp3.dir/HashMap.cpp.o
cpp3.exe: CMakeFiles/cpp3.dir/build.make
cpp3.exe: CMakeFiles/cpp3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/asicherm/private/cpp3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable cpp3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpp3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpp3.dir/build: cpp3.exe

.PHONY : CMakeFiles/cpp3.dir/build

CMakeFiles/cpp3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cpp3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cpp3.dir/clean

CMakeFiles/cpp3.dir/depend:
	cd /cygdrive/c/Users/asicherm/private/cpp3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/asicherm/private/cpp3 /cygdrive/c/Users/asicherm/private/cpp3 /cygdrive/c/Users/asicherm/private/cpp3/cmake-build-debug /cygdrive/c/Users/asicherm/private/cpp3/cmake-build-debug /cygdrive/c/Users/asicherm/private/cpp3/cmake-build-debug/CMakeFiles/cpp3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cpp3.dir/depend

