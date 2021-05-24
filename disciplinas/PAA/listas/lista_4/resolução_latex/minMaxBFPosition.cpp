template <typename T>
void minMaxBruteForcePosition(std::vector<T> &vec, std::pair<int, int> &minMax)
{
    minMax = std::make_pair(0, 0);

    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] < vec[minMax.first])
        {
            minMax.first = i;
        }
        else if (vec[i] > vec[minMax.second])
        {
            minMax.second = i;
        }
    }
}