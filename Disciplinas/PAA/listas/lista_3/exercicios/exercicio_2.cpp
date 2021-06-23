#include "functions.h"
#include "functions.cpp"

using namespace std;

int main()
{
    vector<vector<int>> result;
    vector<int> vec = {1, 2, 3, 4};

    johnsonTrotter(result, vec);
    printVectorOfVector(result);
    cout << "Size of result: " << result.size() << endl;

    return 0;
}
