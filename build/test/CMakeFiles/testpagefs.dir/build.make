# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.0.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.0.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/badpoet/Thursday/3a/DB/projects/SQLeast

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/badpoet/Thursday/3a/DB/projects/SQLeast/build

# Include any dependencies generated for this target.
include test/CMakeFiles/testpagefs.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/testpagefs.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/testpagefs.dir/flags.make

test/CMakeFiles/testpagefs.dir/testpagefs.cpp.o: test/CMakeFiles/testpagefs.dir/flags.make
test/CMakeFiles/testpagefs.dir/testpagefs.cpp.o: ../test/testpagefs.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/badpoet/Thursday/3a/DB/projects/SQLeast/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object test/CMakeFiles/testpagefs.dir/testpagefs.cpp.o"
	cd /Users/badpoet/Thursday/3a/DB/projects/SQLeast/build/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testpagefs.dir/testpagefs.cpp.o -c /Users/badpoet/Thursday/3a/DB/projects/SQLeast/test/testpagefs.cpp

test/CMakeFiles/testpagefs.dir/testpagefs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testpagefs.dir/testpagefs.cpp.i"
	cd /Users/badpoet/Thursday/3a/DB/projects/SQLeast/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/badpoet/Thursday/3a/DB/projects/SQLeast/test/testpagefs.cpp > CMakeFiles/testpagefs.dir/testpagefs.cpp.i

test/CMakeFiles/testpagefs.dir/testpagefs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testpagefs.dir/testpagefs.cpp.s"
	cd /Users/badpoet/Thursday/3a/DB/projects/SQLeast/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/badpoet/Thursday/3a/DB/projects/SQLeast/test/testpagefs.cpp -o CMakeFiles/testpagefs.dir/testpagefs.cpp.s

test/CMakeFiles/testpagefs.dir/testpagefs.cpp.o.requires:
.PHONY : test/CMakeFiles/testpagefs.dir/testpagefs.cpp.o.requires

test/CMakeFiles/testpagefs.dir/testpagefs.cpp.o.provides: test/CMakeFiles/testpagefs.dir/testpagefs.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/testpagefs.dir/build.make test/CMakeFiles/testpagefs.dir/testpagefs.cpp.o.provides.build
.PHONY : test/CMakeFiles/testpagefs.dir/testpagefs.cpp.o.provides

test/CMakeFiles/testpagefs.dir/testpagefs.cpp.o.provides.build: test/CMakeFiles/testpagefs.dir/testpagefs.cpp.o

# Object files for target testpagefs
testpagefs_OBJECTS = \
"CMakeFiles/testpagefs.dir/testpagefs.cpp.o"

# External object files for target testpagefs
testpagefs_EXTERNAL_OBJECTS =

../bin/testpagefs: test/CMakeFiles/testpagefs.dir/testpagefs.cpp.o
../bin/testpagefs: test/CMakeFiles/testpagefs.dir/build.make
../bin/testpagefs: ../lib/libpagefs.a
../bin/testpagefs: test/CMakeFiles/testpagefs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/testpagefs"
	cd /Users/badpoet/Thursday/3a/DB/projects/SQLeast/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testpagefs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/testpagefs.dir/build: ../bin/testpagefs
.PHONY : test/CMakeFiles/testpagefs.dir/build

test/CMakeFiles/testpagefs.dir/requires: test/CMakeFiles/testpagefs.dir/testpagefs.cpp.o.requires
.PHONY : test/CMakeFiles/testpagefs.dir/requires

test/CMakeFiles/testpagefs.dir/clean:
	cd /Users/badpoet/Thursday/3a/DB/projects/SQLeast/build/test && $(CMAKE_COMMAND) -P CMakeFiles/testpagefs.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/testpagefs.dir/clean

test/CMakeFiles/testpagefs.dir/depend:
	cd /Users/badpoet/Thursday/3a/DB/projects/SQLeast/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/badpoet/Thursday/3a/DB/projects/SQLeast /Users/badpoet/Thursday/3a/DB/projects/SQLeast/test /Users/badpoet/Thursday/3a/DB/projects/SQLeast/build /Users/badpoet/Thursday/3a/DB/projects/SQLeast/build/test /Users/badpoet/Thursday/3a/DB/projects/SQLeast/build/test/CMakeFiles/testpagefs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/testpagefs.dir/depend

