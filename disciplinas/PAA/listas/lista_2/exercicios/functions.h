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
template <typename T>
float sequentialSearch(std::vector<T> &, T);
void bruteForceStringMatch(std::string, std::string);
void bruteForceClosestPair(std::vector<std::pair<float, float>> &);
void travellingSalesmanProblem(std::vector<std::vector<float>> &, float, int);
int sortVectorConvexHull(std::vector<std::pair<float, float>> &);
float distanceBetweenPoints(std::vector<std::pair<float, float>> &, auto, auto);
float knapSackProblem(float, std::vector<float> &, std::vector<float> &, int);
bool checkPointsInRight(std::vector<std::vector<float>> &);
std::vector<int> convexHull(std::vector<std::pair<float, float>> &);
std::vector<float> readingFileFloat();
std::vector<std::string> readingFileString();

#endif