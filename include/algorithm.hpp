#pragma once

template <typename T>
void swap(T &left, T &right)
{
    T tmp = left;
    left = right;
    right = tmp;
}

template <typename T>
void bubbleSort(T *array, size_t len)
{
    if (len < 0)
        abort();

    bool isSorted = false;
    while (!isSorted)
    {
        isSorted = true;
        for (size_t i = 0; i < len - 1; ++i)
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