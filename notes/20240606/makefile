#  @file makefile
#  @author Adam T Koehler, PhD
#  @date June 6, 2024
#  @brief Basic makefile to introduce the concept for next term

# makefile basics
# tab characters are used not spaces
# targets can be invoked by specifying the name such as make clean
# more to come in future courses!

build:
	rm -f prog.out
	g++ -Wall -std=c++20 20240606_LiveSession12.cpp 20240606_card.cpp -o prog.out

run:
	./prog.out

clean:
	rm -f prog.out

valgrind:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes  ./prog.out
