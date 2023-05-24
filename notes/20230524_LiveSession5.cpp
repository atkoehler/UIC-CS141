/// @file 20230524_LiveSession5.cpp
/// @author Adam T Koehler, PhD
/// @date May 24, 2023
/// @brief Code and lecture notes from the live session on vectors & arrays.

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution). 

#include <iostream> // input output streams, cin and cout
#include <sstream>  // stringstreams
#include <iomanip>  // input output stream manipulation (setprecision) 
#include <string>
#include <vector>

using namespace std;

// roll function from 05-23-2023 lecture
int roll(int, int);


int main()
{
    // We can create a string and a vector of characters to demonstrate
    // their similarities and differences.
    string s = "Hello";
    vector<char> v;

    // We can build the vector of characters element by element by iterating
    // over the string and pushing each character on to the vector.
    for(size_t i = 0; i < s.size(); ++i)
    {
        v.push_back(s.at(i));
    }

    // When we output the string and the vector element by element, 
    // separating each by a space we see the same output.
    for(size_t i = 0; i < s.size(); ++i)
    {
        cout << s.at(i) << ' ';
    }
    cout << endl;
    for(size_t i = 0; i < v.size(); ++i)
    {
        cout << v.at(i) << ' ';
    }
    cout << endl;

    // strings can be sent to an output buffer using the 
    // insertion operator (<<), but vectors cannot
    cout << s << endl;
    // cout << v << endl;    // compiler error as << is not defined for vectors

    // We can interact directly with elements in a vector similar to the 
    // direct interaction with the elements of a string with the at() function.
    s.at(0) = 'F';
    v.at(0) = 'F';
    
    // We can even read in or output the elements, assuming that >> and << are
    // defined for the specific element types which is a character for strings
    // and we choose the element type for vectors when we define it. Here we
    // have chosen char for vector v.
    cout << "The first element in the string is " << s.at(0) << endl;
    cout << "The second element in the string is " << s.at(1) << endl;
    cout << "Enter a character to change the first character to: ";
    cin >> s.at(0);
    cout << "The first element in the string is " << s.at(0) << endl;
    
    cout << endl;
    cout << "The first element in the vector is " << v.at(0) << endl;
    cout << "The second element in the vector is " << v.at(1) << endl;
    cout << "Enter a value to change to first element to: ";
    cin >> v.at(0);
    cout << "The first element in the vector is " << v.at(0) << endl;
    cout << "The second element in the vector is " << v.at(1) << endl;

    // One of the most useful things we will need is the ability to output
    // the contents of a vector because while developing and debugging our
    // program we will often want to check the contents of the vector.
    // This is the second time we have done this, maybe this should be a
    // function that we can reuse?
    for(size_t i = 0; i < v.size(); ++i)
    {
        cout << v.at(i) << ' ';
    }
    cout << endl;

    // We can even define a vector of vectors (2D vector!)
    vector<vector<int>> v2;
    int value;
    string str;

    cout << endl;
    cout << "Enter a row of space separated values (press enter to stop): "
        << endl;

    // Due to prior use of cin >> we need to ignore the \n that is 
    // is still in the input stream buffer
    cin.ignore();

    // To construct the vector of vectors we will first need to build the
    // internal vector, and the push that vector into our vector of vectors
    while(getline(cin,str) && !str.empty())
    {
        // We can convert our string into a series of different datatypes
        // using stringstreams. Here we send the string acquired via getline
        // to the convert stringstream so that we can pull out the integer
        // values one at a time.
        stringstream convert;
        convert << str;

        // Now that the stringstream has the series of values stored as a 
        // string from getline, we will pull the values from the stream 
        // one at a time as integers and push them into an integer vector.
        vector<int> v3;        
        while(convert >> value)
        {
            v3.push_back(value);
        }

        // Once we have converted all the values in our string to integers
        // and created our vector of integers we can push it on to our
        // vector of vectors creating a 2D integer vector.
        v2.push_back(v3);
    }

    // We can perform the above steps with char or any native datatype to 
    // build a 2D vector of that datatype row by row.

    // Lets output the 2D vector, 2 dimensions is easiest to output
    // using a nested loops structure and since we know the iterations
    // count we will use nested for loops
    cout << "Output the 2D Vector: " << endl;
    for(size_t r = 0; r < v2.size(); ++r)
    {
        for(size_t c = 0; c < v2.at(r).size(); ++c)
        {
            // we don't always need to set these, but for variable length
            // numbers it is nice to unify the output formatting
            // set the alignment to left
            // set the field width to 8
            cout << left << setw(8); 

            // output the element value at a specific row, column
            cout << v2.at(r).at(c);
        }
        cout << endl;
    }
    cout << endl;


    // Let's complete the program we did manually yesterday to perform a 
    // Monte Carlo Simulation to estimate the probabilities associated with
    // rolling various dice values given two 6-sided dies to roll. 
    int numSims;   
    vector<int> dieValues(12);

    // Vector spots are initialized to a default value based on the element's
    // datatype. So for a vector of integers, all spots are initialized to 0.
    cout << "Intial values for our vector of counters: " << endl;
    for(size_t i=0; i < dieValues.size(); ++i)
    {
        cout << left << setw(8);
        cout << to_string(i+1) + ": " + to_string(dieValues.at(i));
        if ((i+1)%3 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;

    cout << "Enter the number of simulations: ";
    cin >> numSims;

    // Perform the number of simulat
    for(int i=0; i < numSims; ++i)
    {
        int rollV = roll(2, 6);
        dieValues.at(rollV - 1) += 1;
    }

    // We don't need to output all the decimal places, so we can specify
    // 2 digits after the decimal as the standard we want for floating 
    // point numbers output to the cout buffer.
    cout << fixed << setprecision(2);

    // calculate and output the estimated probabilities
    // for each potential dice roll value
    cout << "The estimated probability for each 2-dice roll is: " << endl;
    for(size_t i=0; i < dieValues.size(); ++i)
    {
        // We need to cast to avoid integer division pitfalls
        cout << i+1 << ": " 
            << static_cast<double>(dieValues.at(i)) / numSims * 100
            << "%" << endl;
    }

    // output the actual probability for reference
    cout << "Actual probability for 2 and 12 is: " << (1.0/6)*(1.0/6)*100 
        << "%" << endl;

    return 0;
}

// roll function from 05-23-2023 lecture
// see that lecture for more details on this function
int roll(int N, int sides=6)
{
    int r = 0;
    for (int i=0; i < N; ++i)
    {
        r += rand()%sides + 1;
    }
    
    return r;
}
