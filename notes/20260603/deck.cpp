/// @file deck.cpp
/// @author Adam T Koehler, PhD
/// @date June 3, 2026
/// @brief Deck class that is continually under development.
///     New functionality that is added in a lecture will exist at end
///     after comment about lecture date that featured the live additions.
///
/// Functionlity Addendum Dates: 06-02, 06-03

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "card.h"
#include "deck.h"

using namespace std;



// ============================================================================
// Functionality implementations asynchronously added after 06-02-2026 lecture
// ============================================================================

Deck::Deck() : rng(rd()) {}


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

/// @brief sends the object's string conversion to output
void Deck::printDeck() const
{
    cout << to_string() << endl;
}




// =============================================================
// Functionality Implementations From 06-03-2025 lecture
// =============================================================

/// @brief combine all elements of the deck
///         into a single string separated
///         by newline
/// @return single string with all the elements
string Deck::to_string() const
{
    string newString; 

    // we could use an index based for loop
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

/// @brief Insert a card into the deck.
/// @param card The card to insert into the deck.
void Deck::addCard(const Card &card)
{
    addCardBottom(card);
}

/// @brief Insert a card into the deck at the bottom of the deck
///     Design Choice: We are choosing that the back of our vector
///         is where the bottom of our deck is.
/// @param card The card to insert into the deck.
void Deck::addCardBottom(const Card &card)
{
    dk.push_back(card);
}

/// @brief Draw a card from the deck.
/// @return The drawn card.
/// @post the drawn Card no longer exists in the deck
Card Deck::draw()
{
    return drawTop();
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



// =============================================================
// Async Functionality Implementations After 06-03-2025 Lecture
// =============================================================


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

/// @brief perform 100 random Card swaps on the deck as a form "shuffling"
void Deck::scramble()
{
    uniform_int_distribution<int> dist(0, deckSize()-1);

    // perform 100 swaps
    for(int i = 0; i < 100; i++)
    {
        size_t index2 = 0;
        size_t index1 = dist(rng);

        // rechoose index2 as long as it matches index1
        while (index1 == index2)
        {
            index2 = dist(rng);
        }

        // Swap the cards
        Card temp = dk.at(index1);
        dk.at(index1) = dk.at(index2);
        dk.at(index2) = temp;
    }
}
