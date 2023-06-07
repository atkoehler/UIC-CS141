build:
	rm -f program.out
	g++ -std=c++20 -Wall main.cpp plant.cpp garden.cpp -o program.out

run:
	./program.out

clean:
	rm -f program.out	

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./program.out
