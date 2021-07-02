#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <utility>
#include <cmath>

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

std::vector<double> readingFile()
{

    std::vector<double> array;
    std::string line;
    std::string path = "C:\\Users\\rafae\\Documents\\GitHub\\Master_Degree\\Disciplinas\\Metodologia\\probabilidade\\";
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

double mode(const std::vector<double> &data)
{
    double mostElement = data.front();
    int maxCount = 0;

    for (int i = 0; i < data.size(); i++)
    {
        int c = std::count(data.begin(), data.end(), data[i]);
        if (c > maxCount)
        {
            maxCount = c;
            mostElement = data[i];
        }
    }

    return mostElement;
}

int partition(std::vector<double> &vec, int l, int r)
{
    double pivot = vec[r];
    int i = (l - 1);

    for (int j = l; j <= r - 1; j++)
    {
        // If current element is smaller than the pivot
        if (vec[j] < pivot)
        {
            i++; // increment index of smaller element
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], vec[r]);

    return (i + 1);
}

void quickSort(std::vector<double> &vec, int l, int r)
{
    if (l < r)
    {
        int s = partition(vec, l, r);
        quickSort(vec, l, s - 1);
        quickSort(vec, s + 1, r);
    }
}

double percentile(const std::vector<double> &data, int p)
{
    std::vector<double> v(data);
    quickSort(v, 0, v.size() - 1);

    int q = std::ceil((p * (data.size() - 1)) / 100);

    return v[q];
}

double median(std::vector<double> &data)
{
    // return percentile(data, 50);
    std::nth_element(data.begin(), data.begin() + (data.size() / 2), data.end());
    return data[data.size() / 2];
}

std::pair<double, double> interval(const std::vector<double> &data)
{
    double min = data[0], max = data[0];
    std::pair<double, double> inter;

    for (int i = 1; i < data.size(); ++i)
    {
        if (data[i] < min)
        {
            min = data[i];
        }
        if (data[i] > max)
        {
            max = data[i];
        }
    }
    inter = std::make_pair(min, max);
    return inter;
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

int main()
{
    // std::vector<double> v = readingFile();
    std::vector<double> v({1, 2, 3, 4});
    std::pair<double, double> inter = interval(v);

    printVector(v);

    std::cout << "The interval is [" << inter.first << "," << inter.second << "]" << std::endl;
    std::cout << "The variance is " << variance(v) << std::endl;
    std::cout << "The standard deviation is " << std_dev(v) << std::endl;

    return 0;
}