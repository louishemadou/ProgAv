# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zelire/Documents/IMI/ProgAv/TP3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zelire/Documents/IMI/ProgAv/TP3/build

# Include any dependencies generated for this target.
include CMakeFiles/TP3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TP3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TP3.dir/flags.make

CMakeFiles/TP3.dir/main.cpp.o: CMakeFiles/TP3.dir/flags.make
CMakeFiles/TP3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zelire/Documents/IMI/ProgAv/TP3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TP3.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP3.dir/main.cpp.o -c /home/zelire/Documents/IMI/ProgAv/TP3/main.cpp

CMakeFiles/TP3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP3.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zelire/Documents/IMI/ProgAv/TP3/main.cpp > CMakeFiles/TP3.dir/main.cpp.i

CMakeFiles/TP3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP3.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zelire/Documents/IMI/ProgAv/TP3/main.cpp -o CMakeFiles/TP3.dir/main.cpp.s

CMakeFiles/TP3.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/TP3.dir/main.cpp.o.requires

CMakeFiles/TP3.dir/main.cpp.o.provides: CMakeFiles/TP3.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/TP3.dir/build.make CMakeFiles/TP3.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/TP3.dir/main.cpp.o.provides

CMakeFiles/TP3.dir/main.cpp.o.provides.build: CMakeFiles/TP3.dir/main.cpp.o


CMakeFiles/TP3.dir/fonction.cpp.o: CMakeFiles/TP3.dir/flags.make
CMakeFiles/TP3.dir/fonction.cpp.o: ../fonction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zelire/Documents/IMI/ProgAv/TP3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TP3.dir/fonction.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP3.dir/fonction.cpp.o -c /home/zelire/Documents/IMI/ProgAv/TP3/fonction.cpp

CMakeFiles/TP3.dir/fonction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP3.dir/fonction.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zelire/Documents/IMI/ProgAv/TP3/fonction.cpp > CMakeFiles/TP3.dir/fonction.cpp.i

CMakeFiles/TP3.dir/fonction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP3.dir/fonction.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zelire/Documents/IMI/ProgAv/TP3/fonction.cpp -o CMakeFiles/TP3.dir/fonction.cpp.s

CMakeFiles/TP3.dir/fonction.cpp.o.requires:

.PHONY : CMakeFiles/TP3.dir/fonction.cpp.o.requires

CMakeFiles/TP3.dir/fonction.cpp.o.provides: CMakeFiles/TP3.dir/fonction.cpp.o.requires
	$(MAKE) -f CMakeFiles/TP3.dir/build.make CMakeFiles/TP3.dir/fonction.cpp.o.provides.build
.PHONY : CMakeFiles/TP3.dir/fonction.cpp.o.provides

CMakeFiles/TP3.dir/fonction.cpp.o.provides.build: CMakeFiles/TP3.dir/fonction.cpp.o


# Object files for target TP3
TP3_OBJECTS = \
"CMakeFiles/TP3.dir/main.cpp.o" \
"CMakeFiles/TP3.dir/fonction.cpp.o"

# External object files for target TP3
TP3_EXTERNAL_OBJECTS =

TP3: CMakeFiles/TP3.dir/main.cpp.o
TP3: CMakeFiles/TP3.dir/fonction.cpp.o
TP3: CMakeFiles/TP3.dir/build.make
TP3: CMakeFiles/TP3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zelire/Documents/IMI/ProgAv/TP3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable TP3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TP3.dir/build: TP3

.PHONY : CMakeFiles/TP3.dir/build

CMakeFiles/TP3.dir/requires: CMakeFiles/TP3.dir/main.cpp.o.requires
CMakeFiles/TP3.dir/requires: CMakeFiles/TP3.dir/fonction.cpp.o.requires

.PHONY : CMakeFiles/TP3.dir/requires

CMakeFiles/TP3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TP3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TP3.dir/clean

CMakeFiles/TP3.dir/depend:
	cd /home/zelire/Documents/IMI/ProgAv/TP3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zelire/Documents/IMI/ProgAv/TP3 /home/zelire/Documents/IMI/ProgAv/TP3 /home/zelire/Documents/IMI/ProgAv/TP3/build /home/zelire/Documents/IMI/ProgAv/TP3/build /home/zelire/Documents/IMI/ProgAv/TP3/build/CMakeFiles/TP3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TP3.dir/depend
