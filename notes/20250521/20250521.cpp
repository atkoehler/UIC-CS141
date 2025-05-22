/// @file 20250521.cpp
/// @author Adam T Koehler, PhD
/// @date May 21, 2025
///
/// @brief Notes for live CS 141 lecture on May 21, 2025. 
///         Concepts covered include:
///         Loops, Functions, Strings, Vectors, 
///         and Terminal Input Redirect

// To execute with terminal input redirection we use 
// the < operator in the terminal to tell the terminal to send values
// from a location into our executable (by default ./a.out).
// Such as ./a.out < input.txt

#include <vector>
#include <iostream>
#include <string>

using namespace std;

/// @brief count the sizes of the elements of the vector
/// @param v container (normally a vector of strings) 
/// @return the total characters in the vector (sum of string sizes)
unsigned int countSizes(const vector<string>& v)
{
    uint sum = 0 ;
    for (const string& word : v)
    {
        sum += word.size();
    }

    return sum;
}

/// @brief alternate version of countSizes which uses auto
/// @param v container (normally a vector of strings) 
/// @return the sum of all the sizes of the elements in the container
uint otherCount(const auto &v)
{
    uint sum = 0 ;
    for (const auto& word : v)
    {
        sum += word.size();
    }

    return sum;
}



// unsigned int count(string word)
// pass by value is not used with objects as it creates
// a copy of the entire value of the variable and 
// objects such as vectors or strings could have a lot of elements
// so it is more efficient to pass by reference

// choices of pass by reference, const or not
// based on changing the variable or not
// unsigned int count(string& word)
// unsigned int count(const string& word)

/// @brief count how many times the letter 'e' appears in the word
/// @param word the string value to search through
/// @return the number of appearances of the letter 'e'
unsigned int count(const string& word)
{
    uint sum = 0;
    // our length is word.size()
    // "doctor" 'd' is at index 0, 'r' is at 5
    for (size_t i = 0; i < word.size(); ++i)
    {
        if ('e' == word.at(i))
        {
            sum++;
        }
    }

    // We can also use at() on the left hand side of assignment
    // to update a value of a specific index.
    // word.at(0) = 'e'; // invalid because of const parameter

    return sum;
}


int main()
{
    // We may wish to initialize a vector with empty spots preallocated;
    // to do this we can provide a quantity during declaration.
    // vector<string> words(10);

    // one dimensional vector of strings
    vector<string> words;

    // two dimenstional vector of strings or a 
    // vector of a vector of strings
    vector<vector<string>> twoDimWords;

    // a single string value acquired from input
    string value;

    // When we put this in a loop conditional, input will be acquired
    // until the input fails. The common way for failure to occur is for
    // the EOF or end-of-file character to be encountered either by reaching
    // an end of file or sending it manually with ctrl+d
    while(cin >> value)
    {
        // If we had preallocated vector spots, we could use at
        // to set the valuse at a specific index or use a looping variable
        // such as i to set a different index per iteration.
        // words.at(0) = value;
        // words.at(i) = value;

        // We can create a new spot in the vector and place the value at
        // the end with the push_back() member function.
        words.push_back(value);
    }

    // If we want to build our two dimensional vector we can push
    // an entire row at a time. Here we push the same values twice
    // to create a two row two dimensional vector.
    twoDimWords.push_back(words);
    twoDimWords.push_back(words);

    // Iterate through the one dimensional vector and output
    // the quantity of 'e' characters for each word.
    // This uses a normal or standard for loop setup.
    for (size_t i = 0; i < words.size(); ++i)
    {
        cout << "Counted " << count(words.at(i)) << " e's" << endl;
    }


    cout << endl << "print words with basic for each..." << endl;
    // Iterate through the one dimensional vector and output
    // the quantity of 'e' characters for each word.
    // This uses a copy-value for-each loop setup.
    for(string value : words){
        cout << value << endl;
        value = "hello";
    }


    cout << endl << "print words with const ref for each..." << endl;
    // Iterate through the one dimensional vector and output
    // the value of each element (string word).
    // This uses a constant reference variable for-each loop setup.
    // This reference variable allows direct access to changing the container
    // words, but constant prevents the changes so we are just being more 
    // efficient here by not creating copies of each container element.
    for(const string &value : words){
        cout << value << endl;
    }

    
    // use the various count functions
    cout << endl << "total characters: " << countSizes(words) << endl;
    cout << "total characters in 1D vector: " << otherCount(words) << endl;
    cout << "total words 2D vector " << otherCount(twoDimWords) << endl; 


    cout << endl << "modify words with ref for each..." << endl;
    // Iterate through the one dimensional vector and output
    // the value of each element (string word).
    // This uses a reference variable for-each loop setup.
    // This reference variable allows direct access to changing the container
    // words, here we just set all teh values to "hello" after outputting each.
    for(string &value : words){
        cout << "modifying: " << value << endl;
        value = "hello";
    }

    cout << endl << "print words with const ref for each..." << endl;
    // Iterate and print the values to demonstrate the modifications   
    for(const string &value : words){
        cout << value << endl;
    }

    // Count the characters in every string of the vector after mod
    cout << "total characters after mod: " << countSizes(words) << endl;


    return 0;
}
