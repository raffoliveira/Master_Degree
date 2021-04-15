#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include "functions.h"
#include "functions.cpp"

using namespace std;

int main()
{
    int n;
    float elem;
    vector<float> vec;
    vector<vector<float>> result;

    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element " << i + 1 << ": ";
        cin >> elem;
        vec.push_back(elem);
    }
    powerSet(result, vec, n);
    printVectorOfVector(result);

    return 0;
}
