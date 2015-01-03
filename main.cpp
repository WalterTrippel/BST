#include "binarytree.h"

using namespace std;

int main()
{
    srand(10);
    BinaryTree a;
    for(int i = 0; i < 10; ++i)
    {
        cin >> a;
    }
    cout << a << "\n";

    BinaryTree b;
    cout<< b << "\n";
    cout << b.isEmpty() << "\n";
    return 0;
}

