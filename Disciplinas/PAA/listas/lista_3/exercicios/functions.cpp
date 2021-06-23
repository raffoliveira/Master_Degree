#include "functions.h"

using namespace std;

//-------------------------------print vector of vector-------------------------------------

template <typename T>
void printVectorOfVector(vector<vector<T>> &vec)
{
    cout << "[";
    for (auto i = 0; i < vec.size(); i++)
    {
        cout << "[";
        for (auto j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j];
            if (j < vec[i].size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]";

        if (i < vec.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";
    cout << endl; //print new line
}

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
    cout << endl;
}

//----------------------------reading file----------------------------------------
//when load the testing files, it just changes the variable path to your specific path and the filename

vector<float> readingFileFloat()
{

    vector<float> array;
    string line;
    string path = "/media/rafael/rafael_backup/rafaeloliveira/Documents/mestrado/disciplinas/PAA/listas/lista_2/testes/";
    fstream readFile(path + "names.txt");

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
    fstream readFile(path + "alphabet.txt");

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

//------------------------------generate ordered permutation---------------------------

void lexicographicPermute(vector<vector<int>> &all_permutation, vector<int> &item)
{
    bool finished = false;

    while (!finished)
    {
        int last_index = item.size() - 1; //last position

        if (last_index < 1)
        {
            return;
        }

        int i = last_index - 1;

        while ((i >= 0) && !(item[i] < item[i + 1])) //find i that a[i] < a[i + 1]
        {
            i--;
        }

        if (i < 0)
        {
            finished = true;
        }
        else
        {
            int j = last_index;

            while ((j > i + 1) && !(item[j] > item[i])) //find the biggest j greater than i such that a[j] > a[i];
            {
                j--;
            }

            swap(item[i], item[j]);
            reverse(item.begin() + (i + 1), item.end());
            all_permutation.push_back(item);
        }
    }
}

//------------------------------insertion sort---------------------------

template <typename T>
void insertionSort(vector<T> &vec)
{
    for (auto i = 1; i < vec.size(); i++)
    {
        auto v = vec[i];
        auto j = i - 1;

        while (j >= 0 && vec[j] > v)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = v;
    }
}

//------------------------------generate all subsets of a set--------------------------

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
                cout << "count: " << count << endl;
                cout << "j: " << (1 << j) << endl;
                cout << "bitwise: " << (count & (1 << j)) << endl;
                subset.push_back(vec[j]);
                cout << "subset: ";
                printVector(subset);
            }
        }
        cout << "Result: ";
        result.push_back(subset);
        printVectorOfVector(result);
        subset.clear();
    }
}

//-------------------------------random number-------------------------------------

int randomNumber()
{
    return (rand() % 100);
}

//-------------------------------fake coin-------------------------------------

int fakeCoin(const vector<int> &vec, int begin, int end)
{
    int fake_coin = -1; //index of fake coin

    if ((end - begin) == 1)
    {
        return begin;
    }
    else
    {
        int pile_size = (end - begin) / 2;
        int remainder = (end - begin) % 2;

        int begin_p2 = begin + pile_size;

        end = (remainder != 0) ? end - 1 : end;

        int weight_p1 = accumulate(vec.begin() + begin, vec.begin() + begin_p2, 0);
        int weight_p2 = accumulate(vec.begin() + begin_p2, vec.begin() + end, 0);

        if (weight_p1 < weight_p2)
        {
            fake_coin = fakeCoin(vec, begin, begin_p2);
        }
        else if (weight_p1 > weight_p2)
        {
            fake_coin = fakeCoin(vec, begin_p2, end);
        }
        else
        {
            fake_coin = end;
        }
    }

    return fake_coin;
}

//-------------------------------binary search------------------------------------

int binarySearch(vector<float> &vec, int value)
{
    int m, l = 0, r = vec.size() - 1;

    while (l <= r)
    {
        m = (l + r) / 2; //divide by half

        if (value == vec[m]) //find the element
        {
            return m;
        }
        else if (value < vec[m]) //take the left side
        {
            r = m - 1;
        }
        else //take the right side
        {
            l = m + 1;
        }
    }
    return -1;
}

//-------------------------------interpolation search------------------------------------

int interpolationSearch(vector<float> &vec, int value)
{
    int m, l = 0, r = vec.size() - 1;

    while (l <= r && value >= vec[l] && value <= vec[r]) //check if value is between the minimum and maximum
    {
        if (l == r)
        {
            if (vec[l] == value)
            {
                return l;
            }
            return -1;
        }
        int x = l + (((value - vec[l]) * (r - l)) / (vec[r] - vec[l])); //calculating the point x

        if (vec[x] == value)
        {
            return x;
        }
        else if (vec[x] < value)
        {
            l = x + 1;
        }
        else
        {
            r = x - 1;
        }
    }
    return -1;
}
//-------------------------------partition vector------------------------------------

int lomutoPartition(vector<int> &v, int l, int r)
{
    int p = v[l], s = l;

    for (int i = l + 1; i < r; i++)
    {
        if (v[i] < p)
        {
            s++;
            swap(v[s], v[i]);
        }
    }
    swap(v[l], v[s]);
    return s;
}

//-------------------------------find median------------------------------------

int quickSelect(vector<int> &v, int l, int r, int k)
{
    int s = lomutoPartition(v, l, r);

    if (s == k)
    {
        return v[s];
    }
    else if (s > k)
    {
        return quickSelect(v, l, s, k);
    }
    else
    {
        return quickSelect(v, s, r, k);
    }
}

//-------------------------------------------------------------------
template <typename T>
class BinarySearchTree
{
    class BSTNode
    {
    public:
        //attributes
        T value;
        unique_ptr<BSTNode> left;
        unique_ptr<BSTNode> right;

        //construct
        BSTNode(T v)
        {
            value = v;
        }
    };

public:
    //construct
    BinarySearchTree(){};

    InsertInfo insert(T v)
    {
        return insert(v, root);
    }

    SearchInfo search(T v)
    {
        return search(v, root);
    }

    void print()
    {
        print(root);
    }

private:
    unique_ptr<BSTNode> root;

    InsertInfo insert(T v, unique_ptr<BSTNode> &node)
    {
        if (!node)
        {
            // node = unique_ptr<BSTNode>(new BSTNode(v));
            node = make_unique<BSTNode>(v);
            return InsertInfo::Inserted;
        }
        if (v == node->value)
        {
            return InsertInfo::IsAlreadyIn;
        }

        return (v < node->value) ? insert(v, node->left) : insert(v, node->right);
    }

    SearchInfo search(T v, unique_ptr<BSTNode> &node)
    {
        if (!node)
        {
            return SearchInfo::NotFound;
        }

        if (v == node->value)
        {
            return SearchInfo::Found;
        }

        return (v < node->value) ? search(v, node->left) : search(v, node->right);
    }

    void print(unique_ptr<BSTNode> &node)
    {
        if (!node)
        {
            return;
        }
        else
        {
            print(node->left);
            cout << node->value << '\t';
            print(node->right);
        }
    }
};

//-------------------------------------------------------------------

template <typename T>
bool checkMobileElement(vector<int> &arr, vector<T> &v)
{
    vector<bool> aux;

    for (int i = 0; i < v.size(); i++)
    {
        if (arr[i] == 0 && v[i - 1] < v[i] && i != 0)
        {
            aux.push_back(true);
        }
        else if (arr[i] == 1 && v[i + 1] < v[i] && i != v.size() - 1)
        {
            aux.push_back(true);
        }
        else
        {
            aux.push_back(false);
        }
    }

    for (int elem : aux)
    {
        if (elem == true)
        {
            return true;
        }
    }

    return false;
}

//-------------------------------------------------------------------

template <typename T>
int findLargestMobileElement(vector<int> &arr, vector<T> &v)
{
    int k = -1, index_k = -1; //k is the largest mobile element

    for (int i = 0; i < v.size(); i++)
    {
        if (arr[i] == 0 && v[i - 1] < v[i] && i != 0)
        {
            if (v[i] > k)
            {
                k = v[i];
                index_k = i;
            }
        }
        if (arr[i] == 1 && v[i + 1] < v[i] && i != v.size() - 1)
        {
            if (v[i] > k)
            {
                k = v[i];
                index_k = i;
            }
        }
    }
    return index_k;
}

//-------------------------------------------------------------------

template <typename T>
void johnsonTrotter(vector<vector<T>> &result, vector<T> &vec)
{
    //arrows right to left (<-) has 0
    //arrows left to right (->) has 1

    vector<int> arrows(vec.size(), 0);
    int k;
    T value;

    result.push_back(vec);

    while (checkMobileElement(arrows, vec))
    {
        k = findLargestMobileElement(arrows, vec); //largest mobile element
        value = vec[k];

        if (arrows[k] == 0)
        {
            swap(vec[k], vec[k - 1]);       //invert values
            swap(arrows[k], arrows[k - 1]); //invert arrows of values
        }
        else
        {
            swap(vec[k], vec[k + 1]);       //invert values
            swap(arrows[k], arrows[k + 1]); //invert arrows of values
        }

        result.push_back(vec);

        for (int i = 0; i < vec.size(); i++) //reverse the direction of all the elements that are larger than k
        {
            if (vec[i] > value)
            {
                (arrows[i] == 0) ? arrows[i] = 1 : arrows[i] = 0;
            }
        }
    }
}
