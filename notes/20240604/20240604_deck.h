/// @file 20240604_deck.h
/// @author Adam T Koehler, PhD
/// @date June 4, 2024
/// @brief Deck class that is continually under development.
///     New functionality that is added in a lecture will exist at end
///     after comment about lecture date that featured the live additions.

// We need to use this to prevent our header from being included multiple
// times during compilation.
#pragma once

#include <string>
#include <vector>

#include "20240530_card.h" // Date in file name is the same due to no changes

using namespace std;

/// @brief a Deck class to mimic a deck of cards
class Deck
{
    private:
        vector<Card> dk;

    public:
        /// @brief Acquire the quantity of Cards in the deck.
        /// @return The quantity of Cards in the deck.
        size_t deckSize() const
        {
            return dk.size();
        }

        // New implementations worked on as a class or within
        // group activities.

        // Welcome Activity - Second steps
        string to_string() const;
        void printDeck() const;

        // Function ideas that groups previously came up with.
        // Based on group number, implement as group activity
        // 1. addCardBottom (insert a Card into the Deck)
        void addCardBottom(const Card &);

        // 2. drawTop (pull the top card off the deck)
        Card drawTop(); 

        // 3. drawRandom (pull a random card from the deck)
        Card drawRandom();

        // peekAtTop (get value of top Card)
        const Card& peekAtTop() const;

        // We could define without & and without const and it creates a copy
        // of the top card on the deck and return that. For 
        // efficiency we can just return the object memory address
        // that is at the top since we know it cannot be altered
        // Card peekAtTop() const;

    
    // =====================================================
    // Functionality implementations from 05-29-2024 lecture
    // Added after lecture as that lecture directly update the files.
    // =====================================================
    public:
        bool empty() const;
        
    private:
        void shiftLeft(size_t start);
        void removeCard(size_t index);


    // =====================================================
    // Functionality implementations from 05-30-2024 lecture
    // =====================================================
    public:
        size_t findMinInDeck() const;
        void sortDeck();

    // =====================================================
    // Functionality implementations from 06-04-2024 lecture
    // =====================================================
    public:
        Deck operator+(const Deck &) const;
};