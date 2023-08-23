# @file makefile
# @author Adam T Koehler, PhD
# @date June 7, 2023
# @brief makefile for the Garden linked list lecture example

# What are makefiles?
# makefiles allow you to run a series of Linux commands using the make system. 
# These commands are usually a series of Linux commands to compile or execute
# the program you are working on. Or to execute useful debugging programs.
# Using a make system can make compiling multi-file programs much easier.

# Copyright Notice
# This document is protected by U.S. copyright law. Reproduction and 
# distribution of this work, including posting or sharing through any medium, 
# is explicitly prohibited by law, and also violates UIC's Student 
# Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
# Participation in Academically Dishonest Activities: Material Distribution).

build:
	rm -f program.out
	g++ -std=c++20 -Wall 20230607_LiveSession12.cpp plant.cpp garden.cpp -o program.out

run:
	./program.out

clean:
	rm -f program.out	

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./program.out
