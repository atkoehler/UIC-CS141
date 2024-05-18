/// @file 20240514_LiveSession1.cpp
/// @author Adam T Koehler, PhD
/// @date May 14, 2024
/// @brief Code and lecture notes from the live session. Introduction
///     to the basics of C++ through our first branch in C++.
///     C++ Concepts: libraries, std namespace, int main() {return 0;},
///                   thinking about variable types, values, and information,
///                   cin, cout, <<, >>, getline(), rand() and srand()
///                   terminal input redirection: ./a.out < in.txt
///                   string, .at() member function
///                   single if-else branch with basic comparison


// Order of the live code from lecture:
// This is the first program and as such it simply goes from line 1
// to the end of the file for the order. Order will jump around more
// when we start implementing functions.


// libraries to include, we always want to be specific
#include <iostream> // For console input and output
#include <string>   // This library is often silently included by others
#include <random>   // For rand() and random number generation


// We use std namespace to avoid having to type std:: before many 
// of the items we regularly use. As you program in C++ beyond academia
// you may be required to switch between namespaces and therefore would
// want to use the std:: that you may see in examples online on sites
// like C++ reference, Geeks for Geeks, or Stack Overflow.
using namespace std;


// All C++ executable programs require a main function
// Sometimes there will be arguments for main() to handle command line
// arguments, but our introductory C++ main functions do not use thsoe.

// In C++ main() will always return an integer, specifically 0 at the 
// end of the function to tell the system that invoked the program
// that the program ran successfully and executed with "OK" or 0.

int main()
{
    // Activity: Physical Item Characteristics & Assumptions
    // Identify characteristics of the contents of your box that contains
    // a "deck" of cards without opening the box. State any assumptions.
    
    // Activity Followup: How would you store the information
    // in a decipherable way that allows you to catalgoue the contents
    // of the box and distinguish between the individual cards?

    // Encodings and Mappings Volunteered by Groups
    
    // Group 1:
    // Identify a specific two character sequence for each card
    // then store every sequence into a string each separated by a space
    // e.g. "?B AH" is a 2-card deck with a Black Joker and Ace of Hearts
    
    // Issues?
    // Do we retain all the information with just AH?
    // Are we making it built in or innate knowledge that hearts are red?

    // Group 2:
    // Similar to first group but a 3 character sequence with B being black,
    // R being red, a character for each suit, and then letter or number
    // for each actual card.
    // e.g. "B-9 R+4" is a 2-card deck with a Black 9 of Spades and a 
    //      Red 4 of Clubs.

    // Issues?
    // We now have all the information, but are there any conflicts with
    // actual card values? 
    // How did you handle 10? 
    // How did you handle Joker versus Jack?
    // How about Joker not having a suit?

    // We all came up with similar characteristics but may have identified
    // them slightly different and depending on how we view the cards may
    // have created different encoding algorithms but we all achieved the 
    // same end goal of outlining how we could feasibly store the information.
    

    // If we ignore the duplicate nature of a deck of cards we can break 
    // it down to a core set of values. Each represeted by a character.
    // We will use ? for Joker and 0 for 10.
    // When we order them in a string, we could choose various orders or
    // just ordering them randomly. However, when placing Joker at the first
    // spot and Ace being a 1, our characters align in such a way that our
    // index values match the perceived card values in many card games.

    // string values = "?A234567890JQK";

    // poker is the exception, in that case A would be high and no Joker
    // string values = "234567890JQKA";



    // We will circle back to our decks of cards throughout the term and
    // later in this session, let's explore some more data types for now.

    // C++ Native / Built-in Data Types
    // numerical data types examples
    // short, int, long, float, double

    // non-numeric data types that are stored as numbers behind the scenes:
    // bool, char

    // Built-in types DO NOT get initialized, you have to set a value.

    
    // cout stands for console output
    // cin stands for console input
    // these are C++ streams for console interactions

    // Every character is actually a number behind the scenes based on
    // their ASCII value. You can look up the ASCII chart but we 
    // should not be using their numerical values or memorizing the chart.
    cout << "The ASCII value of " << 'A' << " is " << (int) 'A' << endl;    

    // We just did a C-style cast with that (int) converting the character
    // to an integer to make sure cout showed us a number.
    // We should use C++ casting not C-style casting
    cout << "The ASCII value of " << 'Q' << " is " << static_cast<int>('Q')
        << endl << endl;

    // We split stream output to multiple lines like the above.


    // There are two ways to output newlines
    // The actual newline character and endl
    cout << "Different ways to output a newline character" << endl;
    cout << "Using \\n" << '\n';
    cout << "Using \\n as part of string\n";
    cout << "Using endl" << endl;

    // endl is special because it forces your program to also flush
    // the stream/buffer and immediately output its contents. This means
    // that your output will be displayed before the program moves on.
    // This is very useful when attempting to visually debug and determine
    // where your program is crashing or why or similarly nefarious runtime
    // issues where you think your program is "stuck".

    // The input and output operators, >> and << are formally called
    // extraction and insertion operators as the extraction operator (>>)
    // extracts something from the stream and places into the variable 
    // that follows the arrows. Whereas the insertion operator (<<) places
    // a value into the stream.

    cout << "========================================================================";
    cout << endl << endl; 

    // Let's think about the various ways we can acquire input
    char character1, character2;
    string string1, string2;
    int integer1;

    cin >> character1;
    cin >> string1;
    getline(cin, string2);
    cin >> character2;
    cin >> integer1;

    cout << "character1 acquired with >> has value: " << character1 << endl;
    cout << "string1 acquired with >> has value: " << string1 << endl;
    cout << "string2 acquired with getline has value: " << string2 << endl;
    cout << "character2 acquired with >> has value: " << character2 << endl;
    cout << "integer1 acquired with >> has value: " << integer1 << endl;


    // We explored input redirection in the live lecture, so in the terminal
    // we utilized the < to say get this input from a file instead of getting
    // it from typed console input. This is how computers can execute your
    // programs, zyBooks does this to execute and test your programs.
    // ./a.out < in.txt 

    // Note that the data always flows with the arrows!


    cout << endl << endl;
    cout << "========================================================================";
    cout << endl << endl; 


    string values = "?A234567890JQK";
    char userE;

    // Acquire a user guess for which card is on the top of the deck
    cout << "Enter a guess: ";
    cin >> userE;
    cout << endl;

    // The random number generator will seed to 0 if srand isn't called,
    // but calling it explicitly increases readability that we are using
    // a single unchanging number as the seed value. This will then create
    // the same random number sequence every time we execute our program,
    // allowing predictability for demonstration and verification of 
    // program execution correctness.
    srand(100);

    int randIndex;

    // Until we sest a value, randIndex contains garbage
    // but we should not set a value using rand() and then not use
    // the initial value as that wastes a random number from the sequence
    // and in general we should not be "wasting" numbers by calling rand()
    // multiple times but never using one or more values acquired.
    randIndex = rand()  % values.size();

    // Output the correct answer to verify program's win/loss correctness
    cout << "You guessed: " << userE << endl;
    cout << "The answer is: " << (values.at(randIndex)) << endl;
    cout << endl;

    // When the user guesses the randomly selected value, the user wins!
    if (values.at(randIndex) == userE)
    {
        cout << "You win!" << endl;
    }
    else
    {
        cout << "You Lose :(" << endl;
    }

    // Acquire a user guess for which card is on the top of the deck
    cout << endl;
    cout << "Enter a guess: ";
    cin >> userE;
    cout << endl;

    // Output the correct answer to verify program's win/loss correctness
    cout << "You guessed: " << userE << endl;
    cout << "The answer is: " << (values.at(randIndex)) << endl;
    cout << endl;

    // When the user guesses the randomly selected value, the user wins!
    if (values.at(randIndex) == userE)
    {
        cout << "You win!" << endl;
    }
    else
    {
        cout << "You Lose :(" << endl;
    }

}




