#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <utility>
#include "functions.h"

using namespace std;

int main()
{
    int number_vertex, vertex1, vertex2, target, number_edges, initial_vertex;

    cout << "Enter the number of vertex: ";
    cin >> number_vertex;
    cout << endl;

    GraphDFS graph(number_vertex);

    cout << "Now you are going to enter the edges!";
    cout << endl;
    cout << "How many edges do you need? ";
    cin >> number_edges;
    cout << endl;

    while (number_edges > 0)
    {
        cout << "Enter the vertex: ";
        cin >> vertex1;
        cout << endl;
        cout << "Now, " << vertex1 << " is connected with vertex: ";
        cin >> vertex2;
        cout << endl;
        graph.addArrestDFS(vertex1, vertex2);
        number_edges--;
    }

    cout << "Now, enter the value you want to find: ";
    cin >> target;
    cout << endl;
    cout << "I almost forgot, what value do you want I start looking for? ";
    cin >> initial_vertex;
    cout << endl;

    bool result = graph.breadthFirstSearchDFS(initial_vertex, target);
    if (result)
    {
        cout << "The value " << target << " was found!!!" << endl;
    }
    else
    {
        cout << "The value " << target << " was not found!!!" << endl;
    }

    return 0;
}
