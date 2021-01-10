#pragma once

#define DEFAULE_CAPACITY 3

template <typename T>
class Vector
{
public:
    Vector() : capacity(DEFAULE_CAPACITY),
               size(0)
    {
        this->element = new T[capacity]();
    }
    Vector(const T &e, size_t n) : capacity(n * 2), // 初始化n个e元素
                                   size(n)
    {
        this->element = new T[capacity](e);
    }
    Vector(cosnt Vector &vec) // 深拷贝构造
    {
        delete this->element;

        this->size = vec.size();
        this->capacity = vec.capacity();
        this->element = new T[this->capacity]();
        for (int i = 0; i < vec.size(); ++i)
        {
            this->element[i] = vec[i];
        }
    }
    Vector(cosnt Vector &vec, int l, int r) // 拷贝[l,r)区间的元素
    {
        delete this->element;

        this->size = r - l;
        this->element = new T[this->capacity = this->size * 2]();
        for (int i = 0; i < this->size; ++i)
        {
            this->element[i] = vec[l + i];
        }
    }
    ~Vector() { delete[] this->element; }

public:
    size_t size() const { return this->size; }
    size_t capacity() const { return this->capacity; }
    bool empty() const { return !this->size; }
    bool isOrdered() const;
    int find(const T &e) const; // 无序向量查找
    int find(const T &e) const; // 有序向量查找

    T &operator[](int index)
    {
        if (index >= size)
            abort();

        return this->element[index];
    }
    T remove(int index)
    {
        T tmp = element[index];
        for (int i = index, i < size - 1; ++i)
        {
            element[i] = element[i + 1];
        }

        --this->size;
        return tmp;
    }
    void remove(int l, int r) //删除[l,r)区间内元素
    {
        if (r >= size || l >= size)
            abort();

        int len = r - l;
        for (int i = index, i < size - len; ++i)
        {
            element[i] = element[i + len];
        }

        this->size -= len;
        return tmp;
    }
    int insert(int index, const T &e);
    int insert(const T &e); // 在末尾插入
    int pushBack(const T &e);
    int emplaceBack(const T &&e);
    void sort();                  // 自排序
    void deduplicate();           // 去重
    void traverse(void (*)(T &)); // 遍历
    template <typename FT>
    void traverse(FT &); // 遍历(使用函数对象)

private:
    size_t size;
    size_t capacity;
    T *element{nullptr};
};