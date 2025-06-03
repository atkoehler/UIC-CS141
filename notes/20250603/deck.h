#include "card.h"
#include <vector>
#include <string>
#include <iostream>


using namespace std;

class Deck
{
// data members
// vector<Card> vs Card arr[52], size, capacity
    private:
        vector<Card> dk;

// functionality
// shuffle()
// drawBottom/Top/Middle/Random()
// sort()
// display/print

// Card -> rank

// in .cpp
// string Deck::to_string()
    public:
    /// @brief combine all elements of the deck
    ///         into a single string separated
    ///         by newline
    /// @return single string with all the elements
    string to_string()
    {
        string newString; 

        // index based for loop
        // for each is the natural choice
        // going through all the elements
        // and we don't care about the index
        for(const Card& c : dk)
        {
            newString += c.to_string() + "\n";
        }
        
        
        // "Card is a Jack of Spades which is black\n
        //  Card is a Jack of Hearts which is red\n
        //  ";

        if (dk.size() > 0)
        {
            newString.pop_back();
        }

    }

};