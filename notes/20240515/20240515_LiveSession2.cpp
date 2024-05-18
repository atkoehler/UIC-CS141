/// @file 20240515_LiveSession2.cpp
/// @author Adam T Koehler, PhD
/// @date May 15, 2024
/// @brief Code and lecture notes from the live session. Introduction
///     to for and for-each loops and continuing to use branches.
///     C++ Concepts: counting, for & for-each loops, refernce variables (&)
///                   string concatenation and member functions at(), size()
///                   modulo (%) to determine odd or even
///                   compound conditional expressions with && or ||
///                   broken English -> compound conditional translation
///                   isdigit() and character type identifier functions


// Order of the live code from lecture:
// This is the second program and as such it simply goes from line 1
// to the end of the file for the order. Order will jump around more
// when we start implementing functions.


// libraries to include, we always want to be specific
#include <cctype>       // for isdigit() function to check character values
#include <iostream>     // for console input and output streams
#include <string>       // for string data type and member function at()

using namespace std;

int main()
{
    // Welcome Activity: Counting
    // Given the split deck of cards, how can we count how many
    // numeric cards are in each "half" of the deck?
    //
    // We are writing an algorithm, not C++ code. Problem breakdown and
    // problem solving skills are just as important as understanding
    // what syntax to use.
    //
    // How can we verify that our algorithm's count is correct?


    // Goal:
    // Given a "deck" of cards, count the numeric cards

    // Algorithm
    // 1. Look at the first card in the deck

    // 2. count it when it is a number <- branch/if statement

    // 3. (repeat until no more cards in the deck)
    //     look at second card in the deck and so on until none left...

    // Implemenation
    int split = 4;  // we will hardcode the split instead of using rand()

    // our deck representation
    string values;  // strings are initailized to the empty string: ""
    
    // set our standard partial deck representation
    values = "?A234567890JQK";

    // we need a counter for this activity, don't forget to initialize to 0!
    int counter = 0;

    cout << "Activity: Counting" << endl;
    cout << "Counting the number of numeric cards in a split deck." << endl;
    cout << "Splitting at index " << split << endl;
    for (int i=0; i < split; i+=1)
    {
        // We can obtain a value at a specific index in the string with at()
        cout << "Character at current index value: " << values.at(i) << endl;
        
        // We often incorrectly translate boolean compound conditions
        // from English to programming syntax such as C++
        // Here we would say if the character is a '0' or a '1' or a '2'
        // or a '3' or a '4' .... then do something
        // but that translates to bad C++ because we do not have
        // a boolean express (expression that results in true or false)
        // on each side of our or logical operators (||)
        // if ('0' <= values.at(split) || '1' || '2' || '3')

        // For us, we are counting digits, we could use a compound 
        // conditional express to verify that the character is in a specific
        // range of characters from '0' to '9' (inclusive on both ends).
        // if('0' <= values.at(split) 
        //     && values.at(split) <= '9')

        // However, there is a function that will do this for us.
        // isdigit() takes characters and returns true when the
        // character is '0' through '9' (inclusive of both ends)
        

        // increase the counter when character is a digit
        if(isdigit(values.at(i))) 
        {
            // increment the counter
            // many ways to choose:
            // counter++;
            // ++counter;
            // counter += 1;
            // counter = counter + 1;
            counter++;
        }
    }

    // output the result
    cout << "There are " << counter << " numeric cards." << endl;


    cout << endl << endl;
    cout << "========================================================================";
    cout << endl << endl; 


    // Activity: Shuffling
    // Discuss with your group how to shuffle the deck of cards. Now
    // write an algorithm based on your discussion.
    //
    // Again, we are writing an algorithm, not C++ code. Problem breakdown and 
    // problem solving skills are just as important as understanding
    // what syntax to use.
    //
    // Exchange papers with another group, discuss the differences between
    // your algorithm and theirs. Discuss how to implement the 
    // other group's algorithm in C++. If you need more information
    // or are taking steps not in the algorithm, leave notes on for the
    // other group as feedback to help improve their algorithm writing.
    //
    // (out of time) actually implement other group's algorithm in C++


    // Acquire a user input and then determine whether the value from the user
    // exists within the string values. 
    // Code restrictions: only use at(), size() string member functions
    //      You may not need to use both


    // Shuffling Algorithm Example
    // What would a toddler do?
    // 1. dump out all the cards on to the table or floor
    // 2. move them around a bunch with their hands or feet
    // 3. pick them all up one-by-one "randomly"
    //
    // Task on your own time: Implement the above in C++

    // Shuffling Algorithm Example
    // Create a new deck through randomly pulling cards from old deck.
    // 1. Pick a random card out of the deck
    // 2. Remove it from the original deck
    // 3. Place it at the back of the new deck
    // 4. Repeat 1-3 until original deck is empty
    


    // For-each loops
    // For-each loops are useful in a for every element in container scenario
    // for (char e : values)
    // {
    //     // do something   
    // }

    // The for each loop variations....
    // create a copy of the element value in values into char e
    // for (char e : values)

    // acquire the address of each element in values, 
    // allowing direct access or manipulation
    // for (char &e : values)

    // acquire the address of each element in values, 
    // allowing direct access or but constant keyword prevents manipulation
    // for (const char &e : values)

    // auto tells the compiler to determine the value, it is still a specific
    // type and anything done inside the loop has to be able to be done
    // on the anticipated data type, but this allows us to write more
    // generalizable loops
    // acquire the address of each element in values, 
    // allowing direct access or but constant keyword prevents manipulation
    // for (const auto &e : values)

    cout << "Using For-each loops with strings" << endl;

    // set our standard partial deck representation
    values = "?A234567890JQK";
 
    cout << "Original string: " << values << endl;
 
    // Example using each element but not manipulating
    for (const char &e : values)
    {
        cout << e << ' ';
    }
    cout << endl;


    // example manipulation attempt when disallowed
    for (const auto &e : values)
    {
        // e = e + 1;  // commented out because this is a syntax error
    }

    cout << endl << endl;
    cout << "Attempting manipulation with for-each that copies each"
        << endl << "element's value instead of referencing each element."
        << endl;
    cout << "Before attempt: " << values << endl;

    // example potential logic flaw in attempting manipulation
    // on a copy of the element instead of actual element
    for (auto e : values)
    {
        e = e + 1;
    }
    cout << "After attempt:  " << values << endl;


    cout << endl << endl;
    cout << "Attempting manipulation with for-each that references"
        << endl << "each element in the string (using &)."
        << endl;
    cout << "Before attempt: " << values << endl;

    // example manipulation of each element when allowed
    for (auto &e : values)
    {
        e = e + 1;
    }
    cout << "After attempt:  " << values << endl;


    cout << endl << endl;
    cout << "========================================================================";
    cout << endl << endl;  


    // Activity: Faro Shuffle Algorithm 
    // Implement the described Faro Shuffle algorithm in C++
    // "A234567890JQK" should become "A72839405J6QK";

    cout << "Faro Shuffle Algorithm (broken)" << endl;

    // setup or reset the deck due to other lecture activities
    values = "A234567890JQK";

    // temporary deck to build into
    string update;
    
    // divide the deck in half
    split = values.size() / 2;

    // output for easy comparison of before and after
    cout << "original: " << values << endl;

    // broken algorithm, doesn't work for uneven split
    // implementation from class 5/15
    for(int i=0, j=split; i < split || j < values.size(); ++i, ++j)
    {
        update = update + values.at(i) + values.at(j);
    }
    values = update;

    // output for easy comparison of before and after
    cout << "shuffled: " << values << endl;

    // Question: How can we make this less predictable, because if shuffling
    //  is predictable then counting cards is easier.

    cout << endl << endl;
    cout << "========================================================================";
    cout << endl << endl;  


    // Activity: Faro Shuffle Algorithm (fix for odd or even sizes)
    // "?A234567890JQK" should become "?7A829304J5Q6K";
    // "A234567890JQK" should become "A72839405J6QK";
    // The difference here is whether the deck size can be evenly split.

    cout << "Faro Shuffle Algorithm (fixed)" << endl;

    // reset variables before executing algorithm
    values = "A234567890JQK";
    update = "";
    split = values.size() / 2;

    // The updated Faro Shuffle Algorithm implementation from after
    // 5/15 class that fixes the uneven split issue.

    cout << "Executing Faro Shuffle algorithm on uneven split, "
        << "deck size: " << values.size() << endl;

    // output for easy comparison of before and after
    cout << "original: " << values << endl;

    // Stop when either deck has no more cards.
    // We want access to values of iterating variables beyond the loop
    // so it makes sense to use a while loop here instead of a for loop
    size_t i = 0, j = split;
    while(i < split && j < values.size())
    {
        update = update + values.at(i) + values.at(j);
        i++;
        j++;
    }

    // when odd size deck the second half will be 1 card larger
    // add remaining deck of second half in odd split
    if (values.size() % 2 == 1 && j < values.size())
    {
        update += values.at(j);
    }

    // store the updated string into the deck
    values = update;

    // output for easy comparison of before and after
    cout << "shuffled: " << values << endl;


    // repeat the algorithm execution with other sized string
    // reset variables before executing algorithm
    values = "?A234567890JQK";
    update = "";
    split = values.size() / 2;
  
    cout << endl;
    cout << "Executing Faro Shuffle algorithm on even split, "
        << "deck size: " << values.size() << endl;

    // output for easy comparison of before and after
    cout << "original: " << values << endl;

    // Stop when either deck has no more cards.
    i = 0, j = split;
    while(i < split && j < values.size())
    {
        update = update + values.at(i) + values.at(j);
        i++;
        j++;
    }

    // add remaining deck of second half in odd split
    if (values.size() % 2 == 1 && j < values.size())
    {
        update += values.at(j);
    }

    // store the updated string into the deck
    values = update;

    // output for easy comparison of before and after
    cout << "shuffled: " << values << endl;

    // Question: How can we make this less predictable, because if shuffling
    //  is predictable then counting cards is easier.
}




