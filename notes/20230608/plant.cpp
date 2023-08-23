/// @file plant.cpp
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


// Constructors do not have a return data type
// Constructors are used to create a new object of the data type
/// @brief this default constructor has no parameters and initializes all
///        the object's data members to some default values
Plant::Plant()
{
    type = "Basic Plant";
    sunlightHours = 24;
    age = 0;
    indoor = false;
    height = 0;

    // the growthRate array always has the last 10 rate values
    for(int i=0; i < 10; ++i)
    {
        growthRate[i] = 0;
    }
}

/// @brief this parameterized constructor allows us to craft a plant and 
///        specify the type by sending a string to the constructor
/// @param type the value to set the private data member type to
Plant::Plant(const string &type)
{
    this->type = type;
    sunlightHours = 17;
    age = 100;
    indoor = false;
    height = 2;

    // the growthRate array always has the last 10 rate values
    for(int i=0; i < 10; ++i)
    {
        growthRate[i] = i;
    }
}

/// @brief the copy constructor allows us to create a brand new Plant based
///        on another object that is provided
/// @param other the other Plant object to copy all the values from
Plant::Plant(const Plant &other)
{
    cout << "copy constructor" << endl;

    // We grab all the values from other and set the values of
    // all the data members of the object we are creating
    indoor = other.indoor;
    height = other.height;
    sunlightHours = other.sunlightHours;
    age = other.age;

    // We are in the Plant class so we can access all the data members
    // directly versus needing to use the accessor member functions.
    this->type = other.getType();

    // shallow copy => bad
    // If we have any data members that C++ does not know how to natively
    // copy, then we want to avoid shallow copies that only copy the 
    // memory addresses and do not set up an entirely new data member.
    // growthRate = other.growthRate;

    // deep copy => good
    // A deep copy goes through all the elements of the data member that 
    // cannot be natively copied by C++ and copies the values of all the
    // elements one-by-one.
    for(int i=0; i < 10; ++i)
    {
        growthRate[i] = other.growthRate[i];
    }
}

/// @brief the destructor releases any dynamically allocated memory
///         for the object as it is automatically invoked when an object
///         goes out of scope. We cannot invoke this function on our own.
Plant::~Plant()
{
    cout << getType() << ' ';
    cout << "Plant destroyed!" << endl;
}

/// @brief The assignment operator overload allows us to use
///        assignment statements to overwrite Plant objects
/// @param other the other Plant object to get all the values from
/// @return a reference to the updated Plant object
Plant& Plant::operator=(const Plant &other)
{
    cout << "assignment op" << endl;
    this->type = other.getType();
    sunlightHours = other.sunlightHours;
    age = other.age;
    indoor = other.indoor;
    height = other.height;

    // shallow copy - bad
    // growthRate = other.growthRate'

    // deep copy - good
    for(int i=0; i < 10; ++i)
    {
        growthRate[i] = other.growthRate[i];
    }

    // this is the implicit parameter and is a pointer to an object
    // we can dereference it to acquire the memory address to return
    // the updated object
    return *this;
}


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

string Plant::getType() const
{
    return type;
}

// predicate functions are often named differently to 
// allow the function name to act as a question
/// @brief Is this an indoor plant? Get the Plant data member value.
/// @return true when it is an indoor plant, otherwise false
bool Plant::isIndoor() const
{
    return indoor;
}

// mutators allow us to set the data members of a class
void Plant::setType(string type)
{
    this->type = type;
}

void Plant::setHeight(int h)
{
    height = h;
}

void Plant::setSunlightHours(int hr)
{
    sunlightHours = hr;
}

void Plant::setAge(int a)
{
    age = a;
}


void Plant::bloom() const
{ 
    cout << "Growing up at age: " << age << endl; 
}

// June 7th Addition:
// Plant Class display()
/// @brief display some details of the Plant
void Plant::display() const
{
    cout << "I'm a plant! ";
    cout << "Height: " << height;
    cout << ", Age: " << age << endl;
}

// Tree Class Definitions
/// @brief display some details of the Tree
void Tree::display() const
{
    cout << "I'm a tree! ";

    // Height is protected so it can be accessed directly as 
    // we are in the Tree class which is derived from Plant
    cout << "Height: " << height;
    
    // Age is private so it cannot be accessed directly as 
    // we are in the Tree class not the Plant class.
    // So we use the public accessor to get the age.
    // cout << "Age: " << age << endl;
    cout << ", Age: " << Plant::getAge() << endl;
}

/// @brief the destructor releases any dynamically allocated memory
///         for the object as it is automatically invoked when an object
///         goes out of scope. We cannot invoke this function on our own.
Tree::~Tree()
{
    cout << getType() << ' ';
    cout << "Tree destroyed!" << endl;
}