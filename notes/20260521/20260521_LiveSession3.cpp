/// @file 20260521_LiveSession3.cpp
/// @author Adam T Koehler, PhD
/// @date May 21, 2026
/// @brief Code and lecture notes from the live session. Requires -std=c++20

#include <iostream>
#include <vector>
#include <string>

using namespace std;


////////////////////////////////////////////////////////////
///////                                              ///////
///////              Input Redirection               ///////
///////                                              ///////
////////////////////////////////////////////////////////////

// This program utilizes user input. Instead of typing all the
// input every program execution, we can type it all once into
// an input file (e.g. input.txt) and provide that file as the
// source of the input using the terminal input redirection 
// operator. Then we can quickly execute our program repeatedly
// without having to type the input for each execution.

// Assuming our program executable is a.out then we can combine
// with the terminal input redirection operator (<) like this:
//
//    ./a.out < input.txt
//


bool isVowel(char);
void acquireData(int, vector<string> &);
unsigned long countVowels(const vector<string> &);
unsigned long countNonVowels(const vector<string> &);
unsigned long countVowelFirst(const vector<string> &);
unsigned long countVowelLast(const vector<string> &);
void removeNonAlphaFront(string &);

////////////////////////////////////////////////////////////
///////                                              ///////
///////                 main Program                 ///////
///////                                              ///////
////////////////////////////////////////////////////////////

int main()
{
    // Frequency Counter
    // Part 2: Write a function to determine whether a character 
    //         is a vowel or is not a vowel.  
    int count = 0;   
    vector<string> bank;
    cout << "How many words are in the word bank? ";
    cin >> count;
    cout << endl;

    acquireData(count, bank);
    cout << "Vowels: " << countVowels(bank) << endl;
    
    cout << "Non-Vowels: " << countNonVowels(bank) << endl;
    
    cout << "First Vowels: " << countVowelFirst(bank) << endl;
    
    cout << "Last Vowels: " << countVowelLast(bank) << endl;


    // Remove non-alphabetic characters from the front of a string
    for(auto &word : bank)
    {
        cout << word << endl;   
        removeNonAlphaFront(word);
        cout << word << endl;

    }

    return 0;
}





////////////////////////////////////////////////////////////
///////                                              ///////
///////        Functions From 2026-05-21             ///////
///////                                              ///////
////////////////////////////////////////////////////////////

/// @brief Remove all non-alphabetic characters from the front of a string
/// @param s the string to alter
void removeNonAlphaFront(string &s)
{
    // Option 1:
    // iterate through the string
        // when it is a nonalphabetic character, remove it
        // when it is alphabetic, stop looping
            // substr or erase


    // Option 2:
    // iterate through the string, locate first alpha character
    // remove everything before that index
        // substr
}


////////////////////////////////////////////////////////////
///////                                              ///////
///////        Frequency Counter - Part 3            ///////
///////                                              ///////
////////////////////////////////////////////////////////////

/// @brief 
/// @param data a container of strings from our word bank
/// @return 
unsigned long countVowels(const vector<string> &data)
{
    unsigned long counter = 0;

    for(const auto &word : data)
    {
        for(char c : word)
        {
            if (isVowel(c))
            {
                counter++;
            }
        }
    }

    return counter;
}

/// @brief 
/// @param data 
/// @return 
unsigned long countNonVowels(const vector<string> &data)
{
    unsigned long counter = 0;

    for(const auto &word : data)
    {
        for(char c : word)
        {
            if (!isVowel(c))
            {
                counter++;
            }
        }
    }

    return counter;
}


/// @brief 
/// @param data 
/// @return 
unsigned long countVowelFirst(const vector<string> &data)
{
    unsigned long counter = 0;

    for(const auto &word : data)
    {
        if (isVowel(word.front()))
        {
            counter++;
        }
    }

    return counter;
}

/// @brief 
/// @param data 
/// @return 
unsigned long countVowelLast(const vector<string> &data)
{
    unsigned long counter = 0;

    for(const auto &word : data)
    {
        if (isVowel(word.back()))
        {
            counter++;
        }
    }

    return counter;
}



////////////////////////////////////////////////////////////
///////                                              ///////
///////        Functions From 2026-05-20             ///////
///////                                              ///////
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
///////                                              ///////
///////        Frequency Counter - Part 1            ///////
///////                                              ///////
////////////////////////////////////////////////////////////

/// @brief determine whether a character is a vowel
/// @param c the character to check
/// @return true when the provided character is a vowel, otherwise false
bool isVowel(char c)
{
    return 'a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c; 
}




////////////////////////////////////////////////////////////
///////                                              ///////
///////        Frequency Counter - Part 2            ///////
///////                                              ///////
////////////////////////////////////////////////////////////

/// @brief Instantiate a vector by adding strings from standard input
/// @param quantity the number of strings to acquire via input
/// @param data the vector to push each of the strings into
void acquireData(int quantity, vector<string> &data)
{
    // We cannot acquire 0 or less strings
    if (quantity <= 0)
    {
        return;
    }

    // acquire the define quantity of strings
    // placing each into our data vector
    cout << "Enter " << quantity << " strings:" << endl;
    for (int i = 0; i < quantity; ++i)
    {
        string input;
        cin >> input;  
        data.push_back(input);
    }
}
