/// @file 20260609_LiveSession10.cpp
/// @author Adam T Koehler, PhD
/// @date June 9, 2026
/// @brief Code and lecture notes from the live session. Requires -std=c++20
///         Example compilation command: 
///             g++ -std=c++20 20260609_LiveSession10.cpp 

#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"

using namespace std;

void ArrayToPointerConversionExample();
void LinkedListExamples();
void RecursiveExamples();
int recursiveSum(int);
int func(int);



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
//
//
// Whiteboard Task
// Recursive Algorithm Development, Code Implementation, and Testing
// Step 0 - Split whiteboard in half, then left side in half.
// Step 1 - On the top left side of your whiteboard
// Write a recursive algorithm that computes the sum of the first N numbers given N (first N being 0 through N inclusive)
// Step 2 - On the right side of your whiteboard
// Implement your algorithm in C++
// Step 3 - On the bottom left side
// Write at least two testing scenarios to demonstrate 
// your code's correctness.


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

}

/// @brief work through a basic recursive function call examples
/// @brief work through a basic recursive function call examples
void RecursiveExamples()
{
    cout << "Recursive Examples" << endl;
    cout << "==================" << endl;

    // This call will cause "infinite" recursion.
    // func(2);

    // Recursive Function Call Chart
    // func(2)
    //  func(n+1) * func(n-1)
    //   func(3) returns 0
    //   func(1)
    //    func(n+1) * func(n-1)
    //    func(2)
    //     func(n+1) * func(n-1)
    //     func(3) returns 0
    //     func(1)
    //      func(n+1) * func(n-1)
    //      func(2)
    //      ... continue until out of memory

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
    // base case: we intrinsically know or can calculate the sum of 0
    //            so we can return 0 as a base case
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


// algorithm implementation encapsulates (hides) whether the search
// is linear (iterative) or binary (recursive)
// uint search(card c)
// {

//     // linear?

//     // binary search?
//     // sorted?

//     if(sorted)
//     {
//         binarySearch(start, end, c)
//         start, mid-1
//     }
//     else
//     {
//         linear(c)
//     }

// }


int func(int n) 
{
   // output "func(n)" to screen
   if (abs(n) >= 3)
   {
      return 0;
   }
   return func(n+1) * func(n-1);     
}





/// @brief we can define a struct as our single 
///     linked list node data collection. We do not
///     need to use a struct, but in many cases it is
///     sufficient. Then the Class is the actual List class.
struct NODE
{
    int data;
    NODE *nxt;
};

void print(NODE* cur)
{
    // base case
    if (cur->nxt == nullptr)
    {
        cout << cur->data << endl;
    }
    // recursive case/step
    else
    {
        print(cur->nxt);
        cout << cur->data << endl;
    }
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
    cout << endl << endl;
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

    cout << endl << endl;
    cout << "Recursive: " << endl;
    print(head);
}