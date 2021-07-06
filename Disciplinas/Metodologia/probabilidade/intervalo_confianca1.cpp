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

std::vector<double> readingFile()
{

    std::vector<double> array;
    std::string line;
    std::string path = "C:\\Users\\rafae\\Documents\\GitHub\\Master_Degree\\Disciplinas\\Metodologia\\probabilidade\\tests\\";
    std::fstream readFile(path + "medium.txt");

    if (readFile.is_open())
    {
        while (getline(readFile, line)) //reading line by line
        {
            if (line.size() > 0)
            {
                int number = stoi(line); //casting from string to int
                array.push_back(number);
            }
        }
        readFile.close();
    }
    return array;
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
    std::vector<double> v = readingFile();
    double x = 50, x1 = 49, x2 = 52;
    double mu = mean(v);
    double std_deviation = std_dev(v);

    std::cout << "The probability 1 is " << normal_distribution_cdf1(x, mu, std_deviation) << std::endl;
    std::cout << "The probability 2 is " << normal_distribution_cdf2(x) << std::endl;
    std::cout << "The probability 1 between " << x1 << " e " << x2 << " is " << normal_distribution_cdf3(x1, x2, mu, std_deviation) << std::endl;
    std::cout << "The probability 2 between " << x1 << " e " << x2 << " is " << normal_distribution_cdf4(x1, x2) << std::endl;

    return 0;
}