/// @file deck.h
/// @author Adam T Koehler, PhD
/// @date June 3, 2025
/// @brief Definition for the Deck class. Functionality in the
///         the deck.cpp file. Continually developed. New implementations are
///         often timestamped with the leture date within the .cpp file.

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "card.h"


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
    // Synchronous Additions - In-Class Coding & Activities
    private:
        vector<Card> dk;

    public:
        string to_string() const;
        void printDeck() const;
        void addCardBottom(const Card &);
        Card drawRandom();
        size_t searchLinear(const Card &c) const; 
        bool searchLinear(const Card &c, int &spot) const;  

    private:
        void shiftLeft(size_t start);
        Card findMinInDeck(int &index) const;
        size_t findMinInDeck() const;


    // Asynchronous Additions
    public:
        Card drawTop(); 
        bool empty() const;
        size_t deckSize() const;
        void scramble();
        void sortDeck();


        // We could define without & and without const and it creates a copy
        // of the top card on the deck and return that. For 
        // efficiency we can just return the object memory address
        // that is at the top since we know it cannot be altered
        // Card peekAtTop() const;
        const Card& peekAtTop() const;

        Deck operator+(const Deck &rhs) const;
        void sortDeckBuiltIn();

    private:
        void removeCard(size_t index);
};