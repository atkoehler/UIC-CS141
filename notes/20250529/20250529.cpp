/// @file 20250529.cpp
/// @author Adam T Koehler, PhD
/// @date May 29, 2025
/// @brief Code and lecture notes from the live session. 
///     Lecture File IO, Faro Shuffle (string based), and classes.

#include <iostream>
#include <random>
#include <vector>
#include "card.h"

using namespace std;


/// @brief Build a two-dimensional vector row by row. Filling it with values
///         from standard input.
/// @param v The vector to build.
/// @param rows The number of rows in the 2D vector.
/// @param cols The number of cols in the 2D vector.
void fill2DVector(vector<vector<int>> &v, int rows, int cols)
{
    // build a row
    // place that row into the 2D vector

    for(int r = 0; r < rows; ++r)
    {
        vector<int> rowVector;
        for (int c=0; c < cols; ++c)
        {
            float value;
            cin >> value;
            rowVector.push_back(value);
        }
        v.push_back(rowVector);
    }

}


int main()
{
 
    return 0;
}
