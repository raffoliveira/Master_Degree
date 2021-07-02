#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <utility>

template <typename T>
void printVector(std::vector<T> &vec)
{
    std::cout << "[";
    for (auto i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];
        if (i < vec.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]";
    std::cout << std::endl; //print new line
}

template <typename T>
void printVectorOfVector(std::vector<std::vector<T>> &vec)
{
    std::cout << "[";
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << "[";
        for (int j = 0; j < vec[i].size(); j++)
        {
            std::cout << vec[i][j];
            if (j < vec[i].size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]";

        if (i < vec.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]";
    std::cout << std::endl; //print new line
}

template <typename T>
void powerSet(std::vector<std::vector<T>> &result, std::vector<T> &vec, int n)
{
    auto number_subsets = std::pow(2, n);
    int count, j;
    std::vector<float> subset;

    for (count = 0; count < number_subsets; count++)
    {
        for (j = 0; j < n; j++)
        {
            if (count & (1 << j))
            {
                subset.push_back(vec[j]);
            }
        }
        result.push_back(subset);
        subset.clear();
    }
}

template <typename T>
float sequentialSearch(std::vector<T> &vec, T number)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == number)
        {
            return i;
        }
    }
    return -1;
}

void knapSackProblem(float knapSackWeight, std::vector<float> &weights, std::vector<float> &values, int n)
{
    std::vector<std::vector<float>> result_subsets;
    std::vector<float> pair_weights;
    float sub_value = 0, max_value = 0;
    int index;

    if (n == 0 || knapSackWeight == 0) //base case
    {
        std::cout << "The maximum value inside knapsack is 0" << std::endl;
    }

    powerSet(result_subsets, weights, n); //generate all possibilities

    printVectorOfVector(result_subsets);

    for (int i = 0; i < result_subsets.size(); i++)
    {
        if (std::accumulate(result_subsets[i].begin(), result_subsets[i].end(), 0) <= knapSackWeight)
        {
            for (int j = 0; j < result_subsets[i].size(); j++)
            {
                index = sequentialSearch(weights, result_subsets[i][j]);
                sub_value += values[index];
            }
            if (sub_value >= max_value)
            {
                pair_weights = result_subsets[i];
                max_value = sub_value;
                sub_value = 0;
            }
            sub_value = 0;
        }
    }

    std::cout << "The maximum value inside knapsack is " << max_value << std::endl;
    std::cout << "And the weights are: " << std::endl;
    printVector(pair_weights);
}

void knapSackProblem_dynamic(float knapSackWeight, std::vector<float> &weights, std::vector<float> &values, int n)
{
    std::vector<std::vector<float>> result_subsets;
    std::vector<float> pair_weights;
    std::vector<float> cache;
    float sub_value = 0, max_value = 0;
    int index;

    if (n == 0 || knapSackWeight == 0) //base case
    {
        std::cout << "The maximum value inside knapsack is 0" << std::endl;
    }

    powerSet(result_subsets, weights, n); //generate all possibilities

    printVectorOfVector(result_subsets);

    for (int i = 0; i < result_subsets.size(); i++)
    {
        if (std::accumulate(result_subsets[i].begin(), result_subsets[i].end(), 0) <= knapSackWeight)
        {
            for (int j = 0; j < result_subsets[i].size(); j++)
            {
                index = sequentialSearch(weights, result_subsets[i][j]);
                sub_value += values[index];
            }
            if (sub_value >= max_value)
            {
                pair_weights = result_subsets[i];
                max_value = sub_value;
                sub_value = 0;
            }
            sub_value = 0;
        }
    }

    std::cout << "The maximum value inside knapsack is " << max_value << std::endl;
    std::cout << "And the weights are: " << std::endl;
    printVector(pair_weights);
}

int main()
{
    std::vector<float> weight, value;
    int number_items;
    float values, weights, knapSackWeight;

    std::cout << "Enter a weight of knapsack: ";
    std::cin >> knapSackWeight;
    std::cout << "Enter a number of items: ";
    std::cin >> number_items;

    for (int i = 0; i < number_items; i++)
    {
        std::cout << "Enter the weight of item " << i + 1 << ": ";
        std::cin >> weights;
        weight.push_back(weights);
        std::cout << "Enter the value of item " << i + 1 << ": ";
        std::cin >> values;
        value.push_back(values);
    }

    std::cout << "Weights: " << std::endl;
    printVector(weight);
    std::cout << "Values: " << std::endl;
    printVector(value);

    knapSackProblem(knapSackWeight, weight, value, number_items);

    return 0;
}
