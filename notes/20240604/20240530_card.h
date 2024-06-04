/// @file 20240530_card.h
/// @author Adam T Koehler, PhD
/// @date May 30, 2024
/// @brief Card class that is continually under development.
///     New functionality that is added in a lecture will exist at end
///     after comment about lecture date that featured the live additions.

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
  
        /// @brief Default constructors setting creating impossible card
        Card()
        {
            faceValue = "";
            suit = "";
            coloredRed = false;
        }

        /// @brief fully parameterized constructor for the Card class
        /// @param v the face value of the card
        /// @param s the string representation of card suit
        /// @param coloredRed whether the card is red (true when red, false when not)
        Card(string v, string s, bool coloredRed)
        {
            faceValue = v;
            suit = s;
            this->coloredRed = coloredRed;
        }


        // setters/mutators
        /// @brief set the private data member for face value
        /// @param v the string to set the face value to 
        void setFaceValue(string v)
        {
            faceValue = v;
        }

        // accessors/getters
        // provide public ability to acquire a data member's value

        /// @brief acquire the face value of the card
        /// @return the value of the private data member for the card's face value
        string getFaceValue() const
        {
            return faceValue;
        }

        /// @brief acquire the suit value of the card
        /// @return the value of the private data member for the card's suit
        string getSuit() const
        {
            return suit;
        }

        /// @brief is the card a red card?
        /// @return true when the card is a red card, false otherwise
        bool isRed() const
        {
            return coloredRed;
        }
        

        /// @brief Compare two card objects to determine equvialence.
        ///        Equivalence here means all private data members of the two
        ///        objects will be the same values.
        /// @param compare the object to compare to the implicit object
        /// @return true when all data members of the two objects have 
        ///         matching values, otherwise false
        bool operator==(const Card &compare) const
        {
            return compare.isRed() == this->isRed() &&
                compare.getSuit() == this->getSuit() &&
                compare.getFaceValue() == this->getFaceValue();
        }

        // New implementations worked on as group activity.
        // Weclome Activity
        string to_string() const;



    
    // =====================================================
    // Functionality implementations from 05-30-2024 lecture
    // =====================================================
    public:
        // Comparison operators can be overloaded similar
        // to the operetor== operator.
        bool operator>(const Card &compare) const;

        // Some operators do not make sense to overload
        // but we still can overload them.
        Card operator+(const Card &compare) const;

    // Helper functions added after class to complete
    // full playing card sort (versus just by suit in class)
    private:        
        bool convertToRank(int &) const;
        string makeLowerCase(const string &) const;
};