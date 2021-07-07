#define _USE_MATH_DEFINES
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <utility>
#include <random>
#include <cmath>
#include <math.h>

std::default_random_engine g;
std::normal_distribution<float> n(1.0, 50.0);

template <typename T>
void printVector(std::vector<T> &vec)
{
    std::cout << "[";
    for (auto i = 0; i < vec.size(); i++)
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

double mean(const std::vector<double> &data)
{
    double sum = std::accumulate(data.begin(), data.end(), 0);

    return sum / data.size();
}

double variance(const std::vector<double> &data)
{
    double _mean = mean(data), sum = 0;

    for (int i = 0; i < data.size(); ++i)
    {
        sum += std::pow((data[i] - _mean), 2);
    }
    return sum / (data.size() - 1);
}

double std_dev(const std::vector<double> &data)
{
    return std::sqrt(variance(data));
}

double normal_distribution_cdf1(double x, double mu, double std_dev)
{
    return ((1 + (std::erf((x - mu) / (std_dev * std::sqrt(2))))) / 2);
}

//mean = 0 and std_dev = 1
double normal_distribution_cdf2(double x)
{
    return ((1 + (std::erf(x / std::sqrt(2)))) / 2);
}

//assumindo que x2 > x1
double normal_distribution_cdf3(double x1, double x2, double mu, double std_dev)
{
    return normal_distribution_cdf1(x2, mu, std_dev) - normal_distribution_cdf1(x1, mu, std_dev);
}

//assumindo que x2 > x1
double normal_distribution_cdf4(double x1, double x2)
{
    return normal_distribution_cdf2(x2) - normal_distribution_cdf2(x1);
}

int main()
{
    std::vector<double> v;

    for (int i = 0; i < 500; i++)
    {
        v.push_back(n(g));
    }

    double x = 5, x1 = 3, x2 = 6;
    double mu = mean(v);
    double std_deviation = std_dev(v);

    printVector(v);

    std::cout << "The probability 1 of " << x << " is " << normal_distribution_cdf1(x, mu, std_deviation) << std::endl;
    std::cout << "The probability 2 of " << x << " is " << normal_distribution_cdf2(x) << std::endl;
    std::cout << "The probability 1 of " << x << " is between " << x1 << " e " << x2 << " is " << normal_distribution_cdf3(x1, x2, mu, std_deviation) << std::endl;
    std::cout << "The probability 2 of " << x << " is between " << x1 << " e " << x2 << " is " << normal_distribution_cdf4(x1, x2) << std::endl;

    return 0;
}