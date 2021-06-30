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

bool feasible(int val, std::vector<int> sol)
{
    return (sol.size() == 0) ? true : (val < sol.back());
}

bool feasibleNqueens(int val, std::vector<int> sol)
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

bool complete(std::vector<int> sol, int n_vars)
{
    return (sol.size() == n_vars);
}

void backtrack(std::vector<int> &sol,
               std::vector<int> domain,
               std::function<bool(int, std::vector<int>)> feasible,
               std::function<bool(std::vector<int>)> complete)
{
    if (complete(sol))
    {
        return;
    }
    else
    {
        for (int val : domain)
        {
            if (feasible(val, sol))
            {
                sol.push_back(val);
                backtrack(sol, domain, feasible, complete);

                if (!complete(sol))
                {
                    sol.pop_back();
                }
            }
        }
    }
}

int main()
{

    //a>b, b>c
    int n_vars = 4;
    std::vector<int> domain({1, 2, 3, 4});
    std::vector<int> sol({});
    std::function<bool(int, std::vector<int>)> f = [&](int val, std::vector<int> sol) -> bool
    {
        return feasible(val, sol);
    };
    std::function<bool(std::vector<int>)> c = [&](std::vector<int> sol) -> bool
    {
        return complete(sol, n_vars);
    };

    backtrack(sol, domain, f, c);

    printVector(sol);

    return 0;
}