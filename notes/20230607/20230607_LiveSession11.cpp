/// @file 20230606_LiveSession10.cpp
/// @author Adam T Koehler, PhD
/// @date June 7, 2023
/// @brief Class code and lecture notes from the live session. Building on
///        June 6th notes and implementation to demonstrate polymorphism
///        and virtual keyword using display() and destructors.

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
    string nm = "n";
    Plant n(nm);

    // Set the species to make it easier to note when destruction occurs
    p.setSpecies("p");
    m.setSpecies("m");
    o.setSpecies("o");
    
    // We can create poniters to plants too!
    Plant* q = new Plant("ptr");
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
        L.setSpecies("L");
        K.setSpecies("K");
        cout << "Destroying Plant L and Plant K:" << endl;
    }    
    cout << endl;
       
    
    cout << "Using Plants p, q (ptr), r (&m):" << endl;

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
    mine.setSpecies("mine");

    cout << "tree age: ";
    cout << mine.getAge() << endl << endl;


    // Here we set up another scope using the curly braces to force
    // the Plant destructor to be called.
    {
        cout << "Using copy constructor with derived class to create Plant y "
            << "from Tree z" << endl;
        // Derived classes can be assigned into their base classes
        // We will use this concept alongside pointers to demonstrate
        // polymorphism in tomorrow's, June 7th, lecture.
        Tree z; 
        z.setSpecies("Willow");
        
        Plant y = z;
        y.setSpecies("Evergreen");
  
        // June 7th addition ------------------------------------------------
        // Using pointers to demonstrate polymorphism and virtual
        cout << endl
            << "Creating Tree pointer and Plant pointer from the address of "
            << "Tree z" << endl;
        Tree* zptr = &z; 
        Plant* yptr = &z;   // store address of a Tree in a Plant pointer!

        cout << endl;
        cout << "Objects y then z display():" << endl;
        y.display();
        z.display();
        cout << endl;

        // comment/uncomment virtual keyword to note the execution difference!
        cout << "Pointers yptr then zptr display():" << endl;
        yptr->display();
        zptr->display();
        // End June 7th addition --------------------------------------------


        // y and z will get destroyed when it goes out of scope after the
        // following curly brace is hit.
        cout << endl;
        cout << "Destroying Plant y and Tree z, z inherits y's destructor:" 
            << endl;
    }
    cout << endl;

    cout << "Destroying all remaining Plants and Trees at the return from main"
        << endl;
    delete q; // allocated memory in q with new, so we need to delete
    
    return 0;
}