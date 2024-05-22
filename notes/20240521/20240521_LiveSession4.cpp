/// @file 20240521_LiveSession4.cpp
/// @author Adam T Koehler, PhD
/// @date May 21, 2024
/// @brief Code and lecture notes from the live session. Requires -std=c++20
///     C++ Concepts: Monte Carlo Simulations, Estimated Probability
///                   rand(), vectors, arrays, file input intro
///                   function writing and function decomposition


// Order of the live code from lecture:
// 1. Before main() - algorithm development with welcome activity
// 2. vectorVersion() with console input
// 3. maxIndex()
// 4. arrayVersion() with file input
// 5. maxIndexArray()


// libraries to include, we always want to be specific
#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


// Welcome Activity: Algorithm For Recording Roll Sum Observations
// 1. shake and roll
// 2. add all dice together
// 3. write it down
// 4. repeat 1 to 3 a total of 25 times

// Post Activity Questions:
// How do we know the max observation count?
//  Option 1: Track max as you accumulate observations,
//      and replace with the new value when new max.
//  Option 2: After creating or acquiring all the data,
//      go through data to determine the max.

// What is Estimated Probability of an outcome?
//  The occurrences of your outcome divided by the total occurrences observed.



// prototypes in order of implementation after main()
void vectorVersion(); // uses console input
void arrayVersion(); // uses file IO
size_t maxIndex(const auto &obs);
uint maxIndArray(int arr[], uint N);


int main()
{    
    cout << "Vector Version:" << endl;
    srand(1000); // seed to have same seeded sequence
    vectorVersion();

    cout << endl << endl;

    cout << "Array Version:" << endl;
    srand(1000); // seed to have same seeded sequence
    arrayVersion();

    return 0;
}


/// @brief vector implementation of our Monte Carlo simulation of 
///     observations of three dice rolls.
void vectorVersion()
{
    // 0,1,2 go unused, 3-18 will have counts for dice sums
    // Vectors are automatically initialized to default values,
    // here our vector will contain 19 spots initialized to 0.
    vector<uint> observations(19);

    int simulations, sum;

    // Acquire the number of simulations from the user
    cout << "Number of simulations? ";
    cin >> simulations;
    cout << endl;

    // Iterate for the desired number of simulations
    for (int i = 0; i < simulations; ++i)
    {
        // combine three die rolls 
        sum = (1 + rand() % 6) + (1 + rand() % 6) + (1 + rand() % 6);

        // count the observation, use the sum as the index into the array
        observations.at(sum) += 1;
    }
    
    // Output the roll sum with the maximum occurrences
    cout << "Total Simulations: " << simulations << endl;
    cout << "Max occurrences: " << maxIndex(observations) << endl;

    // for (const auto &e : observations)
    // We don't want to use for-each here because we want to skip the first
    // three and we need the index as that is the sum of the three dice that
    // was observed. The contents are just a counter for observations.

    // Iterate through all the valid roll sums and
    //   output the estimated probability for each roll sum
    cout << "Roll Value : Estimated Probability" << endl;
    for (size_t i = 3; i < observations.size(); ++i)
    {
        cout << i << ": ";
        cout << static_cast<double>(observations.at(i)) / simulations * 100;
        cout << "%" << endl;
    }
}


/// @brief array implementation of our Monte Carlo simulation of 
///     observations of three dice rolls
void arrayVersion()
{
    ifstream inF;
    
    // We could open the file during the creation of the stream
    // ifstream inF("in.txt");
    
    // Acquire the file name to open for input
    string filename;
    cout << "Enter a filename: ";
    cin >> filename;
    cout << endl;
    
    // attempt to open the file
    inF.open(filename);

    // We always want to make sure we successfully opened the file
    // Here if we couldn't open the file, then we are done.
    if (!inF.is_open())
    {
        cout << "Invalid filename: " << filename << endl;
        return; 
    }

    // Create an array for the observations
    // int observations[19];  // 19 unitialized spots

    // Create an array for the observations
    // Use initialization list syntax to initialize all values to zero.
    // 0,1,2 go unused, 3-18 will have counts for dice sums
    int observations[19] = {0};

    int simulations, sum;

    // We previously only used console input
    // cin >> simulations;

    // Acquire the simulation count from file
    // Note that the operator is the same, 
    // we simply changed the stream variable name
    inF >> simulations;

    // Close the file as soon as we are done with it    
    inF.close();

    // Iterate for the desired number of simulations
    for (int i = 0; i < simulations; ++i)
    {
        // combine three die rolls 
        sum = (1 + rand() % 6) + (1 + rand() % 6) + (1 + rand() % 6);

        // count the observation, use the sum as the index into the array
        observations[sum] += 1;
    }
    
    // Output the roll sum with the maximum occurrences
    cout << "Total Simulations: " << simulations << endl;
    cout << "Max occurrences: " << maxIndArray(observations, 19) << endl;
    

    // Iterate through all the valid roll sums and
    //   output the estimated probability for each roll sum
    cout << "Roll Value : Estimated Probability" << endl;
    for (size_t i = 3; i < 19; ++i)    
    {
        cout << i << ": ";
        cout << static_cast<double>(observations[i]) / simulations * 100;
        cout << "%" << endl;
    }
}


/// @brief Determine the index of the maximum value of an container.
/// @param obs the container to iterate over
/// @return the index of the highest number in the container
/// @pre container is non-empty
size_t maxIndex(const auto &obs)
// uint maxIndex(const vector<uint> &obs)
{
    size_t maxInd = 0;

    for(size_t i = 0; i < obs.size(); ++i)
    {
        if (obs.at(maxInd) < obs.at(i))
        {
            maxInd = i;
        }
    }
    return maxInd;
}


/// @brief Determine the index of the maximum value of an array.
/// @param arr the array to iterate over
/// @param N the size of the array arr
/// @return an unsigned integer representing the index of the max value
/// @pre arr is a non-zero sized array
uint maxIndArray(int arr[], uint N)
{
    uint maxI = 0;
    for(int i=0; i < N; ++i)
    {        
        if (arr[maxI] < arr[i])
        {
            maxI = i;
        }
    }
    return maxI;
}