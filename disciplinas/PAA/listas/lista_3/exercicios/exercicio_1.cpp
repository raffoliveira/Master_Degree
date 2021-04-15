#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "functions.h"
#include "functions.cpp"

using namespace std;

int main()
{
    // vector<float> arr = readingFileFloat();
    vector<string> arr = readingFileString();

    cout << "Original Data:" << endl;
    printVector(arr);
    cout << endl;
    cout << "Sorted Data:" << endl;
    insertionSort(arr);
    printVector(arr);
    cout << endl;
    return 0;
}
