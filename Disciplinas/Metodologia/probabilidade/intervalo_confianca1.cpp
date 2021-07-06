#define _USE_MATH_DEFINES
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <utility>
#include <cmath>
#include <math.h>

double normal_distribution_cdf1(double x, double mu, double std_dev)
{
    return ((1 + (std::erf((x - mu) / (std_dev * std::sqrt(2))))) / 2);
}

double normal_distribution_cdf2(double x)
{
    return ((1 + (std::erf(x / std::sqrt(2)))) / 2);
}

//assumindo que x2 > x1
double normal_distribution_cdf3(double x1, double x2, double mu, double std_dev)
{
    double result1 = normal_distribution_cdf1(x1, mu, std_dev);
    double result2 = normal_distribution_cdf1(x2, mu, std_dev);

    return result2 - result1;
}

//assumindo que x2 > x1
double normal_distribution_cdf4(double x1, double x2)
{
    double result1 = normal_distribution_cdf2(x1);
    double result2 = normal_distribution_cdf2(x2);

    return result2 - result1;
}

int main()
{
    double x = 1.4, x1 = 4, x2 = 8, mu = 1.56, std_dev = 1.87;

    std::cout << "The probability 1 is " << normal_distribution_cdf1(x, mu, std_dev) << std::endl;
    std::cout << "The probability 2 is " << normal_distribution_cdf2(x) << std::endl;
    std::cout << "The probability 1 between " << x1 << " e " << x2 << " is " << normal_distribution_cdf3(x1, x2, mu, std_dev) << std::endl;
    std::cout << "The probability 2 between " << x1 << " e " << x2 << " is " << normal_distribution_cdf4(x1, x2) << std::endl;

    return 0;
}