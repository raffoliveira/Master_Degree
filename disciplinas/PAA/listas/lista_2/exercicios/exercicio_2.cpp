//Algoritmo bublesort

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "functions.h"

using namespace std;

int main()
{
    vector<float> arr = ReadingFile();
    PrintVector(arr);
    SelectionSort(arr);
    PrintVector(arr);

    return 0;
}
