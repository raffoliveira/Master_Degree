#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <utility>
#include "functions.h"

using namespace std;

int main()
{
    vector<pair<float, float>> vec;
    int number_points;
    float x, y;

    do
    {
        cout << "Enter a number of pairs:";
        cin >> number_points;
    } while (number_points <= 1);

    for (int i = 0; i < number_points; i++)
    {
        cout << "x of Point" << i + 1 << ": ";
        cin >> x;
        cout << "y of Point" << i + 1 << ": ";
        cin >> y;
        vec.push_back(make_pair(x, y));
    }

    cout << "Vector of points: ";
    PrintVectorOfPair(vec);
    BruteForceClosestPair(vec);

    return 0;
}
