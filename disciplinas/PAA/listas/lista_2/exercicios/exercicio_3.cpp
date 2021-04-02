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
    double number;
    float result;

    cout << "Enter a number:";
    cin >> number;

    result = SequentialSearch2(arr, number);

    if (result != -1)
    {
        cout << "The number " << number << " is in position " << result << " of the array.\n";
    }
    else
    {
        cout << "The number " << number << " is not in the array.\n";
    }

    return 0;
}
