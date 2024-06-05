/// @file 20240605_LiveSession11.cpp
/// @author Adam T Koehler, PhD
/// @date June 5, 2024
/// @brief Code and lecture notes from the live session. 
///     Topics Covered: Class Declarations, Code Traversal, and Recursion.

// Order of the live code from lecture:
// 1. Welcome Activity - Class Declaration person.h
// 2. Double includes of person.h
// 3. Class Exercise - Infinite Recursion with fun(2)
// 4. RecursiveExamples()


// Welcome Activity:
// Discuss with your group a Person class. 
// Your task at this time is to write the header file on the front of your
// paper as a group. This will not contain the implementations, only the
// declaration. 
//
// Write the declaration such that it meets at least the 
// following requirements: 
// 1. multiple data members
// 2. at least one constructor
// 3. a member function and a helper function
//
// Code developed in the person.h header file.
#include "20240605_person.h"

// When person.h does not use proper directives or the more 
// contemporary #pragma once the double include will cause errors.
#include "20240605_person.h"


// only include the libraries relevant to this file
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Lecture Parts Prototypes
void RecursiveExamples();
void InfiniteRecursion();


// Each of the recursive implementations corresponds to one of the three 
// potential recursive functions groups were asked to implement as a 
// lecture ativity on June 6, 2024.
// The lecture activity can be found at:
// https://drive.google.com/file/d/1LcIvpZTe67iq5h-rm_BimicC93l-egEj/preview

// Recursive Implementation Prototypes
int acquireInput();
int count(const vector<int> &v, int);
void cntRecursive(const vector<int> &v, int lookFor, 
    int &counter, int startLoc);
int sumFrom(int m, int n);


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
                RecursiveExamples();   
                break;
            case 1:
                InfiniteRecursion();   
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
    }

    return 0;
}



/// @brief live code developed for the recursion portion 
///     of the live lecture
void RecursiveExamples()
{
    cout << "Recursive Examples" << endl;
    cout << "==================" << endl << endl;

    // Recursive impelementation of acquiring a valid input
    // Valid input is 0-100 inclusive
    cout << "Recursively Acquiring Input" << endl;
    cout << "===========================" << endl;
    int value = acquireInput();
    cout << "You entered: " << value << endl;
    cout << endl;

    cout << endl;
    // Recursive impelementation of counting the quantity of a 
    // specified element discovered in a given vector
    cout << "Recursively Counting Matches in a Vector" << endl;
    cout << "========================================" << endl;
    vector<int> a = {1, 2, 3, 4, 3, 3};
    vector<int> b = {1, 2, 3, 4, 2, 7};
    vector<int> c;
    cout << "Calling count(a, 3) where a is {1, 2, 3, 4, 3, 3}" << endl;
    cout << "Quantity counted: " << count(a, 3) << endl << endl;
    cout << "Calling count(b, 2) where b is {1, 2, 3, 4, 2, 7}" << endl;
    cout << "Quantity counted: " << count(b, 2) << endl << endl;
    cout << "Calling count(a, 9) where a is {1, 2, 3, 4, 3, 3}" << endl;
    cout << "Quantity counted: " << count(a, 9) << endl << endl;
    cout << "Calling count(c, 5) where c is {}" << endl;
    cout << "Quantity counted: " << count(c, 5) << endl << endl;

    cout << endl;
    // Recursive impelementation of summing the values from M through N,
    // where M is less than or equal to N.
    cout << "Recursively Summing Values from M to N, Inclusive" << endl;
    cout << "=================================================" << endl;
    cout << "The sum from 1 through 3 is: " << sumFrom(1, 3) << endl;
    cout << "The sum from 1 through 6 is: " << sumFrom(1, 6) << endl;
    cout << "The sum from 2 through 6 is: " << sumFrom(2, 6) << endl;
    cout << "The sum from 1 through 1 is: " << sumFrom(1, 1) << endl;
}


/// @brief Function used for paper code traversal due to "infinite" recursion
/// @param n the initial value for our recursive calculation
/// @return the product calculated recursively
int fun(int n) 
{
    // Add some output to mimic activity performed on paper
    cout << "fun(" << n << ")" << endl;

    // Base Case: The absolute value of parameter exceeds or is equal to 5
    if (abs(n) >= 5)
    {
        return 0;
    }

    // Calcualte the product recursively that attempts to move
    // current value towards either postive or negative 5 base case.
    return fun(n+1) * fun(n-1); 
}

void InfiniteRecursion()
{
    cout << "Infinite Recursion Lecture Example" << endl;
    cout << "==================================" << endl << endl;
    cout << "Calling fun(2)..." << endl;
    cout << "The result of fun(2) is " << fun(2) << endl;
}



/// @brief Recursively acquire inputs until a valid input is acquired.
/// @return a valid integer input that is between 0 and 100, inclusive
int acquireInput()
{
    // Goal: recursively gather a valid input 0-100, inclusive
    // Algorithm:
    //  1. acquire an input from the user
    //  2. check if valid input, 0-100 inclusive
    //     a. return valid input
    //  3. recurse on function to attempt another acquisition
    
    int value;
    cout << "Enter a value between 0 and 100, inclusive: ";
    cin >> value;
    cout << endl;

    // Base Case: Is the value a valid input? If so, return it.
    if (value >= 0 && value <= 100)
    {
        return value;
    }

    // Recursive Case: Acquire another value
    return acquireInput();
}


/// @brief Count the matches to the supplied value within the vector.
/// @param v vector to search
/// @param look element value to look for
/// @return the quantity of elements within the vector that matched
int count(const vector<int> &v, int look)
{   
    // Our recursive algorithm updates a variable by reference.
    int counter = 0;

    // Call the recursive function by giving starter values
    // that the user of count does not need to be concerned with
    // and therefore did not specify.
    cntRecursive(v, look, counter, 0);

    // Once the recusrive algorithm is complete, counter will 
    // have the proper value in it.
    return counter;
}

/// @brief Recursive implementing of counting matches invoked by the 
///     more user friendly count function with starter arguments.
/// @param v vector to search
/// @param look element value to look for
/// @param counter counter to update, passed by reference
/// @param location the current index in the vector to compare to
void cntRecursive(const vector<int> &v, int look, int &counter, int location)
{
    // Base Case: Location has reached beyond the end of the vector
    if(v.size() == location)
    {
        return;
    }
    
    // Update the counter when current element is a match
    if (v.at(location) == look)
    {
        counter++;
    }

    // Recursive Case: Keep counting starting at the next index
    cntRecursive(v, look, counter, location+1);
}


/// @brief Recursively calculate the sum of all the values from m through n.
/// @param m the starting value
/// @param n the last value to sum
/// @return the sum of all values from m through n, e.g. 1,3 is 6
int sumFrom(int m, int n)
{
    // Base Case: m and n are equivalent
    // When m has reached n there is no smaller problem
    // and we know our answer without further calculations.
    if (m == n)
    {
        return n;
    }

    // Recursive Case: 
    //  Calculate the sum of a smaller subset of numbers. 
    //  Effectively solving a smaller problem and moving m towards n.
    //  When we have the result from the smaller problem, add the 
    //  current value (m) and return the sum.
    return sumFrom(m+1, n) + m;
}