#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <utility>

void PrintVector(std::vector<float> &vec);
void PrintVectorOfPair(std::vector<std::pair<float, float>> &vec);
void BubbleSort(std::vector<float> &vec);
void SelectionSort(std::vector<float> &vec);
void BruteForceClosestPair(std::vector<std::pair<float, float>> &vec);
float SequentialSearch2(std::vector<float> &vec, double number);
int BruteForceStringMatch(std::string original, std::string pattern);
float DistanceBetweenPoints(std::vector<std::pair<float, float>> &vec, auto i, auto j);
std::vector<float> ReadingFile();

#endif