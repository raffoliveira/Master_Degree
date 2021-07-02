#include "functions.h"
#include "class_GraphBFS.h"
#include "class_GraphDFS.h"

using namespace std;

//-------------------------------print vector-------------------------------------

template <typename T>
void printVector(vector<T> &vec)
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

//-------------------------------print vector of pairs-------------------------------------

template <typename T>
void printVectorOfPair(vector<pair<T, T>> &vec)
{
    cout << "[";
    for (auto i = 0; i < vec.size(); i++)
    {
        cout << "(" << vec[i].first << "," << vec[i].second << ")";
    }
    cout << "]";
    cout << endl;
}

//----------------------------reading file----------------------------------------
//when load the testing files, it just changes the variable path to your specific path and the filename

vector<float> readingFileFloat()
{

    vector<float> array;
    string line;
    string path = "/media/rafael/rafael_backup/rafaeloliveira/Documents/mestrado/disciplinas/PAA/listas/lista_2/testes/";
    fstream readFile(path + "medium.txt");

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

//---------------------------------reading file-----------------------------------------
//when load the testing files, it just changes the variable path to your specific path and the filename

vector<string> readingFileString()
{

    vector<string> array;
    string line;
    string path = "/media/rafael/rafael_backup/rafaeloliveira/Documents/mestrado/disciplinas/PAA/listas/lista_2/testes/";
    fstream readFile(path + "names.txt");

    if (readFile.is_open())
    {
        while (getline(readFile, line)) //reading line by line
        {
            if (line.size() > 0)
            {
                array.push_back(line);
            }
        }
        readFile.close();
    }
    return array;
}

//----------------------------ordering vector - Bubble Sort----------------------------------------

template <typename T>
void bubbleSort(vector<T> &vec)
{
    int temp = 0;

    for (size_t i = 0; i < vec.size(); i++)
    {
        for (size_t j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[i]) //check if previous element is smaller than actual
            {
                swap(vec[i], vec[j]);
                // temp = vec[i]; //swap elements
                // vec[i] = vec[j];
                // vec[j] = temp;
            }
        }
    }
}

//----------------------------ordering vector - Selection Sort----------------------------------------

template <typename T>
void selectionSort(vector<T> &vec)
{
    int min = 0;
    int temp = 0;

    for (auto i = 0; i < vec.size(); i++)
    {
        min = i;
        for (auto j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[min])
            {
                min = j;
            }
        }
        swap(vec[i], vec[min]);
        // temp = vec[i];
        // vec[i] = vec[min];
        // vec[min] = temp;
    }
}

//------------------------find the element in vector--------------------------------------------

template <typename T>
float sequentialSearch(vector<T> &vec, T number)
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

//-------------------------find match pattern in string-------------------------------------------
//return if pattern not match with original string
//return first index of the match

void bruteForceStringMatch(string original, string pattern)
{
    int i, j;
    for (i = 0; i <= (original.size() - pattern.size()); i++)
    {
        for (j = 0; j < pattern.size(); j++)
        {
            if (original[i + j] != pattern[j])
            {
                break;
            }
        }
        if (j == pattern.size())
        {
            cout << "Pattern found at index " << i << endl;
            return;
        }
    }
    cout << "Pattern not found!" << endl;
}

//--------------------------calculate the distance using Euclidean distance------------------------------------------

float distanceBetweenPoints(vector<pair<float, float>> &vec, int i, int j)
{
    return sqrt(pow(abs((vec[i].first - vec[j].first)), 2) + pow(abs((vec[i].second - vec[j].second)), 2));
}

//------------------------print the smallest distance and the pair of points--------------------------------------------

void bruteForceClosestPair(vector<pair<float, float>> &vec)
{
    vector<float> distances_min;                             //vector of minimum distances
    vector<pair<float, float>> points;                       //vector of points
    float distance;                                          //distance between two points
    vector<pair<float, vector<pair<float, float>>>> results; //vector with distance and your pairs of points

    for (int i = 0; i < vec.size() - 1; i++) //calculate the all possibilities between two points
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            distance = distanceBetweenPoints(vec, i, j);              //calculate the distance
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
            printVectorOfPair(results[i].second);
        }
    }
}

//-----------------------------sort vector to convexhull---------------------------------------

int sortVectorConvexHull(vector<pair<float, float>> &vec)
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

//-----------------------------check if points are in right side of a line---------------------------------------

bool checkPointsInRight(vector<vector<float>> &matrix)
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

//------------------------------------calculate convex hull--------------------------------
//the argument is a vector of point
//return the vector H[1...h] with index of extreme points of convex hull
//based in algorithm gift wrapping
//pair<float, float> = pair.first representing the coord x and pair.second representing the coord y

vector<int> convexHull(vector<pair<float, float>> &vec)
{
    vector<int> extreme_points;              //vector of extreme points belong to convex hull
    vector<vector<float>> matrix;            //auxiliary matrix
    int number_extreme_points = 0;           //number of extreme points
    int i = std::numeric_limits<int>::max(); //iterator
    int n = vec.size();                      //size of the vector of points

    extreme_points.push_back(sortVectorConvexHull(vec)); //set the index of the smallest point
    while (i != extreme_points[0])                       //loop until find the first index. This means the convex full is closed
    {
        i = (extreme_points[number_extreme_points] % (number_extreme_points + 1)) + 1;

        for (int j = 0; j < n; j++)
        {
            //create a matrix
            matrix.push_back({vec[extreme_points[number_extreme_points]].first, vec[extreme_points[number_extreme_points]].second, 1});
            matrix.push_back({vec[i].first, vec[i].second, 1});
            matrix.push_back({vec[j].first, vec[j].second, 1});
            if (checkPointsInRight(matrix))
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

//--------------------------------------------------------------------

GraphBFS::GraphBFS(int vertex) //construct
{
    this->vertex = vertex;            //set the number of vertex
    list_adj = new list<int>[vertex]; //creating the vector
    // list_adj.push_back(vertex);
}

//--------------------------------------------------------------------

void GraphBFS::addArrestBFS(int vertex1, int vertex2) //add an arrest into graph
{
    list_adj[vertex1].push_back(vertex2); //add vertex2 into the vertex1 adjacency list
}

//--------------------------------------------------------------------

bool GraphBFS::breadthFirstSearchBFS(int initial_vertex, int target) //make a BFS from a initial vertex
{
    queue<int> queue_BFS;
    vector<bool> visited_vertex(vertex);

    for (auto i = 0; i < vertex; i++) //set all vertex as false
    {
        visited_vertex.push_back(false);
    }

    if (initial_vertex == target) //find the target if it is root
    {
        cout << "Visiting vertex " << initial_vertex << "..." << endl;
        return true;
    }

    while (true)
    {
        list<int>::iterator it;
        for (it = list_adj[initial_vertex].begin(); it != list_adj[initial_vertex].end(); it++)
        {
            if (!visited_vertex[*it])
            {
                cout << "Visiting vertex " << *it << "..." << endl;
                if ((*it) == target) //find the target
                {
                    return true;
                }
                auto position_visited = visited_vertex.begin() + (*it);
                visited_vertex.insert(position_visited, true); //mark as visited vertex
                queue_BFS.push(*it);                           //insert into queue
            }
        }

        if (!queue_BFS.empty())
        {                                       //check if the queue is empty
            initial_vertex = queue_BFS.front(); //take the first element
            queue_BFS.pop();                    //remove the vertex of the queue
        }
        else
        {
            return false;
        }
    }
}

//--------------------------------------------------------------------

GraphDFS::GraphDFS(int vertex) //construct
{
    this->vertex = vertex;            //set the number of vertex
    list_adj = new list<int>[vertex]; //creating the vector
}

//--------------------------------------------------------------------

void GraphDFS::addArrestDFS(int vertex1, int vertex2) //add an arrest into graph
{
    list_adj[vertex1].push_back(vertex2); //add vertex2 into the vertex1 adjacency list
}

//--------------------------------------------------------------------

bool GraphDFS::breadthFirstSearchDFS(int initial_vertex, int target) //make a DFS from a initial vertex
{
    stack<int> stack_DFS;
    vector<bool> visited_vertex(vertex);

    for (auto i = 0; i < vertex; i++) //set all vertex as false
    {
        visited_vertex.push_back(false);
    }

    if (initial_vertex == target) //find the target if it is a root
    {
        cout << "Visiting vertex " << initial_vertex << "..." << endl;
        return true;
    }
    while (true)
    {
        if (!visited_vertex[initial_vertex])
        {
            cout << "Visiting vertex " << initial_vertex << "..." << endl;
            if (visited_vertex[initial_vertex] == target)
            {
                return true;
            }
            auto position = visited_vertex.begin() + initial_vertex;
            visited_vertex.insert(position, true); //mark as visited vertex
            stack_DFS.push(initial_vertex);        //push into the stack
        }

        bool aux = false;       //auxiliar
        list<int>::iterator it; //iterator
        for (it = list_adj[initial_vertex].begin(); it != list_adj[initial_vertex].end(); it++)
        {
            if (!visited_vertex[*it]) //vertex not yet visited
            {
                if ((*it) == target) //find the target
                {
                    return true;
                }
                aux = true; //mark as visited
                break;
            }
        }
        if (aux) //update initial vertex
        {
            initial_vertex = *it;
        }
        else
        {
            stack_DFS.pop(); //remove from stack

            if (stack_DFS.empty()) //check if stack if empty. If true, search is done.
            {
                return false;
            }
            initial_vertex = stack_DFS.top(); //if stack isn't empty, update initial vertex
        }
    }
}

//--------------------------------------------------------------------

void gp(vector<float> &current_path, vector<float> &to_do, vector<vector<float>> &result)
{
    if (to_do.empty())
    {
        printVector(current_path);
        result.push_back(current_path);
    }
    else
    {
        for (int i = 0; i < to_do.size(); i++)
        {
            vector<float> path(current_path);
            path.push_back(to_do[i]);

            vector<float> left_to_do(to_do);
            left_to_do.erase(left_to_do.begin() + i);

            gp(path, left_to_do, result);
        }
    }
}

//--------------------------------------------------------------------

vector<vector<float>> generate_permutation(int n)
{
    vector<float> current_path = {0};
    vector<float> to_do;
    vector<vector<float>> result;

    for (int i = 1; i < n; i++) //coloca a cidades q faltam visitar
    {
        to_do.push_back(i);
    }
    gp(current_path, to_do, result);
    cout << "Size of result " << result.size() << endl;
    return result;
}

//---------------------------------------------------------------------------------------

void travellingSalesmanProblem(vector<vector<float>> &vec, float initial_city, int number_city)
{
    vector<float> vertex;
    vector<pair<float, float>> cities;
    pair<float, vector<pair<float, float>>> routes;

    vector<vector<float>> permutation = generate_permutation(number_city);

    float min_cost = std::numeric_limits<float>::max(); //minimum cost

    do
    {
        vertex = permutation[0];     //take the first path
        float cost_current_path = 0; //current cost

        int k = initial_city;
        for (int i = 0; i < vertex.size(); i++)
        {
            cost_current_path += vec[k][vertex[i]];
            cities.push_back(make_pair(k, vertex[i])); //store the current path
            k = vertex[i];
        }
        cost_current_path += vec[k][initial_city];    //close the path
        cities.push_back(make_pair(k, initial_city)); //store the current path
        min_cost = min(min_cost, cost_current_path);  //find the minimum route

        if (min_cost == cost_current_path) //if min_cost is minimum than current path, save the min_cost
        {
            routes = make_pair(cost_current_path, cities);
            cities.clear();
        }
        else //otherwise keep the path
        {
            cities.clear();
        }
        permutation.erase(permutation.begin()); ///erase the first path

    } while (!permutation.empty()); //next permutation

    cout << "The smallest route is: " << routes.first << "." << endl;
    cout << "The route is: ";
    printVectorOfPair(routes.second);
}

//---------------------------------------------------------------------------------------

template <typename T>
void powerSet(vector<vector<T>> &result, vector<T> &vec, int n)
{
    auto number_subsets = pow(2, n);
    int count, j;
    vector<float> subset;

    for (count = 0; count < number_subsets; count++)
    {
        for (j = 0; j < n; j++)
        {
            if (count & (1 << j))
            {
                subset.push_back(vec[j]);
            }
        }
        result.push_back(subset);
        subset.clear();
    }
}

//---------------------------------------------------------------------------------------

void knapSackProblem(float knapSackWeight, vector<float> &weights, vector<float> &values, int n)
{
    vector<vector<float>> result_subsets;
    vector<float> pair_weights;
    float sub_value = 0, max_value = 0;
    int index;

    if (n == 0 || knapSackWeight == 0) //base case
    {
        cout << "The maximum value inside knapsack is 0" << endl;
    }

    powerSet(result_subsets, weights, n); //generate all possibilities

    for (int i = 0; i < result_subsets.size(); i++)
    {
        if (accumulate(result_subsets[i].begin(), result_subsets[i].end(), 0) <= knapSackWeight)
        {
            for (int j = 0; j < result_subsets[i].size(); j++)
            {
                index = sequentialSearch(weights, result_subsets[i][j]);
                sub_value += values[index];
            }
            if (sub_value >= max_value)
            {
                pair_weights = result_subsets[i];
                max_value = sub_value;
                sub_value = 0;
            }
            sub_value = 0;
        }
    }

    cout << "The maximum value inside knapsack is " << max_value << endl;
    cout << "And the weights are: " << endl;
    printVector(pair_weights);
}
