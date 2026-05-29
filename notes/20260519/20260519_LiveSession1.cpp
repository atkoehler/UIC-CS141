/// @file 20260519_LiveSession4.cpp
/// @author Adam T Koehler, PhD
/// @date May 19, 2026
/// @brief Code and lecture notes from the live session. Requires -std=c++20

// goal: acquire postive numbers and 
// store them

// what is positive?
// > 0 ? >= 0


// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     //python list
//     //untyped variables

//     int q = 0;
//     long r = 0;
//     float y = 0.0;
//     double z = 0;
 
//     vector<int> v;

//     cout << "Enter a number: ";
//     cin >> q;
//     cout << endl;

//     // cout << q << " " << r << endl;
//     int arr[5];

   
//     // if (q > 0)

//     while (q > 0)
//     {
//         v.push_back(q);
        
//         cout << v.size() << endl;
//         cout << v.back() << endl;

//         cout << "Enter a number: ";
//         cin >> q;
//         cout << endl;
//     }

//     // else if(q == 0)
//     // {
//     //     cout << "zero not included" << endl;
//     // }
//     // else
//     // {
//     //     cout << "wrong number" << endl;
//     //     cout << "am i in the else" << endl;
//     // }

//     cout << v.size() << endl;

//     // how to access an element 
//     // of the vector

//     for (int i = 0; i < 100000; ++i)
//     {
//         cout << "Outputting element " << i << endl;
//         cout << v.at(i) << endl;
//     }

//     return 0;
// }



#include <iostream>
#include <vector>
#include <random>

using namespace std;

int getRoll()
{
    return rand()%6+1 + rand()%6+1 
        + rand()%6+1;
}

int main()
{
    int roll;
    int simCount = 0;
    cin >> simCount;


    int a = 5;
    int b = 7;
    int c = a++ + b;
    int d = ++a + b;

    vector<int> data;

    for(int i=0; i < simCount; ++i)
    {
        roll = getRoll();
        data.push_back(roll);
        // data.push_back(getRoll());
    }

    vector<int> count(19);
    for (auto &e : data)
    {
        count.at(e) += 1;
    }


    for(int i=0; i <= 18; ++i)
    {
        cout << i << ": " 
        << static_cast<double>(count.at(i))
             / simCount << endl;
    }

    return 0;
}


#include <iostream>
#include <vector>
#include <random>
#include <array>
#include <print>

using namespace std;

/// @brief Simulate rolling 3 6-sided dice.
/// @param mt19937 pass the random generator engine by
///                reference (&) to allow internal state to be updated.
/// @param dist the distribution of the individual die rolls
int get_roll(mt19937& rng, uniform_int_distribution<int>& dist) 
{
    return dist(rng) + dist(rng) + dist(rng);
}


int main() 
{
    int sim_count = 0;

    print("Enter simulation count: ");
    if (!(cin >> sim_count) || sim_count <= 0) 
    {
        println(stderr, "Invalid input.");
        return 1;
    }


    // Modern, high-quality random number generator
    // rand() is a pseudorandom number generator
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> dist(1, 6);


    // srand(dist(rng));

    // vector to hold our data
    vector<int> data;
    
    // Populate the vector with random roll data.
    for (int i = 0; i < sim_count; ++i) 
    {
        int roll = get_roll(rng, dist);
        data.push_back(roll);
    }

    // Fixed-size array to count frequencies, initialized to all zeros.
    array<int, 19> count{};
    for (const auto &roll : data) 
    {
        count[roll]++;
    }

    // Formatted Printing
    for (int i = 0; i <= 18; ++i) 
    {
        println("{:2}: {:.5f}", i, static_cast<double>(count[i]) / sim_count);
    }



    // for (indexed)
    // for-each
    // while

    // do-while
    int x = 5; 
    int y = 7;
    do
    {
        x++;
    } while (x < y);
    
    return 0;
}

