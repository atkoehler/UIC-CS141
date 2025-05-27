/// @file 20250527.cpp
/// @author Adam T Koehler, PhD
/// @date May 27, 2025
/// @brief Code and lecture notes from the live session. 
///     Lecture covered basics of structs and classes.

#include <iostream>
#include <string>
#include <vector>

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


// The struct datatype is often used to quickly collect or group
// multiple pieces of data. When C++ was invented structs naturally
// evolved into classes and the choices of how classes are set up.
struct Person 
{
    // public by default
    string name;
    uint age;

    // in C++ we can have functions in structs
    // functions cannot exist in structs in C
    // uint getAge() { return age; }
};

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

    protected:
        void setValue(uint value)
        {
            this->value = value;
        }

    public:
        Die(uint low=1, uint high=6) : lowValue(low), highValue(high) {}

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
            // uint v = lowValue + rand() % 
            //     (highValue - lowValue + 1);
            // setValue(v);
            // pastValues.push_back(getValue());

            allValues.push_back(lowValue + rand() % 
                (highValue - lowValue + 1));
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


int main()
{
    // Struct Usage
    cout << "Using the Person struct..." << endl;
    struct Person professor;
    professor.age = 99;
    professor.name = "Adam T Koehler, PhD";
    cout << "struct usage: " << professor.name << " is " 
        << professor.age << endl;


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
