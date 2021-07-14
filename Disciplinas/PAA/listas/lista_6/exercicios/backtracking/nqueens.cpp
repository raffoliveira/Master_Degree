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

bool completeQueens(std::vector<int> sol, int n)
{
    return (sol.size() == n);
}

bool feasibleQueens(int val, std::vector<int> sol)
{
    //verificar se há uma rainha em cada linha
    //e n há rainha repetidas na coluna
    //val = nova coluna q quero colocar

    for (int i = 0; i < sol.size(); ++i)
    {
        if (val == sol[i])
        {
            return false;
        }

        int delx = std::abs(sol[i] - val);
        int dely = std::abs(i - (int)sol.size());

        if (delx == dely)
        {
            return false;
        }
    }

    return true;
}

void backtracking(std::vector<int> &sol, int number_queens)
{
    if (number_queens == 1)
    {
        sol.push_back(0);
        return;
    }
    else if (number_queens == 2 || number_queens == 3)
    {
        std::cout << "There are no solutions." << std::endl;
        return;
    }
    else
    {
        if (completeQueens(sol, number_queens))
        {
            return;
        }

        for (int j = 0; j < number_queens; ++j)
        {
            if (feasibleQueens(j, sol))
            {
                sol.push_back(j);
                backtracking(sol, number_queens);

                if (!completeQueens(sol, number_queens))
                {
                    sol.pop_back();
                }
            }
        }
    }
}

void fillboard(std::vector<int> &sol, std::vector<std::vector<int>> &board, int number_queens)
{
    for (int i = 0; i < number_queens; ++i)
    {
        board[sol[i]][i] = 1;
    }
    return;
}

int main()
{
    int nqueens = 4;
    std::vector<int> sol({});
    std::vector<std::vector<int>> board(nqueens, std::vector<int>(nqueens, 0));

    printVectorOfVector(board);
    backtracking(sol, nqueens);
    fillboard(sol, board, nqueens);
    printVectorOfVector(board);
    printVector(sol);

    return 0;
}