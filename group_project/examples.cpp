/// @file examples.cpp
/// @author Adam T Koehler, PhD
/// @date May 27, 2026
/// @brief Usage examples of the Die class, system pause, and using escape
///         codes for terminal clearing and terminal coloring.
///         Requires -std=c++20

#include <iostream>
#include <string>
#include <vector>

#include "die.h"
#include "utilities.h"

using namespace std;

/// @brief simple animation example without using loops using 
///      the externally defined pause and clearScreen functions
/// @pre use extern (above) to note the externally defined functions from utils.cpp
void animationWithColorExample()
{
    // could use a vector and loop to do this, could also use file IO for
    // each frame instead of hard coding the strings into the program.

    string first  = "         Hello\n";
    string second = "         Hello, how\n";
    string third  = "         Hello, how are\n";
    string fourth = "         Hello, how are you\n";
    string fifth =  "         Hello, how are you?\n";

    clearScreen();
    cout << first << endl;
    pause(15.5);

    // if the terminal coloring gets messed up and stays that way after your 
    // program completed, you can use "reset" to reset the terminal environment
    clearScreen();
    setBlueBackground();
    cout << second << endl;
    resetColors();
    pause(7.5);

    clearScreen();
    setGreenBackground();
    cout << third << endl;
    resetColors();
    pause(7.5);

    clearScreen();
    setWhiteBackground();
    cout << fourth << endl;
    resetColors();
    pause(5.5);

    clearScreen();
    setRedBackground();
    cout << fifth << endl;
    resetColors();
    pause();
}


/// @brief various Die class examples
void dieExamples()
{
    cout << endl << "Using the die class one pbject at a time..." << endl;
    Die one;
    Die two;
    for (int i = 0; i < 10; ++i)
    {
        one.roll();
        two.roll();
        cout << "Current Die 1 Value: " << one.getValue() << endl;
        cout << "Current Die 2 Value: " << two.getValue() << endl;
    }
  

    // Instead call the publicly accessible function to print all the rolls.
    cout << "All rolled values of the \"one\" die: " << endl;
    cout << one.allValues_toString() << endl;



    // Create a collection of 3 dice and roll!
    cout << endl << "Collection of Dice" << endl 
        << "==================" << endl;

    vector<Die> dice(3);
    for (int i = 0; i < 10; ++i)
    {
        cout << "Loop iteration " << i << ":" << endl;

        // roll every die in the vector
        for(auto& indivDie : dice)
        {
            indivDie.roll();
        }
        
        // iterate over the vector of individual dice and output current values
        for (size_t j = 0; j < dice.size(); ++j)
        {
            cout << "Current Die " << j << " Value: " << dice.at(j).getValue()
                << endl;
        }

        cout << endl;
    }
}


/// @brief simple main program with a menu to choose which examples to run
int main()
{
    int choice;

    // Which example to run?
    cout << "1. Die Examples" << endl;
    cout << "2. Pause and Clear Example" << endl;
    cout << "Choose example to run: ";
    cin >> choice;
    cout << endl;

    // execute examples based on user choice
    switch(choice)
    {
        case 1:
            dieExamples();
            break;

        case 2:
            animationWithColorExample();
            break;

        default:
            cout << "No examples for that choice." << endl;
    }

    return 0;
}
