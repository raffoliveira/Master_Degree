#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <math.h>
#include <memory>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

//-------------------------------print
//vector-------------------------------------

template <typename T>
void printVector(std::vector<T> &vec)
{
    std::cout << "[";
    for (int i = 0; i < vec.size(); i++)
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

//-------------------------------print vector of
//vector-------------------------------------

template <typename T>
void printVectorOfVector(std::vector<std::vector<T>> &vec)
{
    std::cout << "[";
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << "[";
        for (int j = 0; j < vec[i].size(); j++)
        {
            std::cout << vec[i][j];
            if (j < vec[i].size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]";

        if (i < vec.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]";
    std::cout << std::endl; // print new line
}

//----------------------------reading
//file---------------------------------------- when load the testing files, it
// just changes the variable path to your specific path and the filename

std::vector<float> readingFileFloat()
{

    std::vector<float> array;
    std::string line;
    std::string path = "C:\\Users\\rafae\\Documents\\GitHub\\Master_"
                       "Degree\\disciplinas\\PAA\\listas\\lista_4\\testes\\";
    std::fstream readFile(path + "small.txt");

    if (readFile.is_open())
    {
        while (getline(readFile, line)) // reading line by line
        {
            if (line.size() > 0)
            {
                int number = stoi(line); // casting from string to int
                array.push_back(number);
            }
        }
        readFile.close();
    }
    return array;
}

//---------------------------------reading
//file----------------------------------------- when load the testing files, it
// just changes the variable path to your specific path and the filename

std::vector<std::string> readingFileString()
{

    std::vector<std::string> array;
    std::string line;
    std::string path = "C:\\Users\\rafae\\Documents\\GitHub\\Master_"
                       "Degree\\disciplinas\\PAA\\listas\\lista_4\\testes\\";
    std::fstream readFile(path + "alphabet.txt");

    if (readFile.is_open())
    {
        while (getline(readFile, line)) // reading line by line
        {
            if (line.size() > 0)
            {
                array.push_back(line);
            }
        }
        readFile.close();
    }
    return array;
}

//---------------------------------------merge
//vector--------------------------------------------

template <typename T>
void merge(std::vector<T> &v, int l, int middle, int r)
{
    std::vector<T> aux(v);
    int i = l, j = middle + 1, k = l;

    while (i <= middle && j <= r)
    {
        if (aux[i] <= aux[j])
        {
            v[k] = aux[i];
            i++;
        }
        else
        {
            v[k] = aux[j];
            j++;
        }
        k++;
    }

    while (i <= middle)
    {
        v[k] = aux[i];
        i++;
        k++;
    }
    while (j <= r)
    {
        v[k] = aux[j];
        j++;
        k++;
    }
}

//---------------------------------------mergesort---------------------------------------------

template <typename T>
void mergeSort(std::vector<T> &vec, int l, int r)
{
    if (l < r) // base (l => r) has 1 element
    {
        int middle = (r + l) / 2;
        mergeSort(vec, l, middle);     // first half
        mergeSort(vec, middle + 1, r); // second half
        merge(vec, l, middle, r);      // merge
    }
}

//------------------------------find min and max divide and conquer (element)------------------------------------

template <typename T>
void minMaxDivideConquer(std::vector<T> &vec, int l, int r, std::pair<T, T> &minMax)
{
    if (l == r)
    {
        minMax = std::make_pair(vec[l], vec[l]);
    }
    else if (r - l == 1)
    {
        if (vec[l] < vec[r])
        {
            minMax = std::make_pair(vec[l], vec[r]);
        }
        else
        {
            minMax = std::make_pair(vec[r], vec[l]);
        }
    }
    else if (r - l > 1)
    {
        std::pair<T, T> minMax2; // pair -> (min,max)
        T min, max;

        minMaxDivideConquer(vec, l, (l + r) / 2, minMax);
        minMaxDivideConquer(vec, ((l + r) / 2) + 1, r, minMax2);

        min = (minMax.first < minMax2.first) ? minMax.first : minMax2.first;
        max = (minMax.second > minMax2.second) ? minMax.second : minMax2.second;

        minMax = std::make_pair(min, max);
    }
}

//------------------------------find min and max brute force (element)------------------------------------

template <typename T>
void minMaxBruteForce(std::vector<T> &vec, std::pair<T, T> &minMax)
{
    minMax = std::make_pair(vec[0], vec[0]);

    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] < minMax.first)
        {
            minMax.first = vec[i];
        }
        else if (vec[i] > minMax.second)
        {
            minMax.second = vec[i];
        }
    }
}

//------------------------------find min and max divide and conquer (position)------------------------------------

template <typename T>
void minMaxDivideConquerElement(std::vector<T> &vec, int l, int r, std::pair<T, T> &minMax)
{
    if (l == r)
    {
        minMax = std::make_pair(vec[l], vec[l]);
    }
    else if (r - l == 1)
    {
        if (vec[l] < vec[r])
        {
            minMax = std::make_pair(vec[l], vec[r]);
        }
        else
        {
            minMax = std::make_pair(vec[r], vec[l]);
        }
    }
    else if (r - l > 1)
    {
        std::pair<T, T> minMax2; // pair -> (min,max)
        T min, max;

        minMaxDivideConquer(vec, l, (l + r) / 2, minMax);
        minMaxDivideConquer(vec, ((l + r) / 2) + 1, r, minMax2);

        min = (minMax.first < minMax2.first) ? minMax.first : minMax2.first;
        max = (minMax.second > minMax2.second) ? minMax.second : minMax2.second;

        minMax = std::make_pair(min, max);
    }
}

#endif
