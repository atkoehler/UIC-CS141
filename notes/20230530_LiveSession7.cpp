/// @file 20230525_LiveSession6.cpp
/// @author Adam T Koehler, PhD
/// @date May 30, 2023
/// @brief Code and lecture notes from the live session.

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void printRosterNames(const vector<string> &names);
void parseLine(const string &s, vector<string> &names, vector<string> &netIDs, 
    vector<int> &idNums, vector<char> &grades);

int main()
{
    string filename = "data.txt";

    vector<string> names;
    vector<string> netIDs;
    vector<int> idNums;
    vector<char> grades;

    ifstream inF(filename);

    while(!inF.eof())
    {
        string s;
        getline(inF,s);

        if(!inF.fail())
        {
            parseLine(s, names, netIDs, idNums, grades);
        }
    }
    inF.close();

    printRosterNames(names);

    return 0;
}

void parseLine(const string &s, vector<string> &names, vector<string> &netIDs, 
    vector<int> &idNums, vector<char> &grades)
{
    int c = 0;
    string look = s;

    while (string::npos != look.find(","))
    {
        string content = look.substr(0,look.find(","));
        switch (c)
        {
            case 0:
                names.push_back(content);
                break;

            case 1:
                
                netIDs.push_back(content);
                break;

            case 2:

                break;

            case 3:

                break;

            default:
                cout << "uh oh, shouldn't be here" << endl;
                break;
        }
        c = (c+1) % 4;
        look = look.substr(look.find(",")+1);

    }
    
}


void printRosterNames(const vector<string> &names)
{
    vector<string> copy = names;

    // Invokes sort from algorithms library which is almost always 
    // either the QuickSort or MergeSort sorting methods
    sort(copy.begin(), copy.end());
    
    cout << "Sorted Names: " << endl;
    for(size_t i = 0; i < copy.size(); ++i)
    {
        cout << copy.at(i) << endl;
    }
}
