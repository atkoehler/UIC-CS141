/// @file deck.h
/// @author Adam T Koehler, PhD
/// @date June 3, 2025
/// @brief Definition for the Deck class. Functionality in the
///         the deck.cpp file. Continually developed. New implementations are
///         often timestamped with the leture date within the .cpp file.

#pragma once

#include "card.h"
#include <vector>
#include <string>
#include <iostream>


using namespace std;

// Class/Object Design
// data members
//      vector<Card> vs 
//      Card arr[52], size, capacity
//
// functionality
//      shuffle()
//      drawBottom/Top/Middle/Random()
//      display/print
//      sort()
//          * To achieve sort we may need to modify Card to have a rank


/// @brief Collection class for Card objects
class Deck
{
    private:
        vector<Card> dk;

    public:
        string to_string() const;
        void printDeck() const;

        bool empty() const;
        size_t deckSize() const;

        void addCardBottom(const Card &);
        // const Card& peekAtTop() const;
        Card drawTop(); 
        Card drawRandom();
        uint searchLinear(const Card &c) const;

        Card findMinCard(int &) const;

        // We could define without & and without const and it creates a copy
        // of the top card on the deck and return that. For 
        // efficiency we can just return the object memory address
        // that is at the top since we know it cannot be altered
        // Card peekAtTop() const;

    private:
        void shiftLeft(size_t start);
        void removeCard(size_t index);
};