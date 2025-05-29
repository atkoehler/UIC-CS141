/// @file 20250529.cpp
/// @author Adam T Koehler, PhD
/// @date May 29, 2025
/// @brief Code and lecture notes from the live session. 
///     Lecture File IO, Faro Shuffle (string based), and classes.

#include <iostream>
#include <string>
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

/// @brief Implement the Faro Shuffle (interleaving shuffle) algorithm to 
///         build a new string from the provided string.
/// @param s The starting string.
/// @return The shuffled string.
string faroShuffle(const string &s)
{
    string shuffled;
    int start = 0;
    int halfway = 0;

    // demonstration of using substring function if we needed it
    // string fhalf = s.substr(0, s.size() / 2);

    // Algorithm Implementation Version 1
    // for(start = 0, halfway = s.size() / 2; 
    //     start < s.size() / 2 && halfway < s.size(); 
    //     ++start, ++halfway)
    // {
    //     shuffled = shuffled + s.at(start) + s.at(halfway);
    // }

    // // determine if the string is odd sized
    // if (s.size() > 0 && 0 != s.size()%2)
    // {
    //     // add last character that is leftover
    //     shuffled = shuffled + s.back();
    // }


    // Algorithm Implementation Version 2
    halfway = s.size() / 2;
    for(start = 0; start < halfway; ++start)
    {
        shuffled = shuffled + s.at(start) + s.at(start+halfway);
    }

    // determine if the string is odd sized
    if (s.size() > 0 && 0 != s.size()%2)
    {
        // add last character that is leftover
        shuffled = shuffled + s.back();
    }

    return shuffled;
}

int main()
{
    string values;
    
    // even string length test case
    values = "A1234567890JQK";
    cout << "Even Length" << endl;
    cout << "Before: " << values << endl;
    values = faroShuffle(values);
    cout << "After:  " << values << endl;

    // odd string length test case
    values = "A1234567890JQ";
    cout << "Odd Length" << endl;
    cout << "Before: " << values << endl;
    values = faroShuffle(values);
    cout << "After:  " << values << endl;

    return 0;
}
