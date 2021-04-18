#pragma once
#include "algorithm.hpp"

#define DEFAULT_CAPACITY 3

template <typename T>
class Vector
{
public:
    Vector() : _capacity(DEFAULT_CAPACITY),
               _size(0)
    {
        this->element = new T[_capacity]();
    }
    Vector(const T &e, size_t n) : _capacity(n * 2), // 初始化n个e元素
                                   _size(n)
    {
        this->element = new T[_capacity]();
        for (int i = 0; i < this->_size; ++i)
            this->element[i] = e;
    }
    Vector(const Vector &vec) // 深拷贝构造
    {
        delete this->element;

        this->_size = vec.size();
        this->_capacity = vec.capacity();
        this->element = new T[this->_capacity]();
        for (int i = 0; i < vec.size(); ++i)
        {
            this->element[i] = vec.element[i];
        }
    }
    Vector(const Vector &vec, int l, int r) // 拷贝[l,r)区间的元素
    {
        delete this->element;

        this->_size = r - l;
        this->element = new T[this->_capacity = this->_size * 2]();
        for (int i = 0; i < this->_size; ++i)
        {
            this->element[i] = vec.element[l + i];
        }
    }
    ~Vector() { delete[] this->element; }

public:
    size_t size() const { return this->_size; }
    size_t capacity() const { return this->_capacity; }
    bool empty() const { return !this->_size; }
    bool isOrdered() const
    {
        for (int i = 0; i < this->_size - 1; ++i)
        {
            if (this->element[i] > this->element[i + 1])
                return false;
        }

        return true;
    }
    int find(const T &e) const // 无序向量查找
    {
        for (int i = 0; i < this->size(); ++i)
        {
            if (this->element[i] == e)
                return i;
        }
        return -1;
    }
    int search(const T &e) const // 有序向量查找
    {
        int l = 0, r = this->_size;
        while (l < r - 1)
        {
            int mid = (l + r) / 2;
            if (e == this->element[mid])
            {
                while (--mid > 0)
                {
                    if (e != this->element[mid])
                        break;
                }
                return mid + 1;
            }
            if (e < this->element[mid])
                r = mid;
            else
                l = mid + 1;
        }

        if (e == this->element[l])
            return l;
        else
            return -1;
    }

    T &operator[](int index)
    {
        if (index >= _size)
            abort();

        return this->element[index];
    }
    T remove(int index)
    {
        T tmp = element[index];
        for (int i = index; i < this->_size - 1; ++i)
        {
            element[i] = element[i + 1];
        }

        --this->_size;
        return tmp;
    }
    void remove(int l, int r) //删除[l,r)区间内元素
    {
        if (r >= _size || l >= _size)
            abort();

        int len = r - l;
        for (int i = l; i < _size - len; ++i)
        {
            element[i] = element[i + len];
        }

        this->_size -= len;
    }
    void insert(int index, const T &e)
    {
        if (this->_size >= this->_capacity)
            this->expand();

        for (int i = this->_size - 1; i >= index; --i)
            this->element[i + 1] = this->element[i];

        this->element[index] = e;
        this->_size++;
    }
    void pushBack(const T &e)
    {
        if (this->_size >= this->_capacity)
            this->expand();

        this->element[_size++] = e;
    }
    void popBack()
    {
        this->_size--;
    }
    // TODO
    // int emplaceBack(const T &&e);
    void sort() // 自排序
    {
        bubbleSort(this->element, this->_size);
    }
    void deduplicate()
    {
        this->sort();
        int duplicateLen = 0;
        for (int i = 1; i < this->_size; ++i)
        {
            if (this->element[i] == this->element[i - 1 - duplicateLen])
            {
                ++duplicateLen;
                continue;
            }
            else if (duplicateLen)
            {
                this->element[i - duplicateLen] = this->element[i];
            }
        }
        this->_size -= duplicateLen;
    }
    void traverse(void (*fun)(T &)) // 遍历
    {
        for (int i = 0; i < this->_size; ++i)
            fun(this->element[i]);
    }
    // TODO
    // template <typename FT>
    // void traverse(FT &); // 遍历(使用函数对象)

protected:
    void copyFrom(T *element, int l, int r); // 拷贝数组区间[l,r)
    void expand()
    {
        this->_capacity *= 2;
        T *oldElement = this->element;
        this->element = new T[this->_capacity]();
        for (int i = 0; i < this->_size; ++i)
        {
            this->element[i] = oldElement[i];
        }
        delete[] oldElement;
    }

private:
    size_t _size;
    size_t _capacity;
    T *element{nullptr};
};