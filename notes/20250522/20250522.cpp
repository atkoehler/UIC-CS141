/// @file 20250522.cpp
/// @author Adam T Koehler, PhD
/// @date May 22, 2025
/// @brief Code and lecture notes from the live session. Lecture covered
///     more on functions, vectors, arrays, string member functions at, 
///     size, find, and substr, and introduction to structs/classes

// Similar to other languages, in C++ function definitions have distinct parts
// function definition __1__    ____2____(____3____) 
//                     { ____4_____ }
// 1. return type
// 2. name
// 3. parameters?
// 4. function body including matching return statement when needed

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function prototypes define everything needed to invoke a function.
// Note that parameter names are optional, but types are required.
// Using function prototypes allows us to define the function at any
// point in our file.
void printV(const vector<string> &);
void removeNonAlpha(string &);


// creating a struct to represent a single die
struct die
{
    int value;
    string color;
};

// creating a vector of 3 dice using the struct die 
// data type for the individual elements
vector<struct die> dice(3);

/// @brief true when character is a vowel including 'y', otherwise false
/// @param c character to check
/// @return true when character is a vowel, otherwise false
bool isVowel(char c)
{
    c = tolower(c);
    // check for 'a', 'e', 'i', 'o', 'u', and maybe 'y'
    char vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
    for(int i = 0; i < 6; ++i)
    {
        if (c == vowels[i])
        {
            return true;
        }
    }

    // if ('a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c || 'y' == c)
    // {
    //     return true;
    // }

    return false;
}


uint countNonVowels(const vector<string> &data)
{
    uint sum = 0;
    for (const string& word : data)
    {
        for(size_t i = 0; i < word.size(); ++i)
        {
            cout << "checking: " << word.at(i) << endl;
            if (!isVowel(word.at(i)))
            {
                sum++;
            }
        }
    }
    return sum;
}

/// @brief calculate the quantity of words starting with a vowel
/// @param data all the words
/// @return the quantity of words starting with a vowel
uint countStartVowel(const vector<string> &data)
{
    uint sum = 0;
    for (const string &w : data)
    {
        if (isVowel(w.at(0)))
        {
            sum++;
        }
        // if (isVowel(w.front()))
        // {
        //     sum++;
        // }
    }
    return sum;
}

int main()
{
    cout << isVowel('a') << endl;
    cout << isVowel('b') << endl;

    cout << isVowel('d') << endl;
    cout << isVowel('e') << endl;

    vector<string> data = {"hello", "12345", "ee3ek45"};
    printV(data);
    cout << countStartVowel(data) << endl;

    cout << countNonVowels(data) << endl;

    cout << "Before: " << data.at(1) << endl;
    removeNonAlpha(data.at(1));
    cout << "After: " << data.at(1) << endl;

    cout << "Before: " << data.at(2) << endl;
    removeNonAlpha(data.at(2));
    cout << "After: " << data.at(2) << endl;


    return 0;
}

void removeNonAlpha(string &s)
{
    if (s.empty())
    {
        return;
    }

    while(!s.empty())   // not empty implements s.size() > 0
    {
        if(!isalpha(s.back()))
        {
            // removal
            // substr(0, size-1)
            // replace(size-1, 1, "")
            // pop_back
            s.pop_back();
        }
        else
        {
            return;
        }
    }

    /// if we had break at line 144 it would go here next
}


void printV(const vector<string> &v)
{
    for(const string& w : v)
    {
        cout << w << endl;
    }
}
