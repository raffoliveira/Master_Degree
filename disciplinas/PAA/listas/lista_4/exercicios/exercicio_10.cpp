#include "functions.h"

int main()
{
    BinaryTree<int> bt;

    bt.insertBT(9);
    bt.insertBT(10);
    bt.insertBT(7);
    bt.insertBT(3);
    bt.insertBT(5);
    bt.insertBT(11);
    bt.insertBT(4);
    bt.insertBT(10);
    bt.insertBT(5);
    bt.insertBT(8);

    bt.printBT();

    std::cout << std::endl;

    int heightTree = bt.heightBT();

    std::cout << "The height of tree is " << heightTree << std::endl;

    return 0;
}