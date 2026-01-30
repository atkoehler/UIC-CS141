/// @file 20250612.cpp
/// @author Adam T Koehler, PhD
/// @date June 12, 2025
/// @brief Code and lecture notes from the live session. 

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include "deck.h"

using namespace std;

void sortCallExamples();
void Examples2();
void Examples3();
void Examples4();

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
                sortCallExamples();   
                break;

            case 2:
                Examples2();
                break;

            case 3:
                Examples3();
                break;

            case 4:
                Examples4();
                break;
            
            default:
                break;
        }
    }
    else
    {
        // could not parse or did not find extra command line argument
        // therefore just run everything
        sortCallExamples();

        cout << endl << endl;
        Examples2();
        
        cout << endl << endl;  
        Examples3();  
        
    }    
    return 0;
}


/// @brief live code developed for the Classes & Objects portion 
///     of the live lecture
void sortCallExamples()
{
    cout << "Algorithm's sort() Examples" << endl;
    cout << "===========================" << endl << endl;

    // The sort() function and it's implementation are provided by the
    // algorithm library alongside many other algorithm implementations. 

    // The most basic way to call sort is to invoke it on a container
    // that is allocated in a continuous block of memory such as an array.
    int x[6] = {3, 2, 1, 6, 5, 4};
    cout <<"Array before sorting: ";
    for(int i=0; i < 6; ++i)
        cout << x[i] <<  ' ';
    cout << endl; 

    // We send the start address, which for an array is just its name,
    // and we send the ending address which means just adding the quantity
    // of elements to the initial address for an array. 
    sort(x, x + 6);

    cout << "Array after sorting:  ";
    for(int *valuePtr = x; valuePtr - x < 6; valuePtr++)
        cout << *valuePtr <<  ' ';
    cout << endl; 

    cout << endl;

    // Let's create a vector of numbers
    vector<int> v = {7, 2, 9, 4, 5, 6};

    // Output the pre-sort call vector
    cout <<"Vector before sorting: ";
    for(const auto &e : v)
        cout << e <<  ' ';
    cout << endl;

    // With objects we can use the begin() and end() functions to get
    // pointers to the start and end locations that sort() requires.
    // Here we use the vector member functions as a demonstration.
    sort(v.begin(), v.end());

    cout <<"Vector after sorting:  ";
    for(const auto &e : v)
        cout << e <<  ' ';
    cout << endl;

    cout << endl;


    // As we know, a vector can contain any object type, including
    // our own objects. Can sort() still work with our own objects?

    // For our designed classes, we have two possibilities for 
    // invoking the sort() function on a container that contains
    // our own classes. The first way is to define the less than operator
    // (operator<) for our objects as that is what is used by sort().
    // When we do not wish to define that operator, we can pass a 
    // a functor as the third argument to the sort() call. More on functors
    // in future classes!

    // Let's make a vector of Cards using our Card class.
    vector<Card> c;
    c.push_back(Card("Seven", "Clubs", false));
    c.push_back(Card("Three", "Clubs", false));
    c.push_back(Card("Two", "Hearts", true));
    c.push_back(Card("Nine", "Clubs", false));
    c.push_back(Card("Ace", "Clubs", false));

    cout << "Vector of Card objects before sort():" << endl;
    for(const auto &e : c)
        cout << e.to_string() << endl;
    cout << endl;

    // Since we have operator< defined for Card class the call to sort()
    // is the same as before with a vector of integers.
    sort(c.begin(), c.end());

    cout << "Vector of Card objects after sort():" << endl;
    for(const auto &e : c)
        cout << e.to_string() << endl;
}

void Examples2()
{
    vector<string> suits = {"Clubs", "Diamonds", "Hearts", "Spades"};
    vector<string> faces = 
        {"Ace", "Two", "Three", "Four", 
         "Five", "Six", "Seven", "Eight", "Nine", 
         "Ten", "Jack", "Queen", "King"};

    Deck playingCards;

    // Initialize Deck in sorted order
    for(int i = 0; i < 100; ++i)
    {
        for(const auto &e : suits)
        {
            for(const auto& f : faces)
            {
                if("Clubs" == e || "Spades" == e)
                {
                    playingCards.addCardBottom(Card(f,e,false));
                }
                else
                {
                    playingCards.addCardBottom(Card(f,e,true));
                }
            }
        }
    }

    playingCards.scramble();

    // sort the Deck object
    playingCards.sortDeck();
}

void Examples3()
{
    vector<string> suits = {"Clubs", "Diamonds", "Hearts", "Spades"};
    vector<string> faces = 
        {"Ace", "Two", "Three", "Four", 
         "Five", "Six", "Seven", "Eight", "Nine", 
         "Ten", "Jack", "Queen", "King"};

    Deck playingCards;

    // Initialize Deck in sorted order
    for(int i = 0; i < 1000; ++i)
    {
        for(const auto &e : suits)
        {
            for(const auto& f : faces)
            {
                if("Clubs" == e || "Spades" == e)
                {
                    playingCards.addCardBottom(Card(f,e,false));
                }
                else
                {
                    playingCards.addCardBottom(Card(f,e,true));
                }
            }
        }
    }

    playingCards.scramble();

    // sort the Deck object
    playingCards.sortDeckBuiltIn();
}


void Examples4()
{
    vector<string> suits = {"Clubs", "Diamonds", "Hearts", "Spades"};
    vector<string> faces = 
        {"Ace", "Two", "Three", "Four", 
         "Five", "Six", "Seven", "Eight", "Nine", 
         "Ten", "Jack", "Queen", "King"};

    Deck playingCards1, playingCards2;

    // Initialize Deck in sorted order
    for(size_t i = 0; i < 2; ++i)
    {
        for(const auto& f : faces)
        {
            if("Clubs" == suits.at(i) || "Spades" == suits.at(i))
            {
                playingCards1.addCardBottom(Card(f,suits.at(i),false));
            }
            else
            {
                playingCards1.addCardBottom(Card(f,suits.at(i),true));
            }
        }
    }

    for(size_t i = 2; i < suits.size(); ++i)
    {
        for(const auto& f : faces)
        {
            if("Clubs" == suits.at(i) || "Spades" == suits.at(i))
            {
                playingCards2.addCardBottom(Card(f,suits.at(i),false));
            }
            else
            {
                playingCards2.addCardBottom(Card(f,suits.at(i),true));
            }
        }
    }

    cout << "First Deck:" << endl;
    playingCards1.printDeck();
    cout << endl << endl;


    cout << "Second Deck:" << endl;
    playingCards2.printDeck();
    cout << endl << endl;
    
    cout << "Combined Deck:" << endl;
    (playingCards1+playingCards2).printDeck();
    cout << endl << endl;

    Deck m = playingCards1 + playingCards2;
    cout << "Combined: " << m.deckSize() << endl;
}