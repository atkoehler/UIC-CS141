build:
	rm -f game.out
	g++ -I includes -Wall -fconcepts -std=c++2a die.cpp utils.cpp game.cpp -o game.out

examples:
	rm -f examples.out
	g++ -I includes -Wall -fconcepts -std=c++2a die.cpp utils.cpp examples.cpp -o examples.out

run_game:
	clear;./game.out

run_examples:
	clear;./examples.out

clean:
	rm -f game.out
	rm -f examples.out
