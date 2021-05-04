#pragma once

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <math.h>
#include <numeric>
#include <string>
#include <queue>
#include <ctime>
#include <list>
#include <cstdlib>
#include <stack>
#include <chrono>
#include <utility>
#include <concepts>
#include <memory>

template <typename T>
void printVector(std::vector<T> &);
template <typename T>
void printVectorOfVector(std::vector<std::vector<T>> &);
template <typename T>
void johnsonTrotter(std::vector<std::vector<T>> &, std::vector<T> &);
void lexicographicPermute(std::vector<std::vector<int>> &, std::vector<int> &);
template <typename T>
void insertionSort(std::vector<T> &);
template <typename T>
void powerSet(std::vector<std::vector<T>> &, std::vector<T> &, int);
template <typename T>
class BinarySearchTree;
template <typename T>
bool checkMobileElement(std::vector<int> &, std::vector<T> &);
template <typename T>
int findLargestMobileElement(std::vector<int> &, std::vector<T> &);
int fakeCoin(const std::vector<int> &, int, int);
int binarySearch(std::vector<float> &, int);
int interpolationSearch(std::vector<float> &, int);
int quickSelect(std::vector<int> &, int, int, int);
int lomutoPartition(std::vector<int> &, int, int);
int randomNumber();
std::vector<float> readingFileFloat();
std::vector<std::string> readingFileString();
enum class InsertInfo
{
    Inserted,
    IsAlreadyIn
};
enum class SearchInfo
{
    Found,
    NotFound
};

#endif