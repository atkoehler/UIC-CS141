/// @file 20240529_LiveSession8.cpp
/// @author Adam T Koehler, PhD
/// @date May 29, 2024
/// @brief Code and lecture notes from the live session. 
///     Topics Covered: Function decomposition with classes.
///                     C-strings, pointers, new keyword

// Order of the live code from lecture:
// 1. Welcome Activity on function decomposition with classes
// 2. Implement C-string Function: countCString(...)
// 3. Examples() exploring usage of and checking countCString(...)
// 4. Exploring pointer variables in Examples()
// 5. Developing countbyPtr(...) and countbyPtrOnly(...)
// 6. Testing pointer only counting in Examples()
// 7. Introduction to new keyword at end of Examples()


// only include the libraries relevante to this file
#include <iostream>
#include <string>
#include <cstring>


using namespace std;

// Welcome Activity: Function Decomposition with Classes
// Given drawTopCard and drawRandomCard function implementations
// within our Deck class implementations we have some similar and
// repeated code. Discuss and identify repeated code with your group.
// After identifying repeated code, develop helper functions to 
// offload the drawTopCard and drawRandomCard repeated functionality
// into the helper functions. Determine whether the function should
// be public or private and whether it should be a const member function.
//
// Activity Described In:
// https://drive.google.com/file/d/16o7B1bvAbrWpt8fu-obTgcF2noIJazYA/view?usp=drive_link
//
// Here are some of the functions mentioned by name in
// iClicker and collectively developed with class.
//
// We will migrate them into deck.cpp & deck.h and update drawTopCard
// and drawRandom to fully integrat the helpers into our Deck class.
//
// Deck class additional helper functions.
// public:
// bool Deck::empty() const
// {
//     return dk.size() == 0;
// }
//
// private:
// void Deck::shiftLeft(size_t start) 
// {
//     for (size_t i = start; i+1 < dk.size(); ++i)
//     {
//         dk.at(i) = dk.at(i+1);
//     }
// }
//
// private:
// void Deck::removeCard(size_t index) 
// {
//     if(index+1 != dk.size())
//     {
//        shiftLeft(index);
//     }
//
//     dk.pop_back();
// }


// Lecture Parts Prototypes
void Examples();

// Prototypes for functions implemented during lecture
size_t countCString(const char c[]);
size_t countbyPtr(const char *cPtr);
size_t countbyPtrOnly(const char *cPtr);
void replaceCString(char *f, char *s);


/// @brief main function for running our examples
/// @param argc the number of command line arguments
/// @param argv the array containing c-strings of command line args
int main(int argc, char *argv[])
{
    if (argc > 1 && isdigit(argv[1][0]))
    {
        // 0 on command line argument means run Examples      
        switch(atoi(argv[1]))
        {
            case 0:
                Examples();   
                break;
            
            default:
                break;
        }
    }
    else
    {
        // could not parse or did not find extra command line argument
        // therefore just run everything
        Examples();    
    }

    return 0;
}



/// @brief live code developed for objects and classes portion 
///     of the live lecture
void Examples()
{
    char a[6] = "hello";
    char b[81] = "hello world";
    char c[81] = "hello my name is";
    char d[81] = "hello\nworld";

    // Note the counts are the quantity of characters NOT the array sizes
    cout << "Counting using our array based function" << endl;
    cout << "=======================================" << endl << endl;
    cout << "C-string a is:" << endl << a << endl << "and it contains "
        << countCString(a) << " characters." << endl << endl;
    cout << "C-string b is:" << endl << b << endl << "and it contains " 
        << countCString(b) << " characters." << endl << endl;
    cout << "C-string c is:" << endl << c << endl << "and it contains " 
        << countCString(c) << " characters." << endl << endl;
    cout << "C-string d is:" << endl << d << endl << "and it contains " 
        << countCString(d) << " characters." << endl << endl;

    // We can use the cstring library functions to acquire the same counts
    // but if we are asking you to implement a function that mimics a library
    // function it is to gain practice with something not for you to invoke
    // library's function.
    cout << "C-string a is:" << endl << a << endl << "and it contains " 
        << strlen(a) << " characters. (used strlen)" << endl << endl;
    
    // The n-bounded C-string functions help prevent going forever or until
    // program crashes when the functions are sent a malformatted C-string that
    // is not properly null character terminated.
    cout << "C-string b is:" << endl << b << endl << "and it contains " 
        << strnlen(b,81) << " characters. (used strnlen)" << endl << endl;
    

    // Let's explore the new variable type, the pointer!
    int x = 5;
    
    // A pointer stores an address in memory
    // One way to acquire a memory address is to use the 
    // the address of operator (&)
    int *xPtr = &x;

    // Array names are references to the first memory address
    // for the array so we do not need to use the address of
    // operator and can assign an array directly into a pointer!
    char *pArr = c;

    // Three forms of * use
    // 1) multiplication
    // 2) declaring a pointer
    // 3) dereferncing a pointer

    cout << endl << endl;
    cout << "Exploring pointer variables" << endl;
    cout << "===========================" << endl << endl;
    cout << "Defeference the pArr (address " << (void *)pArr << ")" << endl;
    cout << "*pArr is " << *pArr << endl << endl;

    cout << "Same as indexing array c's first address of: " << (void *)&c[0] << endl;
    cout << "c[0] is " << c[0] << endl << endl;

    cout << "TWe can also use square brackets and index 0 on our pointer" << endl;
    cout << "Index 0 of pArr: " << pArr[0] << endl;
    cout << "Index 0 of c: " << c[0] << endl;


    cout << endl << endl;
    cout << "Exploring pointer math" << endl;
    cout << "======================" << endl << endl;
    cout << "Recall pArr is \"" << pArr << "\" and *pArr is " << *pArr << endl;
    cout << "When we add 1 after dereferencing (*pArr + 1) we get:  ";
    cout << static_cast<char>(*pArr + 1) << endl;
    cout << "When we add 1 before dereferencing *(pArr + 1) we get: ";
    cout << *(pArr + 1) << endl;



    // Let's see what happens when we remove the null character
    // For quick reference, remember we defined: char a[6] = "hello";
    cout << endl;
    cout << "Before removing null character termination, C-string a is:"
        << endl << a << endl;
    cout << "and C-string a contains " << countCString(a) << " characters."
        << endl << endl;
    cout << endl;
    // overwrite '\0' with a 'b'
    a[5] = 'b';

    cout << "After removing null character termination, C-string a is:"
        << endl << a << endl; 
    cout << "and it contains " << countCString(a) << " characters." 
        << endl << endl;
    
    cout << endl << endl;
    cout << "Counting by pointer & pointer math results" << endl;
    cout << "==========================================" << endl << endl;
    cout << "C-string c is:" << endl << c << endl << "and it contains " 
        << countCString(c) << " characters. (countString)" << endl << endl;
    cout << "C-string c is:" << endl << c << endl << "and it contains " 
        << countbyPtr(c) << " characters. (countbyPtr)" << endl << endl;
    cout << "C-string c is:" << endl << c << endl << "and it contains " 
        << countbyPtrOnly(c) << " characters. (countbyPtrOnly)" 
        << endl << endl;


    cout << endl << endl;
    cout << "Exploring using the heap instead of the stack." << endl;
    cout << "==============================================" << endl << endl;
    char *heapPtr1 = new char[20];
    char *heapPtr2 = new char[15];

    // Copy over into dynamically allocated memory
    // strcpy will add the null character termination
    strcpy(heapPtr1, "hi y'all how");
    strcpy(heapPtr2, "hello");

    // Let's replace the first C-string with the second
    cout << "Before heapPtr1 C-string is: " << heapPtr1 << endl;
    cout << "Before heapPtr2 C-string is: " << heapPtr2 << endl;
    replaceCString(heapPtr1, heapPtr2);
    cout << "Called replaceCString(heapPtr1, heapPtr2)" << endl;
    cout << "After heapPtr1 C-string is:  " << heapPtr1 << endl;
    cout << "After heapPtr2 C-string is:  " << heapPtr2 << endl;
}


/// @brief Count the quantity of characters that exist in provided C-string
///     Use array accessing and parameter for this version.
/// @param c the C-string to count characters for
/// @return the quantity of characters counted
size_t countCString(const char c[])
{
    // initialize counter, we use size_t type as that will resolve
    // to unsigned integer or the an unsigned data type designated
    // by the system call that replaces the size_t typename.
    // This mimics the variable type provided by the size() member
    // function for the string datatype.
    size_t counter = 0;

    // iterate over the c-string
    size_t index = 0;
    while(c[index] != '\0')
    {
        counter++;
        index++;

        // As noted in class, we could use index as our counter
        // as the values mirror each other. However, this introduces
        // additional code readability complexity without much efficiency
        // gain in this scenario. In another scenario where you wish to 
        // maximize efficiency (reducing time and mimizing memory footprint)
        // you could optimize away the counter variable and just use index.
    }

    return counter;
}


// Similar to when we pass by reference we have to decide const or not
// A pointer contains a memory address, so when we do not specificy const
// then we may modify the contents at the memory address the pointer points to
// size_t countbyPtr(const char *cPtr)


/// @brief Count the quantity of characters that exist in provided C-string
///     Use pointer dereferencing and pointer parameter for this version
/// @param cPtr pointer to address in a C-string to start counting from
/// @return the quantity of characters counted
size_t countbyPtr(const char *cPtr)
{
    // initialize counter
    size_t counter = 0;

    // iterate over the c-string
    // dereference the pointer to get a character, check for null character
    while(*cPtr != '\0')
    {
        // count when not the null character
        counter++;

        // move the pointer, this moves 1 character's worth of memory,
        // which moves us to the next spot in the C-string
        cPtr++; 
    }

    return counter;
}


/// @brief Count the quantity of characters that exist in provided C-string
///     Use pointer dereferencing and pointer parameter for this version
///     Also use pointer math, not a counter, to calculate the difference
///     in memory addresses to calculate the quantity of characters.
/// @param cPtr pointer to address in a C-string to start counting from
/// @return the quantity of characters counted
size_t countbyPtrOnly(const char *cPtr)
{
    const char *start = cPtr;
    // iterate over the c-string
    while(*cPtr != '\0')
    {
        // move the pointer, this moves 1 character's worth of memory,
        // which moves us to the next spot in the C-string
        cPtr++; 
    }

    // We could condense but this decreases our code readability
    // by increasing our complexity, and also over counts by one
    // as the post increment operator always executes.
    // while(*cPtr++ != '\0');
    // cPtr--;

    // Calculate the difference in memory addresses to 
    // determine how many characters exist in the C-string
    return cPtr - start;
}

/// @brief replace the first C-string with the second C-string
/// @param f the c-string to overwrite with the second paraamter
/// @param s the c-string to copy into the first parameter
void replaceCString(char *f, char *s)
{
    // We can use our function to determine how long the C-string is
    int fsize = countbyPtr(f);

    // We can also use strlen() to calculate the length
    int ssize = strlen(s);

    // When the second one doesn't fit, do nothing.
    if (ssize > fsize)
    {
        return;
    }

    // Assign each character from the second to the first C-string
    for(size_t i = 0; i < ssize; ++i)
    {        
        f[i] = s[i];

        // We encountered this bug during live coding.
        // Flip flopping which C-string we were assigning into.
        // Professor Hodges helped identify the error so we could
        // correct our implementation.
        // s[i] = f[i];
    }

    // All C-strings must be properly terminated with a null character
    f[ssize] = '\0';
}