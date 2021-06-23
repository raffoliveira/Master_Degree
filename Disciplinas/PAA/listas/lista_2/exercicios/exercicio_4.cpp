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
    string original;
    string pattern;

    cout << "Enter a string: ";
    cin >> original;
    cout << "Enter a pattern: ";
    cin >> pattern;

    bruteForceStringMatch(original, pattern);

    return 0;
}
