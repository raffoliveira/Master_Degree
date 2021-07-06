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

double t_distribution_pdf(double x, int v)
{
    double part1 = (std::tgamma((v + 1) / 2)) / ((std::sqrt(v * M_PI)) * std::tgamma(v / 2));
    double part2 = std::pow((1 + (std::pow(x, 2) / v)), -((v + 1) / 2));

    return part1 * part2;
}

int main()
{

    return 0;
}