#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <utility>
#include "functions.h"
#include "functions.cpp"

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
    } while (number_points < 2);

    for (int i = 0; i < number_points; i++)
    {
        cout << "x of Point" << i + 1 << ": ";
        cin >> x;
        cout << "y of Point" << i + 1 << ": ";
        cin >> y;
        vec.push_back(make_pair(x, y));
    }

    cout << "Vector of points: ";
    printVectorOfPair(vec);
    vector<int> result = convexHull(vec);
    cout << "The index of the points belonging to convex hull are:" << endl;
    printVector(result);

    return 0;
}
