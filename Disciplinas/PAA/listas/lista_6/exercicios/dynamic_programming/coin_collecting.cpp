#include <iostream>
#include <vector>
#include <limits>

int coinCollecting_rec(std::vector<std::vector<int>> &board, int i, int j)
{
    if (i == 0 && j == 0)
    {
        return board[i][j];
    }
    else if (i == 0)
    {
        return coinCollecting_rec(board, i, j - 1) + board[i][j];
    }
    else if (j == 0)
    {
        return coinCollecting_rec(board, i - 1, j) + board[i][j];
    }
    else
    {
        return std::max(coinCollecting_rec(board, i, j - 1), coinCollecting_rec(board, i - 1, j)) + board[i][j];
    }
}

int coinCollecting_dynamic(std::vector<std::vector<int>> &board, int line, int column)
{
    std::vector<std::vector<int>> aux(line, std::vector<int>(column, 0));
    aux[0][0] = board[0][0];

    for (int j = 1; j < column; ++j)
    {
        aux[0][j] = aux[0][j - 1] + board[0][j]; //resolve o problema da primeira linha
    }

    for (int i = 1; i < line; ++i)
    {
        aux[i][0] = aux[i - 1][0] + board[i][0]; //resolve o problema da primeira coluna

        for (int j = 1; j < column; ++j)
        {
            aux[i][j] = std::max(aux[i - 1][j], aux[i][j - 1]) + board[i][j];
        }
    }
    return aux[line - 1][column - 1];
}

int main()
{

    std::vector<std::vector<int>> board = {{0, 0, 0, 0, 1, 0},
                                           {0, 1, 0, 1, 0, 0},
                                           {0, 0, 0, 1, 0, 1},
                                           {0, 0, 1, 0, 0, 1},
                                           {1, 0, 0, 0, 1, 0}};

    // std::cout << "The minimun number of coins is " << coinCollecting_dynamic(board, 5, 6) << std::endl;
    std::cout << "The minimun number of coins is " << coinCollecting_rec(board, 5 - 1, 6 - 1) << std::endl;

    return 0;
}
