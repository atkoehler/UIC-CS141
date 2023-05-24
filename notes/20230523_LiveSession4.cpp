/// @file 20230523_LiveSession4.cpp
/// @author Adam T Koehler, PhD
/// @date May 23, 2023
/// @brief Code and lecture notes from the live session on functions and vectors.

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution). 

#include <iostream>
#include <string>

using namespace std;


// Recall the function parts:
// return_type function_name (parameters list)
//      function body

// a function prototype tells us everthing we need to know to use a function.
// Below we have a void function, which means it returns nothing via the 
// return statement. Additionally we have the function name and a list of 
// parameters.
//
// The parameters are both strings, which are always passed by reference.
// Therefore choosing between const or not is an important 
// distinction. The presence of const means the varialbe is only used by
// the function and the value is not changed. The lack of const, means that
// the variable may or may not be updated (possibly based on function logic)
// but the variable can be updated.
//
// Within a prototype, variable names are optional, but when they are present
// it is usually a style choice to increase code readability.
void f(const string &, string &strToUpdate);



/// @brief simulate the rolling of N dice with the specified number of sides
/// @param N the number of dice to roll
/// @param sides the number of sides on each die
/// @return the sum of all the dice
int roll(int N, int sides=6)
{
    int r = 0;
    
    // calculate the sum of N die rolls to simulate rolling N dice
    for (int i=0; i < N; ++i)
    {
        int rollvalue = rand()%sides + 1;

        // Debugging Option
        // Output individual die roll value to allow manual summation
        // of the values to check rolls and make sure they are properly
        // accumulating to the value returned and output by main()
        // cout << rollvalue << endl;

        r = r + rollvalue;
    }
    
    return r;
}

// We could do a pass by reference for N, allowing the variable that N
// refers back to to be updated. In this example, N dice are rolled the first
// call and then the second call within the main function loop will roll ten
// dice due to the N variable update at the end of the function.
//
// Generally we will only use pass by reference with native data types if 
// we wish to update a variable that is outside the scope of the function.
// And we will almost never use const reference with native datatypes as 
// it is equally efficient in almost all cases to just use pass by value.
// int roll(int &N, int sides=6)
// {
//     int r = 0;
//    
//     // calculate the sum of N die rolls to simulate rolling N dice
//     for (int i=0; i < N; ++i)
//     {
//         r += rand()%sides + 1;
//     }
//
//     N = 10; //updates the variable in different scope
//    
//     return r;
// }


int main()
{
    // We start the pseudo random sequence with a specific seed so that we 
    // can reproduce our results. In a live system we would seed with some
    // sort of timestamp so that the random sequence is different for every
    // execution. Each time we call srand, the sequence is restarted.
    srand(0);

    int b = 5, c = 6, numSims = 2;

    // Simulation loop that rolls the dice numSims times
    for(int i = 0; i < numSims; ++i)
    {
        // if we simply call our function without storing
        // or using the value then we will lose that value
        // roll(b,c);

        // if we call a function that has a reference parameter, then a 
        // variable must be sent as the corresponding argument, we cannot
        // send a literal value because literals do not have memory addresses
        cout << roll(b,c) << endl;
    }

    return 0;
}

