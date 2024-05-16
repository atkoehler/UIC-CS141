/// @file 20240515_LiveSession2.cpp
/// @author Adam T Koehler, PhD
/// @date May 14, 2024
/// @brief Code and lecture notes from the live session.


// libraries to include, we always want to be specific
#include <iostream>
#include <string>
#include <random>

using namespace std;

int main()
{
    int split;
    string values = "A1234567890JQK?";

    // Goal:
    // Given a "deck" of cards, count the numeric cards

    // Algorithm
    // 1. Look at the first card in the deck

    // 2. count it when it is a number <- branch/if statement

    // 3. (repeat until no more cards in the deck)
    //     look at second card in the deck and so on until none left...

    // int counter = 0;
    // cout << "Split: " << split << endl;
    // for (int i=0; i < split; i+=1)
    // {
    //     // cout << values.at(i) << endl;
    //     // if ('0' <= values.at(split) || '1' || '2' || '3')
    //     // if('0' <= values.at(split) 
    //     //     && values.at(split) <= '9')
    //     if(isdigit(values.at(i))) 
    //     {
    //         counter++;
    //     }
    // }
    // cout << counter << endl;


    // Algorithm
    // dump out all the cards
    // pick them all up one-by-one "randomly"

    // Algorithm
    // for every element in our deck
    // pick a random card
    // remove it
    // add it to back of new deck

    // For-each, useful in a for every element in container scenario
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

    // values = "A1234567890JQK?";
    // cout << "Original string: " << values << endl;
    // Example using each element but not manipulating
    // for (const char &e : values)
    // {
    //     cout << e << ' ';
    // }
    // cout << endl;

    // example manipulation attempt when disallowed
    // for (const auto &e : values)
    // {
    //     e = e + 1;
    // }

    // cout << "Before manipulation: " << values << endl;

    // example potential logic flaw in attempting manipulation
    // on a copy of the element instead of actual element
    // for (auto e : values)
    // {
    //     e = e + 1;
    // }
    // cout << "After copy of value manipulation: " << values << endl;

    // cout << "Before manipulation: " << values << endl;

    // example manipulation of each element when allowed
    // for (auto &e : values)
    // {
    //     e = e + 1;
    // }
    // cout << "After manipulation: " << values << endl;


    // Faro Shuffle Algorithm Implementation
    // setup or reset the deck due to other lecture activities
    values = "A1234567890JQK?";

    // temporary deck to build into
    string update;
    
    // divide the deck in half
    split = values.size() / 2;

    // output for easy comparison of before and after
    cout << "original: " << values << endl;

    // broken algorithm from class 5/15
    // for(int i=0, j=split; i < split || j < values.size(); ++i, ++j)
    // {
    //     update = update + values.at(i) + values.at(j);
    // }
    // values = update;

    // updated algorithm from after class 5/15
    // stop when either deck has no more cards
    // we want access to values of iterating variables beyond the loop
    // so it makes sense to use a while loop here instead of a for loop
    int i = 0, j = split;
    while(i < split && j < values.size())
    {
        update = update + values.at(i) + values.at(j);
        i++;
        j++;
    }

    // when odd size deck the second half will be 1 card larger
    // add remaining deck of second half in odd
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




