#include "functions.h"
#include "functions.cpp"

using namespace std;

int main()
{
    int index, number_elements = 20;
    int value;
    vector<float> vec(number_elements);

    srand(unsigned(time(0))); //different outputs

    generate(vec.begin(), vec.end(), randomNumber); //generate a vector of random number
    sort(vec.begin(), vec.end());
    cout << "Vector: ";
    printVector(vec);

    cout << "Enter the value you are looking for: ";
    cin >> value;
    index = interpolationSearch(vec, value);

    if (index != -1)
    {
        cout << "The value found in index " << index << endl;
    }
    else
    {
        cout << "The value wasn't found" << endl;
    }

    return 0;
}