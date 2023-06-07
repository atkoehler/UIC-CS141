/// @file garden.h
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

#pragma once

#include <iostream>
#include "plant.h"

using namespace std;

struct Row
{
    Plant p;
    Row* nextRow;
};

class Garden
{
    private:
        int numRows;
        Row* firstRow;
        Row* lastRow;

    protected:

    public:
        Garden();
        ~Garden();
        void addFrontRow(const Plant &p);
        void removeFirstRow();
        void drawGarden() const;
};