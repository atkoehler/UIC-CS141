


// goal: acquire postive numbers and 
// store them

// what is positive?
// > 0 ? >= 0



#include <iostream>
#include <vector>

using namespace std;

// int main()
// {
//     //python list
//     //untyped variables

//     int q = 0;
//     long r = 0;
//     float y = 0.0;
//     double z = 0;
 
//     vector<int> v;

//     cout << "Enter a number: ";
//     cin >> q;
//     cout << endl;

//     // cout << q << " " << r << endl;
//     int arr[5];

   
//     // if (q > 0)

//     while (q > 0)
//     {
//         v.push_back(q);
        
//         cout << v.size() << endl;
//         cout << v.back() << endl;

//         cout << "Enter a number: ";
//         cin >> q;
//         cout << endl;
//     }

//     // else if(q == 0)
//     // {
//     //     cout << "zero not included" << endl;
//     // }
//     // else
//     // {
//     //     cout << "wrong number" << endl;
//     //     cout << "am i in the else" << endl;
//     // }

//     cout << v.size() << endl;

//     // how to access an element 
//     // of the vector

//     for (int i = 0; i < 100000; ++i)
//     {
//         cout << "Outputting element " << i << endl;
//         cout << v.at(i) << endl;
//     }

//     return 0;
// }

#include <random>

int getRoll()
{
    return rand()%6+1 + rand()%6+1 
        + rand()%6+1;
}

int main()
{
    int roll;
    int simCount = 0;
    cin >> simCount;


    int a = 5;
    int b = 7;
    int c = a++ + b;
    int d = ++a + b;

    vector<int> data;

    for(int i=0; i < simCount; ++i)
    {
        roll = getRoll();
        data.push_back(roll);
        // data.push_back(getRoll());
    }

    vector<int> count(19);
    for (auto &e : data)
    {
        count.at(e) += 1;
    }


    for(int i=0; i <= 18; ++i)
    {
        cout << i << ": " 
        << static_cast<double>(count.at(i))
             / simCount << endl;
    }

    return 0;
}