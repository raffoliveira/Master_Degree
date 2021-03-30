#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

void PrintVector(std::vector<int> vec);
void PrintVectorOfVector(std::vector<std::vector<float>> vec);
void BubbleSort(std::vector<int> &vec);
void SelectionSort(std::vector<int> &vec);
void BruteForceClosestPair(std::vector<std::vector<float>> vec);
int SequentialSearch2(std::vector<int> vec, double number);
int BruteForceStringMatch(std::string original, std::string pattern);
float DistanceBetweenPoints(std::vector<std::vector<float>> vec, size_t i, size_t j);
std::vector<int> ReadingFile();

#endif