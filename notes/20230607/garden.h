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