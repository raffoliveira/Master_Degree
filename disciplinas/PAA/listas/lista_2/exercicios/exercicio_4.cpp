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
    string original;
    string pattern;

    cout << "Enter a string:";
    cin >> original;
    cout << "Enter a pattern:";
    cin >> pattern;

    int result = BruteForceStringMatch(original, pattern);

    if (result != -1)
    {
        cout << "The pattern " << pattern << " starts at position " << result << " of the original.\n";
    }
    else
    {
        cout << "The pattern " << pattern << " wasn't found in the original.\n";
    }

    return 0;
}
