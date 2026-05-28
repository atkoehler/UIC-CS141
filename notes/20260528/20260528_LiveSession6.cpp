/// @file 20260528_LiveSession6.cpp
/// @author Adam T Koehler, PhD
/// @date May 28, 2026
/// @brief Code and lecture notes from the live session. Requires -std=c++20
///         Example compilation command: 
///             g++ -std=c++20 20260528_LiveSession6.cpp 

#include <iostream>
#include <string>
#include <vector>

#include "card.h"

using namespace std;


// Independent example functions to rotate "main" functions based on provided
// command line argument value.
void faroShuffleExample();
void cardComparisonAndToString();

string faroShuffle(const string &);



/// @brief main function for running our examples
/// @param argc the number of command line arguments
/// @param argv the array containing c-strings of command line args
int main(int argc, char *argv[])
{
    // no second command line argument, run all examples
    if (argc > 1 && isdigit(argv[1][0]))
    {       
        switch(atoi(argv[1]))
        {
            case 1:
                faroShuffleExample();
                break;

            case 2:
                cardComparisonAndToString();
                break;
            
            default:
                break;
        }
    }
    else
    {
        // could not parse or did not find extra command line argument
        // therefore just run everything
        faroShuffleExample();

        cout << endl << endl;
        cardComparisonAndToString();        
    }    
    return 0;
}



void faroShuffleExample()
{
    string values;
    
    // even string length test case
    values = "A1234567890JQK";
    cout << "Even Length" << endl;
    cout << "Before: " << values << endl;
    values = faroShuffle(values);
    cout << "After:  " << values << endl;

    // odd string length test case
    values = "A1234567890JQ";
    cout << "Odd Length" << endl;
    cout << "Before: " << values << endl;
    values = faroShuffle(values);
    cout << "After:  " << values << endl;
}

/// @brief Perform an interleaving shuffling of two halves of the whole 
///         Thus fitting one letter ("card") from the second half in
///         between each letter of the first half.
/// @param s string to generate a shuffled string from
/// @return the shuffled string
string faroShuffle(const string &s)
{
    string shuffled;
    int start = 0;
    int halfway = 0;

    // // demonstration of using substring function if we needed it
    // string fhalf = s.substr(0, s.size() / 2);

    // // Algorithm Implementation Version 1
    // for(start = 0, halfway = s.size() / 2; 
    //     start < s.size() / 2 && halfway < s.size(); 
    //     ++start, ++halfway)
    // {
    //     shuffled = shuffled + s.at(start) + s.at(halfway);
    // }

    // // determine if the string is odd sized
    // if (s.size() > 0 && 0 != s.size()%2)
    // {
    //     // add last character that is leftover
    //     shuffled = shuffled + s.back();
    // }


    // Algorithm Implementation Version 2
    halfway = s.size() / 2;

    for(start = 0; start < halfway; ++start)
    {
        shuffled = shuffled + s.at(start) + s.at(start+halfway);
    }

    // determine if the string is odd sized
    if (s.size() > 0 && 0 != s.size()%2)
    {
        // add last character that is leftover
        shuffled = shuffled + s.back();
    }

    return shuffled;
}



void cardComparisonAndToString()
{
    // Many different things have to_string functions
    // It has become standard for objects to have a function to "stringify"
    // the object into a either a more human readable or more parseable format.

    // From that to_string concept certain native types also gained the
    // capability of being easily converted to 
    int x = 5;
    cout << "We are going to combine some strings with the "
        << "to_string of x which is " << x << endl;
    
    string concatenate = "Hi " + to_string(x) + "!";
    cout << concatenate << endl;


    cout << endl << endl;

    
    cout << "Now let's apply our to_string to cards by constructing several."
        << endl;

    // Create stack-allocated Card objects
    Card A("Jack", "Hearts", true);
    Card B("Jack", "Hearts", true);
    Card C("Jack", "Spades", false);
    Card D("Jack", "Diamonds", true);
    Card E("Two", "Diamonds", true);

    cout << "Card A: " << A.to_string() << endl;
    cout << "Card B: " << B.to_string() << endl;
    cout << "Card C: " << C.to_string() << endl;
    cout << "Card D: " << D.to_string() << endl;
    cout << "Card E: " << E.to_string() << endl;

    cout << endl << endl;
    cout << "Once we overload operator== we can now compare cards directly!"
        << endl;
    
    // Different variations of == and != card comparisons
    cout << "Comparing A == C: ";
    if (A == C)
    {
        cout << "same card!" << endl;
    }
    else
    {
        cout << "different card!" << endl;
    }

    
    cout << "Comparing A == B: ";
    if (A == B)
    {
        cout << "same card!" << endl;
    }
    else
    {
        cout << "different card!" << endl;
    }

    cout << endl << endl;
    cout << "We also inverted our operator== to easily add operator!=" << endl;

    cout << "Comparing A != D: ";
    if (A != D)
    {
        cout << "They are not equal." << endl;
    }
    else
    {
        cout << "They are equal!" << endl;
    }
}