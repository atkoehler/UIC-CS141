/// @file 20260603_LiveSession8.cpp
/// @author Adam T Koehler, PhD
/// @date June 3, 2026
/// @brief Code and lecture notes from the live session. Requires -std=c++20
///         Example compilation command: 
///             g++ -std=c++20 20260603_LiveSession8.cpp 

#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>
#include "card.h"
#include "deck.h"

using namespace std;

void MoreCStringExamples();
void ClassesObjectsExamples();
void DeckExamples();
void RandomnessExamples();
int countC(const char []);
int countC_PtrParam(const char *);
int countC_PtrParam(char *);

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
                MoreCStringExamples();   
                break;

            case 2:
                ClassesObjectsExamples();
                break;

            case 3:
                DeckExamples();
                break;

            case 4:
                RandomnessExamples();
                break;
            
            default:
                break;
        }
    }
    else
    {
        // could not parse or did not find extra command line argument
        // therefore just run everything
        MoreCStringExamples();

        cout << endl << endl;
        ClassesObjectsExamples();

        cout << endl << endl;
        DeckExamples();
        
        cout << endl << endl;  
        RandomnessExamples();  
        
    }    
    return 0;
}

/// @brief Example uses of the C-string character counting functions
void MoreCStringExamples()
{
    char a[6] = "hello";
    char b[81] = "hello world";
    char c[81] = "hello my name is";
    char d[81] = "hello\nworld";

    // Note the counts are the quantity of characters NOT the array sizes
    cout << "Quantity of characters in " << a << " is " << countC(a) << endl;
    cout << "Quantity of characters in " << b << " is " << countC(b) << endl;
    cout << "Quantity of characters in " << c << " is " << countC_PtrParam(c) << endl;
    cout << "Quantity of characters in " << d << " is " << countC_PtrParam(d) << endl;
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
    unique_ptr<Card> eSmartPtr = make_unique<Card>("7", "Clubs", false);
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

    // Testing with matching cards
    if (a != *eSmartPtr)
    {
        cout << "The cards a and e don't match." << endl;
        cout << "a: " << a.to_string() << endl;
        cout << "e: " << eSmartPtr->to_string() << endl;
        // -> is (*eSmartPtr).to_string()
    }
    else
    {
        cout << "The cards a and e match!" << endl;
        cout << "a: " << a.to_string() << endl;
        cout << "e: " << eSmartPtr->to_string() << endl;
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


void DeckExamples()
{
    array<string, 4> suits = {"Clubs", "Diamonds", "Hearts", "Spades"};
    array<string, 14> faces = 
        {"Ace", "Two", "Three", "Four", 
         "Five", "Six", "Seven", "Eight", "Nine", 
         "Ten", "Jack", "Queen", "King"};

    Deck playingCards;
    Deck original;

    // Initialize Deck in sorted order
    for(const auto &e : suits)
    {
        for(const auto& f : faces)
        {
            if("Clubs" == e || "Spades" == e)
            {
                original.addCard(Card(f,e,false));
                playingCards.addCard(Card(f,e,false));
            }
            else
            {
                original.addCard(Card(f,e,true));
                playingCards.addCard(Card(f,e,true));
            }
        }
    }

    // Print the Deck object
    cout << "Original Deck Order" << endl;
    cout << "===================" << endl;
    playingCards.printDeck();

    cout << endl << endl << endl;

    // Scramble
    playingCards.scramble();

    // Print the Deck object
    cout << "Scrambled Deck Order" << endl;
    cout << "====================" << endl;
    playingCards.printDeck();
}


/// @brief live code developed for the true randomness portion
///     of the live lecture
void RandomnessExamples()
{
    int x;

    cout << "Building Towards True Randomness" << endl;
    cout << "================================" << endl << endl;

    // Before using rand() we always used the pseudo random number
    // generator (PNRG) and specified a dedidcated seed with srand().
    // If we did not invoke srand() it was seeded silently as srand(0)
    srand(0);
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
    // and use a uniform distribution. 
    // Here we designate a uniform distribution between 3 and 8, inclusive.

    // We should bypass mt19937 and pull directly from rd is if its something 
    // that requires strict, cryptographic-level security (like generating a 
    // password, a secure token, or an encryption key) where the 
    // predictability of a pseudo-random algorithm is a security vulnerability.
    // mt19937 is a Pseudo-Random Number Generator based on an algorithm 
    // called the Mersenne Twister (hence the mt)
    // rand() is usually implemented using a very simple algorithm,
    // a Linear Congruential Generator and should be avoided in modern C++
    mt19937 rng(rd());
    
    // We could also hardcode a seed value similar to the rand/srand combo.
    // mt19937 rng(2000);
    
    // Previously using rand() we could invoke the seed function srand with a 
    // literal value to hardcode and produce the same pseudorandom sequence.
    // srand(2000);
    // rand();
    
    static uniform_int_distribution<int> dist(3, 8);
    cout << "Creating uniform distribution engine from 3 to 8." 
        << endl;

    cout << "Generating with our random device." << endl;
    cout << "Random number from dist(rd) is " << dist(rd) << endl;
    cout << "Random number from dist(rd) is " << dist(rd) << endl;
    cout << "Random number from dist(rd) is " << dist(rd) << endl;
    cout << "Random number from dist(rd) is " << dist(rd) << endl;
    cout << "Random number from dist(rd) is " << dist(rd) << endl;
    cout << "Random number from dist(rd) is " << dist(rd) << endl;
    cout << "Random number from dist(rd) is " << dist(rd) << endl;
    cout << "Random number from dist(rd) is " << dist(rd) << endl;
    cout << "Random number from dist(rd) is " << dist(rd) << endl;
    cout << endl;

    cout << "Generating with our pseudorandom generator (mt19937)." << endl;
    cout << "Random number from dist(rng) is " << dist(rng) << endl;
    cout << "Random number from dist(rng) is " << dist(rng) << endl;
    cout << "Random number from dist(rng) is " << dist(rng) << endl;
    cout << "Random number from dist(rng) is " << dist(rng) << endl;
    cout << "Random number from dist(rng) is " << dist(rng) << endl;
    cout << "Random number from dist(rng) is " << dist(rng) << endl;
    cout << "Random number from dist(rng) is " << dist(rng) << endl;
    cout << "Random number from dist(rng) is " << dist(rng) << endl;
    cout << "Random number from dist(rng) is " << dist(rng) << endl;
    cout << endl;

    // Quick forced pause for educational overview
    string dummy;
    cout << "Ready to proceed? ";
    cin >> dummy;
    cout << endl;

    // When generating a lot of random numbers quickly, where quickness
    // is relative to the systems ability to create them from its design
    // for entropy, can actually block and wait for a random number
    // on many systems.
    cout << "Generating ten million random numbers with dist(rd)" << endl;
    cout << "Using the random device directly." << endl;
    for (int i=0; i < 10000000; ++i)
    {
        x = dist(rd);
    }
    cout << "Finished generating, the last number was: " << x << endl;
    cout << endl;

    cout << "Notice the slowdown?" << endl;
    cout << endl;

    vector<int> nums_rd(6);
    cout << "Generating & counting ten million numbers with dist(rd)" << endl;
    for (int i=0; i < 10000000; ++i)
    {
        nums_rd.at(dist(rd)-3)++;
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
    // to try to get the "best of both worlds" as mt19937's generator  
    // will not have to wait for the random_device to generate it.
    cout << "Seeding mt19937 rng(rd()) using random_device number." << endl;
    srand(rd());

    cout << "Generating ten million random numbers with dist(rng)" << endl;
    for (int i=0; i < 10000000; ++i)
    {
        x = dist(rng);
    }
    cout << "Finished generating, the last number was: " << x << endl;
    cout << endl;

    vector<int> nums_rand(6);
    cout << "Generating & counting ten million numbers with dist(rng)" << endl;
    for (int i=0; i < 10000000; ++i)
    {
        nums_rand.at(dist(rng) - 3)++;
    }
    cout << "Finished generating. Here are the counts:" << endl;
    for (int i=0; i < 6; ++i)
    {
        cout << "Number " << i+3 << ": " << nums_rand.at(i) << endl;
    }
}




// Similar to when we pass by reference we have to decide const or not
// A pointer contains a memory address, so when we do not specificy const
// then we may modify the contents at the memory address the pointer points to
// size_t countbyPtr(const char *cPtr)


/// @brief Count the quantity of characters that exist in provided C-string
/// @param cArr C-string to start counting from
/// @return the quantity of characters counted
int countC(const char str[])
{
    int sum = 0;
    int index = 0;

    sum = 0;
    while(str[index] != '\0')
    {
        sum++;
        index++;
    }

    sum = 0;
    for(index=0; str[index] != '\0'; index++)
    { 
        sum++;
    }

    // index = 0;
    // while(str[index] != '\0')
    // {
    //     index++;
    // }
    // return index;

    // index = 0;
    // while(str[index++] != '\0');
    // return index;

    return sum;
}



/// @brief Count the quantity of characters that exist in provided C-string
///     Use pointer dereferencing and pointer parameter for this version
/// @param cPtr pointer to address in a C-string to start counting from
/// @return the quantity of characters counted
int countC_PtrParam(const char *str)
{
    int sum = 0;
    int index = 0;

    sum = 0;
    while(str[index] != '\0')
    {
        sum++;
        index++;
    }

    return sum;
}


/// @brief Count the quantity of characters that exist in provided C-string
///     Use pointer dereferencing and pointer parameter for this version
///     Also use pointer math, not a counter, to calculate the difference
///     in memory addresses to calculate the quantity of characters.
/// @param cPtr pointer to address in a C-string to start counting from
/// @return the quantity of characters counted
int countC_PtrParam(char *start)
{
    char *stop = start;

    // *loopVar - we get the character at that memory address
    while(*stop != '\0')
    {
        stop++; 
        // move 1 sizeof() type of pointer further in memory    
    }


    // int length = (stop - start) / sizeof(char);
    // length = (stop - start) / 1

    return stop - start;
}