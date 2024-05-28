/// @file 20240528_LiveSession7.cpp
/// @author Adam T Koehler, PhD
/// @date May 28, 2024
/// @brief Code and lecture notes from the live session. 
///     C++ Concepts: Classes & Objects

// Order of the live code from lecture:
// 1. card.cpp additional functions for Card class
// 2. deck.cpp additional functions for Deck class
// 3. execute with Card & Deck uses in CardDeckExamples()

// only include the libraries relevante to this file
#include <iostream>
#include <string>

// local header files
#include "20240528_card.h"
#include "20240528_deck.h"

using namespace std;


// Lecture Parts Prototypes
void CardDeckExamples();


/// @brief main function for running our examples
/// @param argc the number of command line arguments
/// @param argv the array containing c-strings of command line args
int main(int argc, char *argv[])
{
    if (argc > 1 && isdigit(argv[1][0]))
    {
        // 01 on command line argument means run Class & Object examples        
        switch(atoi(argv[1]))
        {
            case 0:
                CardDeckExamples();   
                break;
            
            default:
                break;
        }
    }
    else
    {
        // could not parse or did not find extra command line argument
        // therefore just run everything
        CardDeckExamples();    
    }

    return 0;
}


/// @brief live code developed for objects and classes portion 
///     of the live lecture
void CardDeckExamples()
{
    cout << "Card & Deck Time!" << endl;
    cout << "=================" << endl << endl;

    Deck playingCards;
    string value, suit, color;

    // Build a deck from user input
    // input order: value suit color (whitespace separated)
    // "Joker" does not have a suit
    // "DONE" will be in first input (value)
    do
    {
        // acquire the face value of the card
        cin >> value;        

        // do not grab more inputs when DONE was found
        if (value != "DONE")
        {                        
            // acquire additional card information
            if ("Joker" == value)
            {
                suit = ""; 
                cin >> color;
            }
            else
            {
                cin >> suit >> color;
            }

            // create a card and insert it into the deck
            playingCards.addCardBottom(Card(value,suit,color=="red"));
        }
    }while (value != "DONE");

    // print out all the contents of the created deck
    cout << "Here is the deck: " << endl;
    playingCards.printDeck();


    // post class usage examples
    cout << endl << endl;
    cout << "Test black card without suit and to_string:" << endl;
    Card x("Test", "No Suit", false);
    cout << x.to_string() << endl;

    cout << endl;
    cout << "Top card on deck (peekAtTop, Card's to_string):" << endl;
    cout << playingCards.peekAtTop().to_string() << endl;

    cout << endl;
    cout << "Draw top card on deck (drawTop, Card to_string):" << endl;
    cout << playingCards.drawTop().to_string() << endl;

    cout << endl;
    cout << "Top card on deck (peekAtTop, Card's to_string):" << endl;
    cout << playingCards.peekAtTop().to_string() << endl;

    cout << endl;
    cout << "Here is the deck before the random pull: " << endl;
    playingCards.printDeck();

    cout << endl;
    cout << "Draw random card (drawRandom, Card to_string):" << endl;
    Card r = playingCards.drawRandom();
    cout << r.to_string() << endl;

    cout << endl;
    cout << "Here is the deck after the random pull: " << endl;
    playingCards.printDeck();
}