/// @file deck.cpp
/// @author Adam T Koehler, PhD
/// @date June 3, 2025
/// @brief Deck class that is continually under development.
///     New functionality that is added in a lecture will exist at end
///     after comment about lecture date that featured the live additions.

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "card.h"
#include "deck.h"

using namespace std;

// =====================================================
// Functionality implementations from 06-03-2025 lecture
// =====================================================

/// @brief combine all elements of the deck
///         into a single string separated
///         by newline
/// @return single string with all the elements
string Deck::to_string() const
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

    return newString;
}

/// @brief sends the object's string conversion to output
void Deck::printDeck() const
{
    cout << to_string() << endl;
}


// ===========================================================================
// Functionality implementations asynchronously added after 06-03-2025 lecture
// ===========================================================================

/// @brief provide the quantity of cards remaining in the deck using the container size
/// @return the quantity of cards remaining in the deck
size_t Deck::deckSize() const
{
    return dk.size();
}

/// @brief checks if the deck is empty or not
/// @return true when the deck is empty, false otherwise
bool Deck::empty() const
{
    return dk.empty();
}



// =====================================================
// Functionality implementations from 06-04-2025 lecture
// =====================================================

/// @brief place card at the bottom of the deck
///     (back of vector is bottom)
/// @param c card to insert into the deck
void Deck::addCardBottom(const Card &c)
{
    dk.push_back(c);
}


/// @brief Draw a random card from the deck.
/// @return the random Card in the deck
/// @post the drawn Card no longer exists in the deck
Card Deck::drawRandom()
{
    // when default constructor object using empty initializer list
    // essentially empty return of a type matching the return type 
    // introduced in C++11, improved in C++14 and C++17
    if (empty())
    {
        return {};
    }

    // generate a random number bounded to valid indices
    int r = rand() % dk.size();
    
    // store a copy of the Card to return
    Card copy = dk.at(r);

    // shift values towards front starting at the randomly
    // generated index value
    shiftLeft(r);

    // Code moved into the above shifting function
    // for (size_t i = r; i+1 < dk.size(); ++i)
    // {
    //     // we should have mutators and can just
    //     // set the values, but we have not defined mutators
    //     // so we get the values and create a Card
    //     // dk.at(i) = Card(dk.at(i+1).getFaceValue(),
    //     //                 dk.at(i+1).getSuit(), 
    //     //                 dk.at(i+1).isRed());

    //     // The above is necessary when C++ does not innately
    //     // know how to copy the object and its data members
    //     // over to a new object. For example when dealing
    //     // with dynamic memory in the future.
    //     // However as our data members are a string, string, and bool
    //     // we can just copy the Card over as all of those have known ways to 
    //     // create a deep copy of the values in C++
    //     dk.at(i) = dk.at(i+1);
    // }

    // When non-empty our algorithm must elimate the last element 
    // from the vector representation of the deck.
    dk.pop_back();
   
    // Finally we return the copy we previously created and stored.
    return copy;
} 

/// @brief Shift all values to the left one spot starting with the value after
///         the provided value.
/// @param start The first value to get overwritten in the leftward shift.
void Deck::shiftLeft(size_t start) 
{
    for (size_t i = start; i+1 < dk.size(); ++i)
    {
        dk.at(i) = dk.at(i+1);
    }
}


// ===========================================================================
// Functionality implementations added asynchronously after 06-04-2025 lecture
// ===========================================================================

/// @brief return the top card from the deck
///     (top is the front, index 0, of the vector)
/// @return the top Card in the deck
/// @post the drawn Card no longer exists in the deck
Card Deck::drawTop()
{
    // If the deck is empty return the generic card using default constructor
    // this avoids the program crashing using at(0) or pop_back on an empty
    // container.
    if (empty())
    {
        return {};
    }

    // We need to store the top so that we can return
    // it later as our algorithm will remove it from
    // the deck.
    Card copy = dk.at(0);

    // Iterate over and shift cards towards the beginning
    // of the deck, eliminating the first card and creating
    // a duplicate at the end that can be popped off.
    shiftLeft(0);

    // Elimate the last element from the vector representation of the deck
    // as it is now a duplicate after shifting.
    dk.pop_back();

    // Could replace both of the above lines with this
    // removeCard(0);

    // Finally we return the copy we previously created and stored.
    return copy;
} 

/// @brief Internal (private) member function to remove the Card 
///         at the specified index from the deck.
/// @param index the location of the Card to remove from the deck
void Deck::removeCard(size_t index) 
{
    // when we are the last index, no shifting is necessary
    if(index+1 != dk.size())
    {
       shiftLeft(index);
    }

    dk.pop_back();
}



// =====================================================
// Functionality implementations from 06-05-2025 lecture
// =====================================================

// Linear Search 
// 1. create or acquire Card to look for
// 
// repeat these until no more deck
// 2. get a card from the deck
// 3. compare to that card, did we find what we are looking for?

uint Deck::searchLinear(const Card &c) const
{
    for(uint i = 0; i < deckSize(); ++i)
    {
        if(c == dk.at(i))
        {
            return i;
        }
    }

    return -1;
}

Card Deck::findMinCard() const
{
    if(empty())
    {
        return {}; // calls Card()
    }

    // first minimum?
    Card min = dk.at(0);


}

// bool Deck::searchLinear(const Card &c, int &spot) const
// {
//     for(size_t i = 0; i < deckSize(); ++i)
//     {
//         if(c == dk.at(i))
//         {
//             spot = i;
//             return true;
//         }
//     }

//     return false;
// }

