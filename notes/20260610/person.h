/// @file person.h
/// @author Adam T Koehler, PhD
/// @date June 10, 2026
/// @brief Definition for the Person class to combine with Line class 
///         to demonstrate Linked Lists

// We need to use this to prevent our header from being included multiple
// times during compilation.
#pragma once

#include <iostream>
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
        Person(const string &n, uint a) : name(n), 
            age(a), eyeColor(""), hairColor(""), selfEsteem(10)
        {}

        void print() const { cout << name << ", " << age; }

        /// @brief Determine whether a person is the same 
        ///         based on matching "stringify"
        /// @param rhs The person to compare to.
        /// @return true when the two Person objects result in the 
        ///         same make_string string return, false otherwise
        bool operator==(const Person &rhs) const
        {
            return this->make_string() == rhs.make_string();
        }

        /// @brief Compare people based on age.
        /// @param rhs the person to compare to
        /// @return true when "this" person is younger than the other (rhs) person
        bool operator<(const Person &rhs) const
        {
            return this->age < rhs.age;
        }

        string getName() const { return name; }
        uint getAge() const { return age; }
        void setAge(uint age) { this->age = age; }

    protected:
        string getEyeColor() const { return eyeColor; };


    private:
        string make_string() const { return name + " " + to_string(age); }

};