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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lberserq/work/neuro/src/3rdparty/dicomsdl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lberserq/work/neuro/src/3rdparty/dicomsdl

# Include any dependencies generated for this target.
include src/example/CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include src/example/CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include src/example/CMakeFiles/test.dir/flags.make

src/example/CMakeFiles/test.dir/test.cxx.o: src/example/CMakeFiles/test.dir/flags.make
src/example/CMakeFiles/test.dir/test.cxx.o: src/example/test.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lberserq/work/neuro/src/3rdparty/dicomsdl/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/example/CMakeFiles/test.dir/test.cxx.o"
	cd /home/lberserq/work/neuro/src/3rdparty/dicomsdl/src/example && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test.dir/test.cxx.o -c /home/lberserq/work/neuro/src/3rdparty/dicomsdl/src/example/test.cxx

src/example/CMakeFiles/test.dir/test.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/test.cxx.i"
	cd /home/lberserq/work/neuro/src/3rdparty/dicomsdl/src/example && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lberserq/work/neuro/src/3rdparty/dicomsdl/src/example/test.cxx > CMakeFiles/test.dir/test.cxx.i

src/example/CMakeFiles/test.dir/test.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/test.cxx.s"
	cd /home/lberserq/work/neuro/src/3rdparty/dicomsdl/src/example && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lberserq/work/neuro/src/3rdparty/dicomsdl/src/example/test.cxx -o CMakeFiles/test.dir/test.cxx.s

src/example/CMakeFiles/test.dir/test.cxx.o.requires:
.PHONY : src/example/CMakeFiles/test.dir/test.cxx.o.requires

src/example/CMakeFiles/test.dir/test.cxx.o.provides: src/example/CMakeFiles/test.dir/test.cxx.o.requires
	$(MAKE) -f src/example/CMakeFiles/test.dir/build.make src/example/CMakeFiles/test.dir/test.cxx.o.provides.build
.PHONY : src/example/CMakeFiles/test.dir/test.cxx.o.provides

src/example/CMakeFiles/test.dir/test.cxx.o.provides.build: src/example/CMakeFiles/test.dir/test.cxx.o

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/test.cxx.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

src/example/test: src/example/CMakeFiles/test.dir/test.cxx.o
src/example/test: src/example/CMakeFiles/test.dir/build.make
src/example/test: src/libdicomsdl.a
src/example/test: src/example/CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable test"
	cd /home/lberserq/work/neuro/src/3rdparty/dicomsdl/src/example && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/example/CMakeFiles/test.dir/build: src/example/test
.PHONY : src/example/CMakeFiles/test.dir/build

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/test.cxx.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

src/example/CMakeFiles/CMakeRelink.dir/test: src/example/CMakeFiles/test.dir/test.cxx.o
src/example/CMakeFiles/CMakeRelink.dir/test: src/example/CMakeFiles/test.dir/build.make
src/example/CMakeFiles/CMakeRelink.dir/test: src/libdicomsdl.a
src/example/CMakeFiles/CMakeRelink.dir/test: src/example/CMakeFiles/test.dir/relink.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable CMakeFiles/CMakeRelink.dir/test"
	cd /home/lberserq/work/neuro/src/3rdparty/dicomsdl/src/example && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/relink.txt --verbose=$(VERBOSE)

# Rule to relink during preinstall.
src/example/CMakeFiles/test.dir/preinstall: src/example/CMakeFiles/CMakeRelink.dir/test
.PHONY : src/example/CMakeFiles/test.dir/preinstall

src/example/CMakeFiles/test.dir/requires: src/example/CMakeFiles/test.dir/test.cxx.o.requires
.PHONY : src/example/CMakeFiles/test.dir/requires

src/example/CMakeFiles/test.dir/clean:
	cd /home/lberserq/work/neuro/src/3rdparty/dicomsdl/src/example && $(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : src/example/CMakeFiles/test.dir/clean

src/example/CMakeFiles/test.dir/depend:
	cd /home/lberserq/work/neuro/src/3rdparty/dicomsdl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lberserq/work/neuro/src/3rdparty/dicomsdl /home/lberserq/work/neuro/src/3rdparty/dicomsdl/src/example /home/lberserq/work/neuro/src/3rdparty/dicomsdl /home/lberserq/work/neuro/src/3rdparty/dicomsdl/src/example /home/lberserq/work/neuro/src/3rdparty/dicomsdl/src/example/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/example/CMakeFiles/test.dir/depend

