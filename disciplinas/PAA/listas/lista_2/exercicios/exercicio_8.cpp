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

    return 0;
}
