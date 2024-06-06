/// @file 20240530_card.cpp
/// @author Adam T Koehler, PhD
/// @date May 30, 2024
/// @brief Card class that is continually under development.
///     New functionality that is added in a lecture will exist at end
///     after comment about lecture date that featured the live additions.

#include <iostream>
#include <sstream>  // used to convert face value to unsigned integer
#include <string>
#include <vector>   // for playing card rank conversion from face value string

// include the Card class declaration so this file knows the Card data type
#include "20240606_card.h"


using namespace std;

/// @brief Generates a human readable string with all the values
///     of the private data members of the Card.
///     e.g. Card is a 2 of Clubs which is black
/// @return the generated string which is not newline terminated
string Card::to_string() const
{
    string color = "black";
    if(isRed())
    {
        color = "red";
    }

    // We can access class data members diretly because we'ree inside class
    if ("Joker" == faceValue)
    {
        return "Card is a " + faceValue + " which is " + color;
    }
    return "Card is a " + faceValue + " of " + suit + " which is " + color;
}



// =====================================================
// Functionality implementations from 05-30-2024 lecture
// =====================================================


/// @brief Overloading the + operator for Cards. Some operators
///     do not make sense to overload because there is not an
///     easy translation of what is normally expected from 
///     the operator. We do not need to always use the normal
///     expected overload with an operator if we have a good purpose
///     that we want to clearly define and use the operator for.
/// @param rightSide the Card object supplied on the right side of 
///     the + operator when used in C++ syntax
/// @return a black Card that has the face value and suits of 
///     the two Card objects concatenated together
Card Card::operator+(const Card &rightSide) const
{
    return Card(getFaceValue() + rightSide.getFaceValue(), 
                getSuit() + rightSide.getSuit(),
                false);
}


// Functionality commented out as post lecture improved function
// compares all aspects of the Card and not just the suit
/// @brief Compare the suits to determine whether a card
///     is greater than another.
/// @param compare the card to compare to the implicit object
/// @return true when the implict object is greater, otherwise false
// bool Card::operator>(const Card &compare) const
// {
//     return this->getSuit() > compare.getSuit();
// }


// Note that this is an updated operator> overload was added after lecture
// to be more robust than just suit comparison and now it will 
// correctly compare all playing cards to allow proper sorting.

/// @brief Compare the cards to determine which is greater than the other.
///     Uses suit strings for first comparison.
///     Then attempt to convert to numerical rank from 0 to 13.
///     When playing card conversion fails use string comparison of 
///     face values where black cards of matching face values come first.
/// @param rightSide the card to compare to the implicit object
/// @return true when the implict object is greater, otherwise false
bool Card::operator>(const Card &rightSide) const
{
    // Suits do not match, simply compare them with greater than
    // operator to compare the strings
    if (this->getSuit() != rightSide.getSuit())
    {
        return this->getSuit() > rightSide.getSuit();
    }

    // Suits match, attempt to convert to numerical rank
    int leftSideAsNumber = -1;
    int rightSideAsNumber = -1;
    if (convertToRank(leftSideAsNumber) && 
        rightSide.convertToRank(rightSideAsNumber))
    {
        // Suits match and ranks match, return whether the card
        // is red as red will come after black (using alphabetical sort)
        if (leftSideAsNumber == rightSideAsNumber)
        {
            // all properties match, not greater
            if (isRed() == rightSide.isRed())
            {
                return false;
            }
            
            // Colors do not match, if I am red, I am larger
            return isRed();
        }
        
        // unmatching ranks, return comparison result
        return leftSideAsNumber > rightSideAsNumber;
    }

    // Rank conversion failed for at least one of the cards fallback to
    // string comparison of face values.

    // Suits match and face values match, return whether the card
    // is red as red will come after black (using alphabetical sort)
    if (getFaceValue() == rightSide.getFaceValue())
    {
        // all properties match, not greater
        if (isRed() == rightSide.isRed())
        {
            return false;
        }
        
        // Colors do not match, if I am red, I am larger
        return isRed();
    }

    // Unmatched face values, just return the alphabetic string comparison
    return getFaceValue() > rightSide.getFaceValue();
}


/// @brief Attempt to convert the Card's face value to a playing card rank
/// @param number pass by reference integer to update with conversion value
/// @return true when successfully converted, false otherwise
bool Card::convertToRank(int &number) const
{
    vector<string> ranks = {"joker", "ace", "2", "3", "4", "5", "6", "7", "8",
         "9", "10", "jack", "queen", "king"};

    // check every rank and see if this card's face value matches
    for (size_t i = 0; i < ranks.size(); ++i)
    {
        if (ranks.at(i) == makeLowerCase(getFaceValue()))
        {
            number = i;
            return true;
        }
    }

    return false;
}


/// @brief Converts the provide string to a all lowercase version of string
/// @param con the string to convert
/// @return a new string with all the alphabetic characters converted to 
///     lowercase versions
string Card::makeLowerCase(const string &con) const
{
    string converted = con;

    // convert every alphabetic character in the converted
    // string to a lowercase character
    for (auto &ch : converted)
    {
        if (isalpha(ch))
        {
            ch = tolower(ch);
        }
    }

    return converted;
}




// =====================================================
// Functionality implementations from 06-06-2024 lecture
// =====================================================
