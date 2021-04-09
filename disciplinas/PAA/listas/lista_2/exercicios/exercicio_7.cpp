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
#define NUMBER_CITY 4

int main()
{
    vector<vector<float>> vec;

    float initial_city = 0;

    //each matrix has the distances between cities

    //M = [c1->c1, c1->c2, c1->c3]
    //    [c2->c1, c2->c2, c2->c3]
    //    [c3->c1, c3->c2, c3->c3]

    //distances of cities c1, c2, c3
    // vec.push_back({0, 10.7, 15.2});
    // vec.push_back({10.7, 0, 25.3});
    // vec.push_back({15.2, 25.3, 0});

    //distances of cities c1, c2, c3, c4
    vec.push_back({0, 10.8, 15.9, 20.7});
    vec.push_back({10.8, 0, 35.2, 25.4});
    vec.push_back({20.7, 35.2, 0, 30.6});
    vec.push_back({20.7, 25.4, 30.6, 0});

    //distances of cities c1, c2, c3, c4, c5
    // vec.push_back({0, 10, 15, 20, 40});
    // vec.push_back({10, 0, 35, 25, 15});
    // vec.push_back({15, 35, 0, 30, 5});
    // vec.push_back({20, 25, 30, 0, 55});
    // vec.push_back({20, 45, 15, 65, 0});

    //distances of cities c1, c2, c3, c4, c5, c6
    // vec.push_back({0, 10, 15, 20, 40, 5});
    // vec.push_back({10, 0, 35, 25, 15, 45});
    // vec.push_back({15, 35, 0, 30, 5, 20});
    // vec.push_back({20, 25, 30, 0, 55, 30});
    // vec.push_back({20, 45, 15, 65, 0, 50});
    // vec.push_back({20, 45, 15, 65, 10, 0});

    travellingSalesmanProblem(vec, initial_city, NUMBER_CITY);

    return 0;
}
