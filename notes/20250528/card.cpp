#include <string>
#include "card.h"

using namespace std;

Card::Card() : faceValue(""), suit(""), coloredRed(true)
{}

Card::Card(const string& fv, const string& st, bool isRed)
{
    faceValue = fv;
    suit = st;
    coloredRed = isRed;
}

// Card::Card(const string& fv, const string& st, bool isRed) : 
//     faceValue(fv), suit(st), coloredRed(isRed)
// {}

string Card::to_string() const
{
    string newString;

    // combine all the data members using string concatenation
    newString += faceValue + " of " + suit;
    if (coloredRed)
    {
        newString += " that is red";
    }
    else
    {
        newString += " that is black";  
    }

    return newString;
}




string Card::getFaceValue() const
{
    return faceValue;
}