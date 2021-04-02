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
    vector<vector<float>> vec;
    vector<float> vec2;

    vec.push_back({2, -3, 1});
    vec.push_back({2, 0, -1});
    vec.push_back({1, 4, 5});

    // vec2.push_back(2.0);
    // PrintVectorFloat(vec2);
    // vec2.push_back(3.0);
    // PrintVectorFloat(vec2);
    // vec2.push_back(4.0);
    // PrintVectorFloat(vec2);
    // cout << vec2[1] * vec2.size();
    bool re = CheckPointsInLeft(vec);
    cout << re;
    if (re)
    {

        cout << "Ffff" << endl;
    }

    return 0;
}
