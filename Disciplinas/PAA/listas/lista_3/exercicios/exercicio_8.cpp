#include "functions.h"
#include "functions.cpp"

using namespace std;

int main()
{
    int index, number_elements = 7;
    float value;
    vector<int> vec(number_elements);

    srand(unsigned(time(0))); //different outputs

    generate(vec.begin(), vec.end(), randomNumber); //generate a vector of random number
    cout << "Original vector: ";
    printVector(vec);

    float p = 0.5;
    int l = 0, r = vec.size(), k = ceil((vec.size() - 1) * p);

    value = quickSelect(vec, l, r, k);

    cout << "The median is " << value << endl;

    sort(vec.begin(), vec.end());
    cout << "Ordered vector: ";
    printVector(vec);

    return 0;
}