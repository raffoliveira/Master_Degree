#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <utility>
#include "functions.h"

using namespace std;

//--------------------------------------------------------------------
void PrintVector(vector<float> &vec)
{
    for (auto i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << "|";
    }
    cout << endl; //print new line
}

//--------------------------------------------------------------------
void PrintVectorOfPair(vector<pair<float, float>> &vec)
{
    cout << "[";
    for (auto i = 0; i < vec.size(); i++)
    {
        cout << "(" << vec[i].first << "," << vec[i].second << ")";
    }
    cout << "]";
    cout << endl;
}

//--------------------------------------------------------------------
/*read file
when load the testing files, it just changes the variable path to your specific path
*/
vector<float> ReadingFile()
{

    vector<float> array;
    string line;
    string path = "/media/rafael/rafael_backup/rafaeloliveira/Documents/mestrado/disciplinas/PAA/listas/lista_2/testes/";
    fstream readFile(path + "small.txt");

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
void BubbleSort(vector<float> &vec)
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
void SelectionSort(vector<float> &vec)
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

//--------------------------------------------------------------------
float SequentialSearch2(vector<float> &vec, double number)
{

    for (auto i = 0; i < vec.size(); i++)
    {
        if (vec[i] == number)
        {
            return i;
        }
    }

    return -1;
}

//--------------------------------------------------------------------

int BruteForceStringMatch(string original, string pattern)
{
    int i, j = 0;
    for (i = 0; i < (original.size() - pattern.size()); i++)
    {
        for (j = 0; (j < pattern.size()) && (pattern[j] == original[i + j]); j++)
        {
        }

        if (j == pattern.size())
        {
            return i;
        }
    }
    return -1;
}

//--------------------------------------------------------------------
float DistanceBetweenPoints(vector<pair<float, float>> &vec, auto i, auto j)
{
    return sqrt(pow(abs((vec[i].first - vec[j].first)), 2) + pow(abs((vec[i].second - vec[j].second)), 2));
}

//--------------------------------------------------------------------

void BruteForceClosestPair(vector<pair<float, float>> &vec)
{
    vector<float> distances_min;
    vector<pair<float, float>> points;                       //distances minimun
    float distance;                                          //distance between two point
    vector<pair<float, vector<pair<float, float>>>> results; //result

    for (auto i = 0; i < vec.size() - 1; i++)
    {
        for (auto j = i + 1; j < vec.size(); j++)
        {
            distance = DistanceBetweenPoints(vec, i, j);
            distances_min.push_back(distance); //set distance in vector of distances
            points.push_back(make_pair(vec[i].first, vec[i].second));
            points.push_back(make_pair(vec[j].first, vec[j].second));
            results.push_back(make_pair(distance, points)); //push pair into vector
            points.clear();
        }
    }
    float distance_minimum = *min_element(distances_min.begin(), distances_min.end()); //find the smallest distance

    for (auto i = 0; i < results.size(); i++)
    {
        if (results[i].first == distance_minimum)
        {
            cout << "The smallest distance is " << results[i].first << " between: ";
            PrintVectorOfPair(results[i].second);
        }
    }
}
