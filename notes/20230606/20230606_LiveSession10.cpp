/// @file 20230606_LiveSession10.cpp
/// @author Adam T Koehler, PhD
/// @date June 6, 2023
/// @brief Class code and lecture notes from the live session split to 
///         header and implementation file.

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution). 

#include <iostream>   
#include "plant.h"

using namespace std;

int main()
{
    // Let's make some plants!
    // Using the default and parameterized constructors
    Plant p,m,o;
    string nm = "tree";
    Plant n(nm);
    
    // We can create poniters to plants too!
    Plant* q = new Plant(nm);
    Plant* r;
    r = &m; // get the address of (&) Plant m


    // Here we set up another scope using the curly braces to force
    // the Plant destructor to be called.
    {
        // copy constructor
        p.setAge(10);

        cout << "Using Copy Constructor to create L and K" << endl;
        Plant L(p);
        Plant K = p;
        
        cout << endl;

        // Using p
        p.bloom();
        cout << "p's memory address: " << &p << endl;

        // Using K which should be a copy of p
        K.bloom();
        cout << "K's memory address: " << &K << endl;

        cout << endl;
        cout << "before assignment: " << endl;
        for(int i = 0; i < 10; ++i)
        {
            cout << K.growthRate[i] << ' ';
        }
        cout << endl;

        // assignment operator (operator=)
        K = n;

        cout << "after assignment: " << endl;
        for(int i = 0; i < 10; ++i)
        {
            cout << K.growthRate[i] << ' ';
        }
        cout << endl;
        cout << endl;

        
        // L and K will get destroyed when it goes out of scope after the
        // following curly brace is hit.
        cout << "Destroying Plant L and Plant K:" << endl;
    }    
    cout << endl;
       
    
    cout << "Using Plants p, q, r:" << endl;

    // Use the Plant objects and Plant pointers
    // the objects can use the dot (.) operator 
    cout << "p: ";
    p.bloom();


    // but the pointers require the arrow (->) operator
    cout << "q: ";
    q->bloom(); 
    
    // the -> is just a C++ operator to do two operations   
    // which dereferences the pointer and then uses the dot operator
    cout << "q: ";
    (*q).bloom();

    cout << "r: ";
    r->bloom();


    // Creating an object of the derived class
    cout << endl;
    cout << "Creating a Tree mine which is derived from a Plant" << endl;
    Tree mine;
    cout << "Tree display function:" << endl;
    mine.display();

    cout << "tree age: ";
    cout << mine.getAge() << endl << endl;


    // Here we set up another scope using the curly braces to force
    // the Plant destructor to be called.
    {
        cout << "Using copy constructor with derived class to create"
            << endl << "Plant y from Tree z" << endl;
        // Derived classes can be assigned into their base classes
        // We will use this concept alongside pointers to demonstrate
        // polymorphism in tomorrow's, June 7th, lecture.
        Tree z; 
        Plant y = z;

        // y and z will get destroyed when it goes out of scope after the
        // following curly brace is hit.
        cout << "Destroying Plant y and Tree z, z inherits y's destructor:" 
            << endl;
    }
    cout << endl;


    cout << "Destroying all remaining Plants and Trees at the return from main"
        << endl;
    return 0;
}