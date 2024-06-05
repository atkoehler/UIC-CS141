/// @file 20240605_person.h
/// @author Adam T Koehler, PhD
/// @date June 5, 2024
/// @brief Code for the Person class developed as groups.


// Welcome Activity:
// Discuss with your group a Person class. 
// Your task at this time is to write the header file on the front of your
// paper as a group. This will not contain the implementations, only the
// declaration. 
//
// Write the declaration such that it meets at least the 
// following requirements: 
// 1. multiple data members
// 2. at least one constructor
// 3. a member function and a helper function

// Important to prevent double includes causing issues.
// It will stop reading the file immediately after discovering this line.
// This depends on compiler compatibility but is widely compatible.
#pragma once

// Preprocessor Directives
// Do not rely on compiler compatibility and often seen in legacy
// C, C++, and areas where pragma is not supported.
// Meaning, newer C++ code will often use the #pragma once as seen above.
// #ifndef PERSON_H
// #define PERSON_H
// header file contents goes here
// #endif

// only include the libraries relevant to this file
#include <string>

using namespace std;

/// @brief Declaration of a Person class as developed individually by the 
///     groups and then collectively joined during live coding
class Person
{
    private:        
        string name;

        // When designing objects, we must be careful of building in our
        // own experiences or biases such as inferring people only have
        // a first and a last name.
        // string firstName;
        // string lastName;

        // An age cannot be negative so we use the unsigned keyword
        // to allow only non-negative values and therefore double the
        // amount of non-negative values that could occupy the variable.
        unsigned int age;
        
        // If we want to memory conscious then we may choose a numeric
        // data type with a smaller footprint.
        // unsigned short age;

        // When declaring height or using it or having a user use it,
        // we must always be aware of the units (e.g. centimeters or inches).
        double height;

        string nationality;

    public:
        Person(const string &, uint, double);

        // Default constructors are only automatic when we don't define
        // another constructor. So we declare that our class one here to
        // allow us to create Person objects without specifying everything.
        Person();
        
        // mutators or setters
        void setName(const string &);

        // accessors or getters
        uint getAge() const;

        // determine whether the person is of legal age based on nationality
        bool isLegalAge() const;

    private:
        // Helper to utilize the object's nationality value to convert
        // it to the legal age via some conversion table or mechanism.
        // This function is not available to users of the class and is
        // only used internally by isLegalAge() and therefore is private.
        uint ageOfMajority() const;
};