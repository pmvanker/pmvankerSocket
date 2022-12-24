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
include ClientServerApp/CMakeFiles/Client.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include ClientServerApp/CMakeFiles/Client.dir/compiler_depend.make

# Include the progress variables for this target.
include ClientServerApp/CMakeFiles/Client.dir/progress.make

# Include the compile flags for this target's objects.
include ClientServerApp/CMakeFiles/Client.dir/flags.make

ClientServerApp/CMakeFiles/Client.dir/Client.cpp.o: ClientServerApp/CMakeFiles/Client.dir/flags.make
ClientServerApp/CMakeFiles/Client.dir/Client.cpp.o: ../ClientServerApp/Client.cpp
ClientServerApp/CMakeFiles/Client.dir/Client.cpp.o: ClientServerApp/CMakeFiles/Client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pmvanker/github/pmvankerSocket/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ClientServerApp/CMakeFiles/Client.dir/Client.cpp.o"
	cd /home/pmvanker/github/pmvankerSocket/build/ClientServerApp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ClientServerApp/CMakeFiles/Client.dir/Client.cpp.o -MF CMakeFiles/Client.dir/Client.cpp.o.d -o CMakeFiles/Client.dir/Client.cpp.o -c /home/pmvanker/github/pmvankerSocket/ClientServerApp/Client.cpp

ClientServerApp/CMakeFiles/Client.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Client.cpp.i"
	cd /home/pmvanker/github/pmvankerSocket/build/ClientServerApp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pmvanker/github/pmvankerSocket/ClientServerApp/Client.cpp > CMakeFiles/Client.dir/Client.cpp.i

ClientServerApp/CMakeFiles/Client.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Client.cpp.s"
	cd /home/pmvanker/github/pmvankerSocket/build/ClientServerApp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pmvanker/github/pmvankerSocket/ClientServerApp/Client.cpp -o CMakeFiles/Client.dir/Client.cpp.s

# Object files for target Client
Client_OBJECTS = \
"CMakeFiles/Client.dir/Client.cpp.o"

# External object files for target Client
Client_EXTERNAL_OBJECTS =

ClientServerApp/Client: ClientServerApp/CMakeFiles/Client.dir/Client.cpp.o
ClientServerApp/Client: ClientServerApp/CMakeFiles/Client.dir/build.make
ClientServerApp/Client: ClientServerApp/libClient_objects.a
ClientServerApp/Client: libpmvankerSocket.so
ClientServerApp/Client: ClientServerApp/CMakeFiles/Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pmvanker/github/pmvankerSocket/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Client"
	cd /home/pmvanker/github/pmvankerSocket/build/ClientServerApp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ClientServerApp/CMakeFiles/Client.dir/build: ClientServerApp/Client
.PHONY : ClientServerApp/CMakeFiles/Client.dir/build

ClientServerApp/CMakeFiles/Client.dir/clean:
	cd /home/pmvanker/github/pmvankerSocket/build/ClientServerApp && $(CMAKE_COMMAND) -P CMakeFiles/Client.dir/cmake_clean.cmake
.PHONY : ClientServerApp/CMakeFiles/Client.dir/clean

ClientServerApp/CMakeFiles/Client.dir/depend:
	cd /home/pmvanker/github/pmvankerSocket/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pmvanker/github/pmvankerSocket /home/pmvanker/github/pmvankerSocket/ClientServerApp /home/pmvanker/github/pmvankerSocket/build /home/pmvanker/github/pmvankerSocket/build/ClientServerApp /home/pmvanker/github/pmvankerSocket/build/ClientServerApp/CMakeFiles/Client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ClientServerApp/CMakeFiles/Client.dir/depend

