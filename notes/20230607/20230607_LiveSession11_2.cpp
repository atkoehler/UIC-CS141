/// @file main.cpp
/// @author Adam T Koehler, PhD
/// @date June 7, 2023
/// @brief Class code and lecture notes from the live session. Building on
///        June 6th Plant class to create a Garden class which is a basic 
///        linked list implementation

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution).

#include <iostream>
#include "plant.h"
#include "garden.h"

using namespace std;

int main()
{
    Plant f("Rose Bush");
    Tree t;

    {
        Garden g;
        t.setType("Spruce");

        g.drawGarden();

        cout << "Adding a " << f.getType() << " to front" << endl;
        g.addFrontRow(f);
    
        cout << endl;
        cout << "Drawing the Garden" << endl;
        g.drawGarden();

        cout << endl;
        cout << "Removing the first Row of the Garden" << endl;
        g.removeFirstRow();

        
        cout << endl;
        cout << "Drawing the Garden" << endl;
        g.drawGarden();

        cout << endl;
        cout << "Adding a " << t.getType() << " to front" << endl;
        g.addFrontRow(t);
        
        cout << endl;
        cout << "Adding a " << f.getType() << " to front" << endl;
        g.addFrontRow(f);
        
        cout << endl;
        cout << "Drawing the Garden" << endl;
        g.drawGarden();

        cout << endl;
        cout << "Garden destructor being called:" << endl;
    }

    cout << endl;
    cout << "Destructor for f and t being called:" << endl;
    return 0;
}