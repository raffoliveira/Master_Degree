#include "functions.h"

int main()
{
    BinaryTree<int> bt;

    std::cout << ((bt.insertBT(9) == InsertionBT::inserted) ? "inserted" : "alreadyIn") << std::endl;
    std::cout << ((bt.insertBT(10) == InsertionBT::inserted) ? "inserted" : "alreadyIn") << std::endl;
    std::cout << ((bt.insertBT(7) == InsertionBT::inserted) ? "inserted" : "alreadyIn") << std::endl;
    std::cout << ((bt.insertBT(3) == InsertionBT::inserted) ? "inserted" : "alreadyIn") << std::endl;
    std::cout << ((bt.insertBT(5) == InsertionBT::inserted) ? "inserted" : "alreadyIn") << std::endl;
    std::cout << ((bt.insertBT(11) == InsertionBT::inserted) ? "inserted" : "alreadyIn") << std::endl;
    std::cout << ((bt.insertBT(4) == InsertionBT::inserted) ? "inserted" : "alreadyIn") << std::endl;
    std::cout << ((bt.insertBT(10) == InsertionBT::inserted) ? "inserted" : "alreadyIn") << std::endl;
    std::cout << ((bt.insertBT(5) == InsertionBT::inserted) ? "inserted" : "alreadyIn") << std::endl;
    std::cout << ((bt.insertBT(8) == InsertionBT::inserted) ? "inserted" : "alreadyIn") << std::endl;

    bt.printBT();

    std::cout << std::endl;

    std::cout << ((bt.searchBT(11) == SearchBT::found) ? "found" : "notFound") << std::endl;
    std::cout << ((bt.searchBT(20) == SearchBT::found) ? "found" : "notFound") << std::endl;

    return 0;
}