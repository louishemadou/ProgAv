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
CMAKE_SOURCE_DIR = /home/zelire/Documents/IMI/ProgAv/TP2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zelire/Documents/IMI/ProgAv/TP2/build

# Include any dependencies generated for this target.
include CMakeFiles/TP2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TP2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TP2.dir/flags.make

CMakeFiles/TP2.dir/main.cpp.o: CMakeFiles/TP2.dir/flags.make
CMakeFiles/TP2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zelire/Documents/IMI/ProgAv/TP2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TP2.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP2.dir/main.cpp.o -c /home/zelire/Documents/IMI/ProgAv/TP2/main.cpp

CMakeFiles/TP2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zelire/Documents/IMI/ProgAv/TP2/main.cpp > CMakeFiles/TP2.dir/main.cpp.i

CMakeFiles/TP2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zelire/Documents/IMI/ProgAv/TP2/main.cpp -o CMakeFiles/TP2.dir/main.cpp.s

CMakeFiles/TP2.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/TP2.dir/main.cpp.o.requires

CMakeFiles/TP2.dir/main.cpp.o.provides: CMakeFiles/TP2.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/TP2.dir/build.make CMakeFiles/TP2.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/TP2.dir/main.cpp.o.provides

CMakeFiles/TP2.dir/main.cpp.o.provides.build: CMakeFiles/TP2.dir/main.cpp.o


CMakeFiles/TP2.dir/eleve.cpp.o: CMakeFiles/TP2.dir/flags.make
CMakeFiles/TP2.dir/eleve.cpp.o: ../eleve.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zelire/Documents/IMI/ProgAv/TP2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TP2.dir/eleve.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP2.dir/eleve.cpp.o -c /home/zelire/Documents/IMI/ProgAv/TP2/eleve.cpp

CMakeFiles/TP2.dir/eleve.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP2.dir/eleve.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zelire/Documents/IMI/ProgAv/TP2/eleve.cpp > CMakeFiles/TP2.dir/eleve.cpp.i

CMakeFiles/TP2.dir/eleve.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP2.dir/eleve.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zelire/Documents/IMI/ProgAv/TP2/eleve.cpp -o CMakeFiles/TP2.dir/eleve.cpp.s

CMakeFiles/TP2.dir/eleve.cpp.o.requires:

.PHONY : CMakeFiles/TP2.dir/eleve.cpp.o.requires

CMakeFiles/TP2.dir/eleve.cpp.o.provides: CMakeFiles/TP2.dir/eleve.cpp.o.requires
	$(MAKE) -f CMakeFiles/TP2.dir/build.make CMakeFiles/TP2.dir/eleve.cpp.o.provides.build
.PHONY : CMakeFiles/TP2.dir/eleve.cpp.o.provides

CMakeFiles/TP2.dir/eleve.cpp.o.provides.build: CMakeFiles/TP2.dir/eleve.cpp.o


# Object files for target TP2
TP2_OBJECTS = \
"CMakeFiles/TP2.dir/main.cpp.o" \
"CMakeFiles/TP2.dir/eleve.cpp.o"

# External object files for target TP2
TP2_EXTERNAL_OBJECTS =

TP2: CMakeFiles/TP2.dir/main.cpp.o
TP2: CMakeFiles/TP2.dir/eleve.cpp.o
TP2: CMakeFiles/TP2.dir/build.make
TP2: CMakeFiles/TP2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zelire/Documents/IMI/ProgAv/TP2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable TP2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TP2.dir/build: TP2

.PHONY : CMakeFiles/TP2.dir/build

CMakeFiles/TP2.dir/requires: CMakeFiles/TP2.dir/main.cpp.o.requires
CMakeFiles/TP2.dir/requires: CMakeFiles/TP2.dir/eleve.cpp.o.requires

.PHONY : CMakeFiles/TP2.dir/requires

CMakeFiles/TP2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TP2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TP2.dir/clean

CMakeFiles/TP2.dir/depend:
	cd /home/zelire/Documents/IMI/ProgAv/TP2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zelire/Documents/IMI/ProgAv/TP2 /home/zelire/Documents/IMI/ProgAv/TP2 /home/zelire/Documents/IMI/ProgAv/TP2/build /home/zelire/Documents/IMI/ProgAv/TP2/build /home/zelire/Documents/IMI/ProgAv/TP2/build/CMakeFiles/TP2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TP2.dir/depend

