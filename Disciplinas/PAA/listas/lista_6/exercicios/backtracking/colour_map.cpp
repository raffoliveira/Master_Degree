#include <iostream>
#include <vector>
#include <limits>
#include <functional>
#include <cmath>

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

void addedge(std::vector<std::vector<int>> &matrix, int u, int v)
{
    matrix[u][v] = 1;
    matrix[v][u] = 1;
}

void backtracking(std::vector<std::vector<int>> &graph, std::vector<std::vector<int>> colour_map, int color)
{
    if (complete(colour_map))
    {
        return;
    }
    else
    {
        for (int i = 0; i < color; ++i)
        {
            for (int j = 0; j < graph.size(); ++j)
            {
                if (feasible(colour_map))
                {
                    colour_map[i][j] = colour_map[0][0] + 1;
                }
            }
        }
    }
}

int main()
{
    int color = 3;
    std::vector<std::vector<int>> graph(4, std::vector<int>(4, 0));
    addedge(graph, 0, 1);
    addedge(graph, 0, 2);
    addedge(graph, 0, 3);
    addedge(graph, 1, 2);
    addedge(graph, 1, 3);
    addedge(graph, 2, 0);
    addedge(graph, 2, 1);
    addedge(graph, 2, 3);
    addedge(graph, 3, 1);
    addedge(graph, 3, 0);

    printVectorOfVector(graph);

    std::vector<std::vector<int>> colour_map(graph);
    colour_map[0][0] = 1;

    backtracking(graph, colour_map, color);

    printMatrix(graph);
}