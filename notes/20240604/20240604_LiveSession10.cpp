/// @file 20240604_LiveSession10.cpp
/// @author Adam T Koehler, PhD
/// @date June 4, 2024
/// @brief Code and lecture notes from the live session. 
///     Topics Covered: Code Traversal, Recursion, Linked Lists.

// Order of the live code from lecture:
// 1. Welcome Activity on function Deck::operator+
// 2. Exploring Deck::opeartor+ in ClassesAndObjectsExamples()
// 3. Post Quiz Activity
// 4. Code developed and placed into hand.h
// 5. LinkedListExamples()
// 6. RecursiveExamples()


// only include the libraries relevante to this file
#include <iostream>
#include <string>

#include "20240530_card.h" // Date in file name is the same due to no changes
#include "20240604_deck.h"
#include "20240604_hand.h"

using namespace std;

// Lecture Parts Prototypes
void ClassesAndObjectsExamples();
void LinkedListExamples();
void RecursiveExamples();


// Welcome Activity: Write a function that takes 
// two Deck objects, combines them such that the first
// Deck is on top of the second in a new combined Deck
// and the function returns the new Deck.
//
// In what situations is this useful?
//
// iClicker:
// In a class, would this be public or private?
// In a class, would this be a const member function?
//
// implemented in the deck.cpp file



// Post Quiz Activity:
// Come up with a way that we could incorporate a Linked List of Cards
// into our Deck & Cards programs. What other ways do we need to collect
// a handful of cards beyond the Deck?
//
// Group Ideas:
// 1. Convert some part of Deck to use Linked Lists as interacting with
//    a Linked List has benefits, for example drawing from the top does
//    not require shifting all of the elements.
//
// 2. Store a portion of the cards such as dealing them out.
//    For example we created 5 piles of 5 cards for Go Fish!
//
// So dealing to create a "hand" for a player could create a 
// linked list per player!
//
// Go Fish!
// 5 players, each has a hand
// Write an algorithm using drawTop from our Deck class and a 
// function named insertFront to build a Linked List for hand for each
// player. We use insertFront because it is best if we only have a head 
// pointer and not both a head and tail.
//
// iClicker: How many times is insertFront called after we have dealt
//           full hands to each of the five players.
//
// Group's Algorithm
// Draw a Card from Deck (drawTop())
// Call insertFront with a node containing that Card.
// Repeat 5 times for each player.
//
// iClicker: 25 calls to insertFront (5 per player)
//
// Code devoloped and moved into hand.h



/// @brief main function for running our examples
/// @param argc the number of command line arguments
/// @param argv the array containing c-strings of command line args
int main(int argc, char *argv[])
{
    // 0 on command line runs recursion examples   
    // 1 on command line runs linked list examples
    // no second command line argument, run both
    if (argc > 1 && isdigit(argv[1][0]))
    {       
        switch(atoi(argv[1]))
        {
            case 0:
                ClassesAndObjectsExamples();   
                break;

            case 1:
                LinkedListExamples();
                break;

            case 2:
                RecursiveExamples();
                break;
            
            default:
                break;
        }
    }
    else
    {
        // could not parse or did not find extra command line argument
        // therefore just run everything
        ClassesAndObjectsExamples();

        cout << endl << endl;
        LinkedListExamples();
        
        cout << endl << endl;  
        RecursiveExamples();  
        
    }

    return 0;
}



/// @brief live code developed for the recursion portion 
///     of the live lecture
void ClassesAndObjectsExamples()
{
    // We are not using any dynamic memory allocations in this example
    // so we do not use the new operator to get memory from the heap.
    // We will simply create objects on the Stack instead of creating
    // pointers to objects on the Heap.

    cout << "Classes & Objects Examples" << endl;
    cout << "==========================" << endl << endl;

    cout << "Exploring the operator+ for the Deck class" << endl;
    cout << "==========================================" << endl << endl;

    // Recall previously we had two choices when using an operator
    // we can combine and use the result immediately but not have it 
    // stored for later use or we can store it and use the result variable.
    int x = 5;
    int y = 7;
    cout << "Recall two choices..." << endl;
    cout << "Combined & use immediately - cout << x+y" << endl;
    cout << x + y << endl << endl;

    // combine and store into a variable
    int r = x + y;
    cout << "Combined & stored - r = x+y; cout << r;" << endl;
    cout << r << endl;

    cout << endl << endl;

    // Build two decks by adding a few cards to each Deck
    Deck a, b;
    a.addCardBottom(Card("Ace", "Clubs", false));
    a.addCardBottom(Card("2", "Hearts", true));
    b.addCardBottom(Card("Ace", "Spades", false));

    // For quick reference let's print out the two Decks a and b
    cout << "Deck a:" << endl;
    a.printDeck();
    cout << endl;

    cout << "Deck b:" << endl;
    b.printDeck();
    cout << endl;

    cout << "We have a similar choice with all function invocations";
    cout << endl << "and operator uses that return a value." << endl << endl;

    // Use operator+ overload on Deck objects to combine into a new Deck
    // then use the result immediately
    cout << "Combined & used immediately, (a+b).printDeck();" << endl;
    (a+b).printDeck();
    cout << endl;

    // Use operator+ overload on Deck objects to combine into a new Deck
    // then store the result for future use
    cout << "Combined & stored, Deck c = a + b; c.printDeck();" << endl;
    Deck c = a + b;
    c.printDeck();   
}



/// @brief live code developed for the linked lists portion 
///     of the live lecture
void LinkedListExamples()
{
    cout << "Linked Lists Examples" << endl;
    cout << "=====================" << endl << endl;

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

    // We have some number of players so we will create a hand for
    // each player. We can store pointers to dynamically allocated
    // Hand objects in a single vector.
    vector<Hand *> players;

    // We will have 5 players, each will have 5 cards for our Go Fish!
    // dealing of hands.
    // We could put this in a 0 through 4 inclusive loop
    players.push_back(new Hand());
    players.push_back(new Hand());
    players.push_back(new Hand());
    players.push_back(new Hand());
    players.push_back(new Hand());

    // Draw the top 5 cards and place them into the front of
    // player 1's hand one by one
    for (size_t i = 0; i < 5; i++)
    {
        players.at(0)->insertFront(new CardNode(playingCards.drawTop()));
    }

    // Draw the top 5 cards and place them into the front of
    // player 2's hand one by one
    for (size_t i = 0; i < 5; ++i)
    {
        players.at(1)->insertFront(new CardNode(playingCards.drawTop()));
    }

    // Draw the top 5 cards and place them into the front of
    // player 3's hand one by one
    for (size_t i = 0; i < 5; ++i)
    {
        players.at(2)->insertFront(new CardNode(playingCards.drawTop()));
    }

    // Draw 10 random cards placing them in either player 4's hand
    // or player 5's hand one by one (5 per player)
    for (size_t i = 0; i < 10; ++i)
    {
        players.at(3+i%2)->insertFront(
                new CardNode(playingCards.drawRandom()));
    }

    // For every hand, print out the player's hand.
    // Note that insertFront reverses the order of the cards
    // that were drawn as the first insertion is the back of the list.
    int count = 0;
    for(const auto &e : players)
    {
        cout << "Player " << count++ << "'s Hand" << endl;
        e->printHand();
        cout << endl << endl;
    }
}



/// @brief live code developed for the recursion portion 
///     of the live lecture
void RecursiveExamples()
{
    cout << "Recursive Examples" << endl;
    cout << "==================" << endl << endl;

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


    // Let's quickly make a hand for player 1 that is the top
    // ten cards in the deck. This way we can verify our printing
    // based on the text file used with terminal input redirection.

    // Let's make the Hand an object on the Stack rather than a 
    // pointer to an object on the Heap
    Hand player1;
    for(int i = 0; i < 10; ++i)
    {
        // Dynamically allocate a CardNode object on the Heap
        // by invoking the CardNode constructor that takes a Card
        player1.insertFront(new CardNode(playingCards.drawTop()));
    }

    // Without parameters the default value parameter will be false
    // and the hand will print in order of the linked list traversal.
    cout << "Linked List In Order Printing of Hand:" << endl;
    player1.printHand();

    cout << endl << endl;

    // With true as the argument the hand will switch to printing in 
    // reverse order of the linked list traversal.
    cout << "Linked List Reverse Order Printing of Hand:" << endl;
    player1.printHand(true);    
}
