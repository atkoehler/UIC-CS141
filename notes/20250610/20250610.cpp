/// @file 20250610.cpp
/// @author Adam T Koehler, PhD
/// @date June 10, 2025
/// @brief Code and lecture notes from the live session. 

#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Pre Quiz Welcome:
// Array -> Pointer Code Conversion (ArrayToPointerConversionExample)
//
// Post Quiz Activity:
// Benefits of a Linked List?
//
// Changing order is more "straightforward"
//
// Pointers to specific nodes such as the end and then modify
// causes broken list, dangling (bad) pointers
//
// Passing a linked list we always just pass a memory address to node (usually head)





/// @brief we can define a struct as our single 
///     linked list node data collection. We do not
///     need to use a struct, but in many cases it is
///     sufficient. Then the Class is the actual List class.
typedef struct NODE
{
    int data;
    NODE *nxt;
} NODE;

void ArrayToPointerConversionExample();
void LinkedListExamples();
void RecursiveExamples();
int recursiveSum(int);

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
                ArrayToPointerConversionExample();   
                break;

            case 2:
                LinkedListExamples();
                break;

            case 3:
                RecursiveExamples();
                break;
            
            default:
                break;
        }
    }
    else
    {
        // could not parse or did not find extra command line argument
        // therefore just run everything
        ArrayToPointerConversionExample();

        cout << endl << endl;
        LinkedListExamples();
        
        cout << endl << endl;  
        RecursiveExamples();  
        
    }    
    return 0;
}

void ArrayToPointerConversionExample()
{
    uint ssize = 5;
    char f[80] = "This string is larger";
    // char *f = first;
    // const char *f = "hi";
    const char *s = "hello";

    cout << "Before: " << endl;
    cout << f << endl;
    cout << s << endl;

    // Given array based code (convert as activity)
    for(size_t i = 0; i < ssize; ++i)
    {    
        f[i] = s[i];
    }
    f[ssize] = '\0';

    cout << "After: " << endl;
    cout << f << endl;
    cout << s << endl;

    cout << endl << endl;

    cout << "Before: " << endl;
    cout << f << endl;
    cout << s << endl;

    // Convert to Pointer Based Code
    // This example uses i as an offset from the 
    // starting address of the array similar to the
    // square bracket indexing
    const char *s2 = "help";
    ssize = 4;
    for(size_t i = 0; i < ssize; ++i)
    {        
        *(f+i) = *(s2+i);
    }
    *(f+ssize) = '\0';

    cout << "After: " << endl;
    cout << f << endl;
    cout << s << endl;

    cout << endl << endl;


    cout << "Before: " << endl;
    cout << f << endl;
    cout << s << endl;

    // Convert to Pointer Based Code
    // This example uses i as an offset from the 
    // starting address of the array similar to the
    // square bracket indexing
    // for(size_t i = 0; i < ssize; ++i)
    // {        
    //     // *f = *s;
    //     // f++;
    //     // s++;
    // }
    // *f = '\0';

    cout << "After: " << endl;
    cout << f << endl;
    cout << s << endl;

}


/// @brief work through various basic linked list examples
void LinkedListExamples()
{
    const int arraySize = 3;
    char arr[arraySize] = {0, 3, 5};

    int cur = 0;
    while(cur != arraySize)
    {
        int value = arr[cur];
        cout << value << endl;
        cur = cur + 1;
    }



    cout << "Linked List Version" << endl;
    // set up list such that head points to first element 
    // in linked list
    NODE *head;
    NODE *a = new NODE;
    a->data = 0;
    a->nxt = nullptr;
    head = a;

    NODE *b = new NODE;
    b->data = 3;
    b->nxt = nullptr;
    b->nxt = head;
    head = b;

    NODE *c = new NODE;
    c->data = 5;
    c->nxt = nullptr;
    c->nxt = head;
    head = c;


    NODE *curPtr = head;
    while (curPtr != nullptr)
    {
        cout << curPtr->data << endl;
        curPtr = curPtr->nxt;
    }
}
















// What ways could we use our Card class as a Linked list that isn't
// just convert the entire Deck class?
// What are some real world examples that could convert to a Linked List?
//
//
//
//Come up with a way that we could incorporate a Linked List of Cards
// into our Deck & Cards programs. What other ways do we need to collect
// a handful of cards beyond the Deck?
//
// Group Ideas:
// 1. Convert some part of Deck to use Linked Lists as interacting with
//    a Linked List has benefits, for example drawing from the top does
//    not require shifting all of the elements.
//
// 2. Store a portion of the cards such as dealing them out.
//    For example we created 5 piles of 5 cards for Go Fish!
//
// So dealing to create a "hand" for a player could create a 
// linked list per player!
//
// Go Fish!
// 5 players, each has a hand
// Write an algorithm using drawTop from our Deck class and a 
// function named insertFront to build a Linked List for hand for each
// player. We use insertFront because it is best if we only have a head 
// pointer and not both a head and tail.





/// @brief work through a basic recursive function call examples
void RecursiveExamples()
{
    cout << "Recursive Examples" << endl;
    cout << "==================" << endl;

    int n = 0;
    cout << "We will sum from 0 to N, what is N? ";
    cin >> n;
    cout << endl;
    cout << "Sum from 0 to " << n << " is: " << recursiveSum(n) << endl;

    // Recursive Function Call Chart
    // recursiveSum(3)
    //  3 + recursiveSum(2)
    //      2 + recursiveSum(1)
    //          1 + recursiveSum(0)
    //              recursiveSum(0) -> 0
}



/// @brief Sum the integer values from 0 through n
/// @param n The final value in the summation
/// @return the accumulated sum of all values from 0 to n
int recursiveSum(int n)
{
    // base case: we can calculate the sum of 0
    //            so we can return 0
    if(0 == n)
    {
        return 0;
    }

    // recursive case: we cannot intrinsically know the sum to N
    //                  so we use dynamic programming, specifically
    //                  recursion to solve a smaller subset of the 
    //                  problem and contribute our knowledge to that
    //                  summation, since we know the value of n
    return n + recursiveSum(n-1);
}
