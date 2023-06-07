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