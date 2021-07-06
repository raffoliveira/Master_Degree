#define _USE_MATH_DEFINES
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <utility>
#include <cmath>

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
    double x = 1.4, mu = 1.56, std_dev = 1.87;

    std::cout << "The normal distribution1 is " << normal_distribution_pdf1(x, mu, std_dev) << std::endl;
    std::cout << "The normal distribution2 is " << normal_distribution_pdf2(x) << std::endl;

    return 0;
}