#include "functions.h"
#include "functions.cpp"

using namespace std;

int main()
{
    int n;
    cout << "Enter the number to generate the permutation: ";
    cin >> n;

    vector<vector<int>> result;
    vector<int> item;

    for (int i = 0; i <= n; i++)
    {
        item.push_back(i);
    }
    result.push_back(item);

    // auto start = chrono::system_clock::now();
    lexicographicPermute(result, item);
    printVectorOfVector(result);
    // auto finish = chrono::system_clock::now();

    // chrono::duration<double> duration = finish - start;
    // cout << "Time: " << duration.count() << endl;

    return 0;
}
