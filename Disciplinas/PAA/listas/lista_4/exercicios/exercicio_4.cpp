#include "functions.h"

int main()
{
    std::vector<float> arr = readingFileFloat();
    //std::vector<std::string> arr = readingFileString();
    //std::vector<std::string> arr = {"f", "j", "a1", "a2", "j1"};
    //std::vector<float> arr = {80, 5, 80, 4, 80, 74, 80, 66, 80, 11, 55, 80, 40, 80};

    std::pair<float, float> minMax;
    //std::pair<std::string, std::string> minMax;

    // minMaxDivideConquer(arr, 0, arr.size() - 1, minMax);
    minMaxBruteForce(arr, minMax);

    std::cout << "Minimum element:" << minMax.first << std::endl;
    std::cout << "Maximum element:" << minMax.second << std::endl;
    printVector(arr);
    return 0;
}