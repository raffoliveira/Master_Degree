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
#include <stdlib.h>
#include <time.h>

std::vector<double> readingFile()
{

    std::vector<double> array;
    std::string line;
    std::string path = "C:\\Users\\rafae\\Documents\\GitHub\\Master_Degree\\Disciplinas\\Metodologia\\probabilidade\\tests\\";
    std::fstream readFile(path + "big.txt");

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

std::pair<double, double> t_distribution_confidence_interval(const std::vector<double> &data, double alpha)
{
    double mean_data = mean(data);
    double std_deviation_data = std_dev(data);
    std::vector<double> sample;
    int sample_size = rand() % data.size() + 1;

    std::cout << "The size of population is " << data.size() << std::endl;

    std::cout << "The mean of population is " << mean_data << std::endl;

    for (int i = 0; i < sample_size; ++i)
    {
        sample.push_back(data[rand() % data.size() + 1]);
    }

    double mean_sample = mean(sample);
    double std_deviation_sample = std_dev(sample);

    std::cout << "The mean of sample is " << mean_sample << std::endl;

    //t value of 95% is 1.96

    double interval1 = mean_sample - 1.96 * (std_deviation_data / std::sqrt(sample_size)); //intervalo de 95%
    double interval2 = mean_sample + 1.96 * (std_deviation_data / std::sqrt(sample_size));

    std::pair<double, double> result = std::make_pair(interval1, interval2);

    return result;
}

int main()
{
    std::srand(time(0));

    std::vector<double> v = readingFile();
    double prob = 0.95;
    std::pair<double, double> result = t_distribution_confidence_interval(v, prob);

    std::cout << "The confidence interval is [" << result.first << "," << result.second << "]" << std::endl;

    return 0;
}
