/// @file 20260604_LiveSession9.cpp
/// @author Adam T Koehler, PhD
/// @date June 4, 2026
/// @brief Code and lecture notes from the live session. Requires -std=c++20
///         Example compilation command: 
///             g++ -std=c++20 20260604_LiveSession9.cpp 

#include <array>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>
#include "card.h"
#include "deck.h"

using namespace std;

void DeckExamples();

/// @brief main function for running our examples
/// @param argc the number of command line arguments
/// @param argv the array containing c-strings of command line args
int main(int argc, char *argv[])
{
    // no second command line argument, run all examples
    if (argc > 1 && isdigit(argv[1][0]))
    {       
        switch(atoi(argv[1]))
        {
            case 1:
                DeckExamples();   
                break;
            
            default:
                break;
        }
    }
    else
    {
        // could not parse or did not find extra command line argument
        // therefore just run everything
        DeckExamples();       
    }    
    return 0;
}


void DeckExamples()
{
    array<string, 4> suits = {"Clubs", "Diamonds", "Hearts", "Spades"};
    array<string, 13> faces = {"Ace", "2", "3", "4", "5", 
                               "6",   "7", "8", "9", "10", 
                               "Jack", "Queen", "King" };

    Deck playingCards;
    Deck original;

    // Initialize Deck in sorted order
    for(const auto &e : suits)
    {
        for(const auto& f : faces)
        {
            if("Clubs" == e || "Spades" == e)
            {
                original.addCard(Card(f,e,false));
                playingCards.addCard(Card(f,e,false));
            }
            else
            {
                original.addCard(Card(f,e,true));
                playingCards.addCard(Card(f,e,true));
            }
        }
    }

    // Print the Deck object
    cout << "Original Deck Order" << endl;
    cout << "===================" << endl;
    playingCards.printDeck();

    cout << endl << endl << endl;

    // Scramble
    playingCards.scramble();

    // Print the Deck object
    cout << "Scrambled Deck Order" << endl;
    cout << "====================" << endl;
    playingCards.printDeck();


    cout << endl << endl << endl;

    // sort the Deck object
    playingCards.sortDeck();

    // Print the Deck object
    cout << "Sorted Deck Order" << endl;
    cout << "=================" << endl;
    playingCards.printDeck();

    cout << endl << endl << endl;

    // Verify that the decks are the same using the string conversions
    if(original.to_string() == playingCards.to_string())
    {
        cout << "Sorted deck is the same as the original!" << endl;
    }
    else
    {
        cout << "Uh oh. Sorted deck is different." << endl;
    }
}