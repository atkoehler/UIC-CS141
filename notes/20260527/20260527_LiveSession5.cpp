/// @file 20260527_LiveSession5.cpp
/// @author Adam T Koehler, PhD
/// @date May 27, 2026
/// @brief Code and lecture notes from the live session. Requires -std=c++20
///         Example compilation command: 
///             g++ -std=c++20 20260527_LiveSession5.cpp utils.cpp 

#include <iostream>
#include <string>
#include <vector>

#include <fstream>  // for file stream reading + writing (only reading today)

#include "utils.h"  // pull in all of the utils.cpp utility functions

using namespace std;

// Implemented Functions
void acquireData(vector <vector<int>> &, const string &, int ROWS, int COLS);
void print2D(const auto &);

// Independent example functions to rotate "main" functions based on provided
// command line argument value.
void ColoringAnimationExample();
void FileIOExample();


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
                ColoringAnimationExample();
                break;

            case 2:
                FileIOExample();
                break;
            
            default:
                break;
        }
    }
    else
    {
        // could not parse or did not find extra command line argument
        // therefore just run everything
        ColoringAnimationExample();

        cout << endl << endl;
        FileIOExample();        
    }    
    return 0;
}


/// @brief Example code using the animation and coloring utility functions.
void ColoringAnimationExample()
{
    int i = 0;
    string str(50, ' ');
    do 
    {
        // Clean screen of any prior writing
        clearScreen();

        // update
        str.at(i) = 'A';
        int j = i % 5;
        switch(j)
        {
            case 0:
                setBlueBackground();
                break;
            case 1:
                setWhiteBackground();
                break;
            case 2:
                setGreenBackground();
                break;
            case 3:
                setRedBackground();
                break;
            case 4:
                setWhiteBackground();
                break;
        }

        // "Draw" new screen
        cout << endl << endl << str << endl << endl;

        // Reset the coloring to avoid future accidental coloring
        resetColors();

        // Pause for a period to mimic frame by frame animation
        pause(3);

       
        i++;

    }while (i < 50);
}

/// @brief Example demonstrating reading numerical data and filling a 
///         2D vector from a file or falling back to standard input.
void FileIOExample()
{
    // 2D Vector that will contain our data
    // We are making the assumption that all of our data will be integers.
    vector <vector<int>> data;
 
    // Filename to pull data from
    string file;   
    cin >> file;

    // build a 3x5 data vector from the file
    acquireData(data, file, 3, 5);
    cout << "Because of the way we wrote print2D, it can be used on different "
        << "types of containers as long as it is two dimensions of iterable "
        << " containers such as a vector<vector<int>>." << endl << endl;


    cout << "Output a 2D vector of integers:" << endl;
    // Display the 2D Vector of Data
    print2D(data);


    cout << endl << endl;
    cout << "Output a vector of 5-letter strings:" << endl;

    // Create a vector of strings of 5 letter words
    vector<string> strData = {"hello", "world", "blimp", "claim", "slays"};

    // Display strings in a 2D grid separating characters
    print2D(strData);
}



/// @brief Aquire the numerical data from the file or the user if the file cannot be opened.
/// @param data the multidimensional data vector to build
/// @param filename the file name to attempt to pull data from
/// @param ROWS the amount of rows in the data
/// @param COLS the amount of columns in each data row
void acquireData(vector <vector<int>> &data, const string &filename, int ROWS, int COLS)
{
    // We can create a ifstream object and then open a file later
    // ifstream inF; 

    // We can also use a parameterized constructor to open a file
    // during the instantiation of the object
    ifstream inF(filename); 


    // Check if the file was successfully opened
    if(!inF.is_open())
    {
        setRedBackground();
        cout << "ERROR: File could not be opened."
            << " Defaulting to standard input." << endl; 
        resetColors();
    }


    for (int r = 0; r < ROWS; r++)
    {
        // Create an empty row vector to build the current data row.
        vector<int> rowV; 

        for (int c = 0; c < COLS; c++)
        {
            int value;

            // Acquire the value from the file or standard input.
            if(inF.is_open())
            {
                inF >> value;
            }
            else
            {
                cin >> value;
            }

            // Place the value into the temporary row vector.
            rowV.push_back(value);
        }

        // PLace row into the 2D vector as a new row
        data.push_back(rowV);
    }

    // Good practice is to close a file as soon as you are done with it.
    // In this case we are also exiting the function which would call the 
    // destructor of our ifstream object (inF) and the destructor will also
    // close the file.
    inF.close();
}

/// @brief print a two-dimension data container element by element where each
///        the every row is an iterable container stored in an iterable 
///        container such as a vector<vector<int>> or vector<string>.
/// @param data 
void print2D(const auto &data)
{
    for (const auto &row : data)
    {
        for (const auto &element : row)
        {
            cout << element << ' ';
        }
        cout << endl;
    }
}