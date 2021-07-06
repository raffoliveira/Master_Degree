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

int aux = 0, number_items = 4, knapSackWeight = 5;
std ::vector<int> weights({2, 1, 3, 2}), values({12, 10, 20, 15});
std ::vector<std::vector<int>> f(number_items + 1, std::vector<int>(knapSackWeight + 1, -1));

int MFknapSackProblem(int i, int j)
{
    if (f[i][j] < 0)
    {
        if (j < weights[i])
        {
            aux = MFknapSackProblem(i - 1, j);
        }
        else
        {
            aux = std::max(MFknapSackProblem(i - 1, j), values[i] + MFknapSackProblem(i - 1, j - weights[i]));
        }
        f[i][j] = aux;
        printVectorOfVector(f);
    }

    return f[i][j];
}

int main()
{
    for (int i = 0; i < number_items + 1; i++)
    {
        f[i][0] = 0;
    }
    for (int i = 0; i < knapSackWeight + 1; i++)
    {
        f[0][i] = 0;
    }

    printVectorOfVector(f);

    std::cout << "The maximal value is " << MFknapSackProblem(number_items, knapSackWeight) << std::endl;
    printVectorOfVector(f);
    return 0;
}
