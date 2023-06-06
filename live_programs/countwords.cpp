/// @file countwords.cpp
/// @author Adam T Koehler, PhD
/// @date June 6, 2023
/// @brief Code developed in class to solve a prompts asking to count
///         the frequencies of words read in from a file where the 
///         number of words to read is provided through user input.

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution). 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
    // Acquire the number of words to read from the file
    int x;
    cin >> x;

    // Create parallel arrays to store the words and the frequencies.
    string words[x];

    // We need to set the frequency counters to all start at 0
    // We can do it here or set to zero with an assignment statement
    // at the same time we set the words.
    int freq[x] = {0};

    // We will always read the words from in.txt
    ifstream inF("in.txt");

    // Grab x words from the in.txt file using the extraction
    // operator to skip over any whitespace
    for(int i = 0; i < x; ++i)
    {
        inF >> words[i];
        // freq[i] = 0; // we don't need to do this as we initialized to 0
    }   

    // Good practice to close our file after we are done with it
    inF.close();

    // O(N^2) solution to count the word frequencies
    // The outer loop goes through all the words, for each of those words
    // the inner loop counts how many matches exist amongst all the words
    for(int i = 0; i < x; ++i)
    {
        for(int j = 0; j < x; ++j)
        {
            // We want to count ourselves so we don't need to skip i==j
            if (words[i] == words[j])
            {
                freq[i]++; // same as freq[i] += 1 or freq[i] = freq[i] + 1
            }
        }
    }


    // Output the data contained in the parallel arrays separated by a dash
    for(int i = 0; i < x; ++i)
    {
        cout << arr[i] << " - " << freq[i] << endl;
    }   

    return 0;
}
