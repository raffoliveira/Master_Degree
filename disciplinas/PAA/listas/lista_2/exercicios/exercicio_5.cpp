//Algoritmo bublesort

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "functions.h"

using namespace std;

int main()
{
    vector<vector<float>> vec;
    vector<float> pairs;
    int number_points = 0;
    float x, y = 0;

    cout << "Enter a number of pairs:";
    cin >> number_points;

    for (int i = 0; i < number_points; i++)
    {
        cout << "Enter with x of pair " << i << ":";
        cin >> x;
        pairs.push_back(x);
        cout << "Enter with y of pair " << i << ":";
        cin >> y;
        pairs.push_back(y);
        vec.push_back(pairs);
        pairs.clear();
    }
    PrintVectorOfVector(vec);
    BruteForceClosestPair(vec);

    // cout << vec[0][0];
    // cout << vec[0][1];
    // cout << vec[1][0];
    // cout << vec[1][0];

    return 0;
}
