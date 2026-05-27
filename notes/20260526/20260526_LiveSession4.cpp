/// @file 20260526_LiveSession4.cpp
/// @author Adam T Koehler, PhD
/// @date May 26, 2026
/// @brief Code and lecture notes from the live session. Requires -std=c++20

#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

// Activity 1 - Designing a Die Class
// Properties of a single die:
//    quantity of faces/sides e.g. 6
//    value on the side/face e.g. 1 through 6
//    representation of the value e.g. dots per value 6 dots is 6
//    equally weighted
//    opposite sides sum to 7
//    color of the die
//    physical die dimensions


// Actions, these often correspond to class functions:
//    roll it to change the internal value
//    set the internal value of the object directly
//    change or set the color
//    change or set the dimensions
//    change or set .... property
//    read/display/get the internal value
//          similar for other properties
//    accessor or setter method for every property

// Who can access or use the data members or functions?
// users should not be able to access properties
//      private, protected 
// accessors (getters) -> public

/// @brief object representing a single die
class Die 
{
    // private by default, so we write this for transparency 
    // and increased code readability
    private:
        uint value;
        string color;
        vector<unsigned int> allValues;
        uint lowValue, highValue;


        // Modern, high-quality random number generator
        // rand() uses a predictable pseudorandom number generator
        random_device rd;
        mt19937 rng;
        uniform_int_distribution<int> dist;

    // protected data members are directly accessible within the class as well
    // as within any derived classes 
    protected:
        void setValue(uint value)
        {
            this->value = value;
        }

    public:
        Die(uint low=1, uint high=6) : lowValue(low), highValue(high), rng(rd()), dist(low, high) {}

        /// @brief acquire the value of the private data member value
        /// @return the private data member value's value
        uint getValue()
        {
            return value;
        }

        /// @brief update the internal die value based on the high and low 
        ///         die face values. Additionally updated the pastValues
        ///         internal vector that stores all the die rolls for this die.
        void roll()
        {
            allValues.push_back(dist(rng));
            setValue(allValues.back());
        }

        /// @brief print out all the past die roll values for this die
        void printAllValues()
        {
            string values;
            for(uint val : allValues)
            {
                values += to_string(val) + " ";
            }

            values.pop_back();

            cout << values << endl;
        }
};


// The struct datatype is often used to quickly collect or group
// multiple pieces of data. When C++ was invented structs naturally
// evolved into classes and the choices of how classes are set up.
struct Person 
{
    // public by default (classes are private by default)
    string name;
    uint age;

    // in C++ we can have functions in structs
    // functions cannot exist in structs in C
    // uint getAge() { return age; }

    // In most cases we do not define functions for structs because
    // in C++ structs are most commonly used simply to gather differing
    // data types. However, it is quite common to define a constructor
    // to make creation of an instance of the struct slightly easier.
    Person(string n="", uint a=0) : name(n), age(a) {};
};


// In C++ we can use the struct identifier as a type
// but if we are using the parent language, we would
// need to use typedef to make the name usable.
// typedef struct Person2
// {
//     string name;
//     int id;
// }Person2;


int main()
{
    // Struct Usage
    cout << "Using the Person struct..." << endl;
    struct Person professor;
    professor.age = 99;
    professor.name = "Adam T Koehler, PhD";
    cout << "struct usage: " << professor.name << " is " 
        << professor.age << endl;

    // Alternatively we could use the constructor
    struct Person student("Steve", 33);
    cout << "struct usage: " << student.name << " is " 
        << student.age << endl; 
        
    // In C++ we can use the struct identifier as a type
    // but if we are using the parent language, we would
    // need to use typedef to make the name usable.
    Person admin("Sarah", 43);
    cout << "struct usage: " << admin.name << " is " 
        << admin.age << endl;     

    // Die Class Usage
    cout << endl << "Using the die class one pbject at a time..." << endl;
    Die one;
    Die two;
    for (int i = 0; i < 10; ++i)
    {
        one.roll();
        two.roll();
        cout << "Current Die 1 Value: " << one.getValue() << endl;
        cout << "Current Die 2 Value: " << two.getValue() << endl;
    }

    // Cannot access pastValues directly as it is private
    // cout << one.pastValues.at(0) << endl;
    
    // Instead call the publicly accessible function to print all the rolls.
    cout << "All rolled values of the \"one\" die: " << endl;
    one.printAllValues();



    // Create a collection of 3 dice and roll!
    cout << endl << "Collection of Dice" << endl 
        << "==================" << endl;

    vector<Die> dice(3);
    for (int i = 0; i < 10; ++i)
    {
        cout << "Loop iteration " << i << ":" << endl;

        // roll every die in the vector
        for(auto& indivDie : dice)
        {
            indivDie.roll();
        }
        
        // iterate over the vector of individual dice and output current values
        for (size_t j = 0; j < dice.size(); ++j)
        {
            cout << "Current Die " << j << " Value: " << dice.at(j).getValue()
                << endl;
        }

        cout << endl;
    }


    return 0;
}




// Card Class Design - Basics

// We want to think at the scale of the class, not multiple instantiations of it
// Property
//  color - often red and black
//  value - the face value of the card convert to a numerical value
//  showing - whether the face of the card is showing or not
//  suit - often hearts, diamonds, spades, clubs

// set up the basic class - pieces left out in live lecture
// class Card
// {
// };


// What about a grouping of cards?
//   Colloquially we would call this a "deck" but we need to define what a 
//   Deck is we could just use a vector, vector<Card> deck; or define an 
//   entire class and internally store the collection in a vector.
//   Having a class allows us to define special non-vector interactions.
// class Deck
// {
//     vector <Card> dk;
// };

// // In main, we may want a small deck of a few cards. This could be the player 
// // hand or we could define a different "Hand" class.
// Deck hand;