/// @file 20230601_LiveSession9.cpp
/// @author Adam T Koehler, PhD
/// @date June 1, 2023
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
    Plant p,m,n,o;
    string nm = "tree";
    Plant* q = new Plant(nm);
    Plant* r;
    r = &m;

    cout << "p: ";
    p.bloom();

    cout << "q: ";
    q->bloom(); 
    
    cout << "q: ";
    (*q).bloom();

    cout << "r: ";
    r->bloom();

    Tree mine;

    cout << "tree display" << endl;
    mine.display();

    cout << "tree age: ";
    cout << mine.getAge() << endl;

    return 0;
}