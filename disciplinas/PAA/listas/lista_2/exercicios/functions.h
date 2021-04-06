#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <utility>
#include <list>

void PrintVectorInt(std::vector<int> &vec);
void PrintVectorFloat(std::vector<float> &vec);
void PrintVectorOfPair(std::vector<std::pair<float, float>> &vec);
void BubbleSort(std::vector<float> &vec);
void SelectionSort(std::vector<float> &vec);
void BruteForceClosestPair(std::vector<std::pair<float, float>> &vec);
void TravellingSalesmanProblem(std::vector<std::vector<float>> vec, float aux, int number_city);
int BruteForceStringMatch(std::string original, std::string pattern);
int SortVectorConvexHull(std::vector<std::pair<float, float>> &vec);
float DistanceBetweenPoints(std::vector<std::pair<float, float>> &vec, auto i, auto j);
float SequentialSearch2(std::vector<float> &vec, double number);
bool CheckPointsInRight(std::vector<std::vector<float>> &matrix);
bool CheckPointsInLeft(std::vector<std::vector<float>> &matrix);
std::vector<float> ReadingFile();
std::vector<int> ConvexHull(std::vector<std::pair<float, float>> &vec);

class GraphBFS
{
    int vertex;               //number of vertex
    std::list<int> *list_adj; //point to vector of adjacency list

public:
    GraphBFS(int vertex);                                       //construct
    void addArrestBFS(int vertex1, int vertex2);                //add an arrest into graph
    bool breadthFirstSearchBFS(int initial_vertex, int target); //make a BFS from a vertex
};

class GraphDFS
{
    int vertex;               //number of vertex
    std::list<int> *list_adj; //point to vector of adjacency list

public:
    GraphDFS(int vertex);                                       //construct
    void addArrestDFS(int vertex1, int vertex2);                //add an arrest into graph
    bool breadthFirstSearchDFS(int initial_vertex, int target); //make a BFS from a vertex
};

#endif