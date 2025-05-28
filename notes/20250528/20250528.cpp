/// @file 20250528.cpp
/// @author Adam T Koehler, PhD
/// @date May 28, 2025
/// @brief Code and lecture notes from the live session. 
///     Lecture covered 2D arrays, 2D vectors, and classes.

#include <iostream>
#include <random>
#include <vector>
#include "card.h"

using namespace std;


/// @brief Build a two-dimensional vector row by row. Filling it with values
///         from the provided one-dimensional array.
/// @param v The vector to build.
/// @param size The size of the array containing all the initial values.
/// @param arr The array with all the intial values.
void fillVector(vector<vector<int>> &v, int size, int arr[])
{
    // build a row
    // place that row into the 2D vector

    for(int i = 0; i < 3; ++i)
    {
        vector<int> row;
        for (int j=0; j < 5; ++j)
        {
            // row_num * col_total + current_col
            int index = i * 5 + j;
            row.push_back(arr[index]);
        }
        v.push_back(row);
    }

}


int main()
{
    // Use the default constructor (no parameters)
    Card A; // Card A();
    cout << "card A: " << A.getFaceValue() << endl;
    cout << endl;
    cout << "Card A: " << A.to_string() << endl;
    cout << endl;

    // Use the fully parameterized constructor
    Card B("Jack", "Hearts", true);
    cout << "card B: " << B.getFaceValue() << endl;
    cout << endl;
    cout << "Card B: " << B.to_string() << endl;
    cout << endl;


    // declare an array, we often pass around the size of an array
    // so making a constant allows us to use the constant name instead
    // of hardcoding a value.
    const int ARRAY_SIZE = 15;
    int myA[ARRAY_SIZE];

    // Show the values of the array prior to assignment.
    for(uint i = 0; i < ARRAY_SIZE; ++i)
    {
        cout << myA[i] << ' ';
    }
    cout << endl;

    
    // fill the array with random values from 32 through 50
    for(uint i = 0; i < ARRAY_SIZE; ++i)
    {
        myA[i] =  32 + rand()%(50-32+1); // 19
        
        // Question: Could we do 32 + rand%18 + 1
        // Answer: No, let's explore the math:
        //   32 + [0,17] + 1 ==> 33 + [0,17] ==> [33,50] which is not [32,50]
    }

    cout << endl << endl;

    // Show the values of the array after to assignment.
    for(uint i = 0; i < ARRAY_SIZE; ++i)
    {
        cout << myA[i] << ' ';
    }
    cout << endl;


    // Create a 1D vector in similar way to the array.
    vector<int> myV1D(ARRAY_SIZE);

    cout << endl << endl;

    // Show the values of the vector after declaration.
    // They are initialized!
    for(uint i = 0; i < myV1D.size(); ++i)
    {
        cout << myV1D.at(i) << ' ';

        // We could use square bracket access method, but
        // then we do not have bounds checking.
        // Try to loop to 10000000, and it will likely cause
        // a segmentation fault due to accessing memory that is 
        // not accessible to the program.
        // cout << myV1D[i] << ' ';
    }
    cout << endl;

    // Create an empty two-dimensional array
    // This is just a vector of vectors
    // Space added around angle brackets for emphasis but are not required.
    vector< vector<int> > myV;

    // Fill the 2D vector in a 3x5 configuration with the arrays values.
    fillVector(myV, ARRAY_SIZE, myA);

    cout << endl << endl;

    // Show the values of the vector after setting them.
    for(int i = 0; i < 3; ++i)
    {
        for (int j=0; j < 5; ++j)
        {    
            cout << myV.at(i).at(j) << ' ';
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
