/// @file 20240604_hand.h
/// @author Adam T Koehler, PhD
/// @date June 4, 2024
/// @brief A hand of cards using a Linked List as the underlying
///     implementation for the hand representation. The CardNode class
///     is a node container for a Card that has a pointer to the next Card
///     in the hand (Linked List).
///
///     New functionality that is added beyond the first lecture will exist at end
///     at the end of the class after comment about lecture date that featured the
///     the live additions to the class.

#pragma once

#include <iostream>
#include "20240530_card.h" // Date in file name is the same due to no changes
#include "20240604_deck.h"

using namespace std;

/// @brief A CardNode class to contain our indivual Cards and
///     a pointer to the next CardNode in our linked list.
class CardNode
{
    public:
        Card value;
        CardNode* next;

        /// @brief constructor for easy creation of CardNode objects
        /// @param v the Card that will be contained within this CardNode
        CardNode(const Card &v)
        {
            value = v;
            next = nullptr;
        }
};

/// @brief A hand of cards that utilzes a Linked List as the underlying
///     representation for collecting the Cards.
class Hand
{
    private:
        CardNode *front;
        CardNode *back;

    public:
        /// @brief Default constructor for Hand simply initializes
        ///     the front and back data member pointers to nullptr
        Hand()
        {
            front = nullptr;
            back = nullptr;
        }

        /// @brief Destructor for the Hand class that traverses
        ///     the linked list to release all the memory one CardNode
        ///     at a time.
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

        /// @brief Adds a provided CardNode to the front of the Linked List
        /// @param toAdd pointer to cardNode to insert into the Linked List
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

        /// @brief Print out the linked list card by card
        /// @param backwards true when we want to print the list backwards
        void printHand(bool backwards=false) const
        {
            if (backwards)
            {
                recursivePrint(front);
            }
            else
            {
                iterativePrint();
            }    
        }

        // A user does not generally get to choose iterative versus
        // recursive unless there are known advantages to one versus the
        // other and then it would make sense to make these functions 
        // public and allow the user to decide.
        //
        // Here we will treat them as internal algorithms that are part
        // of the internal class design. Iterative for forward and recursive
        // for reverse printing.
        //
        // Note that recusion does not imply backwards printing
        // it is just that our implementation yields that.
        
        private:
        /// @brief Printing the linked list one CardNode at a time.
        /// Here we use an iterative implementation to demonstrate
        /// forward traversal and printing of the linked list.
        void iterativePrint() const
        {
            CardNode* travel = front;

            while(travel != nullptr)
            {
                cout << (travel->value).to_string() << endl;
                travel = travel->next;
            }
        }

        private:
        /// @brief Print out the linked list using recursion to 
        ///     print the list backwards.
        /// @param cur pointer to a CardNode in the linked list 
        void recursivePrint(CardNode* cur) const
        {
            // base case (stopping)
            if (cur == nullptr)
            {
                return;
            }

            // nothing to do before the recursive call for this
            // algorithm's recursive implementation

            // recurisve case (smaller sub problem)
            recursivePrint(cur->next);

            // current function call's action: pocess something, 
            // calculate something, or act on something. 
            // In this recursive function we are just going to
            // output this call's Card value as a string.
            cout << cur->value.to_string() << endl;
        }
};