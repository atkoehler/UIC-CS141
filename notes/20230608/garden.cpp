/// @file garden.cpp
/// @author Adam T Koehler, PhD
/// @date June 7, 2023
/// @brief Class code and lecture notes from the live session. Building on
///        June 6th Plant class to create a Garden class which is a basic  
///        linked list implementation.

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution).

#include "garden.h"
#include "plant.h"

using namespace std;

/// @brief The default constructor sets the default values 
///         for an empty linked list
Garden::Garden()
{
    numRows = 0;

    // nullptr has grown in use since typed introduction in C++11
    // where it became defined as a pointer data type.
    // This is in opposition to NULL and 0 which were both used in 
    // proliferation prior to C++11 but both are integers. 
    // While all can be valid and converted to the 0x000 address,
    // the nullptr is now consider more correct.
    firstRow = nullptr;
    lastRow = nullptr;
}

/// @brief The class destructor handles the deallocation of all linked list node
///         memory blocks acquired from the heap to delete the entire list one
///         linked list node at a time.
Garden::~Garden()
{
    // We can create a iteration pointer to use to traverse our linked list.
    // In the destructor we could get away with moving the firstRow pointer
    // because we are destroying the entire linked list, but it is normal
    // practice with traversals to create a pointer to use.
    Row* cur = firstRow;
    
    // traverse the list, deleting the nodes as we go
    while (cur != nullptr)
    {
        // we cannot delete the current node first because
        // we need to use the node to traverse to the next
        // node in our linked list
        Row* del = cur;
        cur = cur->nextRow;
        delete del;
    }

    // Clean up or reset the data members of the Garden class
    firstRow = nullptr;
    lastRow = nullptr;
    numRows = 0;
}

/// @brief insert a new row at the front of the garden linked list
/// @param x the Plant to copy into the new row
void Garden::addFrontRow(const Plant &x)
{
    // First we have to create a new row that we want
    // to insert into the garden
    Row* newRow = new Row();

    // Row is a simple struct and doesn't have constructors, so we
    // set the value of the struct's Plant to x after creation.
    // This will use the Plant's assignment operator (operator=)
    newRow->p = x;

    // add 1 as we are creating a new row
    numRows++;

    // The next pointer of the new row will always be the node
    // currently pointed to by firstRow even if firstRow is a nullptr
    newRow->nextRow = firstRow;
    firstRow = newRow;

    // is this the first node in the list?
    // When more than one item in the list
    // We don't touch the last row pointer
    if (numRows == 0)
    {
        lastRow = newRow;  
    }
}

/// @brief remove the first item from the linked list Garden
void Garden::removeFirstRow()
{
    // nothing to do when there isn't anything in the Garden
    if (numRows == 0)
    {
        return;
    }

    // save the pointer to the front before updating
    // so we don't lose that memory address that we need to delete
    Row* del = firstRow;
    firstRow = firstRow->nextRow;
    delete del;
    
    // remember to update the size of the linked list
    numRows--;
}

/// @brief display the size of the Garden and information for each 
///         Row of the Garden
void Garden::drawGarden() const
{
    Row* cur = firstRow;
    int counter = 1;

    // Output the size of the garden
    cout << "The garden has " << numRows << " row";
    if (numRows != 1)
    {
        cout << "s";
    } 
    cout << "." << endl;

    // Output each Plant for every Row in the garden
    while (cur != nullptr)
    {
        // Output the row number and then increment the counter
        cout << "Row: " << counter++ << endl;

        // Plant curPlant = cur->p; // this will create a copy
        // curPlant.display();
        
        // we can avoid creating a copy by using directly
        cur->p.display();
        cout << endl;

        // move on to the next Row in the Garden
        cur = cur->nextRow;
    }
}

/// @brief iteratively search the list for a plant with the specified type
///         this function does not modified the object's private data members
/// @param s the string identifying the type of plant to search for
/// @return true when the specified plant type exists, false otherwise
bool Garden::iterativeSearch(const string &s) const
{
    Row* cur = firstRow;

    while (cur != nullptr)
    {
        if(cur->p.getType() == s)
        {
            return true;
        }
        cur = cur->nextRow;
    } 
    return false;
}

/// @brief recursively search the list for a plant with the specified type
///         this function does not modified the object's private data members
/// @param s the string identifying the type of plant to search for
/// @param cur the current row to be explored in the garden
/// @return true when the specified plant type exists, false otherwise
bool Garden::recursiveSearch(const string &s, Row* cur) const
{
    if (cur == nullptr)
    {
        return false;
    }

    if (cur->p.getType() == s)
    {
        return true;
    }

    return recursiveSearch(s, cur->nextRow);
}

/// @brief search the list for a plant with the specified type
///         this function does not modified the object's private data members
/// @param s the string identifying the type of plant to search for
/// @return true when the specified plant type exists, false otherwise
bool Garden::hasPlantType(const string &s) const
{
    // return iterativeSearch(s);
    return recursiveSearch(s, firstRow);
}