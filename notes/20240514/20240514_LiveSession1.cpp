/// @file 20240514_LiveSession1.cpp
/// @author Adam T Koehler, PhD
/// @date May 14, 2024
/// @brief Code and lecture notes from the live session.


// libraries to include, we always want to be specific
#include <iostream>
#include <string>
#include <random>

using namespace std;

int main()
{
    // identify a specific two character for each card
    // then storing in a string, separated by a space
    // e.g. "?B AH"

    // "B-9 R+4"

    string values = "A1234567890JQK?";

    string userEntry, userEntry2;
    char userE;
    int uE; // index into the string

    // cout << (int) 'A' << endl;

    cin >> userE;
    // cin >> userEntry;
    // getline(cin, userEntry2);
    // cin >> uE;

    // cout << userE << endl;
    // cout << userEntry << endl;

    // cout << userEntry2 << endl;
    // cout << uE << endl;

    int randIndex;
    srand(100);
    randIndex = rand()  % values.size();

    cout << (values.at(randIndex)) << endl;

    if (values.at(randIndex) < userE)
    {
        cout << "You win!" << endl;
    }
    else
    {
        cout << "You Lose :(" << endl;
    }
}




