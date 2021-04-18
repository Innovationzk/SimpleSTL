#include <iostream>
#include "queue.hpp"

using std::cin;
using std::cout;

void print(int i)
{
    cout << i <<" ";
}

void testConstructor()
{
    Queue<int> q;

    int data[] = {11,111,1,22,1,0,2,2222,2000,3000};

    for (int i = 0; i < sizeof(data) / sizeof(int); ++i)
    {
        q.push(data[i]);
    }
    q.traverse(print);
    cout << "\n";

    for (int i = 0; i < 5; ++i)
    {
        q.pop();
    }
    q.traverse(print);
    cout << "\n";

    for (int i = 0; i < 5; ++i)
    {
        q.push(data[i]);
    }
    q.traverse(print);
    cout << "\n";

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