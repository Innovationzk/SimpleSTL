#include <iostream>
#include "vector.hpp"

int main()
{
    Vector<int> vec;
    for (int i = 0; i < 1000; i += i)
    {
        vec.pushBack(i);
    }
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }

    return 0;
}