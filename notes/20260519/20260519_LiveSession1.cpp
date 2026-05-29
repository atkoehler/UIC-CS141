/// @file 20260519_LiveSession1.cpp
/// @author Adam T Koehler, PhD
/// @date May 19, 2026
/// @brief Code and lecture notes from the live session. Requires -std=c++20

// Whiteboard Activity 1
// Goal: acquire postive numbers and store them

// Whiteboard Activity 2
// Goal: Create a Monte Carlo simulation of dice rolls for three dice.



// Design Decision: what is positive?
// Strictly above 0? Include zero?


// Libraries are used to include code and features developed by others
// #include <iostream>
// #include <vector>

// Specifying a namespace allows us to presume we are working in a 
// specific namespace and not have to use the scope resolution operator
// and namespace name (e.g. std::) with everything we need from that 
// namespace. However, it does make the code development less 
// "portable" as we are restricting the namespace.

// using namespace std;


// A C++ program will always have a main function that is layed out below.
// It also represents the core pieces of a C++ function and function stub:
// return type (int)
// function name (main)
// parameters (none)
// function body: return 0 (basic compliance with return type)
// int main()
// {
//     return 0;
// }




// Libraries to accomplish various tasks
#include <iostream> // Input-Output Steams
#include <string>   // For the string datatype/containers
#include <vector>   // For the vector datatype/containers
#include <random>   // For prodcing random numbers

// Making our basic CS 141 code easier to read and parse
// by just using the std namespace and avoiding having
// std:: before many things such as std::string or std::cout
using namespace std;


//////////////////////////////////////////////////////////////////////////////
//
// An exploration of variables using built-in and not built-in datatypes in
// C++ to discuss C++ variables and some differences between C++ and  
// programming languages that student may have started with.
//
// Pairs with Whiteboard Activity 1
//
//////////////////////////////////////////////////////////////////////////////

void variablesAndVectors()
{
    // python: list and "untyped" variable declarations

    // C++ has several built in (native) types, similar to other language
    // but unlike languages similar to Python we must specify the type
    // at the time of declaration.

    // This variable is an integer and demonstrates camelCase variable naming.
    int varName;

    // Until we assign a value to a variable, the value stored in that memory
    // location is unpredictable and is often considered "garbage." This means
    // we will often assign a useful default value at the time of declaration
    // to initialize the memory space for that variable to a known value. The
    // determination of what is a "good" value to initialize to is a program
    // design choice, but in most cases it is safe to use 0.

    // Here is a demonstration of variable declaration and initialization for
    // several built-in (native) C++ types. This is not an all-inclusive list,
    // so you may discover or encounter more.
    
    // signed numerical types
    short x = 0;        // 16 bits or 2 bytes for our system
    int y = 0;          // 32 bits or 4 bytes for our system
    long z = 0;         // 64 bits or 8 bytes for our system
    float a = 0.0;      // 32 bits or 4 bytes for our system
    double b = 0.0;     // 64 bits or 8 bytes for our system

    // unsigned numerical types
    unsigned short ux = 0;        // 16 bits or 2 bytes for our system
    unsigned int uy = 0;          // 32 bits or 4 bytes for our system
    unsigned long uz = 0;         // 64 bits or 8 bytes for our system
   
    // logical type (contains true / false)
    // note that true and false can be represented in 1 bit but the built-in
    // datatype bool consumes 8 bits or 1 byte for our system
    bool flipped = false;  


    // characters
    // '' (single quotes with nothign in them, is not a valid character and 
    // therefore cannot be utilized to initialize the char datatype. 
    char c = 'A';

    // The character data type is numbers behind the scenes, and this allows 
    // us to perform character mathematics to manipulate from character to
    // another character. Here we take 'A' and add 1 so the result is 'B' 
    char d = 'A' + 1;



    // In C++ we have decrement and increment operators that come in both
    // pre and post form. Here is an example of the increment operator and
    // how it changes for a simple expression using pre-increment and 
    // post-increment within the expression.
    // Post means do the expression and then incremenent, pre means increment
    // and then complete the expression.

    int val1 = 5;
    int val2 = 7;
    int val3 = 2;
    int val4 = 0;
    cout << "Post-Increment Expression: val4 = val1++ + val2 + val3" << endl;
    cout << "Before: " << "val1: " << val1 << ", val2: " << val2 
        << ", val3: " << val3 << ", val4: " << val4 << endl;
    val4 = val1++ + val2 + val3;
    cout << "After:  " << "val1: " << val1 << ", val2: " << val2 
        << ", val3: " << val3 << ", val4: " << val4 << endl;

    cout << endl << endl;

    val1 = 5;
    val2 = 7;
    val3 = 2;
    val4 = 0;
    cout << "Pre-Increment Expression:  val4 = ++val1 + val2 + val3" << endl;
    cout << "Before: " << "val1: " << val1 << ", val2: " << val2 
        << ", val3: " << val3 << ", val4: " << val4 << endl;
    val4 = ++val1 + val2 + val3;
    cout << "After:  " << "val1: " << val1 << ", val2: " << val2 
        << ", val3: " << val3 << ", val4: " << val4 << endl;
    cout << endl << endl << endl;


    // The first non-native data type we will explore is strings. These exist
    // in other langauages but C++ strings are mutable and therefore can be
    // modified without creating a new string. This may be different from your
    // prior programming experience.
    cout << "Moving on to strings..." << endl;
    cout << "A commonly used but non-native datatype is string." << endl;
    string myString1;
    string myString2 = "Hello World!";
    string myString3 = "CS 141 is Awesome!";
    cout << "myString1: " << myString1 << endl;
    cout << "myString2: " << myString2 << endl;
    cout << "myString3: " << myString3 << endl;
    cout << endl << endl;

    // The at() string member function allows us to get a specific element 
    // of the string container. Here we use at(0) to aquire and set the first
    // element. We can also use the first() member function to perform the 
    // same tasks.
    cout << "First character of " << myString2 << " is a " 
        << myString2.at(0) << endl;
    cout << "First character of " << myString2 << " is a " 
        << myString2.at(0) << endl;
    cout << "First character of " << myString3 << " is a " 
        << myString3.front() << endl;
    cout << "First character of " << myString3 << " is a " 
        << myString3.front() << endl;
   
    cout << endl << endl;

    // We can also use the back() member function to perform a similar 
    // task and acquire or set the last character of a string.
    cout << "We can also get the last character in two ways:" << endl;
    cout << "Last character of  " << myString3 << " is a " 
        << myString3.at(myString3.size() - 1) << endl;
    cout << "Last character of  " << myString3 << " is a " 
        << myString3.back() << endl;
    cout << "However the second way using back() is preferred." << endl;

    cout << endl << endl;

    // Exploring first and last character modifications...
    cout << "Turn the first character into a J" << endl;
    cout << "Before: " << myString2 << endl;
    myString2.at(0) = 'J';
    cout << "After:  " << myString2 << endl;

    cout << "Turn the first character back into an H" << endl;
    cout << "Before: " << myString2 << endl;
    myString2.front() = 'H';
    cout << "After:  " << myString2 << endl;

    cout << "Turn the last character into a ?" << endl;
    cout << "Before: " << myString2 << endl;
    myString2.back() = '?';
    cout << "After:  " << myString2 << endl;

    cout << "Turn the last character back into an !" << endl;
    cout << "Before: " << myString2 << endl;
    myString2.at(myString2.size() - 1) = '!';
    cout << "After:  " << myString2 << endl;

    cout << endl << endl << endl;

    cout << "Moving on to vectors..." << endl;
    // A vector is a collection of one type of variables. It can be 
    // dynamically grown and shrunk unlike a C-style array.
    vector<int> v;

    // A C-style array creates space at compile-time and cannot be grown
    // or shrunk without creating a new array. This array has 5 integers 
    // spaces allocated to it, but as with the built-in variable declarations
    // it will have unknown or garbage values in each of the spots.
    int arr[5];


    // Vectors and other objects have member functions. Those are invoked 
    // using the dot operator. Here we output the size of the vector by 
    // invoking the size function. Since we just declared the vector we 
    // expect the output to be 0.
    cout << "The size of vector v is: " << v.size() << endl << endl;


    // Let's grow our vector based on the quantity entered by the user
    int quantity = 0;
    cout << "Enter a number that is greater than 0: ";
    cin >> quantity;
    cout << endl;

    // C++ Syntax for an if-else if-else statement is as follows
    // We could have only an if statement
    // We cannot have an else if or else without an if
    // We may not have else-if at all or else at all
    // if (conditional expression)
    // {
    //     ...
    // }
    // else if (conditional expression)
    // {
    //     ...
    // }
    // else
    // {
    //     ...
    // }


    // If the user enters a negative number we can't do anything so lets ask
    // again for another number.
    if (quantity <= 0)
    {
        cout << "Enter a number that is greater than 0: ";
        cin >> quantity;
        cout << endl;        
    }

    // How could we turn the above into a repeated question such that we keep
    // asking the user until the entered value is a valid value?
    // Answer: A loop
    // For now we will continue with our one-off attempt to fix the issue.


    // If the quantity is 0 or less, there isn't any data to acquire.
    while (quantity > 0)
    {
        // Acquire data from the user
        int val;
        cout << "Enter a integer data value: ";
        cin >> val;
        cout << endl;
        
        // We can grow the size of our vector by 1 and insert the acquired
        // value with the push_back member function.
        v.push_back(val);
        
        // Demonstrate that the vector is growing and that the last item
        // has changed to the new value.
        cout << "Vector Size:  " << v.size() << endl;
        cout << "Last Element: " << v.back() << endl << endl;

        // update quantity to one less as we acquired one value
        quantity--;
    }

   
    // Vectors and other objects have member functions. Those are invoked 
    // using the dot operator. Here we output the size of the vector by 
    // invoking the size function.
    cout << "Vector Size: " << v.size() << endl;

    // how to access an element of the vector?
    // we can use v.at(___) with the blank filled in with the index value


    // Output all the elements of our vector with an index based for-loop
    // We use size_t as it resolves to the same datatype as the result of 
    // our size() function call. This makes sure we are comparing the same
    // datatype and avoid any hidden issues of comparing across datatypes.
    
    // Outputing the vector in various ways
    cout << "Index based loop to output vector: " << endl;
    for(size_t i = 0; i < v.size(); ++i)
    {
        cout << "Outputting element " << i << endl;
        cout << v.at(i) << endl;
    }
    cout << endl;

    cout << "For-each loop to output vector: " << endl;
    for(int element : v)
    {
        cout << element << endl;
    }
    cout << endl;

    // What happens when we output beyond our vector size?
    // Answer: It depends on the access style.

    // With .at() a bounds check is completed to make sure that 
    // the index is a valid index for the current size of the vector

    // for (int i = 0; i < 100000; ++i)
    // {
    //     cout << "Outputting element " << i << endl;
    //     cout << v.at(i) << endl;
    // }

    // With [] array access syntax there isn't a bounds check, and the code 
    // will perform the offset math and just access the calculated memory 
    // address no matter whether it is in bounds or out of bounds. This leads
    // to two possible outcomes. First, the memory access is okay but gives 
    // back a "garbage" value. Second, the memory access is not allowed and
    // a runtime error occurs (segmentation fault) and our program crashes.

    // for (int i = 0; i < 100000; ++i)
    // {
    //     cout << "Outputting element " << i << endl;
    //     cout << v[i] << endl;
    // }

    // Note that we didn't go out of range immediately.
    // We received a "Segmentation fault (core dumped)" error when trying to 
    // output element at index value of 14924.


    // What we covered so far...
    // for (indexed)
    // for-each
    // while

    // One more loop type
    // do-while loops execute the body of the loop and then ask whether to 
    // continue with another execution. This makes them different than other
    // types of loops that ask the condition first before the first iteration.

    string str;
    do
    {
        cout << "Do you want to be done? Type exit to finish: ";
        cin >> str;
        cout << endl;
    } while (str != "exit");
}




//////////////////////////////////////////////////////////////////////////////
//
// Development of a Monte Carlo simulation as a pratical exploration of 
// vectors, counting, accumulating, randomness, and loops within C++.
//
// Pairs with Whiteboard Activity 2
//
//////////////////////////////////////////////////////////////////////////////


/// @brief Produce random values for 3 6-sided dice and return sum.
/// @return The sum that is a acuumulated total from rolling the dice.
int getRollPseduoRandom()
{
    return (1 + rand() % 6) + (1 + rand() % 6) + (1 + rand() % 6);
}

/// @brief Simulate rolling 3 6-sided dice.
/// @param mt19937 pass the random generator engine by
///                reference (&) to allow internal state to be updated.
/// @param dist the distribution of the individual die rolls
int getRollRandom(mt19937& rng, uniform_int_distribution<int>& dist) 
{
    return dist(rng) + dist(rng) + dist(rng);
}

/// @brief Execute a Monte Carlo simulation of 3 6-sided dice rolls
/// @param pseudoRandom true means use pseudorandom number generator rand()
///         otherwise use the random_device for true randomness.
void monteCarloSimulation(bool pseudoRandom=true)
{
    int roll;
    int simCount = 0;
    cout << "How many simulations? ";
    cin >> simCount;
    cout << endl;

    // srand allows us to seed the pseudorandom number generator
    // Using the same seed across different program runs will produce
    // the same random value sequence. This predictably is good for
    // testing but bad if randomness is being used to secure information
    // such as during encryption.
    srand(2026);

    // Modern, high-quality random number generator
    // rand() is a pseudorandom number generator
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> dist(1, 6);

    
    vector<int> data;

    // Execute the expected number of simulations and record rolls.
    for(int i=0; i < simCount; ++i)
    {
        if (pseudoRandom)
        {
            roll = getRollPseduoRandom();
        }
        else
        {
            roll = getRollRandom(rng, dist);
        }

        // Place the roll value into the vector at the end.
        data.push_back(roll);

        // We can combine the above to lines into a single line
        // and eliminate the creation of a variable.
        // data.push_back(getRoll());
    }

    // We hard code 19 here, but it is a "magic" number that relies
    // on understanding that the maximum dice roll is 18. It would
    // be better to use variables to encode the dice roll values or
    // to some how store that information to avoid hardcoding 19.

    // Create a series of counters, one for each potential roll value.
    // Then we can use the roll value to determine which counter to increase.
    vector<int> count(19);
    for (auto &e : data)
    {
        count.at(e) += 1;
    }


    cout << "Roll: Probability" << endl;
    for(int i=0; i <= 18; ++i)
    {
        cout << i << ": " << static_cast<double>(count.at(i)) / simCount 
            << endl;
    }

    // An efficient optimization would be to update our counts when getting
    // the roll data, and in various programs that is the proper way to count.
    // However, here we are trying to mimic the common split of data 
    // acquisition and data analysis as these are often two distinct steps.
    // Meaning the data you are analyzing may be gathered or generated well
    // before or outside the context of your analysis program.
}


/// @brief main function for running our examples
/// @param argc the number of command line arguments
/// @param argv the array containing c-strings of command line args
int main(int argc, char *argv[])
{
    // no second command line argument, run all examples
    if (argc > 1 && isdigit(argv[1][0]))
    {       
        switch(atoi(argv[1]))
        {
            case 1:
                variablesAndVectors();
                break;

            case 2:
                if (argc > 1 && isdigit(argv[2][0]))
                {
                    // Determine whether pseduorandom number generator 
                    // should be used based on the second command line
                    // argument. 0 means truly random, and all other digits
                    // will use the pseudorandom number generator.
                    monteCarloSimulation(argv[2][0] != '0');
                }
                else
                {
                    monteCarloSimulation();    
                }
                break;
            
            default:
                break;
        }
    }
    else
    {
        // could not parse or did not find extra command line argument
        // therefore just run everything
        variablesAndVectors();

        cout << endl << endl;
        monteCarloSimulation();        
    }    

    return 0;
}





//////////////////////////////////////////////////////////////////////////////
//
// An alternative C++23 implementation that requires the full C++23 feature 
// set to have access to print and println.
//
// Key Differences:
//      Take advantage of a broken cin resulting in "false" to check for 
//          a successful input acquisition.
//
//      Use print and println along with format strings for all output.
//
//      Print to standard error (stderr) and stop the program when the user 
//          inputs an invalid simulation count.
//
//      Use the C++ standard library array instead of the vector because
//          counters are a static number of things and therefore the dynamic
//          growing or shrinking aspect of a vector is unwarranted.
//              array<int, 19> count{};  versus     vector<int> count(19);
//          We demonstrated C-style legacy arrays versus modern C++ arrays.
//          C-style arrays are pre for understand or writing C++11 code.
//////////////////////////////////////////////////////////////////////////////


// #include <iostream>  // for input and output streams
// #include <random>    // for random number generation
// #include <array>     // for the array container/datatype
// #include <vector>    // for the vector container/datatype
// #include <cstdio>    // for fflush and stdout
// #include <print>     // for print and println (C++23)
//
// using namespace std;
//
//
// /// @brief Simulate rolling 3 6-sided dice.
// /// @param mt19937 pass the random generator engine by
// ///                reference (&) to allow internal state to be updated.
// /// @param dist the distribution of the individual die rolls
// int getRollRandom(mt19937& rng, uniform_int_distribution<int>& dist) 
// {
//     return dist(rng) + dist(rng) + dist(rng);
// }
//
//
// int main() 
// {
//     int simCount = 0;
//
//     print("Enter simulation count: ");
//     if (!(cin >> simCount) || simCount <= 0) 
//     {
//         // The first argument says to send the output to standard error
//         // instead of standard out. This is a dedicated place for errors
//         // to be output in case a user of the program wishes to separate
//         // the different program outputs.
//         println(stderr, "Invalid input.");
//
//         // Returning 1 indicates to the caller, here the operating system,
//         // that things did not exit with proper completion.
//         return 1;
//     }
//
//
//     // Modern, high-quality random number generator
//     // rand() is a pseudorandom number generator
//     random_device rd;
//     mt19937 rng(rd());
//     uniform_int_distribution<int> dist(1, 6);
//
//     // vector to hold our data
//     vector<int> data;
//   
//     // Populate the vector with random roll data.
//     for (int i = 0; i < simCount; ++i) 
//     {
//         int roll = getRollRandom(rng, dist);
//         data.push_back(roll);
//     }
//
//     // Fixed-size array to count frequencies, initialized to all zeros.
//     array<int, 19> count{};
//     for (const auto &roll : data) 
//     {
//         count[roll]++;
//     }
//
//     // the {} is where the variable goes
//     // println always ends with a newline, print does not.
//     println("\nResults for {} rolls:", simCount);
//
//     // Force the OS to push out the printed text. 
//     //   print and println do not automatically flush and do not have an
//     //   optional flag to send to force a flush
//     fflush(stdout);
//
//     // Formatted Printing of Probabilities
//     for (int i = 0; i <= 18; ++i) 
//     {
//         // the {} is where the variable goes
//         // the : is a separater for formatting rules
//         // the 2 provides a minimum output width of 2 characters
//         // the .5f tells the formatter to always display 5 digits after the decimal
//         println("{:2}: {:.5f}", i, 
//                 static_cast<double>(count[i]) / simCount);
//     }
// 
//     return 0;
// }
