#pragma once
#include "vector.hpp"

template <typename T>
class Stack
{
public:
    Stack() {}
    bool empty() { return this->vec.empty(); }
    size_t size(){return this->vec.size();}
    T top(){ return this->vec.back(); }
    void push(const T& e){this->vec.pushBack(e);}
    T pop(){
        return this->vec.popBack();
    }

    template<typename VST>
    void traverse(VST vst)
    {
        for (int i =0;i<this->vec.size();++i)
        {
            vst(this->vec[i]);
        }
    }

private:
    Vector<T> vec;
};