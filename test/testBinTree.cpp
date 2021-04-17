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

    int data[] = {11,111,1,22,1,0,2,22222,3333};
    for (int i = 0; i < sizeof(data) / sizeof(int); ++i)
    {
        bt.insert(data[i]);
    }

    bt.travIn(print);

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