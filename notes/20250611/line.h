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
        // a spot "container" for each node of the linked list
        typedef struct Spot {
            Person* p;
            Spot* next;
        } Spot;

        // linked list properties
        // having access to the tail allows interaction with the end
        // of the linked list to be more easily achieved for adding
        // items to the end of the list.
        Spot* head;
        Spot* tail;

        // we can keep track of the size so that we do not need to 
        // loop through the entire linked list to calculate the quantity
        // of nodes (Spots) in the list.
        size_t curSize;

    public:
        /// @brief default constructor initilizes and empty list
        Line() : head(nullptr), tail(nullptr), curSize(0) {}

        /// @brief accessor method for the person at the front of the line
        ///         Since we join the line with add the person at the head of the 
        ///         linked list then the front of the line is the first person added
        ///         or the person at the tail of the linked list.
        /// @return a pointer to the person at the front of the line
        Person* front() { return tail->p; }
        
        /// @brief accessor method for the person at the back of the line
        ///         since we join the line with add the person at the head of the 
        ///         linked list then the back of the line is the last person added
        ///         or the person at the head of the linked list.
        /// @return a pointer to the person at the back of the line
        Person* back() { return head->p; }

        /// @brief access method for the current size of the linked list
        /// @return the quantity of persons (Spots) in the line
        size_t size() { return curSize; }

     
        /// @brief Using the provided person pointer, 
        ///         add the person to the back of the line.
        ///         We have defined the back as the person closest to the 
        ///         head of the linked list.
        /// @param p the pointer to the person to add to the line
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
        
        /// @brief Print out the names of every person waiting in the line.
        ///        Printing forwards means the first thing printed out is 
        ///         the back of the line
        /// @param backwards true or false, front to back or back to front
        ///         front to back is reverse, default of false prints back to front
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
            cout << endl;
        }

        /// @brief empty the line of all persons in the line
        ///     This empties the linked list and frees dynamically allocated
        ///     memory where appropriate.
        void clear()
        {
            Spot* cur = head;

            while(cur == nullptr)
            {
                Spot* temp = cur;
                cur = cur->next;
                delete temp->p;
                delete temp;
            }

            curSize = 0;
            head = nullptr;
            tail = nullptr;
        }

        /// @brief destructor for the Line object that is automatically
        ///     invoked when an object goes out of scope. We cannot manually 
        ///     call the destructor but the logic is the same as clear() which
        ///     is publicly available.
        virtual ~Line()
        { 
            clear();
        }
        
        /// @brief Copy constructor allows us to create an object 
        ///         from another object during initial creation of an object
        /// @param from the Line to perform a deep copy of and instantiate
        ///         this object with
        Line(const Line &from)
        {
            Spot* cur = from.head;
            curSize = 0;
            head = nullptr;
            tail = nullptr;

            // as we do not have push_back or add_back we need to add the end
            // of the from list first, which is easiest to do recursively.
            recursiveBuilder(cur);
        }
        
        /// @brief assignment operator overload
        /// @param rhs the right hand side of the assignment operator
        /// @return The implicit obect
        Line& operator=(const Line &rhs)
        {
            // first clear out existing 
            clear();
            head = nullptr;
            tail = nullptr;

            // then copy over everything from rhs
            recursiveBuilder(rhs.head);

            return *this;
        }
        

    private:
        /// @brief recursively print out the people in the line in reverse order
        /// @param cur the spot in the linked list to "start" at
        void printRecursive(const Spot *cur)
        {
            // base case: arrive at end of list
            if (cur == nullptr)
            {
                return;
            }

            // recursive case
            printRecursive(cur->next);

            // interact / process / do something
            cout << cur->p->getName();

            // when not head print the link
            if (cur != head)
            {
                cout << "  <-  ";
            }
        }

        /// @brief Loop based printing of the linked list first to last
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

        /// @brief Recusive list builder that allows us to add
        ///         the last linked list item to our list and then work
        ///         back towards the front as we only have a way to add
        ///         to the front of our list
        /// @param cur the current spot we are looking at
        void recursiveBuilder(Spot *cur)
        {
            if(cur == nullptr)
            {
                return;
            }

            recursiveBuilder(cur->next);
            joinLine(new Person(cur->p->getName()));
        }
};
