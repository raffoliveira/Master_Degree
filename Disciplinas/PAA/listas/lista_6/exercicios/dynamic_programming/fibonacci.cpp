#include <iostream>
#include <vector>
#include <chrono>

int fib_rec(int n)
/*initialize in n -> (n-1 + n-2) -> (n-3 + n-4) -> ... -> 0
using just recursion
*/
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
/*initialize in n -> (n-1 + n-2) -> (n-3 + n-4) -> ... -> 0
using the vector to allocate the values
*/
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
//iniatilize in 0 -> 1 -> 2 -> ...-> n
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

//template to call the real function
double fib_dynamic(int n)
{
    std::vector<int> cache(n + 1, -1);
    return fib_dynamic(n, cache);
}

int main()
{

    auto start1 = std::chrono::steady_clock::now();
    std::cout << fib_rec(40) << std::endl;
    auto end1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration1 = end1 - start1;
    std::cout << "Fib_rec: " << duration1.count() << std::endl;

    auto start2 = std::chrono::steady_clock::now();
    std::cout << fib_dynamic(40) << std::endl;
    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration2 = end2 - start2;
    std::cout << "Fib_dynamic1: " << duration2.count() << std::endl;

    auto start3 = std::chrono::steady_clock::now();
    std::cout << fib_dynamic(50) << std::endl;
    auto end3 = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration3 = end3 - start3;
    std::cout << "Fib_dynamic2: " << duration3.count() << std::endl;

    auto start4 = std::chrono::steady_clock::now();
    std::cout << fib_bottom_up(40) << std::endl;
    auto end4 = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration4 = end4 - start4;
    std::cout << "Fib_bottom_up: " << duration4.count() << std::endl;
}