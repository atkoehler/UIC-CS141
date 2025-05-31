/// @file 20250610.cpp
/// @author Adam T Koehler, PhD
/// @date June 10, 2025
/// @brief Code and lecture notes from the live session. 

#include <iostream>
#include <string>
#include <vector>
#include "card.h"

using namespace std;

void Examples1();
void Examples2();
void Examples3();

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

            case 3:
                Examples3();
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
        
        cout << endl << endl;  
        Examples3();  
        
    }    
    return 0;
}
