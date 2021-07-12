// reading a text file
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

void readFile(std::vector<std::vector<int>> &matrix, std::string file)
{
    std::string line;
    int count = 1;
    std::ifstream myfile(file);

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if (count > 7 && line != "EOF")
            {
                std::vector<int> linedata;
                std::stringstream lineStream(line);
                int value;

                while (lineStream >> value)
                {
                    linedata.push_back(value);
                }

                if (linedata.size() < 57)
                {
                    for (int i = linedata.size(); i < 57; ++i)
                    {
                        linedata.push_back(0);
                    }
                }

                matrix.push_back(linedata);
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
    std::string myfile = "brazil58.tsp";
    std::vector<std::vector<int>> matrix;
    long double result = 1;

    readFile(matrix, myfile);

    for (int i = 1; i < matrix.size(); ++i)
    {
        result *= i;
    }

    std::cout << "This instance has " << result << " routes" << std::endl;

    return 0;
}