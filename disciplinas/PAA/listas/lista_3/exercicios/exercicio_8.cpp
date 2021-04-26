#include "functions.h"
#include "functions.cpp"

using namespace std;

int main()
{
    int index, number_elements = 6;
    float value;
    vector<int> vec(number_elements);

    srand(unsigned(time(0))); //different outputs

    generate(vec.begin(), vec.end(), randomNumber); //generate a vector of random number
    cout << "Vector original: ";
    printVector(vec);

    int l = 0, r = vec.size() - 1;

    value = selectMedian(vec, l, r);
    cout << "The median is " << value << endl;

    sort(vec.begin(), vec.end());
    cout << "Vector: ";
    printVector(vec);

    return 0;
}