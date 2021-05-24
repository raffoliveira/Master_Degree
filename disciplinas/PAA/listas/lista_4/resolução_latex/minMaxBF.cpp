template <typename T>
void minMaxBruteForce(std::vector<T> &vec, std::pair<T, T> &minMax)
{
    minMax = std::make_pair(vec[0], vec[0]);

    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] < minMax.first)
        {
            minMax.first = vec[i];
        }
        else if (vec[i] > minMax.second)
        {
            minMax.second = vec[i];
        }
    }
}