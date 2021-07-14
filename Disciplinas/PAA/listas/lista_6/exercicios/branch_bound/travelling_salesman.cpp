#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

template <typename T>
void printVector(std::vector<T> &vec, float cost)
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
    std::cout << " -> " << cost << std::endl;
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

void readFile(std::vector<std::vector<int>> &matrix, std::string file, int header, int number_cities)
{
    std::string line;
    int count = 0, linem, colm;
    std::ifstream myfile(file);

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            count++;
            if (count > header && line != "EOF")
            {
                // std::vector<int> linedata;
                linem = count - header - 1;
                colm = linem + 1;
                std::stringstream lineStream(line);
                int value;

                while (lineStream >> value)
                {
                    // linedata.push_back(value);
                    matrix[colm][linem] = value;
                    matrix[linem][colm] = value;
                    ++colm;
                }
                // matrix.push_back(linedata);
            }
        }
        myfile.close();
    }
    else
    {
        std::cout << "Unable to open file";
    }
}

float heuristic(std::vector<int> &sol)
{
    return 0;
}

float cost_route(std::vector<int> &sol, std::vector<std::vector<int>> &matrix)
{
    float cost = 0;

    for (int i = 0; i < sol.size() - 1; ++i)
    {
        cost += matrix[sol[i]][sol[i + 1]];
    }

    cost += matrix[sol.back()][sol.front()];

    return cost;
}

void search(std::vector<std::vector<int>> &matrix,
            std::vector<int> &domain,
            std::vector<int> &best_solution,
            std::vector<int> &solution,
            int cities_number,
            float &bound)
{
    if (cost_route(solution, matrix) + heuristic(solution) < bound) //verifica se a solution eh menor do q o bound
    {
        if (solution.size() == cities_number) //se a solução está completa
        {
            best_solution = solution;
            bound = cost_route(solution, matrix);
            printVector(best_solution, bound); //print cada solução
        }
        else //senao está completa adiciona nova cidade
        {
            for (auto elem : domain)
            {
                if (std::find(solution.begin(), solution.end(), elem) == solution.end()) //se a cidade n está na solução
                {
                    std::vector<int> new_solution(solution);
                    new_solution.push_back(elem);

                    search(matrix, domain, best_solution, new_solution, cities_number, bound);
                }
            }
        }
    }
}

void branchandbound(std::vector<std::vector<int>> &matrix,
                    std::vector<int> &domain,
                    int cities_number,
                    float &bound)
{
    std::vector<int> best_solution({});
    std::vector<int> solution({0});

    search(matrix, domain, best_solution, solution, cities_number, bound);
}

int main()
{
    std::string myfile = "brazil58.tsp";
    int header = 7, number_cities = 58;
    float bound = 1000000;
    std::vector<std::vector<int>> matrix(number_cities, std::vector<int>(number_cities, 0));
    std::vector<int> domain;

    for (int i = 0; i < number_cities; ++i)
    {
        domain.push_back(i);
    }
    // std::vector<std::vector<int>> matrix({{0, 1, 1, 2},
    //                                       {1, 0, 2, 1},
    //                                       {1, 2, 0, 1},
    //                                       {2, 1, 1, 0}});
    // std::vector<std::vector<int>> matrix({{0, 10, 2, 9, 3, 10},
    //                                       {10, 0, 4, 3, 6, 3},
    //                                       {2, 4, 0, 8, 7, 8},
    //                                       {9, 2, 8, 0, 8, 5},
    //                                       {3, 3, 7, 8, 0, 9},
    //                                       {10, 3, 8, 5, 9, 0}});

    readFile(matrix, myfile, header, number_cities);

    printVectorOfVector(matrix);

    branchandbound(matrix, domain, number_cities, bound);

    return 0;
}