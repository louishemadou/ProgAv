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
CMAKE_SOURCE_DIR = /home/zelire/Documents/IMI/ProgAv/TP1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zelire/Documents/IMI/ProgAv/TP1/build

# Include any dependencies generated for this target.
include CMakeFiles/TP1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TP1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TP1.dir/flags.make

CMakeFiles/TP1.dir/main.cpp.o: CMakeFiles/TP1.dir/flags.make
CMakeFiles/TP1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zelire/Documents/IMI/ProgAv/TP1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TP1.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP1.dir/main.cpp.o -c /home/zelire/Documents/IMI/ProgAv/TP1/main.cpp

CMakeFiles/TP1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zelire/Documents/IMI/ProgAv/TP1/main.cpp > CMakeFiles/TP1.dir/main.cpp.i

CMakeFiles/TP1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zelire/Documents/IMI/ProgAv/TP1/main.cpp -o CMakeFiles/TP1.dir/main.cpp.s

CMakeFiles/TP1.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/TP1.dir/main.cpp.o.requires

CMakeFiles/TP1.dir/main.cpp.o.provides: CMakeFiles/TP1.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/TP1.dir/build.make CMakeFiles/TP1.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/TP1.dir/main.cpp.o.provides

CMakeFiles/TP1.dir/main.cpp.o.provides.build: CMakeFiles/TP1.dir/main.cpp.o


CMakeFiles/TP1.dir/matrice.cpp.o: CMakeFiles/TP1.dir/flags.make
CMakeFiles/TP1.dir/matrice.cpp.o: ../matrice.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zelire/Documents/IMI/ProgAv/TP1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TP1.dir/matrice.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP1.dir/matrice.cpp.o -c /home/zelire/Documents/IMI/ProgAv/TP1/matrice.cpp

CMakeFiles/TP1.dir/matrice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP1.dir/matrice.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zelire/Documents/IMI/ProgAv/TP1/matrice.cpp > CMakeFiles/TP1.dir/matrice.cpp.i

CMakeFiles/TP1.dir/matrice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP1.dir/matrice.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zelire/Documents/IMI/ProgAv/TP1/matrice.cpp -o CMakeFiles/TP1.dir/matrice.cpp.s

CMakeFiles/TP1.dir/matrice.cpp.o.requires:

.PHONY : CMakeFiles/TP1.dir/matrice.cpp.o.requires

CMakeFiles/TP1.dir/matrice.cpp.o.provides: CMakeFiles/TP1.dir/matrice.cpp.o.requires
	$(MAKE) -f CMakeFiles/TP1.dir/build.make CMakeFiles/TP1.dir/matrice.cpp.o.provides.build
.PHONY : CMakeFiles/TP1.dir/matrice.cpp.o.provides

CMakeFiles/TP1.dir/matrice.cpp.o.provides.build: CMakeFiles/TP1.dir/matrice.cpp.o


# Object files for target TP1
TP1_OBJECTS = \
"CMakeFiles/TP1.dir/main.cpp.o" \
"CMakeFiles/TP1.dir/matrice.cpp.o"

# External object files for target TP1
TP1_EXTERNAL_OBJECTS =

TP1: CMakeFiles/TP1.dir/main.cpp.o
TP1: CMakeFiles/TP1.dir/matrice.cpp.o
TP1: CMakeFiles/TP1.dir/build.make
TP1: CMakeFiles/TP1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zelire/Documents/IMI/ProgAv/TP1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable TP1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TP1.dir/build: TP1

.PHONY : CMakeFiles/TP1.dir/build

CMakeFiles/TP1.dir/requires: CMakeFiles/TP1.dir/main.cpp.o.requires
CMakeFiles/TP1.dir/requires: CMakeFiles/TP1.dir/matrice.cpp.o.requires

.PHONY : CMakeFiles/TP1.dir/requires

CMakeFiles/TP1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TP1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TP1.dir/clean

CMakeFiles/TP1.dir/depend:
	cd /home/zelire/Documents/IMI/ProgAv/TP1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zelire/Documents/IMI/ProgAv/TP1 /home/zelire/Documents/IMI/ProgAv/TP1 /home/zelire/Documents/IMI/ProgAv/TP1/build /home/zelire/Documents/IMI/ProgAv/TP1/build /home/zelire/Documents/IMI/ProgAv/TP1/build/CMakeFiles/TP1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TP1.dir/depend
