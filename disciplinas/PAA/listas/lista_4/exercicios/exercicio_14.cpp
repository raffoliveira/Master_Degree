#include "functions.h"

int main()
{
    std::vector<std::pair<float, float>> vec;
    std::vector<std::pair<float, float>> result;
    int number_points = 20;
    float x, y;

    srand((unsigned int)time(0));

    for (int i = 0; i < number_points; i++)
    {
        x = rand() % 50;
        y = rand() % 50;
        vec.push_back({x, y});
    }
    // vec = {std::make_pair(0, 3),
    //        std::make_pair(1, 1),
    //        std::make_pair(2, 2),
    //        std::make_pair(4, 4),
    //        std::make_pair(0, 0),
    //        std::make_pair(1, 2),
    //        std::make_pair(3, 1),
    //        std::make_pair(3, 3)};
    findQuickHull(vec, result);
    printVectorOfpair(result);

    return 0;
}