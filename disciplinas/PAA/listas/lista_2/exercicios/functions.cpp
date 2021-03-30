#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <cmath>
#include <utility>
#include "functions.h"
#include <bits/stdc++.h>

using namespace std;

//--------------------------------------------------------------------
//print vector
void PrintVector(vector<int> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << "|";
    }
    cout << endl; //print new line
}

//--------------------------------------------------------------------
//print vector of vector
void PrintVectorOfVector(vector<vector<float>> vec)
{
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << "(";
        for (size_t j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j];
            if (j != vec[i].size() - 1)
            {
                cout << ",";
            }
        }
        cout << ")";
        if (i != vec.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]";
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

//--------------------------------------------------------------------

int SequentialSearch2(vector<int> vec, double number)
{

    for (size_t i = 0; i < vec.size(); i++)
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

float DistanceBetweenPoints(vector<vector<float>> vec, size_t i, size_t j)
{
    return sqrt(pow((vec[i][j] - vec[i + 1][j]), 2) + pow((vec[i][j + 1] - vec[i + 1][j + 1]), 2));
}

//--------------------------------------------------------------------

void BruteForceClosestPair(vector<vector<float>> vec)
{
    cout << "arrived";
    vector<float> distances_min;                        //distances minimun
    vector<float> point;                                //one point
    vector<vector<float>> pair_points;                  //pair of two points
    float distance;                                     //distance between two point
    vector<pair<float, vector<vector<float>>>> results; //result

    if (vec.size() < 2)
    {
        cout << "Vector has one pair. Please insert more than one!";
    }

    for (size_t i = 0; i < vec.size(); i++)
    {
        for (size_t j = 0; j < vec[i].size(); j++)
        {
            distance = DistanceBetweenPoints(vec, i, j);
            distances_min.push_back(distance); //set distance in vector of distances
            point.push_back(vec[i][j]);        //mount first point
            point.push_back(vec[i][j + 1]);
            pair_points.push_back(point);   //push in vector of points
            point.clear();                  //clear point
            point.push_back(vec[i + 1][j]); //mount second point
            point.push_back(vec[i + 1][j + 1]);
            pair_points.push_back(point);                        //push in vector of points
            point.clear();                                       //clear point
            results.push_back(make_pair(distance, pair_points)); //push pair into vector
        }
    }
    float distance_minimun = *min_element(distances_min.begin(), distances_min.end()); //find the smallest distance

    vector<pair<float, vector<vector<float>>>>::iterator it = find_if(results.begin(), results.end(),
                                                                      [&distance_minimun](const pair<float, vector<vector<float>>> &element) { return element.first == distance_minimun; });
    cout << "The pair ";
    PrintVectorOfVector((*it).second);
    cout << "has " << (*it).first << "as the smallest distance." << endl;
}
