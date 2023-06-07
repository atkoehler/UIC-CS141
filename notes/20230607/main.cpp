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
    Garden g;

    Plant f("Rose Bush");
    
    Tree t;
    t.setType("Spruce");

    g.drawGarden();

    g.addFrontRow(f);
    g.drawGarden();

    g.addFrontRow(t);
    g.drawGarden();

    return 0;
}