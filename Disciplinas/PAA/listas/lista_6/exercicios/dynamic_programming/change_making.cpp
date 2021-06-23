#include <iostream>
#include <vector>
#include <limits>

int change_making(std::vector<int> &coins, int amount)
{
    std::vector<int> aux;
    aux.push_back(0);

    for (int i = 1; i <= amount; ++i)
    {
        int j = 0, temp = std::numeric_limits<int>::max();

        while (j < coins.size() && i >= coins[j])
        {
            temp = std::min(aux[i - coins[j]], temp);
            ++j;
        }
        aux.push_back(temp + 1);
    }

    return aux[amount];
}

int main()
{

    int amount = 38;
    std::vector<int> coins = {1, 5, 10, 25, 50};

    std::cout << "The minimun number of coins is " << change_making(coins, amount) << std::endl;

    return 0;
}
