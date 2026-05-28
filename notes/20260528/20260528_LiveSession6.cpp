/// @file 20260528_LiveSession6.cpp
/// @author Adam T Koehler, PhD
/// @date May 28, 2026
/// @brief Code and lecture notes from the live session. Requires -std=c++20
///         Example compilation command: 
///             g++ -std=c++20 20260528_LiveSession6.cpp 

#include <iostream>
#include <string>
#include <vector>

using namespace std;


// Independent example functions to rotate "main" functions based on provided
// command line argument value.
void Examples1();
void Examples2();


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
                Examples1();
                break;

            case 2:
                Examples2();
                break;
            
            default:
                break;
        }
    }
    else
    {
        // could not parse or did not find extra command line argument
        // therefore just run everything
        Examples1();

        cout << endl << endl;
        Examples2();        
    }    
    return 0;
}



void Examples1()
{
}


void Examples2()
{
}