/// @file card.cpp
/// @author Adam T Koehler, PhD
/// @date June 3, 2025
/// @brief Card class that is continually under development.
///     New functionality that is added in a lecture will exist at end
///     after comment about lecture date that featured the live additions.

#include <iostream>
#include <string>
#include <vector>
#include "card.h"

using namespace std;




////////////////////////////////////////////////////////////
// constructors
// facilitate object creation
////////////////////////////////////////////////////////////

/// @brief default constructor for the Card object
Card::Card() : faceValue(""), suit(""), coloredRed(false)
{}

/// @brief fully parameterized constructor for the Card object
/// @param fv the value to set to the private data member faceValue
/// @param st the value to set to the private data member suit
/// @param isRed the value to set to the private data member coloredRed
Card::Card(const string& fv, const string& st, bool isRed) : 
    faceValue(fv), suit(st), coloredRed(isRed)
{}






////////////////////////////////////////////////////////////
// private or protected functions
////////////////////////////////////////////////////////////

/// @brief is the card a red card?
/// @return true when the card is a red card, false otherwise
bool Card::isRed() const
{
    return coloredRed;
}


////////////////////////////////////////////////////////////
// setters/mutators
// provide public ability to change a data member's value
////////////////////////////////////////////////////////////

/// @brief set the private data member for face value
/// @param v the string to set the face value to 
void Card::setFaceValue(const string &faceValue)
{
    this->faceValue = faceValue;
}


////////////////////////////////////////////////////////////
// accessors/getters
// provide public ability to acquire a data member's value
////////////////////////////////////////////////////////////


// =====================================================
// Functionality implementations from 05-28-2025 lecture
// =====================================================
/// @brief acquire the face value of the card
/// @return the value of the private data member for the card's face value
string Card::getFaceValue() const
{
    return faceValue;
}

/// @brief acquire the suit value of the card
/// @return the value of the private data member for the card's suit
string Card::getSuit() const
{
    return suit;
}






////////////////////////////////////////////////////////////
// object funtionality implementations or usage functions
// provide public ability to acquire a data member's value
////////////////////////////////////////////////////////////


// =====================================================
// Functionality implementations from 05-28-2025 lecture
// =====================================================
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



////////////////////////////////////////////////////////////
// relational operator function overloads
// provide public ability to acquire compare objects
////////////////////////////////////////////////////////////

// =====================================================
// Functionality implementations from 05-29-2025 lecture
// =====================================================

/// @brief Relational equal operator overlaod for the Card class.
/// @param rhs The right hand side object of the relational comparison.
/// @return true when the Cards have all the same values, otherwise false.
bool Card::operator==(const Card &rhs) const
{
    // Compare faceValue
    if (this->faceValue == rhs.faceValue)
        // Compare the suit
        if(this->suit == rhs.suit)
            // Compare the color
            if (this->isRed() == rhs.isRed())
                return true;

    return false;
}



// =====================================================
// Functionality implementations from 06-03-2025 lecture
// =====================================================
/// @brief Relational not equal operator overlaod for the Card class.
/// @param rhs The right hand side object of the relational comparison.
/// @return true when the Cards are not equal to one another, meaning they 
///         do not have all the same values, otherwise false.
bool Card::operator!=(const Card &rhs) const
{
    // How can we define != in terms of other operators?
    // We cannot use != to define != as it will cause a recursive
    //  function call when we do:
    // this != rhs

    // Let's consider simple variables first
    // int x = 5;
    // int y = 3;

    // bool equiv = x == y;
    // bool inequiv =   (x != y);
    // bool inequiv2 = !(x == y);
    
    return !(*this == rhs);
}

// We can similarly define other relational operators in pairs
/// @brief Compare the cards to determine which is greater than the other.
///     Uses suit strings for first comparison.
///     Then attempt to convert to numerical rank from 0 to 13.
///     When playing card conversion fails use string comparison of 
///     face values where black cards of matching face values come first.
/// @param rhs the card to compare to the implicit object
/// @return true when the implict object is greater, otherwise false
bool Card::operator>(const Card &rhs) const
{
    /// 1. Uses suit strings for first comparison.
    if (getSuit() != rhs.getSuit())
    {   
        return getSuit() > rhs.getSuit();
    }

    /// 2. Then attempt to convert to numerical rank from 0 to 13.
    int myRank = -1, rhsRank = -1;
    if (this->convertToRank(myRank) && rhs.convertToRank(rhsRank))
    {
        cout << myRank << " " << rhsRank << endl;
        return myRank > rhsRank;
    }

    
    /// 3. When playing card conversion fails use string comparison of 
    ///     face values where black cards of matching face values come first.
    // if (this->getFaceValue() == rhs.getFaceValue())
    // {
    //     // A > C (black, red) false
    //     // A > C (black, black) false
    //     // A > C (red, ) false
    //     // A > C (red, red) false
    //     return !this->isRed();
    // }
    std::cout << "shouldn't get here" << std::endl;

    return this->getFaceValue() > rhs.getFaceValue();
}


/// @brief Relational less than or equal to operator overlaod for the Card class.
/// @param rhs The right hand side object of the relational comparison.
/// @return true when the implicit object is not greater than the parameter object
bool Card::operator<=(const Card &rhs) const
{

    return !(*this > rhs);
}


/// @brief Relational less than than operator overlaod for the Card class.
/// @param rhs The right hand side object of the relational comparison.
/// @return true when the implicit object is defined as less than the parameter object
bool Card::operator<(const Card &rhs) const
{
    // TODO: implement logic of what it means to be less than
    return false;
}


/// @brief Relational greater than or equal to operator overlaod for the Card class.
/// @param rhs The right hand side object of the relational comparison.
/// @return true when the implicit object is not less than the parameter object
bool Card::operator>=(const Card &rhs) const
{

    return !(*this < rhs);
}

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



// ===========================================================================
// Functionality implementations asynchronously added after 06-03-2025 lecture
// ===========================================================================

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
