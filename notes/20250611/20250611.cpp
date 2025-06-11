/// @file 20250611.cpp
/// @author Adam T Koehler, PhD
/// @date June 11, 2025
/// @brief Code and lecture notes from the live session. 

#include <iostream>
#include <string>
#include <vector>
#include "line.h"
#include "person.h"

using namespace std;

void LinkedListExamples();
void Examples2(){}
void Examples3(){}

/// @brief main function for running our examples
/// @param argc the number of command line arguments
/// @param argv the array containing c-strings of command line args
int main(int argc, char *argv[])
{
    // no second command line argument, run all examples
    if (argc > 1 && isdigit(argv[1][0]))
    {       
        switch(atoi(argv[1]))
        {
            case 1:
                LinkedListExamples();   
                break;

            case 2:
                Examples2();
                break;

            case 3:
                Examples3();
                break;
            
            default:
                break;
        }
    }
    else
    {
        // could not parse or did not find extra command line argument
        // therefore just run everything
        LinkedListExamples();

        cout << endl << endl;
        Examples2();
        
        cout << endl << endl;  
        Examples3();  
        
    }    
    return 0;
}


void LinkedListExamples()
{
    // A stack-based instance of a line object
    Line one;

    // A pointer to a dynamically allocated instance of a line object
    Line *two = new Line;
    Line *three = new Line;

    // Create dynamically allocated people
    Person* a = new Person("Alice");
    Person* b = new Person("Bob");
    Person* c = new Person("Charlie");
    Person* d = new Person("Dory");
    Person* e = new Person("Elaine");
    Person *f = new Person("Francine");

    one.joinLine(a);
    one.print();
    cout << endl << endl;

    two->joinLine(b);
    two->joinLine(c);
    two->print();
    cout << endl << endl;

    three->joinLine(e);
    three->joinLine(d);
    three->joinLine(f);
    three->print();
    cout << endl << endl;

    // A collection of pointers to Line objects
    {
        vector<Line *> allLines;
        allLines.push_back(new Line);
        allLines.push_back(two);
        allLines.push_back(three);

        // Index-Based For Loop
        cout << "Collection of Lines:" << endl;
        cout << "Index-Based For Loop Printing:" << endl;
        for (size_t i = 0; i < allLines.size(); ++i)
        {
            allLines.at(i)->print();
            cout << endl;
        }

        cout << endl << endl;

        allLines.front()->joinLine(new Person("George"));

        cout << "For-Each Loop Printing:" << endl;
        for (const auto &e : allLines)
        {
            e->print();
            cout << endl;
        }

        cout << "For-Each Loop Printing Backwards:" << endl;
        for (const auto &e : allLines)
        {
            e->print(true);
            cout << endl;
        }

        // release all the memory for each line
        cout << "Index-Based For Loop Deleting:" << endl;
        for (size_t i = 0; i < allLines.size(); ++i)
        {
            delete allLines.at(i);
        }
    }
}
