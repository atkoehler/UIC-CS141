/// @file deck.cpp
/// @author Adam T Koehler, PhD
/// @date June 2, 2026
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



// ============================================================================
// Functionality implementations asynchronously added after 06-02-2026 lecture
// ============================================================================

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
// Functionality Implementations Left For 06-03-2025 lecture
// =============================================================

/// @brief combine all elements of the deck
///         into a single string separated
///         by newline
/// @return single string with all the elements
string Deck::to_string() const
{
    string newString; 


    return newString;
}
