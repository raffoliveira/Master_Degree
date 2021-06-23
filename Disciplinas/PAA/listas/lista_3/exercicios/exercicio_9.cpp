#include "functions.h"
#include "functions.cpp"

using namespace std;

int main()
{

    BinarySearchTree<int> bst;

    cout << (bst.insert(9) == InsertInfo::Inserted ? "Inserted" : "IsAlreadyIn") << endl;
    cout << (bst.insert(10) == InsertInfo::Inserted ? "Inserted" : "IsAlreadyIn") << endl;
    cout << (bst.insert(7) == InsertInfo::Inserted ? "Inserted" : "IsAlreadyIn") << endl;
    cout << (bst.insert(3) == InsertInfo::Inserted ? "Inserted" : "IsAlreadyIn") << endl;
    cout << (bst.insert(2) == InsertInfo::Inserted ? "Inserted" : "IsAlreadyIn") << endl;
    cout << (bst.insert(3) == InsertInfo::Inserted ? "Inserted" : "IsAlreadyIn") << endl;
    cout << (bst.insert(7) == InsertInfo::Inserted ? "Inserted" : "IsAlreadyIn") << endl;
    cout << (bst.insert(12) == InsertInfo::Inserted ? "Inserted" : "IsAlreadyIn") << endl;
    cout << (bst.insert(1) == InsertInfo::Inserted ? "Inserted" : "IsAlreadyIn") << endl;
    cout << (bst.insert(5) == InsertInfo::Inserted ? "Inserted" : "IsAlreadyIn") << endl;
    cout << (bst.insert(17) == InsertInfo::Inserted ? "Inserted" : "IsAlreadyIn") << endl;

    bst.print();

    cout << endl;

    cout << (bst.search(17) == SearchInfo::Found ? "Found" : "NotFound") << endl;
    cout << (bst.search(37) == SearchInfo::Found ? "Found" : "NotFound") << endl;

    return 0;
}
