#include "functions.h"

int main()
{
    //std::vector<float> arr = readingFileFloat();
    //std::vector<std::string> arr = readingFileString();
    std::vector<std::string> arr = {"f", "j", "a1", "a2", "j1"};

    std::cout << "Original vector:" << std::endl;
    printVector(arr);
    mergeSort(arr, 0, arr.size() - 1);
    std::cout << "Ordered Data:" << std::endl;
    printVector(arr);

    return 0;
}