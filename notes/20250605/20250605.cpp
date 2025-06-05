/// @file 20250605.cpp
/// @author Adam T Koehler, PhD
/// @date June 5, 2025
/// @brief Code and lecture notes from the live session. 

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "card.h"

using namespace std;

void RandomnessExamples();
void ClassesObjectsExamples();
void Examples3(){}

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
                RandomnessExamples();
                break;

            case 2:
                ClassesObjectsExamples();
                break;

            case 3:
                Examples3();
                break;
            
            default:
                break;
        }
    }
    else
    {
        // could not parse or did not find extra command line argument
        // therefore just run everything
        RandomnessExamples();

        cout << endl << endl;
        ClassesObjectsExamples();
        
        cout << endl << endl;  
        Examples3();  
        
    }    
    return 0;
}




/// @brief live code developed for the Classes & Objects portion 
///     of the live lecture
void ClassesObjectsExamples()
{
    cout << "Classes & Objects Examples" << endl;
    cout << "==========================" << endl << endl;

    Card a("7", "Clubs", false);
    Card b("2", "Clubs", false);
    Card c("9", "Clubs", false);
    Card d("Ace", "Clubs", false);
    Card *e = new Card("7", "Clubs", false);

    cout << "operator!=" << endl;
    cout << "==========" << endl;

    // Testing with non matching cards
    if (a != b)
    {
        cout << "The cards a and b don't match." << endl;
        cout << "a: " << a.to_string() << endl;
        cout << "b: " << b.to_string() << endl;
    }
    else
    {
        cout << "The cards a and b match!" << endl;
        cout << "a: " << a.to_string() << endl;
        cout << "b: " << b.to_string() << endl;
    }
    cout << endl;


    // Testing with matching cards
    if (a != *e)
    {
        cout << "The cards a and e don't match." << endl;
        cout << "a: " << a.to_string() << endl;
        cout << "e: " << e->to_string() << endl;
        // -> is (*e).to_string
    }
    else
    {
        cout << "The cards a and e match!" << endl;
        cout << "a: " << a.to_string() << endl;
        cout << "e: " << e->to_string() << endl;
    }
    cout << endl;

    // Testing with same card
    if (a != a)
    {
        cout << "The cards a and a don't match." << endl;
        cout << "a: " << a.to_string() << endl;
        cout << "a: " << a.to_string() << endl;
    }
    else
    {
        cout << "The cards a and a match!" << endl;
        cout << "a: " << a.to_string() << endl;
        cout << "a: " << a.to_string() << endl;
    }  
    cout << endl;
    cout << endl;


    cout << "operator<" << endl;
    cout << "==========" << endl;
    
    // Testing with non matching cards where b is less than c
    if (b < c)
    {
        cout << "The card b is less than c." << endl;
        cout << "b: " << b.to_string() << endl;
        cout << "c: " << c.to_string() << endl;
    }
    else
    {
        cout << "The card b is not less than c." << endl;
        cout << "b: " << b.to_string() << endl;
        cout << "c: " << c.to_string() << endl;
    }
    cout << endl;

    // Testing with non matching cards where c is not less than d
    if (c < d)
    {
        cout << "The card c is less than d." << endl;
        cout << "c: " << c.to_string() << endl;
        cout << "d: " << d.to_string() << endl;
    }
    else
    {
        cout << "The card c is not less than d." << endl;
        cout << "c: " << c.to_string() << endl;
        cout << "d: " << d.to_string() << endl;
    }
    cout << endl;

    // Testing with matching but different cards
    if (a < *e)
    {
        cout << "The card a is less than e." << endl;
        cout << "a: " << a.to_string() << endl;
        cout << "e: " << e->to_string() << endl;
    }
    else
    {
        cout << "The card a is not less than e." << endl;
        cout << "a: " << a.to_string() << endl;
        cout << "e: " << e->to_string() << endl;
    }
    cout << endl;

    // Testing with matching and same card
    if (a < a)
    {
        cout << "The card a is less than a." << endl;
        cout << "a: " << a.to_string() << endl;
        cout << "a: " << a.to_string() << endl;
    }
    else
    {
        cout << "The card a is not less than a." << endl;
        cout << "a: " << a.to_string() << endl;
        cout << "a: " << a.to_string() << endl;
    }
}



/// @brief live code developed for the true randomness portion
///     of the live lecture
void RandomnessExamples()
{
    int x;

    cout << "True Randomness Examples" << endl;
    cout << "========================" << endl << endl;

    // Before using rand() we always used the pseudo random number
    // generator (PNRG) and specified a dedidcated seed with srand().
    // If we did not invoke srand() it was seeded silently as srand(0)
    cout << "Let's grab a random number between two numbers." << endl;
    cout << "From 3 to 8, inclusive (3 + rand() % (8-3+1)): ";
    cout << 3 + rand() % (8 - 3 + 1) << endl;
    cout << endl;

    // When we call srand() it restarts the pseudo random sequence
    cout << "Calling srand(0)" << endl;
    srand(0);
    cout << "Let's grab a random number between two numbers." << endl;
    cout << "From 3 to 8, inclusive (3 + rand() % (8-3+1)): ";
    cout << 3 + rand() % (8 - 3 + 1) << endl;
    cout << endl;

    // Knowing the seed for srand creates predictability and potential
    // security vulnerabilities in our programs. Many older methodologies
    // teach srand(time(0)) to increase unpredictablility. This would use
    // the time in seconds since Jan 1 1970 at the invocation of srand()
    // to seed the pseduo random number generator. However, if someone knows
    // this time they can predict your randomness and we fall back towards
    // the issues such as security vulnerabilities. 

    // Modern systems have built in devices to introduce entropy and 
    // unpredictability in random number creation. This makes the items
    // more truly random than the pseudo random number generator.
    cout << "Creating a random_device rd" << endl;
    random_device rd;

    // Additionally we can create an engine to generate random numbers
    // in a uniform distribution. 
    // Here we designate a uniform distribution between 3 and 8, inclusive.
    static uniform_int_distribution<int> eng(3, 8);
    cout << "Creating uniform distribution engine from 3 to 8." 
        << endl;

    cout << "Generating a random number with our random device." << endl;
    cout << "Random number from eng(rd) is " << eng(rd) << endl;
    cout << "Random number from eng(rd) is " << eng(rd) << endl;
    cout << "Random number from eng(rd) is " << eng(rd) << endl;
    cout << "Random number from eng(rd) is " << eng(rd) << endl;
    cout << "Random number from eng(rd) is " << eng(rd) << endl;
    cout << "Random number from eng(rd) is " << eng(rd) << endl;
    cout << "Random number from eng(rd) is " << eng(rd) << endl;
    cout << "Random number from eng(rd) is " << eng(rd) << endl;
    cout << "Random number from eng(rd) is " << eng(rd) << endl;
    cout << endl;


    // When generating a lot of random numbers quickly, where quickness
    // is relative to the systems ability to create them from its design
    // for entropy, can actually block and wait for a random number
    // on many systems.
    cout << "Generating a million random numbers with eng(rd)" << endl;
    for (uint i=0; i < 10000000000000; ++i)
    {
        x = eng(rd);
    }
    cout << "Finished generating, the last number was: " << x << endl;
    cout << endl;

cout << "Finished generating, the last number was: " << x << endl;
    cout << endl;

    cout << "Notice the slowdown?" << endl;
    cout << endl;

    vector<int> nums_rd(6);
    cout << "Generating & counting a million numbers with eng(rd)" << endl;
    for (int i=0; i < 1000000; ++i)
    {
        nums_rd.at(eng(rd)-3)++;
    }
    cout << "Finished generating. Here are the counts:" << endl;
    for (int i=0; i < 6; ++i)
    {
        cout << "Number " << i+3 << ": " << nums_rd.at(i) << endl;
    }
    cout << endl;
    
    cout << "Notice the slowdown?" << endl;
    cout << endl;


    // A rudimentary fix is to use the random_device to generate the
    // seed for srand and then use the pseudo random number generator
    // to try to get the "best of both worlds" as rand() will not 
    // will not have to wait for the random_device to generate it.
    cout << "Seeding srand(rd()) using random_device number." << endl;
    srand(rd());
    cout << "Generating a million random numbers with rand()" << endl;
    for (int i=0; i < 1000000; ++i)
    {
        x = 3 + rand()%(8-3+1);
    }
    cout << "Finished generating, the last number was: " << x << endl;
    cout << endl;

}

