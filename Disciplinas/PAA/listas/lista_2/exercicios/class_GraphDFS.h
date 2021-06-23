#pragma once
#include <list>

class GraphDFS
{
    int vertex;               //number of vertex
    std::list<int> *list_adj; //point to vector of adjacency list

public:
    GraphDFS(int vertex);                                       //construct
    void addArrestDFS(int vertex1, int vertex2);                //add an arrest into graph
    bool breadthFirstSearchDFS(int initial_vertex, int target); //make a BFS from a vertex
};