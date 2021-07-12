#include <iostream>
#include <vector>
#include <limits>
#include <functional>
#include <cmath>

template <typename T>
void printVector(std::vector<T> &vec)
{
    std::cout << "[";
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];
        if (i < vec.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]";
    std::cout << std::endl;
}

template <typename T>
void printVectorOfVector(std::vector<std::vector<T>> &vec)
{
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
        std::cout << std::endl; //print new line
    }

    std::cout << std::endl; //print new line
}

void printMatrix(std::vector<std::vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        std::cout << "Adjacent list of vertex " << i << "\n head";

        for (int j = 0; j < matrix[i].size(); ++j)
        {
            if (matrix[i][j] == 1)
            {
                std::cout << " -> " << j;
            }
        }
        std::cout << std::endl;
    }
}

bool feasible(std::vector<std::vector<int>> &graph, std::vector<int> &colour_map, int index, int k)
{
    for (int i = 0; i < graph.size(); ++i)
    {
        if (graph[index][i] && colour_map[i] == k) //check the neighbors colors
        {
            return false;
        }
    }
    return true;
}

bool backtracking(std::vector<std::vector<int>> &graph, std::vector<int> &colour_map, int color_number, int index)
{
    //base case
    if (index == color_number + 1)
    {
        return true;
    }

    for (int k = 1; k <= color_number; ++k)
    {
        if (feasible(graph, colour_map, index, k)) //check if assignment color is good
        {
            colour_map.insert(colour_map.begin() + index, k);
            colour_map.pop_back();

            if (backtracking(graph, colour_map, color_number, index + 1))
            {
                return true;
            }

            colour_map.erase(colour_map.begin() + index); //remove the last insert
        }
    }

    return false; //if no possible to assign color
}

int main()
{
    int color_number = 4;
    std::vector<std::vector<int>> graph = {{0, 1, 1, 1, 0},
                                           {1, 0, 1, 0, 1},
                                           {1, 1, 0, 1, 0},
                                           {1, 0, 1, 0, 1},
                                           {0, 1, 0, 1, 0}};

    printVectorOfVector(graph);

    std::vector<int> colour_map(graph.size(), 0);

    if (backtracking(graph, colour_map, color_number, 0))
    {
        printVector(colour_map);
    }
    else
    {
        (std::cout << "Solution does not exist" << std::endl);
    }

    return 0;
}