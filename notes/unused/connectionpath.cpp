#include <iostream>
#include <string>

#include "connectionpath.h"

using namespace std;

ConnectionPath::ConnectionPath()
{
    start = nullptr;
    end = nullptr;
}

ConnectionPath::~ConnectionPath()
{
    while(start != nullptr)
    {
        Connection *temp = start;
        start = start->next();
        delete temp;
    }
}

Connection* ConnectionPath::getStart() const
{
    return start;
}

int ConnectionPath::length() const
{
    Connection* travel = start;
    int count = 0;
    while(travel != nullptr)
    {
        count++;
        travel = travel->next();
    }

    return count;
}

void ConnectionPath::printPath() const
{
    Connection* travel = start;
    while(travel != nullptr)
    {
        cout << travel->toString();
        if (travel->next() != nullptr)
            cout << " -> ";
        travel = travel->next();
    }
    cout << endl;
}

void ConnectionPath::printConAddresses() const
{
    Connection* travel = start;
    int count = 0;
    cout << "My Connection Info" << endl;
    cout << "==================" << endl;
    while(travel != nullptr)
    {
        cout << "Connection " << count++ << ":" << endl;
        cout << " Con Address: " << travel << endl;
        cout << " Person Address: " << travel->getPerson() << endl; 
        cout << "  Name: " << travel->getPerson()->getName() << endl;
        if (travel->next() != nullptr)
            cout << endl;
        travel = travel->next();
    }
    cout << endl;
}        

void ConnectionPath::addBack(Connection* toAdd)
{
    if (end != nullptr)
        end->setNext(toAdd);
    
    end = toAdd;

    if (start == nullptr)
    {
        start = end;
    }
}

void ConnectionPath::deleteFront()
{
    if (start != nullptr)
    {
        Connection* temp;
        start = start->next();
        delete temp;
    }
}