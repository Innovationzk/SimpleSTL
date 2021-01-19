#pragma once

template <typename T>
void swap(T &left, T &right)
{
    T tmp = left;
    left = right;
    right = tmp;
}

template <typename T>
void bubbleSort(T *array, int len)
{
    if (len < 0)
        abort();

    bool isSorted = false;
    while (!isSorted)
    {
        isSorted = true;
        for (int i = 0; i < len - 1; ++i)
        {
            if (array[i] > array[i + 1])
            {
                swap(array[i], array[i + 1]);
                isSorted = false;
            }
        }
        --len; // 经过一轮扫描后，末位元素必然就位
    }
}

template <typename T>
void selectionSort(T *array, int len)
{
    if (len < 0)
        abort();

    for (int i = 0; i < len; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < len; ++j)
        {
            if (array[j] < array[minIndex])
                minIndex = j;
        }
        swap(array[i], array[minIndex]);
    }
}

template <typename T>
void insertionSort(T *array, int len)
{
    if (len < 0)
        abort();

    for (int i = 1; i < len; ++i)
    {
        T tmp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > tmp)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = tmp;
    }
}

template <typename T>
void mergeSort(T *array, int len)
{
    if (len <= 1)
        return;

    int mid = len / 2;

    mergeSort(array, mid);
    mergeSort(array + mid, len - mid);

    T *tmpArray = new T[len];
    int l = 0, r = mid, idx = 0;

    while (l < mid && r < len)
    {
        if (array[l] < array[r])
            tmpArray[idx++] = array[l++];
        else
            tmpArray[idx++] = array[r++];
    }

    while (l < mid)
        tmpArray[idx++] = array[l++];

    while (r < len)
        tmpArray[idx++] = array[r++];

    for (int i = 0; i < len; ++i)
        array[i] = tmpArray[i];
    delete[] tmpArray;
}