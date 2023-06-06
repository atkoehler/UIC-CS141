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
    Plant p,m,o;
    string nm = "tree";
    Plant* q = new Plant(nm);
    Plant n(nm);
    Plant* r;
    r = &m;

    Tree z; 
    Plant y = z;

    cout << "Objects:" << endl;
    z.display();
    y.display();


    cout << "Pointers:" << endl;
    Tree *zptr = &z;
    Plant *yptr = &z;
    zptr->display();
    yptr->display();


    // copy constructor
    {
        // Plant L(p);
        // Plant K = p;
        // K.bloom();

        // // assignment operator
        // // cout << "before assignment: " << endl;
        // // for(int i = 0; i < 10; ++i)
        // // {
        // //     cout << K.growthRate[i] << ' ';
        // // }
        // // cout << endl;
        // K = n;
    }    
    // cout << "after assignment: " << endl;
    // for(int i = 0; i < 10; ++i)
    // {
    //     cout << K.growthRate[i] << ' ';
    //     n.growthRate[i] = 0;
    // }
    // cout << endl;
    
    // int *x = &K.growthRate[0];
    // cout << "after update: " << endl;  
    // for(int i = 0; i < 10; ++i)
    // {
    //     cout << *(x+i) << ' ';
    // }
    // cout << endl;
    
    
    // cout << "p: ";
    // p.bloom();

    // cout << "q: ";
    // q->bloom(); 
    
    // cout << "q: ";
    // (*q).bloom();

    // cout << "r: ";
    // r->bloom();

    // Tree mine;

    // cout << "tree display" << endl;
    // mine.display();

    // cout << "tree age: ";
    // cout << mine.getAge() << endl;

    return 0;
}