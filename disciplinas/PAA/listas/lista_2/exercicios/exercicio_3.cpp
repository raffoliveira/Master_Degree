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
    vector<float> arr = readingFileFloat();
    // vector<string> arr = readingFileString();
    float number;
    string word;
    float result;

    cout << "Enter a number: ";
    cin >> number;
    // cout << "Enter a string: ";
    // cin >> word;

    result = sequentialSearch(arr, number);
    // result = sequentialSearch(arr, word);

    if (result != -1)
    {
        cout << "The number " << number << " is at position " << result << " of the array.\n";
        // cout << "The string " << word << " is at position " << result << " of the array.\n";
    }
    else
    {
        cout << "The number " << number << " is not in the array.\n";
        // cout << "The string " << word << " is not in the array.\n";
    }

    return 0;
}
