#include "functions.h"

int main()
{
    std::vector<std::pair<int, int>> vec;
    std::set<std::pair<int, int>> result;
    int number_points = 30;
    int x, y;

    srand((unsigned int)time(0));

    for (int i = 0; i < number_points; i++)
    {
        x = rand() % 50;
        y = rand() % 50;
        vec.push_back({x, y});
    }

    quickHull(vec, result);
    printVectorOfpair(vec);
    printSetOfpair(result);

    return 0;
}