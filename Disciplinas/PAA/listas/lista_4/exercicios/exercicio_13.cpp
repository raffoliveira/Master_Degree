#include "functions.h"

int main()
{
    std::vector<std::vector<int>> a = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> b = {{5, 6}, {7, 8}};
    std::vector<std::vector<int>> result;

    strassenMatrix(a, b, result);
    printVectorOfVector(result);

    // std::vector<std::vector<int>> c = {{1, 2, 3}, {6, 5, 6}};
    // std::vector<std::vector<int>> d = {{3}, {4}, {5}};
    // std::vector<std::vector<int>> e(c.size(), std::vector<int>(d[0].size(), 0));

    // multiplicationMatrixBF(c, d, e);
    // printVectorOfVector(e);

    return 0;
}