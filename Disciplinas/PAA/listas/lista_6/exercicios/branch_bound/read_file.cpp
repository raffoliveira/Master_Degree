#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

template <typename T>
void printVectorOfVector(std::vector<std::vector<T>> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << "[";
        for (int j = 0; j < vec[i].size(); j++)
        {
            std::cout << vec[i][j];
            if (j < vec[i].size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]";
        std::cout << std::endl; //print new line
    }

    std::cout << std::endl; //print new line
}

void readFile(std::vector<std::vector<int>> &matrix, std::string file, int header, int number_cities)
{
    std::string line;
    int count = 1;
    std::ifstream myfile(file);

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if (count > header && line != "EOF")
            {
                // std::vector<int> linedata;
                std::stringstream lineStream(line);
                int value, col = 0;

                while (lineStream >> value)
                {
                    // linedata.push_back(value);
                    matrix[count - header - 1][col] = value;
                    // matrix[col][count - header - 1] = value;
                    ++col;
                }

                // if (linedata.size() < number_cities)
                // {
                //     for (int i = linedata.size(); i < number_cities; ++i)
                //     {
                //         linedata.push_back(0);
                //     }
                // }

                // matrix.push_back(linedata);
            }

            count++;
        }
        myfile.close();
    }
    else
    {
        std::cout << "Unable to open file";
    }
}

int main()
{
    std::string myfile = "brazil10.tsp";
    // long double result = 1;
    // int header = 7, number_cities = 10;
    // std::vector<std::vector<int>> matrix(number_cities, std::vector<int>(number_cities, 0));

    // readFile(matrix, myfile, header, number_cities);

    // printVectorOfVector(matrix);

    // for (int i = 1; i < matrix.size(); ++i)
    // {
    //     result *= i;
    // }

    // std::cout << "This instance has " << result << " routes" << std::endl;

    std::vector<int> v({1, 2, 3});

    std::cout << v.front();

    return 0;
}