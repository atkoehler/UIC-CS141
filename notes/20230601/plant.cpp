/// @file plant.cpp
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


// Constructors do not have a return data type
// Constructors are used to create a new object of the data type
Plant::Plant()
{
    species = "Basic Plant";
    sunlightHours = 24;
    age = 0;
    indoor = false;
    height = 0;
}

Plant::Plant(const string &species)
{
    this->species = species;
    sunlightHours = 17;
    age = 100;
    indoor = false;
    height = 0;
}

// We could define a constructor with a default parameter and then we do not
// need the default constructor as this constructor would be called
// Plant::Plant(string species="Basic Plant")
// {
//     this->species = species;
//     sunlightHours = 24;
//     age = 0;
//     indoor = false;
// }


// accessors
int Plant::getAge() const
{
    return age;
}

int Plant::getHeight() const
{
    return height;
}

int Plant::getSunlightHours() const
{
    return sunlightHours;
}

string Plant::getSpecies() const
{
    return species;
}

// predicate functions are often named differently to 
// allow the function name to act as a question
bool Plant::isIndoor() const
{
    return indoor;
}

// mutators
void Plant::setSpecies(string species)
{
    this->species = species;
}

void Plant::setHeight(int h)
{
    height = h;
}

void Plant::setSunlightHours(int hr)
{
    sunlightHours = hr;
}


void Plant::bloom() const
{ 
    cout << "Growing up at age: " << age << endl; 
}


// Tree Class Definitions
void Tree::display() const
{
    // Height is protected so it can be accessed directly as 
    // we are in the Tree class which is derived from Plant
    cout << "Height: " << height << endl;
    
    // Age is private so it cannot be accessed directly as 
    // we are in the Tree class not the Plant class.
    // So we use the public accessor to get the age.
    // cout << "Age: " << age << endl;
    cout << "Age: " << Plant::getAge() << endl;
}