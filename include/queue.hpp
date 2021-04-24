#pragma once
#include <algorithm.hpp>

template <typename T>
class Queue
{
public:
    static constexpr int DEFAULT_CAPACITY = 3;

public:
    Queue() {
        this->_capacity = DEFAULT_CAPACITY;
        this->element = new T[this->_capacity];
    }
    void push(const T &e)
    {
        if (this->firstIndex >= this->_capacity - 1 || this->firstIndex + this->_size >= this->_capacity)
        {
            size_t newcapacity = (this->_capacity - this->firstIndex) * 2;
            T *newelement = new T[newcapacity];
            for (int i = 0; i < this->_size; ++i)
            {
                newelement[i] = this->element[firstIndex + i];
            }
            delete[] this->element;
            this->element = newelement;
            this->firstIndex = 0;
            this->_capacity = newcapacity;
        }
        
        this->element[this->firstIndex + this->_size] = e;
        this->_size++;
    }
    T pop()
    {
        if (!this->_size)
            abort();
        this->firstIndex += 1;
        this->_size -= 1;
        return this->element[firstIndex - 1];
    }
    size_t size() { return this->_size; }
    bool empty() { return !this->_size; }
    T front() { return this->element[firstIndex]; }

    template<typename VST>
    void traverse(VST& vst)
    {
        for (int i = 0;i<this->_size;++i)
        {
            vst(this->element[this->firstIndex + i]);
        }
    }

private:
    int firstIndex{0};
    size_t _size{0};
    size_t _capacity{0};
    T *element{nullptr};
};