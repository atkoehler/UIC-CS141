/// @file 20250520.cpp
/// @author Adam T Koehler, PhD
/// @date May 20, 2025
///
/// @brief Notes for live CS 141 lecture on May 20, 2025. 
///         Concepts covered include:
///         Algorithms, Variables, Branches, Loops, 
///         Functions, Randomness, Counting, and Full C++ Programs.


// Process Concerns & Reflections
// 1. Step by Step vs Prose Paragraph
// 2. More precise definitions of terms and processes
// 3. Very precise definition of how to shake, why certain choices
//      in an algorithm design, ---> preference at time of invention
// 4. Dice vs die gramatical concerns, describe hand movement
//      reflections: need more room to write 
// 5. how do dice get picked up?
//        --> gave more precise description of picking up 
// 6. More detail on step 1, less on step 2, 
//      and 3 environment unnecessary 
//      -- alterations to some of the steps to account for differences

#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;


/// @brief 
/// @param n number of dice
/// @return the accumulated sum of dice
int dieRoll(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += rand() % 6 + 1;
    }
    return sum;
}


int main()
{
    srand(2025);

    int x, n, count=0;
    // x = 6;
    // n = 10;

    cout << "What value to look for? ";
    cin >> x;
    cout << endl;

    cout << "How many simulations? ";
    cin >> n;
    cout << endl;

    cout << "Values: " << x << " " << n << endl;

    x = 3;
    int count1, count2, count3, count4, count5, count6;
    count1 = 0;
    count2 = 0;
    count3 = 0;
    count4 = 0;
    count5 = 0;
    count6 = 0;

    // x = "string";
    for (int i = 1; i <= n; ++i)
    {
        int value= dieRoll(1);

        if (1 == value)
        {
            ++count1; // count += 1; count = count + 1;
        }
        else if (2 == value)
        {
            ++count2; // count += 1; count = count + 1;
        }
        else if (3 == value)
        {
            ++count3; // count += 1; count = count + 1;
        }
        else if (4 == value)
        {
            ++count4; // count += 1; count = count + 1;
        }
        else if (5 == value)
        {
            ++count5; // count += 1; count = count + 1;
        }
        else if (6 == value)
        {
            ++count6; // count += 1; count = count + 1;
        }
    }

    cout << static_cast<double>(count1) / n << endl;
    cout << static_cast<double>(count2) / n << endl;
    cout << static_cast<double>(count3) / n << endl;
    cout << static_cast<double>(count4) / n << endl;
    cout << static_cast<double>(count5) / n << endl;
    cout << static_cast<double>(count6) / n << endl;

    // srand(time(0)); // not a good way to randomize

    // cout << "Hello CS 141 SUmmer 2025!\n" << endl;

    // string s = "Hello CS 141 SUmmer 2025!\n";
    // cout << s
    //     << endl;

    // long, int, short, char -- whole numbers
    // double, float -- floating point numbers

    // int y = 5 / 4 + 4.5;
    // int x = rand();
    // int z = rand() %  6 + 1; // range + min

    // // if we want a range from 2-6 how?
    // // range ==> max - min
    // // int q = rand()%(max - min) + min;
    // cout << y << endl;
    // cout << x << " " << z << endl;

    // if (z == 5)
    // {
    //     cout << "Winner" << endl;
    // }
    // else
    // {
    //     cout << "Not a winner" << endl;
    // }

    // for (int i = 0; i < 5; ++i)
    // {
    //     cout << "hi" << endl;
    // }

    // int i = 0;
    // do 
    // {
    //     cout << "there" << endl;
    //     ++i; //pre-increment
    //     i++; //post-increment
    // } while (i < 5);

    return 0;
}
