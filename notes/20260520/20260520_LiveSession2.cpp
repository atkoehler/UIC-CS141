/// @file 20260520_LiveSession2.cpp
/// @author Adam T Koehler, PhD
/// @date May 21, 2024
/// @brief Code and lecture notes from the live session. Requires -std=c++20
///     C++ Concepts: Monte Carlo Simulations, Estimated Probability
///                   rand(), vectors, arrays, file input intro
///                   function writing and function decomposition

#include <iostream>
#include <vector>
#include <string>


// For sanity of the professor typing during live coding examples
// we use the standard namespace. This allows me to not have to 
// type std:: before things like cout to declare which namespace
// cout can be found in. Outside of academic settings, you would likely
// not default to using this line so that you can easily use multiple
// namespaces within your code.
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



////////////////////////////////////////////////////////////
///////                                              ///////
///////             Function Prototypes              ///////
///////                                              ///////
////////////////////////////////////////////////////////////

// Function Prototypes are portions of the function header that can be 
// declared prior to the full function definition to allow the function 
// callers to know the appropriate caller methodology and allow the 
// compile to continue compiling our code.

// A function prototype will have return type, function name, 
// and all parameter variable types. It can optionally contain variable
// names to further help with readability, but they are not required. 

// Similar to other languages, in C++ function definitions have distinct parts
// function definition __1__    ____2____(____3____) { ____4_____ }
// 1. return type
// 2. name
// 3. parameters?
// 4. function body including matching return statement when needed
// Function prototypes do not need all these parts, but enough to understand
// how to call the function.


bool isVowel(char);

// BAD: return by value, makes a copy, which could be resource intensive
// vector<string> acquireData(int);
// good "return" our updated vector by reference
void acquireData(int, vector<string> &);



////////////////////////////////////////////////////////////
///////                                              ///////
///////                 main Program                 ///////
///////                                              ///////
////////////////////////////////////////////////////////////

int main()
{
    char c;
    cout << "Enter a letter: ";
    cin >> c;
    cout << endl;

    // Frequency Counter
    // Part 1: Write a function to determine whether a character 
    //         is a vowel or is not a vowel. 
    if(isVowel(c))
    {
        cout << "It's a vowel!" << endl;
    }
    else
    {
        cout << "It's not a vowel :(" << endl;
    }


    // Frequency Counter
    // Part 2: Write a function to determine whether a character 
    //         is a vowel or is not a vowel.  
    int count = 0;   
    vector<string> bank;
    cout << "How many words are in the word bank? ";
    cin >> count;
    cout << endl;

    acquireData(count, bank);
    for(const auto &word : bank)
    {
        cout << word << endl;
    }

    return 0;
}



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
    // Many novice programmers will write a single if-else statement to
    // complete a predicate (boolean) function. The if-else returns either
    // true or false depending on the conditional expression.
    // if ('a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c)
    // {
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }

    // Instead of using a branch to return the literal result of the 
    // conditional expression, we can write the expression directly
    // into the return statement.
    return 'a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c; 
}




////////////////////////////////////////////////////////////
///////                                              ///////
///////        Frequency Counter - Part 2            ///////
///////                                              ///////
////////////////////////////////////////////////////////////

// BUILD VECTOR ALGORITHM & DESIGN QUESTIONS
// how many strings? 
//      caller will supply
// how to get the string? 
//      user input to acquire a string
// what do we do with the input? 
//      place it into our data vector
// how do we get the updates or calculation back to the caller?
//      "return" our vector to the caller

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
        cin >> input;  //getline to grab lines with whitespace
        data.push_back(input);
    }
}

/////////////////////////////////////////////////
// C++23 Rewrite:
//    Compile with g++ -std=c++23 20260520_LiveSession2.cpp -o program.out
//
//  There are additional things we could do with C++23 to further streamline
//  our code, but those items can add cognitive complexity to the code that
//  makes it more difficult to understand for those learning C++ with limited 
//  prior Computer Science experience.
//
// Uses two models:
// 1. buildVector always creates a vector from scratch and returns it
//      This model is uses the innate behind the scenes "move" dynamics that
//      avoid the copying of all the individual elements of the vector.
//      This has existed since C++11 but is more commonplace after 2015-2017
//      due to delayed adoption of C++ standards.
// 2. appendVector always requires a pre-existing vector and appends new data
//      This model is similar to our acquireData function and uses pass by 
//      reference to add data to an already existing vector of data.

// #include <print> // for C++23 print/println

// /// @brief Model 1: Create a brand-new vector from scratch
// /// @param quantity the number of strings to acquire via input
// /// @return a new vector containing the acquired strings
// vector<string> buildVector(int quantity)
// {
//     vector<string> data;

//     if (quantity <= 0)
//     {
//         return data; 
//     }

//     // C++23 format-printing syntax with automatic line breaks
//     println("Enter {} strings:", quantity);

//     for (int i = 0; i < quantity; ++i)
//     {
//         string input;
//         cin >> input;
//         data.push_back(input);
//     }

//     return data; // Instant "move" optimization happens here automatically
// }

// /// @brief Model 2: Add to a vector that already exists (The Appender)
// /// @param quantity the number of strings to acquire via input
// /// @param data the existing vector to append each of the strings into
// void appendVector(int quantity, vector<string> &data)
// {
//     if (quantity <= 0)
//     {
//         return;
//     }

//     println("Enter {} more strings:", quantity);

//     for (int i = 0; i < quantity; ++i)
//     {
//         string input;
//         cin >> input;
//         data.push_back(input); // Modifies the original vector directly
//     }
// }