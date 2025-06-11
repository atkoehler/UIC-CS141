/// @file line.h
/// @author Adam T Koehler, PhD
/// @date June 11, 2025
/// @brief Definition for the Line class to demonstrate Linked Lists

// We need to use this to prevent our header from being included multiple
// times during compilation.
#pragma once

#include <string>
#include "person.h"

using namespace std;

class Line
{
    private:
        typedef struct Spot {
            Person* p;
            Spot* next;
        } Spot;

        Spot* head;
        Spot* tail;
        size_t curSize;

    public:
        Line() : head(nullptr), tail(nullptr), curSize(0) {}
        Person* front() { return head->p; }
        Person* back() { return tail->p; }
        size_t size() { return curSize; }

        // place someone at the back of the line
        void joinLine(Person *p)
        {
            Spot* toAdd = new Spot;
            toAdd->p = p;
            toAdd->next = head;

            // empty list? update tail
            if (tail == nullptr)
            {
                tail = toAdd;
            }

            head = toAdd;
            curSize++;
        }
        
        // print out the occupants of each spot in the line
        void print(bool backwards=false) 
        { 
            string front; 

            // empty list?
            if (head == nullptr)
            {
                front = "Front: (empty)";
            }
            else
            {
                front = "Front: " + head->p->getName();
            }

            // Output note to note the front of the list
            string fill(front.size(), '-');
            cout << "Size: " << size() << endl 
                << front << endl << fill << endl;

            // Print the list with a private helper function
            if (head == nullptr)
            {
                cout << "(empty)";
            }
            else if (backwards)
            {
                printRecursive(head); 
            }
            else
            {
                printIterative();
            }
            cout << endl << endl;
        }

        // empty the line, freeing memory as appropriate
        void clear(){}

        // destructor
        virtual ~Line()
        { 
            cout << "Destroying Line Starting With " 
                << head->p->getName() << endl; 
        }
        
    private:
        void printRecursive(const Spot *cur)
        {
            cout << "TODO" << endl;
        }

        void printIterative()
        {
            Spot* cur = head;

            while (cur != nullptr)
            {
                cout << cur->p->getName();
                if (cur->next != nullptr)
                {
                    cout << "  <-  ";
                }

                cur = cur->next;
            }
        }
};
