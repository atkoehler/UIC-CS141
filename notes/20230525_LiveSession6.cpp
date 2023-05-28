/// @file 20230525_LiveSession6.cpp
/// @author Adam T Koehler, PhD
/// @date May 25, 2023
/// @brief Code and lecture notes from the live session on 2D vectors & arrays.

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution). 

#include <iostream>
#include <string>
#include <fstream>

#include <cstring> // for C-string functions such as strlen()

using namespace std;

/// @brief print out a c-string one character per line
/// @param x the c-string to print
/// @param size the size of the array
void printMe(char *x, int size)
{
    // When using arrays we pass the size to the function
    // to know how large the array is as arrays do not have
    // member functions and therefore we cannot invoke .size()
    for(int j = 0; j < size; j++)
    {
        cout << x[j] << endl;
    }

    // Alternatively with C-strings we can loop until
    // we see the terminating null character
    for(int j = 0; x[j] != '\0'; ++j)
    {
        cout << x[j] << endl;
    }
}

/// @brief count the quantity of characters in a C-string
/// @param x the c-string to count the length of
int countMe(char *x)
{
    // start i at the first index for an array
    int i = 0;

    // remember we always need to start counters at 0
    // otherwise when we try to add to the current value
    // the value will be garbage
    int c = 0;

    // using post-increment operator within an expression means that the
    // expression will evaluate and then the variable will be incremented
    // in this specific case we acquire x[i]'s value and then add 1 to i
    while(x[i++] != '\0')
    {
        c++;
    }

    // as we looped until but did not include the null character we have 
    // counted all the characters prior to the C-string terminating character
    return c;
}

/// @brief replce the first C-string with the second C-string
/// @param f the c-string to overwrite with the second paraamter
/// @param s the c-string to copy into the first parameter
void replaceCString(char *f, char *s)
{
    // We can use our function to determine how long the C-string is
    int fsize = countMe(f);

    // We can also use strlen() to calculate the length
    int ssize = strlen(s);

    // When the second one doesn't fit, do nothing.
    if (ssize > fsize)
    {
        return;
    }

    // Assign each character from the second to the first C-string
    for (int i = 0; i < ssize; ++i)
    {
        f[i] = s[i];
    }

    // All C-strings must be properly terminated with a null character
    f[ssize] = '\0';
}

void printArray(int a[], int size)
{
    for(int j = 0; j < size; j++)
    {
        cout << a[j] << ' ';
    }   
    cout << endl;
}

int main()
{
    // We can create an unitialized array
    int a[10]; // <- will be garbage values, but could be 0

    // We can initialize all values to a single value
    int b[10] = {0};

    // We can initialize some values and 
    // the other values will be set to a default value
    int c[10] = {1,2,3};


    // one useful function to define is the print array
    // function because it is a very common task, especially
    // while debugging
    // for(int j = 0; j < 25; j++)
    // {
    //     cout << s[j] << ' ';
    // }
    // cout << endl;

    // We invoke arrays with functions just like all other functions    
    printArray(a,5);
    printArray(b,10);
    printArray(c,10);


    // C-strings are null terminated character arrays
    // we can initialize immediately with a string literal
    // the null character is automatically added with this initialization
    char t[6] = "hello"; 
    char r[4] = "bye";
    
    // C-strings can be output directly just like strings
    cout << t << endl << r << endl;

    // Arrays can be output but will just output 
    // the address of the first element
    cout << a << endl;
    cout << &a[0] << endl; // same as outputting a
    cout << &b[1] << endl;

    // We invoke arrays with functions just like all other functions    
    replaceCString(t, r);

    // The null character terminates the string when using the
    // inersertion operator
    cout << t << endl;

    // However, there are still characters that exist in the other spots
    // of the array that was partially overwritten.
    printMe(t,6);

    // We can also write functions to count the characters.
    cout << countMe(t) << endl;


    // We can access any index in the square brackets including negative
    // indices, C++ just calculates the offset from the 0 index and then
    // accesses that memory spot. For example, -1 will access the memory
    // spot just above the 0 index spot. There is no bounds checking with
    // square brackets, the program will simply attempt to get the value
    // from that memory offset. If that memory is accessible to the program
    // the program will continue, if it is not then a segmentation fault
    // will occur. SEG errors are memory access errors.
    cout << t[-1] << endl;
    

    // We can declare an array that is a size taken in from user or file input.
    // However once the array is created it is static in size so it cannot
    // grow any larger (unlike a vector).    
    int howbig;
    cin >> howbig;
    int q[howbig];


    // File Streams allow us to use the insertion and extraction operators as
    // well as other input or output operations to acquire data from files.
    // We include the fstream library to use input file streams, ifstream,
    // and output file streams, ofstream.
    ifstream inFile;
    ofstream outFile;

    int array_ten[10];

    inFile.open("in.txt"); // open and attach file to inFile

    // We know we have 10 spots, so we can loop and acquire 10 data values
    // from the inFile stream.
    for(int z=0; z < 10; ++z)
    {
        inFile >> array_ten[z];
    }   
    
    inFile.close(); // always remember to close the file, it is good practice

    // We could get a whole line at a time with getline
    // getline(inFile, str);

    printArray(array_ten, 10);

    // Similar to input interactions we can output to a file as well.
    outFile.open("out.txt");
    for(int z=0; z < 10; ++z)
    {
        outFile << 2 * array_ten[z] << ' ';
    }   
    outFile << endl;
    outFile.close();

    return 0;
}
