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
CMAKE_COMMAND = /snap/clion/99/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/99/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bagniz/dev/code/C++/Game-Cpp/Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bagniz/dev/code/C++/Game-Cpp/Game/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Game.dir/flags.make

CMakeFiles/Game.dir/main.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bagniz/dev/code/C++/Game-Cpp/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Game.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/main.cpp.o -c /home/bagniz/dev/code/C++/Game-Cpp/Game/main.cpp

CMakeFiles/Game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bagniz/dev/code/C++/Game-Cpp/Game/main.cpp > CMakeFiles/Game.dir/main.cpp.i

CMakeFiles/Game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bagniz/dev/code/C++/Game-Cpp/Game/main.cpp -o CMakeFiles/Game.dir/main.cpp.s

CMakeFiles/Game.dir/source/Game.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/source/Game.cpp.o: ../source/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bagniz/dev/code/C++/Game-Cpp/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Game.dir/source/Game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/source/Game.cpp.o -c /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Game.cpp

CMakeFiles/Game.dir/source/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/source/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Game.cpp > CMakeFiles/Game.dir/source/Game.cpp.i

CMakeFiles/Game.dir/source/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/source/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Game.cpp -o CMakeFiles/Game.dir/source/Game.cpp.s

CMakeFiles/Game.dir/source/Board.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/source/Board.cpp.o: ../source/Board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bagniz/dev/code/C++/Game-Cpp/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Game.dir/source/Board.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/source/Board.cpp.o -c /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Board.cpp

CMakeFiles/Game.dir/source/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/source/Board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Board.cpp > CMakeFiles/Game.dir/source/Board.cpp.i

CMakeFiles/Game.dir/source/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/source/Board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Board.cpp -o CMakeFiles/Game.dir/source/Board.cpp.s

CMakeFiles/Game.dir/source/Element.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/source/Element.cpp.o: ../source/Element.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bagniz/dev/code/C++/Game-Cpp/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Game.dir/source/Element.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/source/Element.cpp.o -c /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Element.cpp

CMakeFiles/Game.dir/source/Element.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/source/Element.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Element.cpp > CMakeFiles/Game.dir/source/Element.cpp.i

CMakeFiles/Game.dir/source/Element.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/source/Element.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Element.cpp -o CMakeFiles/Game.dir/source/Element.cpp.s

CMakeFiles/Game.dir/source/Position.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/source/Position.cpp.o: ../source/Position.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bagniz/dev/code/C++/Game-Cpp/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Game.dir/source/Position.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/source/Position.cpp.o -c /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Position.cpp

CMakeFiles/Game.dir/source/Position.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/source/Position.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Position.cpp > CMakeFiles/Game.dir/source/Position.cpp.i

CMakeFiles/Game.dir/source/Position.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/source/Position.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Position.cpp -o CMakeFiles/Game.dir/source/Position.cpp.s

CMakeFiles/Game.dir/source/Reumu.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/source/Reumu.cpp.o: ../source/Reumu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bagniz/dev/code/C++/Game-Cpp/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Game.dir/source/Reumu.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/source/Reumu.cpp.o -c /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Reumu.cpp

CMakeFiles/Game.dir/source/Reumu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/source/Reumu.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Reumu.cpp > CMakeFiles/Game.dir/source/Reumu.cpp.i

CMakeFiles/Game.dir/source/Reumu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/source/Reumu.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Reumu.cpp -o CMakeFiles/Game.dir/source/Reumu.cpp.s

CMakeFiles/Game.dir/source/Diam.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/source/Diam.cpp.o: ../source/Diam.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bagniz/dev/code/C++/Game-Cpp/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Game.dir/source/Diam.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/source/Diam.cpp.o -c /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Diam.cpp

CMakeFiles/Game.dir/source/Diam.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/source/Diam.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Diam.cpp > CMakeFiles/Game.dir/source/Diam.cpp.i

CMakeFiles/Game.dir/source/Diam.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/source/Diam.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Diam.cpp -o CMakeFiles/Game.dir/source/Diam.cpp.s

CMakeFiles/Game.dir/source/Geurchar.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/source/Geurchar.cpp.o: ../source/Geurchar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bagniz/dev/code/C++/Game-Cpp/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Game.dir/source/Geurchar.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/source/Geurchar.cpp.o -c /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Geurchar.cpp

CMakeFiles/Game.dir/source/Geurchar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/source/Geurchar.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Geurchar.cpp > CMakeFiles/Game.dir/source/Geurchar.cpp.i

CMakeFiles/Game.dir/source/Geurchar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/source/Geurchar.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Geurchar.cpp -o CMakeFiles/Game.dir/source/Geurchar.cpp.s

CMakeFiles/Game.dir/source/Teupor.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/source/Teupor.cpp.o: ../source/Teupor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bagniz/dev/code/C++/Game-Cpp/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Game.dir/source/Teupor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/source/Teupor.cpp.o -c /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Teupor.cpp

CMakeFiles/Game.dir/source/Teupor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/source/Teupor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Teupor.cpp > CMakeFiles/Game.dir/source/Teupor.cpp.i

CMakeFiles/Game.dir/source/Teupor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/source/Teupor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Teupor.cpp -o CMakeFiles/Game.dir/source/Teupor.cpp.s

CMakeFiles/Game.dir/source/Oueurj.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/source/Oueurj.cpp.o: ../source/Oueurj.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bagniz/dev/code/C++/Game-Cpp/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Game.dir/source/Oueurj.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/source/Oueurj.cpp.o -c /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Oueurj.cpp

CMakeFiles/Game.dir/source/Oueurj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/source/Oueurj.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Oueurj.cpp > CMakeFiles/Game.dir/source/Oueurj.cpp.i

CMakeFiles/Game.dir/source/Oueurj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/source/Oueurj.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bagniz/dev/code/C++/Game-Cpp/Game/source/Oueurj.cpp -o CMakeFiles/Game.dir/source/Oueurj.cpp.s

CMakeFiles/Game.dir/source/IStreumon.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/source/IStreumon.cpp.o: ../source/IStreumon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bagniz/dev/code/C++/Game-Cpp/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Game.dir/source/IStreumon.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/source/IStreumon.cpp.o -c /home/bagniz/dev/code/C++/Game-Cpp/Game/source/IStreumon.cpp

CMakeFiles/Game.dir/source/IStreumon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/source/IStreumon.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bagniz/dev/code/C++/Game-Cpp/Game/source/IStreumon.cpp > CMakeFiles/Game.dir/source/IStreumon.cpp.i

CMakeFiles/Game.dir/source/IStreumon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/source/IStreumon.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bagniz/dev/code/C++/Game-Cpp/Game/source/IStreumon.cpp -o CMakeFiles/Game.dir/source/IStreumon.cpp.s

CMakeFiles/Game.dir/source/PStreumon.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/source/PStreumon.cpp.o: ../source/PStreumon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bagniz/dev/code/C++/Game-Cpp/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Game.dir/source/PStreumon.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/source/PStreumon.cpp.o -c /home/bagniz/dev/code/C++/Game-Cpp/Game/source/PStreumon.cpp

CMakeFiles/Game.dir/source/PStreumon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/source/PStreumon.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bagniz/dev/code/C++/Game-Cpp/Game/source/PStreumon.cpp > CMakeFiles/Game.dir/source/PStreumon.cpp.i

CMakeFiles/Game.dir/source/PStreumon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/source/PStreumon.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bagniz/dev/code/C++/Game-Cpp/Game/source/PStreumon.cpp -o CMakeFiles/Game.dir/source/PStreumon.cpp.s

CMakeFiles/Game.dir/source/XStreumon.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/source/XStreumon.cpp.o: ../source/XStreumon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bagniz/dev/code/C++/Game-Cpp/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Game.dir/source/XStreumon.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/source/XStreumon.cpp.o -c /home/bagniz/dev/code/C++/Game-Cpp/Game/source/XStreumon.cpp

CMakeFiles/Game.dir/source/XStreumon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/source/XStreumon.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bagniz/dev/code/C++/Game-Cpp/Game/source/XStreumon.cpp > CMakeFiles/Game.dir/source/XStreumon.cpp.i

CMakeFiles/Game.dir/source/XStreumon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/source/XStreumon.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bagniz/dev/code/C++/Game-Cpp/Game/source/XStreumon.cpp -o CMakeFiles/Game.dir/source/XStreumon.cpp.s

CMakeFiles/Game.dir/source/SStreumon.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/source/SStreumon.cpp.o: ../source/SStreumon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bagniz/dev/code/C++/Game-Cpp/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Game.dir/source/SStreumon.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/source/SStreumon.cpp.o -c /home/bagniz/dev/code/C++/Game-Cpp/Game/source/SStreumon.cpp

CMakeFiles/Game.dir/source/SStreumon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/source/SStreumon.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bagniz/dev/code/C++/Game-Cpp/Game/source/SStreumon.cpp > CMakeFiles/Game.dir/source/SStreumon.cpp.i

CMakeFiles/Game.dir/source/SStreumon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/source/SStreumon.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bagniz/dev/code/C++/Game-Cpp/Game/source/SStreumon.cpp -o CMakeFiles/Game.dir/source/SStreumon.cpp.s

CMakeFiles/Game.dir/source/clicked_char.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/source/clicked_char.cpp.o: ../source/clicked_char.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bagniz/dev/code/C++/Game-Cpp/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Game.dir/source/clicked_char.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/source/clicked_char.cpp.o -c /home/bagniz/dev/code/C++/Game-Cpp/Game/source/clicked_char.cpp

CMakeFiles/Game.dir/source/clicked_char.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/source/clicked_char.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bagniz/dev/code/C++/Game-Cpp/Game/source/clicked_char.cpp > CMakeFiles/Game.dir/source/clicked_char.cpp.i

CMakeFiles/Game.dir/source/clicked_char.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/source/clicked_char.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bagniz/dev/code/C++/Game-Cpp/Game/source/clicked_char.cpp -o CMakeFiles/Game.dir/source/clicked_char.cpp.s

# Object files for target Game
Game_OBJECTS = \
"CMakeFiles/Game.dir/main.cpp.o" \
"CMakeFiles/Game.dir/source/Game.cpp.o" \
"CMakeFiles/Game.dir/source/Board.cpp.o" \
"CMakeFiles/Game.dir/source/Element.cpp.o" \
"CMakeFiles/Game.dir/source/Position.cpp.o" \
"CMakeFiles/Game.dir/source/Reumu.cpp.o" \
"CMakeFiles/Game.dir/source/Diam.cpp.o" \
"CMakeFiles/Game.dir/source/Geurchar.cpp.o" \
"CMakeFiles/Game.dir/source/Teupor.cpp.o" \
"CMakeFiles/Game.dir/source/Oueurj.cpp.o" \
"CMakeFiles/Game.dir/source/IStreumon.cpp.o" \
"CMakeFiles/Game.dir/source/PStreumon.cpp.o" \
"CMakeFiles/Game.dir/source/XStreumon.cpp.o" \
"CMakeFiles/Game.dir/source/SStreumon.cpp.o" \
"CMakeFiles/Game.dir/source/clicked_char.cpp.o"

# External object files for target Game
Game_EXTERNAL_OBJECTS =

Game: CMakeFiles/Game.dir/main.cpp.o
Game: CMakeFiles/Game.dir/source/Game.cpp.o
Game: CMakeFiles/Game.dir/source/Board.cpp.o
Game: CMakeFiles/Game.dir/source/Element.cpp.o
Game: CMakeFiles/Game.dir/source/Position.cpp.o
Game: CMakeFiles/Game.dir/source/Reumu.cpp.o
Game: CMakeFiles/Game.dir/source/Diam.cpp.o
Game: CMakeFiles/Game.dir/source/Geurchar.cpp.o
Game: CMakeFiles/Game.dir/source/Teupor.cpp.o
Game: CMakeFiles/Game.dir/source/Oueurj.cpp.o
Game: CMakeFiles/Game.dir/source/IStreumon.cpp.o
Game: CMakeFiles/Game.dir/source/PStreumon.cpp.o
Game: CMakeFiles/Game.dir/source/XStreumon.cpp.o
Game: CMakeFiles/Game.dir/source/SStreumon.cpp.o
Game: CMakeFiles/Game.dir/source/clicked_char.cpp.o
Game: CMakeFiles/Game.dir/build.make
Game: CMakeFiles/Game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bagniz/dev/code/C++/Game-Cpp/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX executable Game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Game.dir/build: Game

.PHONY : CMakeFiles/Game.dir/build

CMakeFiles/Game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Game.dir/clean

CMakeFiles/Game.dir/depend:
	cd /home/bagniz/dev/code/C++/Game-Cpp/Game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bagniz/dev/code/C++/Game-Cpp/Game /home/bagniz/dev/code/C++/Game-Cpp/Game /home/bagniz/dev/code/C++/Game-Cpp/Game/cmake-build-debug /home/bagniz/dev/code/C++/Game-Cpp/Game/cmake-build-debug /home/bagniz/dev/code/C++/Game-Cpp/Game/cmake-build-debug/CMakeFiles/Game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Game.dir/depend

