/// @file 20260528_LiveSession7.cpp
/// @author Adam T Koehler, PhD
/// @date June 2, 2026
/// @brief Code and lecture notes from the live session. Requires -std=c++20
///         Example compilation command: 
///             g++ -std=c++20 20260602_LiveSession7.cpp 

#include <iostream>
#include <string>
#include <vector>
#include "card.h"

using namespace std;


// deep copy goes through and creates an entire duplicate
// int arr[5]; int arr2[5]; all elements are the same
// shallow copy int arr[5]; int *arr2 = arr;

/// @brief determine if a character ('f') exists using null terminated 
///         C-string (char array)
/// @param arr the c-string
/// @return true when the character is discovered, otherwise false
bool charExists(const char arr[], char);


/// @brief determine if a character ('f') exists using null terminated 
///         C-string (char array)
/// @param arr the C-string to search
/// @param c the character to search for
/// @param location the location variable to update upon discovery
/// @post location variable is untouched when the character is not found
/// @return true when the character is discovered, otherwise false
bool charExists(char *arr, char, size_t &);



/// @brief main function for running our examples
/// @param argc the number of command line arguments
/// @param argv the array containing c-strings of command line args
int main(int argc, char *argv[])
{
    // no second command line argument, run all examples
    if (argc > 1 && isdigit(argv[1][0]))
    {       
        char str1[] = "hfllo";
        char str2[] = "hello";
        size_t loc = -1;
        switch(atoi(argv[1]))
        {
            case 1:
                cout << "Raw Return: " << charExists(str1, 'f') << endl;
                cout << "Raw Return: " << charExists(str2, 'f') << endl;
                
                if(charExists(str1, 'f', loc))
                {
                    cout << "Discovered at index " << loc << " in " << str1;
                }
                else
                {
                    cout << "Not discoverered in " << str1;
                }
                cout << endl;

                if(charExists(str2, 'f', loc))
                {
                    cout << "Discovered at index " << loc << " in " << str2;
                }
                else
                {
                    cout << "Not discoverered in " << str2;
                }
                cout << endl;
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

// Similar to when we pass by reference we have to decide const or not
// A pointer contains a memory address, so when we do not specificy const
// then we may modify the contents at the memory address the pointer points to

/// @brief determine if a character ('f') exists using null terminated 
///         C-string (char array)
/// @param arr the C-string to search
/// @param c the character to search for
/// @param location the location variable to update upon discovery
/// @post location variable is untouched when the character is not found
/// @return true when the character is discovered, otherwise false
bool charExists(char *arr, char c, size_t &location)
{
    char *start = arr;
    while('\0' != *arr)
    {
        if (c == *arr)
        {
            location = arr - start;
            return true;
        }
        arr++;
    }

    return false;
}