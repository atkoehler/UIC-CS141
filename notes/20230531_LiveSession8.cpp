/// @file 20230531_LiveSession8.cpp
/// @author Adam T Koehler, PhD
/// @date May 31, 2023
/// @brief Code and lecture notes from the live session.
///         This is a continuation of the May 30, 2023 program. We move from
///         parallel vector implementation to a struct and finally to a class
///         implementation. Each of these designs is contained within a single
///         file even though most class implementations are split across
///         files (a .h header and a .cpp implementation file).

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution). 


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>    // for sort()
#include <sstream>      // for stringstream conversions
#include <iomanip>      // used for console output formatting

// If we were to place our Student class in a separate file
// the class declaration would go in a header file (.h) that
// we can include with our other library includes.
// #include "student.h"

using namespace std;

// A struct can be utilized to create a collection of different
// data types, unlike our parallel data structure example where
// the vectors all contained the same data type and then multiple
// vectors were used to allow multiple data types.

// A struct is public by default
struct StudentStruct
{
    string name;
    string netID;
    int idNum;
    char grade;
};
//  ^ the semicolon terminates the struct declaration

// In C++ we implement objects using classes. Classes are private by default.
// Classes can have three areas, private, protected, and public.
class Student
{
    // Our private data members or functions are only accessible within the 
    // class. This means that any of our member functions can access the 
    // private data members directly, but everyone else (users, derived 
    // classes, etc) will need to use the public accessors and mutators to
    // acquire or set the values of the private data members.
    private:
        string name;
        string netID;
        int idNum;

    // The protected area contains data members or functions that are
    // accessible within class itself as well as any derived classes.
    protected:
        char grade;       

    // The public area contains data members or functions that are directly
    // accessible to all users of the class.
    public:

    // We can define our functions directly inside the class or we can just
    // declare a prototype and then define the function elsewhere.
        char getGrade() const;

    // const in the above and below cases (and elsewhere) demonstrates a
    // function declaration or definition that is not allowed to change
    // the data members of the class. Any function called within a const
    // function must also be const to maintain the const chain.
        string getName() const 
        {
            return name;
        }

        /// @brief acquire the value of the student's netID
        /// @return the string value of the private netID data member
        string getNetID() const 
        {
            return netID;
        }

        /// @brief acquire the ID number of the student
        /// @return the value of the private ID number data member
        int getIDNum() const 
        {
            return idNum;
        }
       
        /// @brief set the private data member grade to the provided grade
        void setGrade(char);

        /// @brief set the private data member ID number to the provided number
        /// @param n the number to set the student's ID number to
        void setIDNum(int n)  
        {
            idNum = n;
        }

        void setNetID(string n)  
        {
            netID = n;
        }

        void setName(string n)  
        {
            name = n;
        }
};
// ^ the semicolon terminates the class declaration

// We can also define class member functions outside the class. In this case
// we will need to use the scope resolution operator as well as the class name
// to note where the function is declared and what is belongs to.

/// @brief acquire the student's current grade
/// @return return the value of the private data member grade
char Student::getGrade() const 
{
    return grade;
}

/// @brief set the student's current grade
/// @param g the value to set the private data member grade to
void Student::setGrade(char g) 
{
    grade = g;
}


// Hold over helper function
// Converts a string to an integer using stringstreams
int to_int(const string &);


// Helper functions which we converted to use our Student data type
void parseLine(const string &s, vector<Student> &data);
int searchIDs(int, const vector<Student> &);
void printRoster(const vector<Student> &data);
void addData(const string &content, int caseNum, vector<Student> &data);


int main()
{
    // the input data file name
    string filename = "data.txt";

    // We can create an object of type Student just like creating any variable
    // by using the type, Student, and providing a name for our variable.
    StudentStruct blank;
    
    // Since a struct is public by default we can set and access all the data
    // members of the struct directly.
    blank.name = "Tom Thumb";
    blank.netID = "tthumb";
    
    // Just like we saw with vectors, our data members are initilized to the
    // default for the specific data type.
    cout << blank.idNum << endl;

    blank.grade = 'Q';
    cout << blank.grade << endl;
    
    // We can also create containers of the data type because the data type
    // we have now defined as a class is like any other data type we might
    // use with vectors.
    vector<Student> data;

    // We converted our parallel vectors into a single vector of type Student
    // vector<string> names;
    // vector<string> netIDs;
    // vector<int> idNums;
    // vector<char> grades;

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
            // We no longer need to pass all the vectors, we just pass
            // the one vector of Student objects.
            // parseLine(s, names, netIDs, idNums, grades);
            parseLine(s, data);
        }
    }
    inF.close();


    // Our printRoster function just needs to take the single vector
    // now and properly iterate over the container of Students
    // printRoster(names, netIDs, idNums, grades);
    printRoster(data);


    // We can search through our vector of students just like a vector
    // of any data type. We use function decomposition to allow us
    // to search multiple times and create more readable code.
    cout << endl << "Begin Search for specific ID query..." << endl;
    int userNum;
    cout << "Enter an ID (-1 to quit): ";
    cin >> userNum;
    cout << endl;

    while (userNum != -1) 
    {
        cout << "Searching... " << searchIDs(userNum, data) << endl;
        cout << "Enter an ID (-1 to quit): ";
        cin >> userNum;
        cout << endl;
    }

    return 0;
}


/// @brief parse a comma separated string of data
/// @param s the string to parse into individual data pieces
/// @param data the data vector containing all the Student objects
void parseLine(const string &s, vector<Student> &data)
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
        // addData(content, c, names, netIDs, idNums, grades);
        addData(content, c, data);

        // shorten the string taking substring of everything after the comma
        look = look.substr(look.find(",") + 1);

        // switch which vector is being updated        
        c = (c+1) % 4;        
    }

    // the last piece of content on the line doesn't have a comma
    string content = look;    

    // We no longer need to add the data to one of the four vectors,
    // but we still need to know which data member field we should 
    // be filling so we can use a similar switching strategy.          
    // addData(content, c, names, netIDs, idNums, grades);
    addData(content, c, data);

    // handle partial line of data, don't use empty strings because
    // visually those look like missing data instead of purposefully
    // skipped data
    if (c == 0)
    {
        addData("-", 1, data);   
        addData("0", 2, data);   
        addData("-", 3, data);   
    }
    else if (c == 1)
    {   
        addData("0", 2, data);   
        addData("-", 3, data);   
    }
    else if (c == 2)
    {     
        addData("-", 3, data);   
    }
}


/// @brief set the proper private data member of the Student
/// @param content the string value stripped from the parsed line
/// @param caseNum the indicator for determining which data member to update
/// @param data the container with all the Student objects
void addData(const string &content, int caseNum, vector<Student> &data)
{
    // when the case is 0 we will need to create a new entry in the container
    // we can just quickly generate a blank student to push into the vector
    Student blank;

    // update the specific data member in the Student object
    // as this is a "user" of the class, we cannot directly access the private
    // data members and therefore need to use the mutator functions
    switch (caseNum)
    {
        // Create an entry in the container and set the name
        // We use back() to acquire the last spot in the vector versus
        // using at(size() - 1).
        case 0:
            data.push_back(blank);
            data.back().setName(content);
            break;

        // case 1 sets the netID private data member
        case 1:                
            data.back().setNetID(content);
            break;

        // case 2 set the ID number private data member
        case 2:
            data.back().setIDNum(to_int(content));
            break;

        // case 3 set the grade private data member
        case 3:
            data.back().setGrade(content.at(0));
            break;

        // any other case is an error
        default:
            cout << "uh oh, shouldn't be here" << endl;
            break;
    }    
}


/// @brief Search for a specific ID number, and return the index or -1
/// @param searchFor the ID number to search for
/// @param data the container of all the Student objects
/// @return the numerical index value when a match is found, otherwise -1
int searchIDs(int searchFor, const vector<Student> &data)
{
    // unsorted so we use linear search, if the vector was sorted
    // then we would use binary search because it is much faster
    for(size_t i = 0; i < data.size(); ++i)
    {
        if (data.at(i).getIDNum() == searchFor)
        {
            // we want to return as soon as we discover the value because
            // if we do not immediately return then we will always search
            // the entire vector. This means if we found a match at index 0
            // then we would still search the other N-1 elements where N
            // is the size of the vector. That is very inefficient when N
            // could be in the billions.
            return i;
        }
    }

    // When we get to this point of our algorithm, we never entered the branch
    // that exists inside our loop and therefore never discovered a match.
    return -1;
}


/// @brief Print out a nicely formatted roster with all the student information
/// @param data the data vector containing all the Student objects
void printRoster(const vector<Student> &data)
{
    cout << left;
    cout << setw(16) << "Name";
    cout << setw(12) << "netID";
    cout << setw(12) << "ID Number";
    cout << setw(10) << "Grades" << endl;
    cout << setfill('-') << setw(50) << '-' << endl;
    cout << setfill(' ');

    for(size_t i=0; i<data.size(); ++i)
    {
        cout << setw(16) << data.at(i).getName();
        cout << setw(12) << data.at(i).getNetID();
        cout << setw(12) << data.at(i).getIDNum();
        cout << setw(10) << data.at(i).getGrade() << endl;
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