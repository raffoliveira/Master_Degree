#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <utility>
#include "functions.h"

using namespace std;

//--------------------------------------------------------------------
//print vector int
void PrintVectorInt(vector<int> &vec)
{
    cout << "[";
    for (auto i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i < vec.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";
    cout << endl; //print new line
}

//--------------------------------------------------------------------
//print vector float
void PrintVectorFloat(vector<float> &vec)
{
    cout << "[";
    for (auto i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i < vec.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";
    cout << endl; //print new line
}

//--------------------------------------------------------------------
//print vector of pairs

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
when load the testing files, it just changes the variable path to your specific path and the filename
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
//ordering vector

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
//ordering vector

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
//find the element in vector

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
//return -1 if pattern not match with original string
//return first index of the match

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
//calculate the distance using Euclidean distance

float DistanceBetweenPoints(vector<pair<float, float>> &vec, auto i, auto j)
{
    return sqrt(pow(abs((vec[i].first - vec[j].first)), 2) + pow(abs((vec[i].second - vec[j].second)), 2));
}

//--------------------------------------------------------------------
//print the smallest distance and the pair of points

void BruteForceClosestPair(vector<pair<float, float>> &vec)
{
    vector<float> distances_min;                             //vector of minimum distances
    vector<pair<float, float>> points;                       //vector of points
    float distance;                                          //distance between two points
    vector<pair<float, vector<pair<float, float>>>> results; //vector with distance and your pairs of points

    for (auto i = 0; i < vec.size() - 1; i++) //calculate the all possibilities between two points
    {
        for (auto j = i + 1; j < vec.size(); j++)
        {
            distance = DistanceBetweenPoints(vec, i, j);              //calculate the distance
            distances_min.push_back(distance);                        //set distance in vector of distances
            points.push_back(make_pair(vec[i].first, vec[i].second)); //mount point i
            points.push_back(make_pair(vec[j].first, vec[j].second)); //mount point j
            results.push_back(make_pair(distance, points));           //push pair into vector
            points.clear();                                           //clear vector of points
        }
    }
    float distance_minimum = *min_element(distances_min.begin(), distances_min.end()); //find the smallest distance

    for (auto i = 0; i < results.size(); i++) //print result
    {
        if (results[i].first == distance_minimum)
        {
            cout << "The smallest distance is " << results[i].first << " between: ";
            PrintVectorOfPair(results[i].second);
        }
    }
}

//--------------------------------------------------------------------
//sort vector to convexhull

int SortVectorConvexHull(vector<pair<float, float>> &vec)
{
    vector<pair<float, float>> aux(vec);

    sort(aux.begin(), aux.end()); //ordering original vector

    for (size_t i = 0; i < vec.size(); i++)
    {
        if ((vec[i].first == aux[0].first) && (vec[i].second == aux[0].second))
        {
            return i;
        }
    }
}

bool CheckPointsInRight(vector<vector<float>> &matrix)
{
    //calculate determinant
    float det = 0; //result of determinant

    float x = ((matrix[1][1] * matrix[2][2]) - (matrix[2][1] * matrix[1][2]));
    float y = ((matrix[1][0] * matrix[2][2]) - (matrix[2][0] * matrix[1][2]));
    float z = ((matrix[1][0] * matrix[2][1]) - (matrix[2][0] * matrix[1][1]));

    det = ((matrix[0][0] * x) - (matrix[0][1] * y) + (matrix[0][2] * z));

    if (det < 0)
    {
        return true;
    }
    return false;
}

bool CheckPointsInLeft(vector<vector<float>> &matrix)
{
    //calculate determinant
    float det = 0; //result of determinant

    float x = ((matrix[1][1] * matrix[2][2]) - (matrix[2][1] * matrix[1][2]));
    float y = ((matrix[1][0] * matrix[2][2]) - (matrix[2][0] * matrix[1][2]));
    float z = ((matrix[1][0] * matrix[2][1]) - (matrix[2][0] * matrix[1][1]));

    det = ((matrix[0][0] * x) - (matrix[0][1] * y) + (matrix[0][2] * z));

    if (det >= 0)
    {
        return true;
    }
    return false;
}

//--------------------------------------------------------------------
//the argument is a vector of point
//return the vector H[1...h] with index of extreme points of convex hull
//based in algorithm gift wrapping
//pair<float, float> = pair.first representing the coord x and pair.second representing the coord y

vector<int> ConvexHull(vector<pair<float, float>> &vec)
{
    vector<int> extreme_points;              //vector of extreme points belong to convex hull
    vector<vector<float>> matrix;            //auxiliary matrix
    int number_extreme_points = 0;           //number of extreme points
    int i = std::numeric_limits<int>::max(); //iterator
    int n = vec.size();                      //size of the vector of points

    extreme_points.push_back(SortVectorConvexHull(vec)); //set the index of the smallest point
    while (i != extreme_points[0])                       //loop until find the first index. This means the convex full is closed
    {
        i = (extreme_points[number_extreme_points] % (number_extreme_points + 1)) + 1;

        for (int j = 0; j < n; j++)
        {
            //create a matrix
            matrix.push_back({vec[extreme_points[number_extreme_points]].first, vec[extreme_points[number_extreme_points]].second, 1});
            matrix.push_back({vec[i].first, vec[i].second, 1});
            matrix.push_back({vec[j].first, vec[j].second, 1});
            if (CheckPointsInRight(matrix))
            {
                i = j;
            }
            matrix.clear();
        }
        number_extreme_points++;
        extreme_points.push_back(i);
    }

    return extreme_points;
}
