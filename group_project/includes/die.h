#pragma once

/// @file die.h
/// @author Adam T Koehler, PhD
/// @date May 26, 2026
/// @brief Die class declaration. Requires -std=c++20

#include <random>
#include <string>
#include <vector>

/// @brief object representing a single die
class Die 
{
    private:
        uint value;
        std::string color;
        std::vector<unsigned int> allValues;
        uint lowValue, highValue;


        // Modern, high-quality random number generator
        // rand() uses a predictable pseudorandom number generator
        std::random_device rd;
        std::mt19937 rng;
        std::uniform_int_distribution<int> dist;

    protected:
        void setValue(uint);

    public:
        Die(uint low=1, uint high=6);

        // accessors
        uint getValue() const;
   
        // interactions
        void roll();

        // to_string functions
        std::string allValues_toString() const;

    private:
        // direct mutators
        void setHighValue(uint);
        void setLowValue(uint);
};