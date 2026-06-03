/// @file deck.h
/// @author Adam T Koehler, PhD
/// @date June 2, 2026
/// @brief Definition for the Deck class. Functionality in the
///         the deck.cpp file. Continually developed. New implementations are
///         often timestamped with the leture date within the .cpp file.

#pragma once

#include "card.h"
#include <random>
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
//      compare decks
//      drawBottom/Top/Middle/Random()
//      display/print
//      sort()
//          * sort by card characteristic?
//          * To achieve sort we may need to modify Card to have a rank


/// @brief Collection class for Card objects
class Deck
{
    private:
        vector<Card> dk;
        random_device rd;
        mt19937 rng;

    public:
        Deck();
        string to_string() const;
        void printDeck() const;

        // Deck Internal State Checks/Getters
        bool empty() const;
        size_t deckSize() const;

        // Deck Interactions
        Card draw(); 
        void addCard(const Card &);
        void scramble();
        Card drawRandom();


        // We could define without & and without const and it creates a copy
        // of the top card on the deck and return that. But that breaks the
        // design of the card is either with the player or in the deck, not
        // in multiple locations. Also, for efficiency reasons, we can just 
        // return the object memory address that is at the top since we 
        // know it cannot be altered
        // Card peekAtTop() const;

        const Card& peekAtTop() const;

    // Private functions are accessible from within the Deck class but are
    // not accessible to users of the class. So the following IS NOT possible:
    //          Deck b; 
    //          b.drawBottom();
    private:
        Card drawTop();
        Card drawBotton();
        void addCardBottom(const Card &);
        void shiftLeft(size_t start);
        void removeCard(size_t index);
};