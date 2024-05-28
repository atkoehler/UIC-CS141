/// @file 20240528_deck.cpp
/// @author Adam T Koehler, PhD
/// @date May 28, 2024
/// @brief Additional functionality developed for the Deck class.
///     Original class and functions developed previously exist as 
///     functions defined directly deck.h. This split is simply for academic
///     learning reasons, we would normally put all our Deck class function
///     definitions all in this C++ file.

#include <iostream>
#include <string>
#include <vector>

#include "20240528_deck.h"


// Welcome Activity Part 2 to_string() & printDeck()

/// @brief Generates a string with all the Cards converted to human readable
///     strings. One card per line.
/// @return the generated string which is not newline terminated
string Deck::to_string() const
{
    // create a return value to buidl the string from all the Cards in deck
    string r;

    // for every Card c in the deck (dk)
    for (const auto &c : dk)
    {
        // Concatenate the Card's string on to collected string.
        // Use Card member function to generate a string and then add newline
        r += c.to_string() + "\n";
    }

    // Was a string built? If so it will have a newline on end that needs to
    // be removed from the string.
    if (r.size() > 0)
    {
        r.pop_back();
    }
    
    return r;
}


/// @brief Output the entire deck's string conversion to the console.
void Deck::printDeck() const
{
    // We should not repeat functionality of to_string, instead we
    // simply invoke the to_string function from within this member function.
    cout << to_string() << endl;
}
    

/// @brief place card at the bottom of the deck
///     (back of vector is bottom)
/// @param c card to insert into the deck
void Deck::addCardBottom(const Card &c)
{
    dk.push_back(c);
}


/// @brief return the top card from the deck
///     (top is the front of the vector)
/// @return the top Card in the deck
/// @post the drawn Card no longer exists in the deck
Card Deck::drawTop()
{
    // We need to store the top so that we can return
    // it later as our algorithm will remove it from
    // the deck.
    Card copy = dk.at(0);

    // Iterate over and shift cards towards the beginning
    // of the deck, eliminating the first card and creating
    // a duplicate at the end that can be popped off.
    for (size_t i = 0; i+1 < dk.size(); ++i)
    {
        // we should have mutators and can just
        // set the values, but we have not defined mutators
        // so we get the values and create a Card
        // dk.at(i) = Card(dk.at(i+1).getFaceValue(),
        //                 dk.at(i+1).getSuit(), 
        //                 dk.at(i+1).isRed());

        // The above is necessary when C++ does not innately
        // know how to copy the object and its data members
        // over to a new object. For example when dealing
        // with dynamic memory in the future.

        // However as our data members are a string, string, and bool
        // we can just copy the Card over as C++ will use concepts similar
        // to pass-by-value function calling to create a copy of the object
        dk.at(i) = dk.at(i+1);
    }

    // When non-empty our algorithm must elimate the last element 
    // from the vector representation of the deck.
    if(dk.size() > 0)
    {
        dk.pop_back();
    }

    // Finally we return the copy we previously created and stored.
    return copy;
} 

/// @brief Draw a random card from the deck.
/// @return the random Card in the deck
/// @post the drawn Card no longer exists in the deck
Card Deck::drawRandom()
{
    // generate a random number bounded to valid indices
    int r = rand() % dk.size();
    
    // store a copy of the Card to return
    Card copy = dk.at(r);

    // shift values towards front starting at the randomly
    // generated index value
    for (size_t i = r; i+1 < dk.size(); ++i)
    {
        dk.at(i) = dk.at(i+1);
    }

    // When non-empty our algorithm must elimate the last element 
    // from the vector representation of the deck.
    if(dk.size() > 0)
    {
        dk.pop_back();
    }

    // Finally we return the copy we previously created and stored.
    return copy;
} 


// const Card& Deck::peekAtTop() const
// const is used twice here!
// first const means the returned reference address cannot be modified
//      we have seen this in for-each loops
// second const prevents changing of data members of the deck object

/// @brief Provide a reference to the top card in the deck so user 
///     can peek at the values of the top most card.
/// @return constant reference to top most Card
const Card& Deck::peekAtTop() const
{
    // Top is the front of the vector, index 0
    // return dk.at(0);

    // Since C++11 we use the front() function (and back() function)
    // front() is defined for several containers to unify the function names
    // to make it easier to use containers without having to memorize or 
    // recall functions that are only for one container or another
    // (in this case vectors). Specific container functions do still exist
    // as they make sense for only that container type.
    return dk.front();
}
