#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

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

int cost(int val, std::vector<int> &sol)
{
    int conflit = 0;

    for (int i = 0; i < sol.size(); ++i)
    {
        if (val == sol[i]) //duplicatas
        {
            conflit += 1;
        }

        int delx = std::abs(sol[i] - val); //diagonal
        int dely = std::abs(i - int(sol.size()));

        if (delx == dely)
        {
            conflit += 1;
        }
    }

    return conflit;
}

int h()
{
    return 0;
}

void search(std::vector<int> &domain,
            std::vector<int> &sol,
            std::vector<int> &best_sol,
            int nqueens,
            int &bound)
{
    for (int i = 0; i < nqueens; ++i)
    {
        if (sol.size() == nqueens)
        {
            best_sol = sol;
            return;
        }
        if (cost(i, sol) + h() <= bound)
        {
            bound = cost(i, sol);
            std::vector<int> new_sol(sol);
            new_sol.push_back(i);
            search(domain, new_sol, best_sol, nqueens, bound);
        }
    }
}

std::vector<int> branchandbound(std::vector<int> &domain, int nqueens, int &bound)
{
    std::vector<int> sol({});
    std::vector<int> best_sol({});

    search(domain, sol, best_sol, nqueens, bound);

    return best_sol;
}

int main()
{
    int nqueens = 4, bound = 0;
    std::vector<int> domain({0, 1, 2, 3}); //columns

    std::vector<int> result = branchandbound(domain, nqueens, bound);

    printVector(result);

    return 0;
}