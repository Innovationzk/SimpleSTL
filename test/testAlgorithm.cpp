#include <iostream>
#include "algorithm.hpp"

int main()
{
    int array[] = {123, 854, 1637, 542, 167, 9642, 478, 974, 125};
    bubbleSort(array, sizeof(array) / sizeof(int));
    for (auto i : array)
        std::cout << i << " ";
    std::cout << "\n";
    return 0;
}