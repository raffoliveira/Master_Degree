#define _USE_MATH_DEFINES
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <utility>
#include <cmath>
#include <random>

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

double normal_distribution_pdf1(double x, double mu, double std_dev)
{
    double part1 = std::exp(-((std::pow((x - mu), 2)) / (2 * std::pow(std_dev, 2))));
    double part2 = std::sqrt(2 * M_PI * std::pow(std_dev, 2));
    return part1 / part2;
}
double normal_distribution_pdf2(double x)
{
    double part1 = std::exp(-((std::pow(x, 2)) / 2));
    double part2 = std::sqrt(2 * M_PI);
    return part1 / part2;
}

int main()
{
    std::vector<double> v;

    for (int i = 0; i < 500; i++)
    {
        v.push_back(n(g));
    }

    double x = 5;
    double mu = mean(v);
    double std_deviation = std_dev(v);

    std::cout << "The probability 1 is " << normal_distribution_pdf1(x, mu, std_deviation) << std::endl;
    std::cout << "The probability 2 is " << normal_distribution_pdf2(x) << std::endl;

    return 0;
}