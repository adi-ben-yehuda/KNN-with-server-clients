# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /home/shahar/clion-2022.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/shahar/clion-2022.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shahar/Documents/advencd1/advanced_ex_4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shahar/Documents/advencd1/advanced_ex_4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/advanced_ex_4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/advanced_ex_4.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/advanced_ex_4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/advanced_ex_4.dir/flags.make

CMakeFiles/advanced_ex_4.dir/Distance.cpp.o: CMakeFiles/advanced_ex_4.dir/flags.make
CMakeFiles/advanced_ex_4.dir/Distance.cpp.o: /home/shahar/Documents/advencd1/advanced_ex_4/Distance.cpp
CMakeFiles/advanced_ex_4.dir/Distance.cpp.o: CMakeFiles/advanced_ex_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shahar/Documents/advencd1/advanced_ex_4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/advanced_ex_4.dir/Distance.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/advanced_ex_4.dir/Distance.cpp.o -MF CMakeFiles/advanced_ex_4.dir/Distance.cpp.o.d -o CMakeFiles/advanced_ex_4.dir/Distance.cpp.o -c /home/shahar/Documents/advencd1/advanced_ex_4/Distance.cpp

CMakeFiles/advanced_ex_4.dir/Distance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/advanced_ex_4.dir/Distance.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shahar/Documents/advencd1/advanced_ex_4/Distance.cpp > CMakeFiles/advanced_ex_4.dir/Distance.cpp.i

CMakeFiles/advanced_ex_4.dir/Distance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/advanced_ex_4.dir/Distance.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shahar/Documents/advencd1/advanced_ex_4/Distance.cpp -o CMakeFiles/advanced_ex_4.dir/Distance.cpp.s

CMakeFiles/advanced_ex_4.dir/client.cpp.o: CMakeFiles/advanced_ex_4.dir/flags.make
CMakeFiles/advanced_ex_4.dir/client.cpp.o: /home/shahar/Documents/advencd1/advanced_ex_4/client.cpp
CMakeFiles/advanced_ex_4.dir/client.cpp.o: CMakeFiles/advanced_ex_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shahar/Documents/advencd1/advanced_ex_4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/advanced_ex_4.dir/client.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/advanced_ex_4.dir/client.cpp.o -MF CMakeFiles/advanced_ex_4.dir/client.cpp.o.d -o CMakeFiles/advanced_ex_4.dir/client.cpp.o -c /home/shahar/Documents/advencd1/advanced_ex_4/client.cpp

CMakeFiles/advanced_ex_4.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/advanced_ex_4.dir/client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shahar/Documents/advencd1/advanced_ex_4/client.cpp > CMakeFiles/advanced_ex_4.dir/client.cpp.i

CMakeFiles/advanced_ex_4.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/advanced_ex_4.dir/client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shahar/Documents/advencd1/advanced_ex_4/client.cpp -o CMakeFiles/advanced_ex_4.dir/client.cpp.s

CMakeFiles/advanced_ex_4.dir/File.cpp.o: CMakeFiles/advanced_ex_4.dir/flags.make
CMakeFiles/advanced_ex_4.dir/File.cpp.o: /home/shahar/Documents/advencd1/advanced_ex_4/File.cpp
CMakeFiles/advanced_ex_4.dir/File.cpp.o: CMakeFiles/advanced_ex_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shahar/Documents/advencd1/advanced_ex_4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/advanced_ex_4.dir/File.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/advanced_ex_4.dir/File.cpp.o -MF CMakeFiles/advanced_ex_4.dir/File.cpp.o.d -o CMakeFiles/advanced_ex_4.dir/File.cpp.o -c /home/shahar/Documents/advencd1/advanced_ex_4/File.cpp

CMakeFiles/advanced_ex_4.dir/File.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/advanced_ex_4.dir/File.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shahar/Documents/advencd1/advanced_ex_4/File.cpp > CMakeFiles/advanced_ex_4.dir/File.cpp.i

CMakeFiles/advanced_ex_4.dir/File.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/advanced_ex_4.dir/File.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shahar/Documents/advencd1/advanced_ex_4/File.cpp -o CMakeFiles/advanced_ex_4.dir/File.cpp.s

CMakeFiles/advanced_ex_4.dir/MaxHeap.cpp.o: CMakeFiles/advanced_ex_4.dir/flags.make
CMakeFiles/advanced_ex_4.dir/MaxHeap.cpp.o: /home/shahar/Documents/advencd1/advanced_ex_4/MaxHeap.cpp
CMakeFiles/advanced_ex_4.dir/MaxHeap.cpp.o: CMakeFiles/advanced_ex_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shahar/Documents/advencd1/advanced_ex_4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/advanced_ex_4.dir/MaxHeap.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/advanced_ex_4.dir/MaxHeap.cpp.o -MF CMakeFiles/advanced_ex_4.dir/MaxHeap.cpp.o.d -o CMakeFiles/advanced_ex_4.dir/MaxHeap.cpp.o -c /home/shahar/Documents/advencd1/advanced_ex_4/MaxHeap.cpp

CMakeFiles/advanced_ex_4.dir/MaxHeap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/advanced_ex_4.dir/MaxHeap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shahar/Documents/advencd1/advanced_ex_4/MaxHeap.cpp > CMakeFiles/advanced_ex_4.dir/MaxHeap.cpp.i

CMakeFiles/advanced_ex_4.dir/MaxHeap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/advanced_ex_4.dir/MaxHeap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shahar/Documents/advencd1/advanced_ex_4/MaxHeap.cpp -o CMakeFiles/advanced_ex_4.dir/MaxHeap.cpp.s

CMakeFiles/advanced_ex_4.dir/Setting.cpp.o: CMakeFiles/advanced_ex_4.dir/flags.make
CMakeFiles/advanced_ex_4.dir/Setting.cpp.o: /home/shahar/Documents/advencd1/advanced_ex_4/Setting.cpp
CMakeFiles/advanced_ex_4.dir/Setting.cpp.o: CMakeFiles/advanced_ex_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shahar/Documents/advencd1/advanced_ex_4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/advanced_ex_4.dir/Setting.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/advanced_ex_4.dir/Setting.cpp.o -MF CMakeFiles/advanced_ex_4.dir/Setting.cpp.o.d -o CMakeFiles/advanced_ex_4.dir/Setting.cpp.o -c /home/shahar/Documents/advencd1/advanced_ex_4/Setting.cpp

CMakeFiles/advanced_ex_4.dir/Setting.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/advanced_ex_4.dir/Setting.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shahar/Documents/advencd1/advanced_ex_4/Setting.cpp > CMakeFiles/advanced_ex_4.dir/Setting.cpp.i

CMakeFiles/advanced_ex_4.dir/Setting.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/advanced_ex_4.dir/Setting.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shahar/Documents/advencd1/advanced_ex_4/Setting.cpp -o CMakeFiles/advanced_ex_4.dir/Setting.cpp.s

CMakeFiles/advanced_ex_4.dir/Command.cpp.o: CMakeFiles/advanced_ex_4.dir/flags.make
CMakeFiles/advanced_ex_4.dir/Command.cpp.o: /home/shahar/Documents/advencd1/advanced_ex_4/Command.cpp
CMakeFiles/advanced_ex_4.dir/Command.cpp.o: CMakeFiles/advanced_ex_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shahar/Documents/advencd1/advanced_ex_4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/advanced_ex_4.dir/Command.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/advanced_ex_4.dir/Command.cpp.o -MF CMakeFiles/advanced_ex_4.dir/Command.cpp.o.d -o CMakeFiles/advanced_ex_4.dir/Command.cpp.o -c /home/shahar/Documents/advencd1/advanced_ex_4/Command.cpp

CMakeFiles/advanced_ex_4.dir/Command.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/advanced_ex_4.dir/Command.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shahar/Documents/advencd1/advanced_ex_4/Command.cpp > CMakeFiles/advanced_ex_4.dir/Command.cpp.i

CMakeFiles/advanced_ex_4.dir/Command.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/advanced_ex_4.dir/Command.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shahar/Documents/advencd1/advanced_ex_4/Command.cpp -o CMakeFiles/advanced_ex_4.dir/Command.cpp.s

CMakeFiles/advanced_ex_4.dir/UploadFile.cpp.o: CMakeFiles/advanced_ex_4.dir/flags.make
CMakeFiles/advanced_ex_4.dir/UploadFile.cpp.o: /home/shahar/Documents/advencd1/advanced_ex_4/UploadFile.cpp
CMakeFiles/advanced_ex_4.dir/UploadFile.cpp.o: CMakeFiles/advanced_ex_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shahar/Documents/advencd1/advanced_ex_4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/advanced_ex_4.dir/UploadFile.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/advanced_ex_4.dir/UploadFile.cpp.o -MF CMakeFiles/advanced_ex_4.dir/UploadFile.cpp.o.d -o CMakeFiles/advanced_ex_4.dir/UploadFile.cpp.o -c /home/shahar/Documents/advencd1/advanced_ex_4/UploadFile.cpp

CMakeFiles/advanced_ex_4.dir/UploadFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/advanced_ex_4.dir/UploadFile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shahar/Documents/advencd1/advanced_ex_4/UploadFile.cpp > CMakeFiles/advanced_ex_4.dir/UploadFile.cpp.i

CMakeFiles/advanced_ex_4.dir/UploadFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/advanced_ex_4.dir/UploadFile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shahar/Documents/advencd1/advanced_ex_4/UploadFile.cpp -o CMakeFiles/advanced_ex_4.dir/UploadFile.cpp.s

CMakeFiles/advanced_ex_4.dir/Results.cpp.o: CMakeFiles/advanced_ex_4.dir/flags.make
CMakeFiles/advanced_ex_4.dir/Results.cpp.o: /home/shahar/Documents/advencd1/advanced_ex_4/Results.cpp
CMakeFiles/advanced_ex_4.dir/Results.cpp.o: CMakeFiles/advanced_ex_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shahar/Documents/advencd1/advanced_ex_4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/advanced_ex_4.dir/Results.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/advanced_ex_4.dir/Results.cpp.o -MF CMakeFiles/advanced_ex_4.dir/Results.cpp.o.d -o CMakeFiles/advanced_ex_4.dir/Results.cpp.o -c /home/shahar/Documents/advencd1/advanced_ex_4/Results.cpp

CMakeFiles/advanced_ex_4.dir/Results.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/advanced_ex_4.dir/Results.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shahar/Documents/advencd1/advanced_ex_4/Results.cpp > CMakeFiles/advanced_ex_4.dir/Results.cpp.i

CMakeFiles/advanced_ex_4.dir/Results.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/advanced_ex_4.dir/Results.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shahar/Documents/advencd1/advanced_ex_4/Results.cpp -o CMakeFiles/advanced_ex_4.dir/Results.cpp.s

CMakeFiles/advanced_ex_4.dir/Classify.cpp.o: CMakeFiles/advanced_ex_4.dir/flags.make
CMakeFiles/advanced_ex_4.dir/Classify.cpp.o: /home/shahar/Documents/advencd1/advanced_ex_4/Classify.cpp
CMakeFiles/advanced_ex_4.dir/Classify.cpp.o: CMakeFiles/advanced_ex_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shahar/Documents/advencd1/advanced_ex_4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/advanced_ex_4.dir/Classify.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/advanced_ex_4.dir/Classify.cpp.o -MF CMakeFiles/advanced_ex_4.dir/Classify.cpp.o.d -o CMakeFiles/advanced_ex_4.dir/Classify.cpp.o -c /home/shahar/Documents/advencd1/advanced_ex_4/Classify.cpp

CMakeFiles/advanced_ex_4.dir/Classify.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/advanced_ex_4.dir/Classify.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shahar/Documents/advencd1/advanced_ex_4/Classify.cpp > CMakeFiles/advanced_ex_4.dir/Classify.cpp.i

CMakeFiles/advanced_ex_4.dir/Classify.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/advanced_ex_4.dir/Classify.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shahar/Documents/advencd1/advanced_ex_4/Classify.cpp -o CMakeFiles/advanced_ex_4.dir/Classify.cpp.s

CMakeFiles/advanced_ex_4.dir/Download.cpp.o: CMakeFiles/advanced_ex_4.dir/flags.make
CMakeFiles/advanced_ex_4.dir/Download.cpp.o: /home/shahar/Documents/advencd1/advanced_ex_4/Download.cpp
CMakeFiles/advanced_ex_4.dir/Download.cpp.o: CMakeFiles/advanced_ex_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shahar/Documents/advencd1/advanced_ex_4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/advanced_ex_4.dir/Download.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/advanced_ex_4.dir/Download.cpp.o -MF CMakeFiles/advanced_ex_4.dir/Download.cpp.o.d -o CMakeFiles/advanced_ex_4.dir/Download.cpp.o -c /home/shahar/Documents/advencd1/advanced_ex_4/Download.cpp

CMakeFiles/advanced_ex_4.dir/Download.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/advanced_ex_4.dir/Download.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shahar/Documents/advencd1/advanced_ex_4/Download.cpp > CMakeFiles/advanced_ex_4.dir/Download.cpp.i

CMakeFiles/advanced_ex_4.dir/Download.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/advanced_ex_4.dir/Download.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shahar/Documents/advencd1/advanced_ex_4/Download.cpp -o CMakeFiles/advanced_ex_4.dir/Download.cpp.s

CMakeFiles/advanced_ex_4.dir/Data.cpp.o: CMakeFiles/advanced_ex_4.dir/flags.make
CMakeFiles/advanced_ex_4.dir/Data.cpp.o: /home/shahar/Documents/advencd1/advanced_ex_4/Data.cpp
CMakeFiles/advanced_ex_4.dir/Data.cpp.o: CMakeFiles/advanced_ex_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shahar/Documents/advencd1/advanced_ex_4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/advanced_ex_4.dir/Data.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/advanced_ex_4.dir/Data.cpp.o -MF CMakeFiles/advanced_ex_4.dir/Data.cpp.o.d -o CMakeFiles/advanced_ex_4.dir/Data.cpp.o -c /home/shahar/Documents/advencd1/advanced_ex_4/Data.cpp

CMakeFiles/advanced_ex_4.dir/Data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/advanced_ex_4.dir/Data.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shahar/Documents/advencd1/advanced_ex_4/Data.cpp > CMakeFiles/advanced_ex_4.dir/Data.cpp.i

CMakeFiles/advanced_ex_4.dir/Data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/advanced_ex_4.dir/Data.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shahar/Documents/advencd1/advanced_ex_4/Data.cpp -o CMakeFiles/advanced_ex_4.dir/Data.cpp.s

CMakeFiles/advanced_ex_4.dir/DefaultIO.cpp.o: CMakeFiles/advanced_ex_4.dir/flags.make
CMakeFiles/advanced_ex_4.dir/DefaultIO.cpp.o: /home/shahar/Documents/advencd1/advanced_ex_4/DefaultIO.cpp
CMakeFiles/advanced_ex_4.dir/DefaultIO.cpp.o: CMakeFiles/advanced_ex_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shahar/Documents/advencd1/advanced_ex_4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/advanced_ex_4.dir/DefaultIO.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/advanced_ex_4.dir/DefaultIO.cpp.o -MF CMakeFiles/advanced_ex_4.dir/DefaultIO.cpp.o.d -o CMakeFiles/advanced_ex_4.dir/DefaultIO.cpp.o -c /home/shahar/Documents/advencd1/advanced_ex_4/DefaultIO.cpp

CMakeFiles/advanced_ex_4.dir/DefaultIO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/advanced_ex_4.dir/DefaultIO.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shahar/Documents/advencd1/advanced_ex_4/DefaultIO.cpp > CMakeFiles/advanced_ex_4.dir/DefaultIO.cpp.i

CMakeFiles/advanced_ex_4.dir/DefaultIO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/advanced_ex_4.dir/DefaultIO.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shahar/Documents/advencd1/advanced_ex_4/DefaultIO.cpp -o CMakeFiles/advanced_ex_4.dir/DefaultIO.cpp.s

CMakeFiles/advanced_ex_4.dir/SocketIO.cpp.o: CMakeFiles/advanced_ex_4.dir/flags.make
CMakeFiles/advanced_ex_4.dir/SocketIO.cpp.o: /home/shahar/Documents/advencd1/advanced_ex_4/SocketIO.cpp
CMakeFiles/advanced_ex_4.dir/SocketIO.cpp.o: CMakeFiles/advanced_ex_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shahar/Documents/advencd1/advanced_ex_4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/advanced_ex_4.dir/SocketIO.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/advanced_ex_4.dir/SocketIO.cpp.o -MF CMakeFiles/advanced_ex_4.dir/SocketIO.cpp.o.d -o CMakeFiles/advanced_ex_4.dir/SocketIO.cpp.o -c /home/shahar/Documents/advencd1/advanced_ex_4/SocketIO.cpp

CMakeFiles/advanced_ex_4.dir/SocketIO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/advanced_ex_4.dir/SocketIO.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shahar/Documents/advencd1/advanced_ex_4/SocketIO.cpp > CMakeFiles/advanced_ex_4.dir/SocketIO.cpp.i

CMakeFiles/advanced_ex_4.dir/SocketIO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/advanced_ex_4.dir/SocketIO.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shahar/Documents/advencd1/advanced_ex_4/SocketIO.cpp -o CMakeFiles/advanced_ex_4.dir/SocketIO.cpp.s

# Object files for target advanced_ex_4
advanced_ex_4_OBJECTS = \
"CMakeFiles/advanced_ex_4.dir/Distance.cpp.o" \
"CMakeFiles/advanced_ex_4.dir/client.cpp.o" \
"CMakeFiles/advanced_ex_4.dir/File.cpp.o" \
"CMakeFiles/advanced_ex_4.dir/MaxHeap.cpp.o" \
"CMakeFiles/advanced_ex_4.dir/Setting.cpp.o" \
"CMakeFiles/advanced_ex_4.dir/Command.cpp.o" \
"CMakeFiles/advanced_ex_4.dir/UploadFile.cpp.o" \
"CMakeFiles/advanced_ex_4.dir/Results.cpp.o" \
"CMakeFiles/advanced_ex_4.dir/Classify.cpp.o" \
"CMakeFiles/advanced_ex_4.dir/Download.cpp.o" \
"CMakeFiles/advanced_ex_4.dir/Data.cpp.o" \
"CMakeFiles/advanced_ex_4.dir/DefaultIO.cpp.o" \
"CMakeFiles/advanced_ex_4.dir/SocketIO.cpp.o"

# External object files for target advanced_ex_4
advanced_ex_4_EXTERNAL_OBJECTS =

advanced_ex_4: CMakeFiles/advanced_ex_4.dir/Distance.cpp.o
advanced_ex_4: CMakeFiles/advanced_ex_4.dir/client.cpp.o
advanced_ex_4: CMakeFiles/advanced_ex_4.dir/File.cpp.o
advanced_ex_4: CMakeFiles/advanced_ex_4.dir/MaxHeap.cpp.o
advanced_ex_4: CMakeFiles/advanced_ex_4.dir/Setting.cpp.o
advanced_ex_4: CMakeFiles/advanced_ex_4.dir/Command.cpp.o
advanced_ex_4: CMakeFiles/advanced_ex_4.dir/UploadFile.cpp.o
advanced_ex_4: CMakeFiles/advanced_ex_4.dir/Results.cpp.o
advanced_ex_4: CMakeFiles/advanced_ex_4.dir/Classify.cpp.o
advanced_ex_4: CMakeFiles/advanced_ex_4.dir/Download.cpp.o
advanced_ex_4: CMakeFiles/advanced_ex_4.dir/Data.cpp.o
advanced_ex_4: CMakeFiles/advanced_ex_4.dir/DefaultIO.cpp.o
advanced_ex_4: CMakeFiles/advanced_ex_4.dir/SocketIO.cpp.o
advanced_ex_4: CMakeFiles/advanced_ex_4.dir/build.make
advanced_ex_4: CMakeFiles/advanced_ex_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shahar/Documents/advencd1/advanced_ex_4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable advanced_ex_4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/advanced_ex_4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/advanced_ex_4.dir/build: advanced_ex_4
.PHONY : CMakeFiles/advanced_ex_4.dir/build

CMakeFiles/advanced_ex_4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/advanced_ex_4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/advanced_ex_4.dir/clean

CMakeFiles/advanced_ex_4.dir/depend:
	cd /home/shahar/Documents/advencd1/advanced_ex_4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shahar/Documents/advencd1/advanced_ex_4 /home/shahar/Documents/advencd1/advanced_ex_4 /home/shahar/Documents/advencd1/advanced_ex_4/cmake-build-debug /home/shahar/Documents/advencd1/advanced_ex_4/cmake-build-debug /home/shahar/Documents/advencd1/advanced_ex_4/cmake-build-debug/CMakeFiles/advanced_ex_4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/advanced_ex_4.dir/depend

