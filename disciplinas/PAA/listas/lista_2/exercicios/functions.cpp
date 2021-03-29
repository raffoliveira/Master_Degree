#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include "functions.h"

using namespace std;

//--------------------------------------------------------------------
//print vector
void PrintVector(vector<int> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << "|";
    }
    cout << endl;
}

//--------------------------------------------------------------------
/*read file
when load the testing files, it just changes the variable path to your specific path
*/
vector<int> ReadingFile()
{

    vector<int> array;
    string line;
    string path = "/media/rafael/rafael_backup/rafaeloliveira/Documents/mestrado/disciplinas/PAA/listas/lista_2/testes/";
    fstream readFile(path + "big.txt");

    if (readFile.is_open())
    {
        while (getline(readFile, line)) //reading line by line
        {
            if (line.size() > 0)
            {
                int number = stoi(line); //casting from string to int
                array.push_back(number);
            }
        }
        readFile.close();
    }
    return array;
}

//--------------------------------------------------------------------

void BubbleSort(vector<int> &vec)
{
    int temp = 0;

    for (size_t i = 0; i < vec.size(); i++)
    {
        for (size_t j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[i]) //check if previous element is smaller than actual
            {
                temp = vec[i]; //swap elements
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
}

//--------------------------------------------------------------------
void SelectionSort(vector<int> &vec)
{
    int min = 0;
    int temp = 0;

    for (size_t i = 0; i < vec.size(); i++)
    {
        min = i;
        for (size_t j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[min])
            {
                min = j;
            }
        }
        temp = vec[i];
        vec[i] = vec[min];
        vec[min] = temp;
    }
}