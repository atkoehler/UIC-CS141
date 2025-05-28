/// @file card.h
/// @author Adam T Koehler, PhD
/// @date May 28, 2025
/// @brief Definition for the Card class. Functionality in the
///         the card.cpp file.

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

    public:
        Card();
        Card(const string&, const string&, bool);
        string getFaceValue() const;
        string to_string() const;
};