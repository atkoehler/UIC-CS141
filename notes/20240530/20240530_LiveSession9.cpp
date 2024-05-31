/// @file 20240530_LiveSession9.cpp
/// @author Adam T Koehler, PhD
/// @date May 30, 2024
/// @brief Code and lecture notes from the live session. 
///     C++ Concepts: Searching & Sorting with user defined Classes & Objects

// Order of the live code from lecture:
// 1. card.cpp updates for operator overloading
// 2. deck.cpp updates for sorting
// 3. execute with Card & Deck uses in CardDeckExamples()

// only include the libraries relevante to this file
#include <iostream>
#include <string>

// local header files
#include "20240530_card.h"
#include "20240530_deck.h"

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

    cout << "Let's explore the operator> overload." << endl;
    cout << "=====================================" << endl;
    cout << "We will create three cards..." << endl;
    Card x("Ace", "Clubs", false);
    Card y("Ace", "Hearts", true);
    Card z("Ace", "Hearts", true);

    cout << "   our x Card: " << x.to_string() << endl;
    cout << "   our y Card: " << y.to_string() << endl;
    cout << "   our z Card: " << z.to_string() << endl;

    cout << "When we check y > z we find that..." << endl;      
    if (y > z)
    {
        cout << "   y is larger" << endl;
    }
    else
    {
        cout << "   z is larger or equivalent" << endl;
    }

    cout << "When we check z > x we find that..." << endl;      
    if (z > x)
    {
        cout << "   z is larger" << endl;
    }
    else
    {
        cout << "   x is larger or equivalent" << endl;
    }    


    
    cout << endl << endl << endl;

    // Exploring sorting now that we have comparison
    cout << "Let's explore sorting our Deck." << endl;
    cout << "===============================" << endl;

    // print out all the contents of the created deck
    cout << "We read in data and created " << playingCards.deckSize() 
        << " Cards and inserted them into our Deck." << endl << endl;
    
    cout << "Here is the current deck: " << endl;
    playingCards.printDeck();

    cout << endl;
    cout << "Sorting requires an algorithm, we have chosen Selection Sort, ";
    cout << endl << "and selection sort requires finding a minimum value in "
        << "the unsorted pile." << endl;
    cout << endl;

    cout << endl << endl;
    cout << "Exploring findMinInDeck()" << endl;
    cout << "=========================" << endl;
    cout << "Let's explore the find minimum function for our current Deck."
        << endl;
    cout << "Calling playingCards.findMinInDeck() gives a minimum card index of: ";
    int count = playingCards.findMinInDeck();
    cout << count << endl << endl;
    
    Deck original = playingCards;

    cout << "We will draw the top card until the minimimum card is removed." << endl;
    Card min;
    while (count >= 0)
    {
        min = playingCards.drawTop();
        count--;
    }

    cout << "The minimum card was: " << min.to_string() << endl << endl;

    cout << "Here is the updated deck: " << endl;
    playingCards.printDeck();
    cout << endl;

    cout << "Calling playingCards.findMinInDeck() gives a minimum card index of: ";
    cout << playingCards.findMinInDeck() << endl;


    cout << endl << endl << endl;
    cout << "Now let's explore sorting our Deck" << endl;
    cout << "==================================" << endl;
    cout << endl;
    cout << "Here is the current deck: " << endl;
    playingCards.printDeck();
    cout << endl << endl;

    cout << "Calling playingCards.sortDeck()" << endl << endl;
    playingCards.sortDeck();

    cout << "Here is the deck after sort: " << endl;
    playingCards.printDeck();
    cout << endl << endl;

    cout << "Let's try on our larger original deck." << endl;
    playingCards = original;
    cout << "Here is the current deck: " << endl;
    playingCards.printDeck();
    cout << endl << endl;

    cout << "Calling playingCards.sortDeck()" << endl << endl;
    playingCards.sortDeck();

    cout << "Here is the deck after sort: " << endl;
    playingCards.printDeck();
    cout << endl << endl << endl;


    cout << "Exploring operator+ as another operator overload" << endl;
    cout << "================================================" << endl;
    cout << endl;

    cout << "Not all operators make sense to overload." << endl;
    cout << "Here we overloaded + to concatenate properties and create a Card "
        << "that is " << endl << "black and has a faceValue and suit "
        << "that are concatenations of the cards." << endl;
    cout << endl;

    cout << "x is:   " << x.to_string() << endl;
    cout << "y is:   " << y.to_string() << endl;
    cout << "x+y is: " << (x+y).to_string() << endl;
    cout << endl;

    // We could also store the result into a variable so that we can use
    // the variable again later throughout our program.
    cout << "Storing result, Card q = x + y" << endl;
    Card q = x + y;
    cout << "q is:   " << q.to_string() << endl;
}