#include "functions.h"

int main()
{

    //std::vector<float> arr = readingFileFloat();
    //std::vector<std::string> arr = readingFileString();
    std::vector<std::string> arr = {"f", "j", "a1", "a2", "j1"};
    //std::vector<float> arr = {80, 5, 80, 4, 80, 74, 80, 66, 80, 11, 55, 80, 40, 80};
    //std::vector<float> arr = {80, 5};
    //std::vector<float> arr = {80};

    printVector(arr);
    quickSort(arr, 0, arr.size() - 1);
    printVector(arr);

    return 0;
}