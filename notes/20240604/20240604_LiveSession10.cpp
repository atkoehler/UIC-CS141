/// @file 20240604_LiveSession10.cpp
/// @author Adam T Koehler, PhD
/// @date June 4, 2024
/// @brief Code and lecture notes from the live session. 
///     Topics Covered: Code Traversal, Recursion, Linked Lists.

// Order of the live code from lecture:
// 1. Welcome Activity on function Deck::operator+


// only include the libraries relevante to this file
#include <iostream>
#include <string>

#include "20240530_card.h"
#include "20240604_deck.h"

using namespace std;


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


// Lecture Parts Prototypes
void RecursiveExamples();
void LinkedListExamples();


/// Linked List Use Cases with our Deck and Cards
/// linked list to store cards -> deck add/remove
/// player gets a hand of 5 cards -> go fish

// dealing
// 4 or 5 players, each has a hand
// drawTop -> insertFront (best if only head ptr)
// vector<CardNode *> hands;

class CardNode
{
    public:
        Card value;
        CardNode* next;
        CardNode(Card v)
        {
            value = v;
            next = nullptr;
        }
};

class Hand
{
    private:
        CardNode *front;
        CardNode *back;
    public:
        Hand()
        {
            front = nullptr;
            back = nullptr;
        }

        virtual ~Hand()
        {
            CardNode* travel = front;

            while(travel != nullptr)
            {
                CardNode* temp = travel;
                travel = travel->next;
                delete temp;
            }
        }

        void insertFront(CardNode *toAdd)
        {
            toAdd->next = front;
            front = toAdd;

            // empty list
            if (back != nullptr)
            {
                back = toAdd;
            }
                
        }
        void printHand() const
        {
            iterativePrint();
            cout << endl << endl;
            recursivePrint(front);
        }

        private:
        void iterativePrint() const
        {
            CardNode* travel = front;

            while(travel != nullptr)
            {
                cout << (travel->value).to_string() << endl;
                travel = travel->next;
            }
        }

        void recursivePrint(CardNode* t) const
        {
            // base case (stopping)
            if (t == nullptr)
                return;

            // recurisve case (smaller sub problem)
            recursivePrint(t->next);

            // current function call action: pocess something, 
            // calculate something, or act on something. 
            // In this recursive function we are just going to
            // output this call's Card value as a string.
            cout << t->value.to_string() << endl;
        }
};


// Recursive Function Prototypes




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
                RecursiveExamples();   
                break;

            case 1:
                LinkedListExamples();
                break;
            
            default:
                Deck a, b;
                a.addCardBottom(Card("Ace", "Clubs", false));
                b.addCardBottom(Card("Ace", "Spades", false));
                cout << "A Deck: " << endl;
                a.printDeck();
                cout << "B Deck: " << endl;
                b.printDeck();
                cout << "Combined:" << endl;
                // (a+b).printDeck();
                Deck c = a + b;
                c.printDeck();
                // int x = 5;
                // int y = 7;
                // cout << x + y << endl;

                break;
        }
    }
    else
    {
        // could not parse or did not find extra command line argument
        // therefore just run everything
        RecursiveExamples();  
        cout << endl << endl;
        LinkedListExamples();  
    }

    return 0;
}



/// @brief live code developed for the recursion portion 
///     of the live lecture
void RecursiveExamples()
{
    cout << "Recursive Examples" << endl;
    cout << "==================" << endl << endl;
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



    Hand player1;
    vector<Hand *> players;

    players.push_back(new Hand());
    players.push_back(new Hand());
    players.push_back(new Hand());

    for (size_t i = 0; i < 5; i++)
    {
        players.at(0)->insertFront(new CardNode(playingCards.drawTop()));
    }

    for (size_t i = 0; i < 5; ++i)
    {
        players.at(1)->insertFront(new CardNode(playingCards.drawTop()));
    }

    for (size_t i = 0; i < 5; ++i)
    {
        players.at(2)->insertFront(new CardNode(playingCards.drawTop()));
    }

    for(const auto &e : players)
    {
        cout << "Player Hand" << endl;
        e->printHand();
        cout << endl << endl;
    }

}


