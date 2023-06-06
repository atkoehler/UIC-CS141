/// @file plant.h
/// @author Adam T Koehler, PhD
/// @date June 6, 2023
/// @brief Class code and lecture notes from the live session. Building on
///        June 1st notes and implementation to fully build a class with 
///        recursion examples.

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution). 

#pragma once
#include <string>

using namespace std;

class Plant
{
    private: 
        string species;
        // int height; // moved to protected to demo inheritance
        int sunlightHours;
        int age;
        bool indoor;
    
    public:
        int growthRate[10];

    protected:
        int height;

    public: 
        Plant();
        Plant(const string &);              // Rule of Three:
        Plant(const Plant &);               // copy constructor
        Plant& operator=(const Plant &);    // assignment operator
        virtual ~Plant();                   // destructor

        void bloom() const;

        // accessors and mutators
        int getAge() const;
        int getHeight() const;
        int getSunlightHours() const;
        string getSpecies() const;

        bool isIndoor() const;

        void setSpecies(string species);
        void setHeight(int h);
        void setSunlightHours(int hr);

        virtual void display() const;
};


// We can utilize inheritance and create a derived
// class that inherits from our base class
class Tree : public Plant
{
    public:
        virtual void display() const;
};

// We can define additional classes
// class Flower
// {
// };

// We can create classes that are derived from multiple
// base classes creating a multiple inheritance situation.
// class Rose : public Flower, public Plant
// {
// }