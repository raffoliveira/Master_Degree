#include "functions.h"
#include "functions.cpp"

using namespace std;

int main()
{

    vector<int> vec(1000, 3);
    vec[1005] = 1;

    int result = fakeCoin(vec, 0, vec.size());
    cout << "The index of the fake coin is " << result << endl;

    return 0;
}
