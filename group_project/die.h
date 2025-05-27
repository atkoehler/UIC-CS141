#pragma once

/// @file die.h
/// @author Adam T Koehler, PhD
/// @date May 27, 2025
/// @brief Die class declaration.

#include <string>
#include <vector>

/// @brief object representing a single die
class Die 
{
    private:
        uint value;
        uint highValue, lowValue;
        std::vector<unsigned int> allValues;

    protected:
        // example mutator that is accessible internally
        // and to derived classes (class inheritance)
        void setValue(uint);

    public:
        Die();
        Die(uint, uint);

        // accessors
        uint getValue();

        // direct mutators
        void setHighValue(uint);
        void setLowValue(uint);
    
        // interactions
        void roll();

        // to_string functions
        std::string allValues_toString();
};