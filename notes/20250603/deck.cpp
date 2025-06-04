/// @file deck.cpp
/// @author Adam T Koehler, PhD
/// @date June 3, 2025
/// @brief Deck class that is continually under development.
///     New functionality that is added in a lecture will exist at end
///     after comment about lecture date that featured the live additions.

#include <iostream>
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
