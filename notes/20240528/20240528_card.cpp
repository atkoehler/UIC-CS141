/// @file 20240528_card.cpp
/// @author Adam T Koehler, PhD
/// @date May 28, 2024
/// @brief Additional functionality developed for the Card class.
///     Original class and functions developed previously exist as 
///     functions defined directly card.h. This split is simply for academic
///     learning reasons, we would normally put all our Card class function
///     definitions all in this C++ file.

#include <string>

// include the Card class declaration so this file knows the Card data type
#include "20240528_card.h"


using namespace std;


// Note all the parts of this function header now that we are defining 
// member functions outside of the class declaration. We still have
// the return type, funtion name, parameters (none here), and const'ness,
// but we also use the scope resolution operator (::) to note which class
// this function comes from. Here it belongs to the Card class.
// string Card::to_string() const


// Welcome Activity Implementation:

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

