#include <iostream>
#include <iomanip> // for setw() and ws
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

/* function prototype(s) */
void solveit(std::ifstream &);
void addContents(std::ifstream &);

int main(int argc, char *argv[])
{
    std::ifstream datafile{argv[1]}; /* first arg is filename */
    addContents(datafile);
    datafile.close();
    return 0;
}

void addContents(std::ifstream &ff)
{
    std::vector<int> xCord;
    std::vector<int> yCord;
    int xCurrentLine;
    int yCurrentLine;
    int cityNumber;
    int numberCities;
    ff >> numberCities;
    for (int i = 0; i < numberCities; i++)
    {
        ff >> cityNumber;
        ff >> xCurrentLine;
        ff >> yCurrentLine;
        //do whatever you wanted to do with cityNumber
        xCord.push_back(xCurrentLine);
        yCord.push_back(yCurrentLine);
    }
    for (int i = 0; i < xCord.size(); i++)
    {
        std::cout << xCord.at(i) << " " << yCord.at(i) << std::endl;
    }
}