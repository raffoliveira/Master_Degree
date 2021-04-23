#include "functions.h"
#include "functions.cpp"

using namespace std;

int main()
{
    vector<pair<float, float>> vec;
    int number_points = 20;
    float x, y;

    srand((unsigned int)time(0));

    for (int i = 0; i < number_points; i++)
    {
        x = rand() % 50;
        y = rand() % 50;
        vec.push_back(make_pair(x, y));
    }

    cout << "Vector of points: ";
    printVectorOfPair(vec);
    vector<int> result = convexHull(vec);
    cout << "The index of the points belonging to convex hull are:" << endl;
    printVector(result);

    return 0;
}
