/// @file frequencies.cpp
/// @author Adam T Koehler, PhD
/// @date May 22, 2026
/// @brief Implementation of a counting program that counts the frequency of
///     various characteristics within a data set of strings. Data is acquired 
///     through file input and stored only when it meets specific conditions.



// Program Core Concepts:
//  strings & vectors (and associated member functions)
//  switch statements
//  User Defined Functions
//   - Pass by Value, Pass by Reference, Pass by Const Reference
//  File Input


#include <iostream>
#include <string>
#include <vector>

using namespace std;


// Prototypes for all local functions
// Implemented in order listed here below main()
int countNonVowels(const vector<string> &);
int countVowels(const vector<string> &data);
int countVowelStarters(const vector<string> &);
bool exists(const vector<string> &, const string &);
bool isvowel(char);
bool islower(const string &);
void printMenu();
int readData(vector<string> &);
void trimEnd(string &);
bool validSize(const string &);

int main()
{
    // When testing we can hardcode values into our data vector
    // so that we can test our functions with specific data.
    // vector<string> data = {"my", "name", "bob", "and"};


    // When not testing we want to start with an empty data container.
    vector<string> data;


    string filename;    
    int option = -1, reads = -1;
    const int DONE = 6;

    cout << "Frequency Calculator" << endl;
    cout << "====================" << endl;
    cout << endl;

    do
    {   
        printMenu();

        // Acquire a user option based on the menu
        cout << "Choose an option: ";
        cin >> option;
        cout << endl;

        // Act on the option entered by the user
        switch(option)
        {
            case 1:
                cout << "Reading data..." << endl;
                data.clear();
                reads = readData(data);
                cout << "Data reading complete." << endl << endl;

                cout << "Read in " << reads << " total words." << endl;
                cout << "Invalid Data: " << reads - data.size() << endl;
                cout << "Valid Data: " << data.size() << endl;
                break;

            case 2:
                data.clear();
                cout << "Data cleared." << endl;
                break;

            case 3:
                cout << "Found " << countVowels(data) << " vowels." 
                    << endl;
                break;
            case 4:
                cout << "Found " << countNonVowels(data) << " non-vowels." 
                    << endl;
                break;

            case 5:
                cout << "Found " << countVowelStarters(data) 
                    << " words that start with vowels." << endl;
                break;

            case DONE:
                break;

            default:
                cout << "Invalid Option: " << option << endl;
                break;
        }

        cout << endl;
    } while (option != DONE);


    cout << "Enjoy your day!" << endl;

    return 0;
}

/// @brief Count the quantity of non-vowel characters in the data.
/// @param data the vector containing all the strings of data
/// @return the quantity of non-vowel characters in the data
int countNonVowels(const vector<string> &data)
{
    int counter = 0;

    // iterate over data
    for(size_t i = 0; i < data.size(); ++i)
    {
        // iterate over every character in the string
        for(const auto &e : data.at(i))
        {   
            if (!isvowel(e))
            {
                counter++;
            }
        }
    }
    
    return counter; 
}



/// @brief Count the quantity of vowel characters in the data.
/// @param data the vector containing all the strings of data
/// @return the quantity of vowel characters in the data
int countVowels(const vector<string> &data)
{
    int counter = 0;

    // iterate over data
    for(size_t i = 0; i < data.size(); ++i)
    {
        // iterate over every character in the string
        for(const auto &e : data.at(i))
        {   
            if (isvowel(e))
            {
                counter++;
            }
        }
    }
    
    return counter;   
}


/// @brief Count the quantity of words in the data that start with a vowel.
/// @param data the vector containing all the strings of data
/// @return the quantity of words counted that start with a vowel
int countVowelStarters(const vector<string> &data)
{
    int counter = 0;

    // every element in the data
    for(const auto &e : data)
    {
        if (e.size() > 0 && isvowel(e.at(0)))
        {
            counter++;
        }
    }
    
    return counter; 
}


/// @brief determine whether the supplied word already exists in the data
/// @param data the container of data to check
/// @param word the string to look for in the data
/// @return true when the word exists in the data, false otherwise
bool exists(const vector<string> &data, const string &word)
{
    // iterate over every word in the data
    for(const auto &w : data)
    {
        // return true upon discovery of the word in the data
        if (w == word)
        {
            return true;
        }
    }
    return false;
}


/// @brief determine whether a string is all lowercase alphabetic characters
/// @param word the string to check
/// @return true when all lowercase alphabetic characters, otherwise false
bool islower(const string &word)
{
    // iterate over every character in word
    for(const auto &letter : word)
    {
        // return false immediately when not between 'a' and 'z' (inclusive)
        if (!('a' <= letter && letter <= 'z'))
        {
            return false;
        }
    }
    return true;
}


/// @brief Predicate function to determine if a character is a lowercase
///      vowel (not 'y').
/// @param c the character to check 
/// @return true when a lowercase vowel, otherwise false
bool isvowel(char c)
{
    // We could create a branch based on all valid vowel characters
    // if (c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u')
    // {
    //     return true;
    // }
    // return false;

    // Common practice would be to create a one-line function where
    // we could use the result of the compound conditional directly.
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}


/// @brief output the menu containing all the program options
void printMenu()
{
    cout << "Menu Options" << endl;
    cout << "1. Read Data" << endl;
    cout << "2. Clear Data" << endl;
    cout << "3. Count Vowels" << endl;
    cout << "4. Count Non-Vowels" << endl;
    cout << "5. Count words that start with vowels" << endl;
    cout << "6. Exit" << endl << endl;
}


/// @brief read in all the words from the specified file
/// @param data the gathered data containing all valid strings
/// @return the quantity of words read (valid and invalid)
int readData(vector<string> &data)
{
    int counter = 0;

    string value;

    while(cin >> value)
    {        
        counter++;

        trimEnd(value);

        if(validSize(value) && islower(value) && !exists(data, value))
        {
            data.push_back(value);
        }
        else
        {
            cout << "Invalid Data: " << value << endl;
            break;
        }
    }

    return counter;
}

/// @brief eliminate all non-alphabetic characters from the end of a string
/// @param word the string to trim non-alphabetic ending characters from
void trimEnd(string &word)
{
    if (word.empty())
    {
        return;
    }

    while(word.size() > 0 && !isalpha(word.back()))
    {
        word.pop_back();
    }
}

/// @brief Determines that a supplied string is a valid size
/// @param s the string to validate the size of
/// @return true when the string size if valid, otherwise false
bool validSize(const string &s)
{
    // 5 is the only valid string size    
    return s.size() == 5;
}