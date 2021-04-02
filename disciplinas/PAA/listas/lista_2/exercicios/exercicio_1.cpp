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
    PrintVectorFloat(arr);
    BubbleSort(arr);
    PrintVectorFloat(arr);

    return 0;
}
