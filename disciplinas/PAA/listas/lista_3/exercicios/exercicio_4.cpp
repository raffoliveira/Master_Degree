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
    // int n;
    // float elem;
    // vector<float> vec;
    // vector<vector<float>> result;

    // cout << "Enter the number of elements: ";
    // cin >> n;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Enter the element " << i + 1 << ": ";
    //     cin >> elem;
    //     vec.push_back(elem);
    // }
    // powerSet(result, vec, n);

    vector<float> weight, value;
    int number_items;
    float values, weights, knapSackWeight;

    cout << "Enter a weight of knapsack: ";
    cin >> knapSackWeight;
    cout << "Enter a number of items: ";
    cin >> number_items;

    for (int i = 0; i < number_items; i++)
    {
        cout << "Enter the weight of item " << i + 1 << ": ";
        cin >> weights;
        weight.push_back(weights);
        cout << "Enter the value of item " << i + 1 << ": ";
        cin >> values;
        value.push_back(values);
    }

    cout << "Weights: " << endl;
    printVector(weight);
    cout << "Values: " << endl;
    printVector(value);

    knapSackProblem(knapSackWeight, weight, value, number_items);

    // vector<vector<float>> v = {{10}, {10, 20}, {30}, {10, 30}, {10, 20, 30}};
    // printVectorOfVector(v);

    // v.erase(v.begin() + 1);
    // printVectorOfVector(v);
    // vector<float> vw = v[1];
    // cout << accumulate(v[1].begin(), v[1].end(), 0);

    return 0;
}
