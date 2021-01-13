#include <iostream>
#include "vector.hpp"

using std::cin;
using std::cout;

template <typename T>
void print(T &t) { std::cout << t << ' '; }

template <typename T>
void printVector(Vector<T> &vec)
{
    vec.traverse(print);
    std::cout << '\n';
}

void testConstructor()
{
    cout << '[' << __FUNCTION__ << ']' << "------------test start----------------\n";

    Vector<int> vec1;
    Vector<int> vec2(12345, 10);

    for (int i = 1; i < 100000; i += i)
    {
        vec1.pushBack(i);
    }
    for (int i = 0, j = 1; i < vec1.size(); ++i, j += j)
    {
        if (vec1[i] != j)
            goto error;
    }

    if (vec2.size() != 10)
        goto error;
    for (int i = 0; i < 10; ++i)
    {
        if (vec2[i] != 12345)
            goto error;
    }

    cout << '[' << __FUNCTION__ << ']' << "------------test end----------------\n";
    return;

error:
    cout << '[' << __FUNCTION__ << ']' << "----------test failed!--------------\n";
    return;
}

void testSort()
{
    cout << '[' << __FUNCTION__ << ']' << "------------test start----------------\n";

    Vector<int> vec(12345, 10);
    for (int i = 1; i < 100000; i += i)
    {
        vec.insert(0, i);
    }
    vec.remove(0, 10);

    if (vec.isOrdered())
        goto error;

    vec.sort();
    if (!vec.isOrdered())
        goto error;

    cout << '[' << __FUNCTION__ << ']' << "------------test end----------------\n";
    return;

error:
    cout << '[' << __FUNCTION__ << ']' << "----------test failed!--------------\n";
    return;
}


// TODO
void testDeduplicate()
{
    cout << '[' << __FUNCTION__ << ']' << "------------test start----------------\n";

    int array[] = {8, 8, 8, 123, 123, 45, 45, 45, 77, 77, 789, 789, 5, 6};
    int array1[] = {5, 6, 8, 45, 77, 123, 789};
    Vector<int> vec;
    for (auto i : array)
        vec.pushBack(i);
    
    printVector(vec);
    vec.deduplicate();
    printVector(vec);

    for (int i = 0; i < vec.size(); ++i)
        if (vec[i] != array1[i])
            goto error;

    cout << '[' << __FUNCTION__ << ']' << "------------test end----------------\n";
    return;

error:
    cout << '[' << __FUNCTION__ << ']' << "----------test failed!--------------\n";
    return;
}

int main()
{
    testConstructor();
    testSort();
    testDeduplicate();

    return 0;
}