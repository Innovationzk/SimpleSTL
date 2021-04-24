#include <iostream>
#include "bintree.hpp"

using std::cin;
using std::cout;

void print(int i)
{
    cout << i <<" ";
}

void testConstructor()
{
    BinTree<int> bt;

    /*
                    11
                  /    \
                 1     111
                / \    /  \
               1   2  22  2222
             /           /   \
            0          2000  3000
    */
    int data[] = {11,111,1,22,1,0,2,2222,2000,3000};
    for (int i = 0; i < sizeof(data) / sizeof(int); ++i)
    {
        bt.insert(data[i]);
    }

    cout << "\ntravPreRecurse:\n";
    bt.travPreRecurse(print);
    cout << "\ntravInRecurse:\n";
    bt.travInRecurse(print);
    cout << "\ntravPostRecurse:\n";
    bt.travPostRecurse(print);

    cout << "\ntravPreIterate:\n";
    bt.travPreIterate(print);
    cout << "\ntravInIterate:\n";
    bt.travInIterate(print);
    cout << "\ntravPostIterate:\n";
    bt.travPostIterate(print);
    cout << "\ntravLevel:\n";
    bt.travLevel(print);

    cout << '.';
    return;

error:
    cout << '[' << __FUNCTION__ << ']' << "----------test failed!--------------\n";
    return;
}

int main()
{
   testConstructor();

   return 0;
}