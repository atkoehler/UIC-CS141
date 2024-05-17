/// @file 20240516_LiveSession3.cpp
/// @author Adam T Koehler, PhD
/// @date May 16, 2024
/// @brief Code and lecture notes from the live session. Lecture covered
///     introduction to functions, global values, and linear search, early 
///     search termination for efficiency, random number generating function,
///     and string member functions at, size, find, and substr.

// Order of the live code from lecture:
// 1. main()
// 2. function prototypes
// 3. global constants, global variables
// 4. search function and main() invocation
// 5. find() and substr() string member functions
// 6. guessTheCard game with helper generateRandomInt


// libraries to include, we always want to be specific
#include <iostream>
#include <string>

using namespace std;


// Global constants can be utilized for constant values that might exist 
// across the entire of a program. These are different than global variables.
const int STOP_VALUE = -99;

// Global variables are seldom used when learning about proper programming
// practices because learners will use global variables to avoid understanding
// function parameters and pass by reference.
int myValue = 45;



// Similar to other languages, in C++ function definitions have distinct parts
// function definition __1__    ____2____(____3____) { ____4_____ }
// 1. return type
// 2. name
// 3. parameters?
// 4. function body including matching return statement when needed

// Function prototypes outline all the parts of a function that are necessary
// for proper invocation of the function and terminate with a semicolon.
// Note that the function body and variable names are not necessary!
int search(const string &, char);



/// @brief Generates a random number between minimum and maximum 
///         values including both minimum and maximum
/// @param min the minimum in the valid range (included)
/// @param max the maximum of the valid range (not included)
/// @return the random number
int generateRandomInt(int min, int max)
{
    return min + rand() % (max-min+1);
}


/// @brief Implement a one-round guessing game where the user attempts 
///        to guess the face value (Ace, 1-10, Jack, Queen, King, Joker) of the "next" card.
void guessTheCard()
{
    // seed the random number generator, creates predictability as same random
    // number sequence will be used so this is good for verification of working
    // code and demonstrations, but bad for an actual game that wants to be
    // random and not predictable when playing multiple times.
    srand(100);

    // every card face value, ? is Joker
    string values = "?A234567890JQK";

    // the random index associated with the "top" card
    int randIndex = generateRandomInt(0, values.size() - 1);

    // Acquire the guess from the user through synchronous console input
    char userE;
    cout << "Guess a character: ";
    cin >> userE;
    cout << endl;

    // Output the result of the guessing game
    if (values.at(randIndex) == userE)
    {
        cout << "You win!" << endl;
    }
    else
    {
        cout << "You Lose :(" << endl;
    }
}


int main()
{
    // Welcome Activity Part 1: linear search example
    // Acquire a user input and then determine whether the value from the user
    // exists within the string values. 
    // Code restrictions: only use at(), size() string member functions
    //      You may not need to use both

    bool found = false;
    char userInput;
    string values = "?A234567890JQK";

    cout << "Let's search the deck to see if a card exists." << endl;
    cout << "Enter the face card value to search for (A, 2-0, J, Q, K): ";
    cin >> userInput;
    cout << endl;

    // search through the string character by character
    for(size_t i = 0; i < values.size(); ++i)
    {
        if (values.at(i) == userInput)
        {
            found = true;            
        }
    }

    // search through the string character by character,
    // but stop searching when the entry is found
    for(size_t i = 0; i < values.size(); ++i)
    {
        if (values.at(i) == userInput)
        {
            found = true;           

            // we can break out of our look
            // break always breaks out of the "closest"
            // control structure in which it is applicably invoked 
            // here we break out of the loop
            break;
        }
    }    

    // use the boolean flag to output the search result
    if (found)
    {
        cout << "Found the character: " << userInput
            << endl;
    }
    else
    {
        cout << "Did not find the character: " << userInput
            << endl;
    }


    // Welcome Activity Part 2: linear search example into a function
    // Let's repeat the same activity but define a funtion
    // with our previously written code.

    // Acquire a value to search for from the user
    cin >> userInput;

    // Let's use our search function that gives us the index of the 
    // discovered character.
    int location = search(values, userInput);
    cout << location << endl;

    // We could also use the string member function find()
    int location2 = values.find(userInput);

    // Find does not return -1 upon failure, it returns a special
    // value denoting the nth position was reached. Recall a string has valid
    // indices from 0 to n-1 so the n position is the first invalid after
    // the string. When printing out as an integer -1 will be displayed but
    // we should use string::npos and not -1 to check for discovery.

    // when we reach the nth position, the character was not found
    if (string::npos == values.find(userInput))
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << location2 << endl;
    }
    
    
    // find() is often paired with substr() to acquire a part of a string
    // Here we will extract the quote from the string
    string x = "hello \"this\" is the problem";

    // locate the first quotation mark
    int loc1 = x.find('"');

    // locate the first quotation mark after the discovered one
    int loc2 = x.find('"', loc1+1);

    // if we know there are only two we could use reverse find (rfind)
    // to discover the first quotation mark searching in reverse
    loc2 = x.rfind('"');

    // we should probably verfiy that we discovered two distinct
    // quotation marks but we will skip error checking due to limited
    // live lecture time remaining

    // Let's output the two locations of the discovered quotation marks.
    cout << loc1 << ' ' << loc2 << endl;
    
    // Now we can invoke substr to acquire a substring of the string starting
    // 1 character after the initial location and containing the number
    // of characters between the quotation marks.
    cout << x.substr(loc1+1, loc2-loc1-1) << endl;

    // substr() allows multiple different invocations based on arguments sent
    cout << x.substr() << endl;     // substring from index 0 to the end
    cout << x.substr(3) << endl;    // substring from index 3 to the end
    cout << x.substr(3, 4) << endl; // substring from index 3 with a size 4


    // Let's quickly build a function and a helper function for 
    // one of our past implementations, the guess the card game!
    guessTheCard();

    return 0;
}



/// @brief A search function that discovers the index of the character we want to search for
///        in the provided string
/// @param lookIn the string to search within
/// @param lookFor the character to look for
/// @return the index of the character, otherwise -1
int search(const string &lookIn, char lookFor)
{
    // iterate through the entire string
    for(int i = 0; i < lookIn.size(); ++i)
    {
        // when discovering the character, return immediately
        // to improve the efficiency of the search algorithm
        if (lookIn.at(i) == lookFor)
        {
            return i;
        }
    }

    // we will only get to this line when the character is not found
    return -1;
}