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
    std::cout << ", " << vec.front();
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

bool feasible(std::vector<std::vector<int>> &graph, std::vector<int> &circuit, int index, int k)
{
    if (graph[circuit[index - 1]][k] == 0) //check if vertex is an adjacent vertex
    {                                      //of the previously added vertex
        return false;
    }

    for (int i = 0; i < index; ++i) //check if vertex has already inserted
    {
        if (circuit[i] == k)
        {
            return false;
        }
    }
    return true;
}

bool backtracking(std::vector<std::vector<int>> &graph, std::vector<int> &circuit, int index)
{
    //base case
    if (index == graph.size())
    {
        return (graph[circuit[index - 1]][circuit[0]] == 1); //verified if there is a edge between last inserted
                                                             //and the first inserted
    }

    for (int k = 1; k < graph.size(); ++k)
    {
        if (feasible(graph, circuit, index, k)) //check if vertex is visited
        {
            circuit.insert(circuit.begin() + index, k); //insert
            circuit.pop_back();

            if (backtracking(graph, circuit, index + 1))
            {
                return true;
            }

            circuit.erase(circuit.begin() + index);
        }
    }
    return false;
}

int main()
{
    std::vector<std::vector<int>> graph = {{0, 1, 0, 1, 0},
                                           {1, 0, 1, 1, 1},
                                           {0, 1, 0, 0, 1},
                                           {1, 1, 0, 0, 1},
                                           {0, 1, 1, 1, 0}};
    printVectorOfVector(graph);

    std::vector<int> circuit(graph.size(), -1);
    circuit.insert(circuit.begin(), 0);
    circuit.pop_back();

    backtracking(graph, circuit, 1);
    printVector(circuit);

    return 0;
}