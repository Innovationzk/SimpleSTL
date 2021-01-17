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

    cout << '.';
    return;

error:
    cout << '[' << __FUNCTION__ << ']' << "----------test failed!--------------\n";
    return;
}

void testSort()
{
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

    cout << '.';
    return;

error:
    cout << '[' << __FUNCTION__ << ']' << "----------test failed!--------------\n";
    return;
}

void testDeduplicate()
{
    int array[] = {8, 8, 8, 123, 123, 45, 45, 45, 77, 77, 789, 789, 5, 6};
    int array1[] = {5, 6, 8, 45, 77, 123, 789};
    Vector<int> vec;
    for (auto i : array)
        vec.pushBack(i);

    vec.deduplicate();

    for (int i = 0; i < vec.size(); ++i)
        if (vec[i] != array1[i])
            goto error;

    cout << '.';
    return;

error:
    cout << "\n[" << __FUNCTION__ << ']' << "----------test failed!--------------\n";
    return;
}

void testFind()
{
    int array[] = {8, 8, 8, 123, 123, 45, 45, 45, 77, 77, 789, 789, 5, 6};
    Vector<int> vec;
    for (auto i : array)
        vec.pushBack(i);

    if (vec.find(8) != 0 || vec.find(45) != 5 || vec.find(789) != 10 || vec.find(10) != -1)
        goto error;

    cout << '.';
    return;

error:
    cout << "\n[" << __FUNCTION__ << ']' << "----------test failed!--------------\n";
    return;
}

void testSearch()
{
    int array[] = {8, 8, 8, 123, 123, 45, 45, 45, 77, 77, 789, 789, 5, 6};
    Vector<int> vec;
    for (auto i : array)
        vec.pushBack(i);

    // 5 6 8 8 8 45 45 45 77 77 123 123 789 789
    vec.sort();

    if (vec.search(5) != 0 || vec.search(8) != 2 || vec.search(45) != 5 || vec.search(1234) != -1)
        goto error;

    cout << '.';
    return;

error:
    cout << "\n[" << __FUNCTION__ << ']' << "----------test failed!--------------\n";
    return;
}

int main()
{
    testConstructor();
    testSort();
    testDeduplicate();
    testFind();
    testSearch();

    return 0;
}