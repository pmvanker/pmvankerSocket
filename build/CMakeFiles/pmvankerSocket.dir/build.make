# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pmvanker/github/pmvankerSocket

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pmvanker/github/pmvankerSocket/build

# Include any dependencies generated for this target.
include CMakeFiles/pmvankerSocket.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pmvankerSocket.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pmvankerSocket.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pmvankerSocket.dir/flags.make

CMakeFiles/pmvankerSocket.dir/library/libpmvankerSocket/Socket.cpp.o: CMakeFiles/pmvankerSocket.dir/flags.make
CMakeFiles/pmvankerSocket.dir/library/libpmvankerSocket/Socket.cpp.o: ../library/libpmvankerSocket/Socket.cpp
CMakeFiles/pmvankerSocket.dir/library/libpmvankerSocket/Socket.cpp.o: CMakeFiles/pmvankerSocket.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pmvanker/github/pmvankerSocket/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pmvankerSocket.dir/library/libpmvankerSocket/Socket.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pmvankerSocket.dir/library/libpmvankerSocket/Socket.cpp.o -MF CMakeFiles/pmvankerSocket.dir/library/libpmvankerSocket/Socket.cpp.o.d -o CMakeFiles/pmvankerSocket.dir/library/libpmvankerSocket/Socket.cpp.o -c /home/pmvanker/github/pmvankerSocket/library/libpmvankerSocket/Socket.cpp

CMakeFiles/pmvankerSocket.dir/library/libpmvankerSocket/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pmvankerSocket.dir/library/libpmvankerSocket/Socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pmvanker/github/pmvankerSocket/library/libpmvankerSocket/Socket.cpp > CMakeFiles/pmvankerSocket.dir/library/libpmvankerSocket/Socket.cpp.i

CMakeFiles/pmvankerSocket.dir/library/libpmvankerSocket/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pmvankerSocket.dir/library/libpmvankerSocket/Socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pmvanker/github/pmvankerSocket/library/libpmvankerSocket/Socket.cpp -o CMakeFiles/pmvankerSocket.dir/library/libpmvankerSocket/Socket.cpp.s

# Object files for target pmvankerSocket
pmvankerSocket_OBJECTS = \
"CMakeFiles/pmvankerSocket.dir/library/libpmvankerSocket/Socket.cpp.o"

# External object files for target pmvankerSocket
pmvankerSocket_EXTERNAL_OBJECTS =

libpmvankerSocket.so: CMakeFiles/pmvankerSocket.dir/library/libpmvankerSocket/Socket.cpp.o
libpmvankerSocket.so: CMakeFiles/pmvankerSocket.dir/build.make
libpmvankerSocket.so: CMakeFiles/pmvankerSocket.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pmvanker/github/pmvankerSocket/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libpmvankerSocket.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pmvankerSocket.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pmvankerSocket.dir/build: libpmvankerSocket.so
.PHONY : CMakeFiles/pmvankerSocket.dir/build

CMakeFiles/pmvankerSocket.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pmvankerSocket.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pmvankerSocket.dir/clean

CMakeFiles/pmvankerSocket.dir/depend:
	cd /home/pmvanker/github/pmvankerSocket/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pmvanker/github/pmvankerSocket /home/pmvanker/github/pmvankerSocket /home/pmvanker/github/pmvankerSocket/build /home/pmvanker/github/pmvankerSocket/build /home/pmvanker/github/pmvankerSocket/build/CMakeFiles/pmvankerSocket.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pmvankerSocket.dir/depend

