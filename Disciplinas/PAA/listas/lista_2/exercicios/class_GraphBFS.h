#pragma once
#include <list>

class GraphBFS
{
    int vertex;               //number of vertex
    std::list<int> *list_adj; //point to vector of adjacency list

public:
    GraphBFS(int vertex);                                       //construct
    void addArrestBFS(int vertex1, int vertex2);                //add an arrest into graph
    bool breadthFirstSearchBFS(int initial_vertex, int target); //make a BFS from a vertex
};
