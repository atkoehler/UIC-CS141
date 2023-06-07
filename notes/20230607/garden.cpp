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


Garden::Garden()
{
    numRows = 0;
    firstRow = nullptr;
    lastRow = nullptr;
}

Garden::~Garden()
{
    Row* temp = firstRow;
    // output each plant row in the garden
    while (temp != nullptr)
    {
        Row *del = temp;
        temp = temp->nextRow;
        delete del;
    }
}

void Garden::addFrontRow(const Plant &p)
{


}

void Garden::removeFirstRow()
{

}

void Garden::drawGarden() const
{
    Row* temp = firstRow;
    int counter = 1;

    // output the size of the garden
    cout << "The garden has " << numRows << " row";
    if (numRows != 1)
    {
        cout << "s";
    } 
    cout << "." << endl;

    // output each plant row in the garden
    while (temp != nullptr)
    {
        cout << "Row: " << counter << endl;
        Plant curPlant = temp->p;
        curPlant.display();
        cout << endl;

        temp = temp->nextRow;
    }
}