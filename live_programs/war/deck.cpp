/// @file deck.cpp
/// @author Adam T Koehler, PhD
/// @date June 5, 2025
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
    size_t r = rand() % dk.size();
    
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

    removeCard(0);

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

/// @brief Search for a Card within the Deck and return -1 or the location of
///         the first match.
/// @param c The card to search for.
/// @return The matching Card's index within the container, otherwise -1.
size_t Deck::searchLinear(const Card &c) const
{
    for(size_t i = 0; i < deckSize(); ++i)
    {
        if(c == dk.at(i))
        {
            return i;
        }
    }

    return -1;
}


/// @brief Search for a Card within the Deck and return -1 or the location of
///         the first match.
/// @param c The card to search for.
/// @param spot the reference parameter filled with the index of the matched card
/// @return true when the match is discovered, otherwise false
bool Deck::searchLinear(const Card &c, int &spot) const
{
    for(size_t i = 0; i < deckSize(); ++i)
    {
        if(c == dk.at(i))
        {
            spot = i;
            return true;
        }
    }

    return false;
}

/// @brief internal member function to determine the minimum Card in the deck and provide
///     the Card back to the caller along with the index.
/// @param index reference variable that is filled with the index of the minimum Card
/// @return a copy of the Card that is the minimum in the Deck
Card Deck::findMinInDeck(int &index) const
{
    // 0) nothing in the Deck, no Card to return
    index = -1;
    if(empty())
    {
        return {}; // calls Card()
    }

    // 1) set up the first minimum value
    Card min = dk.at(0);

    // 2) iterate over the Deck and determine if a new
    //      minimum needs to be kept
    for(int i = 0; i < deckSize(); ++i)
    {
        // Do we have a new minimum to store?
        if (dk.at(i) < min)
        {
            min = dk.at(i);
            index = i;
        }
    }

    return min;
}

/// @brief internal member function to determine the index of the minimum
///         Card in the deck.
/// @return the index of the minimum Card in the Deck
/// @pre deck is non-empty 
size_t Deck::findMinInDeck() const
{
    size_t retVal = 0;

    // iterate through the Deck of Cards locating the index of the 
    // minimum Card
    for (size_t i = 1; i < deckSize(); i++) 
    {
        // card we are look at is not equivalent and it is smaller
        // need compound conditional due to not having < operator defined
        if (dk.at(i) < dk.at(retVal))
        {
            retVal = i;
        }
    }

    return retVal;
}



// ===========================================================================
// Functionality implementations added asynchronously after 06-05-2025 lecture
// ===========================================================================

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

/// @brief perform 100 random Card swaps on the deck as a form "shuffling"
void Deck::scramble()
{
    // perform 100 swaps
    for(int i = 0; i < 100; i++)
    {
        size_t index2 = 0;
        size_t index1 = rand() % deckSize();

        // rechoose index2 as long as it matches index1
        while (index1 == index2)
        {
            index2 = rand() % deckSize();
        }

        // Swap the cards
        Card temp = dk.at(index1);
        dk.at(index1) = dk.at(index2);
        dk.at(index2) = temp;
    }
}

/// @brief Sort the deck of cards
void Deck::sortDeck()
{
    vector<Card> temp;

    // Selection Sort:
    // go through the vector storing deck of cards
    //  find the minimum card within the Deck (vector of Cards)
    //  place the discovered minimum in the back of the temp vector
    //  find the minimum card from the Deck (vector of Cards)
    //  continue finding, adding, removing until no more cards
    while(!dk.empty())
    {
        size_t indMin = findMinInDeck();
        Card tempCard = dk.at(indMin);
        temp.push_back(tempCard);
        removeCard(indMin);
    }

    // update internal deck representation to the sorted vector
    dk = temp;
}