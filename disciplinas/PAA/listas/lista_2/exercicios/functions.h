#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <utility>

void PrintVectorInt(std::vector<int> &vec);
void PrintVectorFloat(std::vector<float> &vec);
void PrintVectorOfPair(std::vector<std::pair<float, float>> &vec);
void BubbleSort(std::vector<float> &vec);
void SelectionSort(std::vector<float> &vec);
void BruteForceClosestPair(std::vector<std::pair<float, float>> &vec);
float SequentialSearch2(std::vector<float> &vec, double number);
int BruteForceStringMatch(std::string original, std::string pattern);
int SortVectorConvexHull(std::vector<std::pair<float, float>> &vec);
float DistanceBetweenPoints(std::vector<std::pair<float, float>> &vec, auto i, auto j);
bool CheckPointsInRight(std::vector<std::vector<float>> &matrix);
bool CheckPointsInLeft(std::vector<std::vector<float>> &matrix);
std::vector<float> ReadingFile();
std::vector<int> ConvexHull(std::vector<std::pair<float, float>> &vec);

#endif