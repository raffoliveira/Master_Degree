#include <iostream>
#include <vector>

int fib_rec(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fib_rec(n - 2) + fib_rec(n - 1);
    }
}

double fib_dynamic(int n, std::vector<int> &cache) //top_down
{
    if (cache[n] != -1)
    {
        return cache[n];
    }
    else
    {
        if (n <= 1)
        {
            cache[n] = n;
        }
        else
        {
            cache[n] = fib_dynamic(n - 1, cache) + fib_dynamic(n - 2, cache);
        }
        return cache[n];
    }
}

double fib_bottom_up(int n)
{
    std::vector<double> cache(n + 1);
    cache[0] = 0;
    cache[1] = 1;

    for (int i = 2; i < cache.size(); ++i)
    {
        cache[i] = cache[i - 1] + cache[i - 2];
    }
    return cache[n - 1];
}

double fib_dynamic(int n)
{
    std::vector<int> cache(n + 1, -1);
    return fib_dynamic(n, cache);
}

int main()
{
    int n = 100, j = 150;
    //std::cout << fib_rec(n) << std::endl;
    //std::cout << fib_dynamic(n) << std::endl;
    //std::cout << fib_dynamic(j) << std::endl;
    std::cout << fib_bottom_up(8) << std::endl;
}