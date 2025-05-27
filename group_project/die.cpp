/// @file die.cpp
/// @author Adam T Koehler, PhD
/// @date May 27, 2025
/// @brief Die class function implementations.

#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "die.h"

using namespace std;


/////////////////////////////////////////////
//             Constructors                //
/////////////////////////////////////////////

/// @brief default constructor create a normal six-sided die
Die::Die() : highValue(6), lowValue(1)
{}

/// @brief parameterized constructor for the Die class
/// @param low the lowest value on the die
/// @param high the highest value on the die
Die::Die(uint low, uint high) : highValue(high), lowValue(low)
{}




/////////////////////////////////////////////
//               Accessors                 //
/////////////////////////////////////////////

/// @brief acquire the value of the private data member value
/// @return the private data member value's value
uint Die::getValue()
{
    return value;
}




/////////////////////////////////////////////
//                Mutators                 //
/////////////////////////////////////////////

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
    // record a new roll in the collection of all rolls by generating
    // a random value between low and high values (inclusive)
    allValues.push_back(lowValue + rand() % 
        (highValue - lowValue + 1));

    // set the current die value to the last item in the collection
    setValue(allValues.back());
}



/////////////////////////////////////////////
//            to_string Functions          //
/////////////////////////////////////////////

/// @brief combine all the values into a space separated string
/// @return the space separated string of all the die roll values.
string Die::allValues_toString()
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