#include <iostream>
#include "algorithm.hpp"

using std::cin;
using std::cout;

void testBubbleSort()
{
    int array1[] = {123, 854, 1637, 542, 167, 9642, 478, 974, 125};
    int sortedArray1[] = {123, 125, 167, 478, 542, 854, 974, 1637, 9642};
    int array2[] = {-12, -836, 1637, 0, -4, 9642, 435, -7894, 125};
    int sortedArray2[] = {-7894, -836, -12, -4, 0, 125, 435, 1637, 9642};

    bubbleSort(array1, sizeof(array1) / sizeof(int));
    for (int i = 0; i < sizeof(array1) / sizeof(int); ++i)
        if (array1[i] != sortedArray1[i])
            goto error;

    bubbleSort(array2, sizeof(array2) / sizeof(int));
    for (int i = 0; i < sizeof(array2) / sizeof(int); ++i)
        if (array2[i] != sortedArray2[i])
            goto error;

    std::cout << '.';
    return;

error:
    cout << "\n[" << __FUNCTION__ << ']' << "----------test failed!--------------\n";
    return;
}

void testSelectionSort()
{
    int array1[] = {123, 854, 1637, 542, 167, 9642, 478, 974, 125};
    int sortedArray1[] = {123, 125, 167, 478, 542, 854, 974, 1637, 9642};
    int array2[] = {-12, -836, 1637, 0, -4, 9642, 435, -7894, 125};
    int sortedArray2[] = {-7894, -836, -12, -4, 0, 125, 435, 1637, 9642};

    selectionSort(array1, sizeof(array1) / sizeof(int));
    for (int i = 0; i < sizeof(array1) / sizeof(int); ++i)
        if (array1[i] != sortedArray1[i])
            goto error;

    selectionSort(array2, sizeof(array2) / sizeof(int));
    for (int i = 0; i < sizeof(array2) / sizeof(int); ++i)
        if (array2[i] != sortedArray2[i])
            goto error;

    std::cout << '.';
    return;

error:
    cout << "\n[" << __FUNCTION__ << ']' << "----------test failed!--------------\n";
    return;
}

void testInsertionSort()
{
    int array1[] = {123, 854, 1637, 542, 167, 9642, 478, 974, 125};
    int sortedArray1[] = {123, 125, 167, 478, 542, 854, 974, 1637, 9642};
    int array2[] = {-12, -836, 1637, 0, -4, 9642, 435, -7894, 125};
    int sortedArray2[] = {-7894, -836, -12, -4, 0, 125, 435, 1637, 9642};

    insertionSort(array1, sizeof(array1) / sizeof(int));
    for (int i = 0; i < sizeof(array1) / sizeof(int); ++i)
        if (array1[i] != sortedArray1[i])
            goto error;

    insertionSort(array2, sizeof(array2) / sizeof(int));
    for (int i = 0; i < sizeof(array2) / sizeof(int); ++i)
        if (array2[i] != sortedArray2[i])
            goto error;

    std::cout << '.';
    return;

error:
    cout << "\n[" << __FUNCTION__ << ']' << "----------test failed!--------------\n";
    return;
}

void testMergeionSort()
{
    int array1[] = {123, 854, 1637, 542, 167, 9642, 478, 974, 125};
    int sortedArray1[] = {123, 125, 167, 478, 542, 854, 974, 1637, 9642};
    int array2[] = { -12, -836, 1637, 0, -4, 9642, 435, -7894, 125 };
    int sortedArray2[] = { -7894, -836, -12, -4, 0, 125, 435, 1637, 9642 };

    mergeSort(array1, sizeof(array1) / sizeof(int));
    for (int i = 0; i < sizeof(array1) / sizeof(int); ++i)
        if (array1[i] != sortedArray1[i])
            goto error;

    mergeSort(array2, sizeof(array2) / sizeof(int));
    for (int i = 0; i < sizeof(array2) / sizeof(int); ++i)
        if (array2[i] != sortedArray2[i])
            goto error;

    std::cout << '.';
    return;

error:
    cout << "\n[" << __FUNCTION__ << ']' << "----------test failed!--------------\n";
    return;
}

int main()
{
    testBubbleSort();
    testSelectionSort();
    testInsertionSort();
    testMergeionSort();

    return 0;
}