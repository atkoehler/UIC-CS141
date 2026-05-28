/// @file die.cpp
/// @author Adam T Koehler, PhD
/// @date May 26, 2026
/// @brief Die class function implementations. Requires -std=c++20

#include "die.h"

using namespace std;

/////////////////////////////////////////////
//             Constructors                //
/////////////////////////////////////////////

/// @brief parameterized constructor for the Die class
/// @param low the lowest value on the die
/// @param high the highest value on the die
Die::Die(uint low, uint high) : lowValue(low), highValue(high), rng(rd()), dist(low, high) {}



/////////////////////////////////////////////
//               Accessors                 //
/////////////////////////////////////////////

/// @brief acquire the value of the private data member value
/// @return the private data member value's value
uint Die::getValue() const
{
    return value;
}

/////////////////////////////////////////////
//                Mutators                 //
/////////////////////////////////////////////

/// @brief set the current die value to the provided value
/// @param value 
void Die::setValue(uint value)
{
    this->value = value;
}

/// @brief set the private data member lowValue
/// @param low the value to set lowValue to
void Die::setLowValue(uint low)
{
    lowValue = low;
}

/// @brief set the private data member highValue
/// @param high the value to set highValue to
void Die::setHighValue(uint high)
{
    highValue = high;
}



/////////////////////////////////////////////
//             Interactions                //
/////////////////////////////////////////////

/// @brief update the internal die value based on the high and low 
///         die face values. Additionally updated the pastValues
///         internal vector that stores all the die rolls for this die.
void Die::roll()
{
    allValues.push_back(dist(rng));
    setValue(allValues.back());
}



/////////////////////////////////////////////
//            to_string Functions          //
/////////////////////////////////////////////

/// @brief combine all the values into a space separated string
/// @return the space separated string of all the die roll values.
string Die::allValues_toString() const
{
    string values;

    // use concatenation to combine all the values
    for(uint val : allValues)
    {
        values += to_string(val) + " ";
    }

    // pop off the space after the last number
    values.pop_back();

    return values;
}
