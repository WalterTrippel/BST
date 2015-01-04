#include "binarytree.h"

using namespace std;

int main()
{
    srand(10);
    BinaryTree a = {1, 2, 3, 4};
    a.remove(3);
    cout << a << "\n";
    return 0;
}

