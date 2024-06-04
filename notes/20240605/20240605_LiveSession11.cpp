/// @file 20240605_LiveSession11.cpp
/// @author Adam T Koehler, PhD
/// @date June 5, 2024
/// @brief Code and lecture notes from the live session. 
///     Topics Covered: Code Traversal, Recursion, Linked Lists.



// only include the libraries relevante to this file
#include <iostream>
#include <string>

using namespace std;



// Lecture Parts Prototypes
void RecursiveExamples();
void LinkedListExamples();

// Recursive Function Prototypes




/// @brief main function for running our examples
/// @param argc the number of command line arguments
/// @param argv the array containing c-strings of command line args
int main(int argc, char *argv[])
{
    // 0 on command line runs recursion examples   
    // 1 on command line runs linked list examples
    // no second command line argument, run both
    if (argc > 1 && isdigit(argv[1][0]))
    {       
        switch(atoi(argv[1]))
        {
            case 0:
                RecursiveExamples();   
                break;

            case 1:
                LinkedListExamples();
                break;
            
            default:
                break;
        }
    }
    else
    {
        // could not parse or did not find extra command line argument
        // therefore just run everything
        RecursiveExamples();  
        cout << endl << endl;
        LinkedListExamples();  
    }

    return 0;
}



/// @brief live code developed for the recursion portion 
///     of the live lecture
void RecursiveExamples()
{
    cout << "Recursive Examples" << endl;
    cout << "==================" << endl << endl;
}



/// @brief live code developed for the linked lists portion 
///     of the live lecture
void LinkedListExamples()
{
    cout << "Linked Lists Examples" << endl;
    cout << "=====================" << endl << endl;
}


