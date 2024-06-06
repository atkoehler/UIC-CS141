/// @file 20240606_LiveSession12.cpp
/// @author Adam T Koehler, PhD
/// @date June 6, 2024
/// @brief Code and lecture notes from the live session. 
///     Topics Covered: Randomness, sort(), Class Design Strategies

// Order of the live code from lecture:



// only include the libraries relevant to this file
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "20240606_card.h"

using namespace std;

// Lecture Parts Prototypes
void ClassesObjectsExamples();
void sortCallExamples();
void RandomnessExamples();



/// @brief main function for running our examples
/// @param argc the number of command line arguments
/// @param argv the array containing c-strings of command line args
int main(int argc, char *argv[])
{
    // 0 on command line runs recursion examples   
    // no second command line argument, run everything
    if (argc > 1 && isdigit(argv[1][0]))
    {       
        switch(atoi(argv[1]))
        {
            case 0:
                ClassesObjectsExamples();   
                break;
            case 1:
                sortCallExamples();
                break;
            case 2:
                RandomnessExamples();
                break;                
            default:
                break;
        }
    }
    else
    {
        // could not parse or did not find extra command line argument
        // therefore just run everything
        ClassesObjectsExamples();  
        cout << endl << endl;
        sortCallExamples();
        cout << endl << endl;
        RandomnessExamples();        
    }

    return 0;
}



/// @brief live code developed for the Classes & Objects portion 
///     of the live lecture
void ClassesObjectsExamples()
{
    cout << "Classes & Objects Examples" << endl;
    cout << "==========================" << endl << endl;

    cout << "operator!=" << endl;
    cout << "==========" << endl;
    cout << endl;

    cout << "operator<" << endl;
    cout << "==========" << endl;
    cout << endl;
}


/// @brief live code developed for the Classes & Objects portion 
///     of the live lecture
void sortCallExamples()
{
    cout << "Algorithm's sort()" << endl;
    cout << "==================" << endl << endl;
}

/// @brief live code developed for the true randomness portion
///     of the live lecture
void RandomnessExamples()
{
    cout << "True Randomness Examples" << endl;
    cout << "========================" << endl << endl;
}
