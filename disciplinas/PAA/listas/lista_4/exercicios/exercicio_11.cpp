#include "functions.h"

int main()
{
    BinaryTree<std::string> bt;

    bt.insertBT("a");
    bt.insertBT("b");
    bt.insertBT("c");
    bt.insertBT("d");
    bt.insertBT("e");
    bt.insertBT("f");

    std::cout << std::endl;

    std::cout << "Preorder: ";
    bt.preorderBT();
    std::cout << std::endl;

    std::cout << "Inorder: ";
    bt.inorderBT();
    std::cout << std::endl;

    std::cout << "Postorder: ";
    bt.postorderBT();
    std::cout << std::endl;

    return 0;
}