/// @file person.h
/// @author Adam T Koehler, PhD
/// @date June 11, 2025
/// @brief Definition for the Person class to combine with Line class 
///         to demonstrate Linked Lists

// We need to use this to prevent our header from being included multiple
// times during compilation.
#pragma once

#include <string>

using namespace std;

class Person
{
    private:
    // data members
    string name;
    uint age;

    // other characteristics
    string eyeColor;
    string hairColor;

    // traits or mutable (at some period)
    int selfEsteem; 


    public:
        // having parameterized constructor and no default prevents default Person creation
        Person(const string &n) : name(n), 
            age(0), eyeColor(""), hairColor(""), selfEsteem(10)
        {}

        void print() const { cout << name << endl; }
        bool operator==(const Person &rhs) const
        {
            return this->make_string() == rhs.make_string();
        }

        string getName() const { return name; }

    protected:
        string getEyeColor() const { return eyeColor; };


    private:
        string make_string() const { return name + " " + to_string(age); }

};