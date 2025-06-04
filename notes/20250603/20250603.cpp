/// @file 20250603.cpp
/// @author Adam T Koehler, PhD
/// @date June 3, 2025
/// @brief Code and lecture notes from the live session. 

#include <iostream>
#include <string>
#include <vector>
#include "card.h"

// using namespace std;
// ...(const Deck &other)
// {
//     other.getDeck

//     >=
// }

// deep copy goes through and creates an entire duplicate
// int arr[5]; int arr2[5]; all elements are the same
// shallow copy int arr[5]; int *arr2 = arr;

/// @brief determine if a character ('f') exists using null terminated 
///         C-string (char array)
/// @param arr the c-string
/// @return true when the character is discovered, otherwise false
bool charExists(const char arr[], char);


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
                cout << charExists("hfllo", 'f') << endl;
                cout << charExists("hello", 'f') << endl;
                break;

            default:
                break;
        }
    }
    else
    {
        // could not parse or did not find extra command line argument
        // therefore just run everything
        cout << charExists("hello", 'f') << endl;
    }    
    
    return 0;
}



/// @brief determine if a character ('f') exists using null terminated 
///         C-string (char array)
/// @param arr the c-string
/// @return true when the character is discovered, otherwise false
bool charExists(const char arr[], char c)
{
    int index = 0;
    while('\0' != arr[index])
    {
        if (c == arr[index])
        {
            return true;
        }
        ++index;
    }

    return false;
}
