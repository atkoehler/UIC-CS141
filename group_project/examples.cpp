/// @file die.cpp
/// @author Adam T Koehler, PhD
/// @date May 27, 2025
/// @brief Usage examples of the Die class, system pause, and using escape
///         codes for terminal clearing and terminal coloring.

#include <iostream>
#include <vector>

#include "die.h"

using namespace std;

// Externally defined project utility functions
extern void clearScreen();
extern void pause(float scale=1);
extern void resetColors();
extern void setBlueBackground();
extern void setGreenBackground();
extern void setRedBackground();
extern void setWhiteBackground();


/// @brief simple animation example without using loops using 
///      the externally defined pause and clearScreen functions
/// @pre use extern (above) to note the externally defined functions from utils.cpp
void animationWithColorExample()
{
    // could use a vector and loop to do this, could also use file IO instead of 
    // hard coding the strings into the program.

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
    pause(3.5);

    clearScreen();
    setGreenBackground();
    cout << third << endl;
    resetColors();
    pause(2.5);

    clearScreen();
    setWhiteBackground();
    cout << fourth << endl;
    resetColors();
    pause(1.5);

    clearScreen();
    setRedBackground();
    cout << fifth << endl;
    resetColors();
    pause();
}


/// @brief various Die class examples
void dieExamples()
{
    // Die Class Usage
    cout << endl << "Using the die class one pbject at a time..." << endl;
    Die one;
    Die two;

    // roll each die ten times and output the new values
    for (int i = 0; i < 10; ++i)
    {
        one.roll();
        two.roll();
        cout << "Current Die 1 Value: " << one.getValue() << endl;
        cout << "Current Die 2 Value: " << two.getValue() << endl;
    }

    // Print all the rolls for the "one" die.
    cout << endl << "All rolled values of the \"one\" die: " << endl;
    cout << one.allValues_toString() << endl;

    // Print all the rolls for the "two" die.
    cout << endl << "All rolled values of the \"two\" die: " << endl;
    cout << two.allValues_toString() << endl;
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
