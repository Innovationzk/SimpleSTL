#include <iostream>
#include "list.hpp"

using std::cin;
using std::cout;

int test[] = {5, 4, 3, 75, 164, 2415, 5, 423, 84, 75};

template<typename T>
void printNode(const T& e)
{
    cout << e << " ";
}

template<typename T>
void printList(List<T> &l)
{
    l.traverse(printNode<T>);
}

void testConstructor()
{
    List<int> list1;
    int size=0;

    for (int i = 1; i < 100000; i += i)
    {
        list1.insert(i);
        size++;
    }

    List<int> list2(list1);

    //list1.traverse(printNode<int>());
    printList(list1);
    for (int i = 0, j = 1; i < list1.size(); ++i, j += j)
    {
        if (list1.at(i) != j)
            goto error;
    }

    if (list2.size() != size)
        goto error;
    for (int i = 0, j = 1; i < list2.size(); ++i, j += j)
    {
        if (list2.at(i) != j)
            goto error;
    }

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