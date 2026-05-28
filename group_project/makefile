# to execute in terminal type "make build"
# or replace "build" with another target name from below

# If you create your own files, to add them to the commands,
# you can add your .cpp files to the space separated
# GAME_SRCS list after the game.cpp file name.

# --- Variables ---
CXX = g++
CXXFLAGS = -I includes -Wall -fconcepts -std=c++2a

# --- Source Files ---
SHARED_SRCS = die.cpp utils.cpp
GAME_SRCS = $(SHARED_SRCS) game.cpp
EXAMPLE_SRCS = $(SHARED_SRCS) examples.cpp

# --- Targets ---
build:
	rm -f game.out
	$(CXX) $(CXXFLAGS) $(GAME_SRCS) -o game.out

examples:
	rm -f examples.out
	$(CXX) $(CXXFLAGS) $(EXAMPLE_SRCS) -o examples.out

run_game:
	clear;./game.out

run_examples:
	clear;./examples.out

clean:
	rm -f game.out
	rm -f examples.out