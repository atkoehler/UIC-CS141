/// @file war.cpp
/// @author Adam T Koehler, PhD
/// @date June 6, 2025
/// @brief Code for implementation of the card game War.

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "card.h"
#include "deck.h"

using namespace std;

// from utils.cpp
extern void clearScreen();
extern void pause(float scale=1);
void resetColors();
void setRedBackground();
void setGreenBackground();


void initDeck(Deck &);
uint warRank(const Card &);

const bool pauseForInteraction = false;

/// @brief main function for running our examples
/// @param argc the number of command line arguments
/// @param argv the array containing c-strings of command line args
int main(int argc, char *argv[])
{
    bool warFail = false;
    int p1CardsPickedUp = 0;
    int p2CardsPickedUp = 0;
    int draws = 0;
    int warCount = 0;
    int p1MaxSize = 0, p2MaxSize = 0;
    int p1MinSize = 0, p2MinSize = 0;

    string dummy;
    random_device rd;
    srand(rd());

    // srand(2025);

    Deck cards;
    initDeck(cards);
    cards.scramble();

    Deck player1;
    Deck player2;
    while(!cards.empty())
    {
        player1.addCardBottom(cards.drawTop());
        player2.addCardBottom(cards.drawTop());
    }

    p1MaxSize = p1MinSize = player1.deckSize();
    p2MaxSize = p2MinSize = player2.deckSize();

    cout << "Begin the game (enter to continue)" << endl;
    getline(cin,dummy);

    while(!player1.empty() && !player2.empty())
    {
        warFail = false;
        vector<Card> pile;
        Card p1, p2;

        clearScreen();
        pause(10);
        cout << "Game of War Status" << endl;
        cout << "==================" << endl;
        cout << "Player 1: " << player1.deckSize() << " cards" << endl;        
        cout << "Player 2: " << player2.deckSize() << " cards" << endl;

        cout << endl << endl;
        cout << "   DRAW!   " << endl;
        cout << endl << endl;
        pause(10);

        p1 = player1.drawTop();
        p2 = player2.drawTop();

        // place drawn cards into pile for later acquisition
        pile.push_back(p1);
        pile.push_back(p2);

        draws++;
        cout << "Player 1 draws a " << p1.getFaceValue() << endl;
        cout << "Player 2 draws a " << p2.getFaceValue() << endl;
        cout << endl << endl;
        pause(10);

        // Go to war when equal!
        while(warRank(p1) == warRank(p2))
        {
            cout << endl << endl << " <<<   WAR   >>> " << endl << endl;
            warCount++;

            cout << "Three cards contributed to the pile per player." << endl;
            cout << endl;

            // each player draws 3 unseen
            for (int i = 0; i < 3 && (!player1.empty()) && (!player2.empty()); ++i)
            {
                pile.push_back(player1.drawTop());
                pile.push_back(player2.drawTop());
            }

            // either player out of cards?
            if (player1.empty() || player2.empty())
            {
                warFail = true;
                break;
            }

            // each player draws 1 more to determine winner
            p1 = player1.drawTop();
            p2 = player2.drawTop();

            // place drawn cards into pile for later acquisition
            pile.push_back(p1);
            pile.push_back(p2);

            draws++;
            cout << "Player 1 draws a " << p1.getFaceValue() << endl;
            cout << "Player 2 draws a " << p2.getFaceValue() << endl;
            pause(10);
        }

        // either player out of cards?
        if (warFail)
        {
            cout << "Oh no! Someone ran out of cards during WAR!" << endl;
            cout << endl << endl;
            break;
        }

        // who won the draw?
        if (warRank(p1) > warRank(p2))
        {
            cout << "Player 1 wins the draw." << endl << endl;
            cout << "Player 1 acquires " << pile.size() << " cards." << endl << endl;
            p1CardsPickedUp += pile.size();
            for(Card e : pile)
            {
                player1.addCardBottom(e);
            }

            if (p1MaxSize < player1.deckSize())
            {
                p1MaxSize = player1.deckSize();
            }

            if (p1MinSize > player1.deckSize())
            {
                p1MinSize = player1.deckSize();
            }
        }
        else
        {
            cout << "Player 2 wins the draw." << endl << endl;
            cout << "Player 2 acquires " << pile.size() << " cards." << endl << endl;
            p2CardsPickedUp += pile.size();
            for(Card e : pile)
            {
                player2.addCardBottom(e);
            }

            if (p2MaxSize < player2.deckSize())
            {
                p2MaxSize = player2.deckSize();
            }

            if (p2MinSize > player2.deckSize())
            {
                p2MinSize = player2.deckSize();
            }
        }

        if (pauseForInteraction)
        {
            cout << endl << endl << "(enter to continue)" << endl << endl;
            getline(cin, dummy);
        }
        else
        {
            pause(40);
        }
    }

    if (p1MaxSize < player1.deckSize())
    {
        p1MaxSize = player1.deckSize();
    }

    if (p1MinSize > player1.deckSize())
    {
        p1MinSize = player1.deckSize();
    }

    if (p2MaxSize < player2.deckSize())
    {
        p2MaxSize = player2.deckSize();
    }

    if (p2MinSize > player2.deckSize())
    {
        p2MinSize = player2.deckSize();
    }

    clearScreen();

    // Declare a game winner base on who doesn't have an empty deck
    if(player2.empty())
    {
        cout << endl;
        cout << "===========================" << endl;
        cout << "| ";
        setGreenBackground();
        cout << "Player 1 wins the game!";
        resetColors();
        cout << " |" << endl;
        cout << "===========================" << endl;

    }
    else
    {
        cout << endl;
        cout << "===========================" << endl;
        cout << "| ";
        setRedBackground();
        cout << "Player 2 wins the game!";
        resetColors();
        cout << " |" << endl;
        cout << "===========================" << endl;
    }

    cout << endl << endl;
    cout << "Game of War Stats" << endl;
    cout << "=================" << endl;
    cout << "Draws: " << draws << endl;
    cout << "Times at War: " << warCount << endl;
    cout << "Cards Acquired by Player 1: " << p1CardsPickedUp << endl;
    cout << "Cards Acquired by Player 2: " << p2CardsPickedUp << endl;
    cout << "Largest Deck Size for Player 1: " << p1MaxSize << endl;
    cout << "Largest Deck Size for Player 2: " << p2MaxSize << endl;
    cout << "Smallest Deck Size for Player 1: " << p1MinSize << endl;
    cout << "Smallest Deck Size for Player 2: " << p2MinSize << endl;

    return 0;
}


void initDeck(Deck &playingCards)
{
    vector<string> suits = {"Clubs", "Diamonds", "Hearts", "Spades"};
    vector<string> faces = 
        {"Ace", "Two", "Three", "Four", 
         "Five", "Six", "Seven", "Eight", "Nine", 
         "Ten", "Jack", "Queen", "King"};

    // Initialize Deck in sorted order
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


string makeLowerCase(const string &con)
{
    string converted = con;

    // convert every alphabetic character in the converted
    // string to a lowercase character
    for (auto &ch : converted)
    {
        if (isalpha(ch))
        {
            ch = tolower(ch);
        }
    }

    return converted;
}

uint warRank(const Card &c)
{
    vector<string> ranks = 
        {"", "", "two", "three", "four", 
         "five", "six", "seven", "eight",
         "nine", "ten", "jack", "queen", "king", "ace"};

    string face = makeLowerCase(c.getFaceValue());
    // check every rank and see if this card's face value matches
    for (size_t i = 0; i < ranks.size(); ++i)
    {
        if (ranks.at(i) == face)
        {
            return i;
        }
    }

    return -1;
}
