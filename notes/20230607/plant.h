/// @file plant.h
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

#pragma once
#include <string>

using namespace std;

class Plant
{
    private: 
        string species;
        int sunlightHours;
        int age;
        bool indoor;
    
    // We made public (violating good object design) to gain quick
    // access during examples. Normally we would make accessor or 
    // mutator for this array.
    public:
        int growthRate[10];

    // Protected data members are accessible in this class and all
    // derived classes.
    protected:
        int height;

    public: 
        Plant();
        Plant(const string &); 
        
                                            // Rule of Three:
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
        void setAge(int);

        virtual void display() const;
        // void display() const;
};


// We can utilize inheritance and create a derived
// class that inherits from our base class
class Tree : public Plant
{
    public:
        void display() const;
        virtual ~Tree();
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