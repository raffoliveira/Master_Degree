#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <utility>
#include <string>

template <typename T>
void printVector(std::vector<T> &);
template <typename T>
void printVectorOfPair(std::vector<std::pair<T, T>> &);
template <typename T>
void selectionSort(std::vector<T> &);
template <typename T>
void bubbleSort(std::vector<T> &);
std::vector<float> readingFileFloat();
std::vector<std::string> readingFileString();
template <typename T>
float sequentialSearch(std::vector<T> &, T);
void bruteForceStringMatch(std::string, std::string);
void bruteForceClosestPair(std::vector<std::pair<float, float>> &vec);
std::vector<int> convexHull(std::vector<std::pair<float, float>> &vec);
void travellingSalesmanProblem(std::vector<std::vector<float>> vec, float aux, int number_city);
int sortVectorConvexHull(std::vector<std::pair<float, float>> &vec);
float distanceBetweenPoints(std::vector<std::pair<float, float>> &vec, auto i, auto j);
bool checkPointsInRight(std::vector<std::vector<float>> &matrix);

#endif