/// @file card.h
/// @author Adam T Koehler, PhD
/// @date June 3, 2025
/// @brief Definition for the Card class. Functionality in the
///         the card.cpp file. Continually developed. New implementations are
///         often timestamped with the leture date within the .cpp file.

// We need to use this to prevent our header from being included multiple
// times during compilation.
#pragma once

#include <string>

using namespace std;

/// @brief a Card class to mimic a playing card
class Card
{
    private:
        string faceValue;
        string suit;
        bool coloredRed;

        
    ////////////////////////////////////////////////////////////
    // private or protected functions
    // facilitate functionality only to be used internally by
    // the Card class or any derived class from the Card class
    ////////////////////////////////////////////////////////////
    private:
        bool isRed() const;


    ////////////////////////////////////////////////////////////
    // publicly (user) accessible data members and functionality
    // facilitating an API for users of the Card class
    ////////////////////////////////////////////////////////////
    public:
        ////////////////////////////////////////////////////////////
        // constructors
        // facilitate object creation
        ////////////////////////////////////////////////////////////
        Card();
        Card(const string&, const string&, bool);

        ////////////////////////////////////////////////////////////
        // setters/mutators
        // provide public ability to change a data member's value
        ////////////////////////////////////////////////////////////
        void setFaceValue(const string &v);

        ////////////////////////////////////////////////////////////
        // accessors/getters
        // provide public ability to acquire a data member's value
        ////////////////////////////////////////////////////////////
        string getFaceValue() const;
        string getSuit() const;

        ////////////////////////////////////////////////////////////
        // object funtionality implementations or usage functions
        // provide public ability to acquire a data member's value
        ////////////////////////////////////////////////////////////
        string to_string() const;


        ////////////////////////////////////////////////////////////
        // relational operator function overloads
        // provide public ability to acquire compare objects
        ////////////////////////////////////////////////////////////
        bool operator==(const Card &) const;
        bool operator!=(const Card &) const;
        bool operator>(const Card &) const;
        bool operator<=(const Card &) const;
        bool operator<(const Card &) const;
        bool operator>=(const Card &) const;
        Card operator+(const Card &) const;

    private:
        bool convertToRank(int &number) const;
        string makeLowerCase(const string &) const;

};