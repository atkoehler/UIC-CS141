/// @file 20250604.cpp
/// @author Adam T Koehler, PhD
/// @date June 4, 2025
/// @brief Code and lecture notes from the live session. 

#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include "deck.h"

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


void Examples1()
{
    char a[6] = "hello";
    char b[81] = "hello world";
    char c[81] = "hello my name is";
    char d[81] = "hello\nworld";

    // Note the counts are the quantity of characters NOT the array sizes

}

void Examples2()
{
    Card A("Jack", "Spades", false);
    Card B("Jack", "Hearts", true);
    Card C("King", "Spades", false);



    if (A > B)
    {
        cout << "A is larger than B" << endl;
    }
    else
    {
        cout << "A is not larger than B" << endl;
    }

    if (A > C)
    {
        cout << "A is larger than C" << endl;
    }
    else
    {
        cout << "A is not larger than C" << endl;
    }

}

void Examples3()
{

}



// Similar to when we pass by reference we have to decide const or not
// A pointer contains a memory address, so when we do not specificy const
// then we may modify the contents at the memory address the pointer points to
// size_t countbyPtr(const char *cPtr)


/// @brief Count the quantity of characters that exist in provided C-string
/// @param cArr C-string to start counting from
/// @return the quantity of characters counted
int countC(const char str[])
{
    int sum = 0;
    int index = 0;

    sum = 0;
    while(str[index] != '\0')
    {
        sum++;
        index++;
    }

    sum = 0;
    for(index=0; str[index] != '\0'; index++)
    { 
        sum++;
    }

    // index = 0;
    // while(str[index] != '\0')
    // {
    //     index++;
    // }
    // return index;

    // index = 0;
    // while(str[index++] != '\0');
    // return index;

    return sum;
}



/// @brief Count the quantity of characters that exist in provided C-string
///     Use pointer dereferencing and pointer parameter for this version
/// @param cPtr pointer to address in a C-string to start counting from
/// @return the quantity of characters counted
int countC_PtrParam(const char *str)
{
    int sum = 0;
    int index = 0;

    sum = 0;
    while(str[index] != '\0')
    {
        sum++;
        index++;
    }

    return sum;
}


/// @brief Count the quantity of characters that exist in provided C-string
///     Use pointer dereferencing and pointer parameter for this version
///     Also use pointer math, not a counter, to calculate the difference
///     in memory addresses to calculate the quantity of characters.
/// @param cPtr pointer to address in a C-string to start counting from
/// @return the quantity of characters counted
int countC_PtrParam(char *start)
{
    char *stop = start;

    // *loopVar - we get the character at that memory address
    while(*stop != '\0')
    {
        stop++; 
        // move 1 sizeof() type of pointer further in memory    
    }


    // int length = (stop - start) / sizeof(char);
    // length = (stop - start) / 1

    return stop - start;
}