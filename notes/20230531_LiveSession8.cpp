/// @file 20230525_LiveSession6.cpp
/// @author Adam T Koehler, PhD
/// @date May 31, 2023
/// @brief Code and lecture notes from the live session.
///         This is a continuation of the May 30, 2023 program. We move from
///         parallel vector implementation to a struct and finally to a class
///         implementation. Each of these designs is contained within a single
///         file even though most class implementations are split across
///         files (a .h header and a .cpp implementation file).


#include <iostream>
#include <fstream>
#include <algorithm>    // for sort()
#include <sstream>      // for stringstream conversions
#include <iomanip>      // used for console output formatting

using namespace std;

int to_int(const string &);
void parseLine(const string &s, vector<string> &names, vector<string> &netIDs, 
    vector<int> &idNums, vector<char> &grades);
void printRosterNames(const vector<string> &);

// Simple function to print out all the vectors just to verify
// that the data was entered into each of the vectors.
void sanityPrint(const vector<string> &names, const vector<string> &netIDs, 
    const vector<int> &idNums, const vector<char> &grades);


int main()
{
    // the input data file name
    string filename = "data.txt";

    // Our parallel arrays serve as our data storage implementation
    // such that each index represents an individual, and using
    // that index for each of the vectors will get the data for
    // the one individual.    
    vector<string> names;
    vector<string> netIDs;
    vector<int> idNums;
    vector<char> grades;

    // Create a stream and immediately open using the filename.
    ifstream inF(filename);

    // Loop over the file, reading contents line by line until
    // the end of file is reached.
    while(!inF.eof())
    {
        string s;
        getline(inF,s);

        // We do not want to parse the line when we failed to get it
        // We do not want to parse the line when it is empty
        if(!inF.fail() && !s.empty())
        {
            parseLine(s, names, netIDs, idNums, grades);
        }
    }
    inF.close();

    // Simple sanity check to verify that all the vectors acquired all the 
    // data from within the file.
    cout << "--- SANITY CHECK: START PRINTING OF VECTORS ---"
        << endl;
    sanityPrint(names, netIDs, idNums, grades);
    cout << "--- SANITY CHECK: END PRINTING OF VECTORS ---"
        << endl << endl;

    // Print the names in alphabetical order
    printRosterNames(names);

    return 0;
}


/// @brief parse a comma separated string of data
/// @param s the string to parse into individual data pieces
/// @param names the data vector containing names
/// @param netIDs the data vector containing netIDs
/// @param idNums the data vector containing ID numbers
/// @param grades the data vector containing names
void parseLine(const string &s, vector<string> &names, vector<string> &netIDs, 
    vector<int> &idNums, vector<char> &grades)
{
    // the first piece of data will always go in case 0, names vector
    int c = 0;

    // create a copy of the string as we aren't allowed to alter
    // the original that is passed by const reference
    string look = s;

    // update the data vectors while content exists
    while (string::npos != look.find(","))
    {   
        // extract a substring up to first comma
        string content = look.substr(0,look.find(","));              

        // add the data to specific vector container
        addData(content, c, names, netIDs, idNums, grades);

        // shorten the string taking substring of everything after the comma
        look = look.substr(look.find(",") + 1);

        // switch which vector is being updated        
        c = (c+1) % 4;        
    }

    // the last piece of content on the line doesn't have a comma
    string content = look;              
    addData(content, c, names, netIDs, idNums, grades);

    // TODO
    //
    // TODO: What happens if we do not have a full line of data?
    // For example: Tom S,ts    
    //
    // TODO
}


/// @brief add the data in content to a specific vector of data
/// @param content the data to add to the vector
/// @param caseNum the integer determining which vector to add to
/// @param names the data vector containing names
/// @param netIDs the data vector containing netIDs
/// @param idNums the data vector containing ID numbers
/// @param grades the data vector containing names
void addData(const string &content, int caseNum,
    vector<string> &names, vector<string> &netIDs, 
    vector<int> &idNums, vector<char> &grades)
{
    // create a new entry in a specific data vector
    switch (caseNum)
    {
        case 0:
            names.push_back(content);
            break;

        case 1:                
            netIDs.push_back(content);
            break;

        case 2:
            idNums.push_back(to_int(content));
            break;

        case 3:
            grades.push_back(content.at(0));
            break;

        default:
            cout << "uh oh, shouldn't be here" << endl;
            break;
    }    
}

/// @brief Search for a specific ID number, and return the index or -1
/// @param names the data vector containing names
/// @param netIDs the data vector containing netIDs
/// @param idNums the data vector containing ID numbers
/// @param grades the data vector containing names
int searchIDs(int searchFor, const vector<int> &idNums)
{
    // TODO

    return -1;
}


/// @brief Print out a nicely formatted roster with all the student information
/// @param names the data vector containing names
/// @param netIDs the data vector containing netIDs
/// @param idNums the data vector containing ID numbers
/// @param grades the data vector containing names
void printRoster(const vector<string> &names, const vector<string> &netIDs, 
    const vector<int> &idNums, const vector<char> &grades)
{

    // TODO

}


/// @brief print out all the names in alphabetical order
/// @param names the data vector containing all the names
void printRosterNames(const vector<string> &names)
{
    // we cannot modify a const reference and do not want to update to just 
    // to pass by reference because sorting one parallel vector will rearrange
    // it and then the index for one cannot be used across all of them to 
    // access index-linked data of an individual
    vector<string> copy = names;

    // Invokes sort from algorithms library which is almost always 
    // either the QuickSort or MergeSort sorting methods
    // sort requires two iterators, the beginning and the end of the container
    // these can be acquired using the begin() and end() member functions
    sort(copy.begin(), copy.end());
    
    cout << "Sorted Names:" << endl;
    for(size_t i = 0; i < copy.size(); ++i)
    {
        cout << copy.at(i) << endl;
    }
}




/// @brief convert a given string to an integer using stringstreams
/// @param convert the string containing a number
/// @return the integer value extracted from the string
int to_int(const string &convert)
{
    int result;
    stringstream ss;
    ss << convert;
    ss >> result;
    return result;
}

/// @brief Simple function to print out all the vectors just to verify
///          that the data was entered into each of the vectors.
void sanityPrint(const vector<string> &names, const vector<string> &netIDs, 
    const vector<int> &idNums, const vector<char> &grades)
{
    vector<string> copy = names;
    for(size_t i = 0; i < copy.size(); ++i)
    {
        cout << copy.at(i) << endl;
    }
    cout << endl;

    copy = netIDs;
    for(size_t i = 0; i < copy.size(); ++i)
    {
        cout << copy.at(i) << endl;
    }
    cout << endl;

    vector<int> copy2 = idNums;
    for(size_t i = 0; i < copy2.size(); ++i)
    {
        cout << copy2.at(i) << endl;
    }
    cout << endl;

    vector<char> copy3 = grades;
    for(size_t i = 0; i < copy3.size(); ++i)
    {
        cout << copy3.at(i) << endl;
    }
}