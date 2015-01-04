#include "binarytree.h"

using namespace std;

int main()
{
    srand(10);
    BinaryTree a;
    for(int i = 0; i < 4; ++i)
    {
        cin >> a;
    }
    cout << a << "\n";

    int data;
    cin >> data;
    a.remove(data);
    cout << a << "\n";
    return 0;
}

