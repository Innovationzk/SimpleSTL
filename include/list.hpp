#pragma once

template <typename T>
class List;

template <typename T>
class Node
{
public:
	friend class List<T>;

public:
	Node(){};
	Node(const T &e) : element(e){};
	Node(const T &e, Node<T> *p = nullptr, Node<T> *s = nullptr) : element(e), pred(p), succ(s){};
	~Node() {}
	T data() { return this->element; }
	T &operator*() { return this->element; }

private:
	void insertAsPred(const T &e)
	{
		Node<T> *node = new Node<T>(e, this->pred, this);
		if (this->pred)
			this->pred->succ = node;
		this->pred = node;
	}
	void insertAsSucc(const T &e)
	{
		Node<T> *node = new Node<T>(e, this, this->succ);
		if (this->succ)
			this->succ->pred = node;
		this->succ = node;
	}

	Node<T> *pred{nullptr};
	Node<T> *succ{nullptr};
	T element;
};

template <typename T>
class List
{
public:
	List()
	{
		this->header = new Node<T>();
		this->trailer = new Node<T>();
		this->header->succ = this->trailer;
		this->trailer->pred = this->header;
	}
	List(const List<T> &l)
	{
		this->header = new Node<T>();
		this->trailer = new Node<T>();
		this->header->succ = this->trailer;
		this->trailer->pred = this->header;

		this->_size = l._size;

		for (Node<T> *p = l.header->succ; p != l.trailer; p = p->succ)
		{
			this->insert(p->data());
		}
	}
	List(const List &l, int index, int len);
	~List() {}

	int size() { return this->_size; }
	bool empty() { return this->_size; }
	bool isOrdered()
	{
		if (this->_size <= 1)
			return true;

		Node<T> *p = this->header->succ->succ;
		while (p != this->trailer)
		{
			if (p->data < p->pred->data)
				return false;
			p = p->succ;
		}
		return true;
	}
	Node<T> *first() { return this->header->succ; }
	Node<T> *last() { return this->trailer->pred; }
	Node<T> *find(const T &e);
	T at(int index)
	{
		if (index >= this->_size)
			abort();

		Node<T> *p = this->header->succ;
		while (index)
		{
			p = p->succ;
			--index;
		}
	}

	void insert(const T &e) // 在尾部插入
	{
		this->trailer->insertAsPred(e);
		this->_size++;
	}
	Node<T> *insert(const T &e, Node<T> *p) // 在元素p之前插入
	{
		p->insertAsPred(e);
		this->_size++;
	}
	void remove(Node<T> *e)
	{
		e->pred->succ = e->succ;
		e->succ->pred = e->pred;
		delete e;
		this->_size--;
	}
	int clear()
	{
		Node<T> *p = this->header->succ;
		while (p != this->trailer)
		{
			p = p->succ;
			delete p->pred;
		}

		this->header->succ = this->trailer;
		this->trailer->pred = this->header;
		this->_size = 0;
	}
	void sort()
	{
		this->mergeSort();
	}
	void mergeSort()
	{
		this->mergeSort(this->header->succ, this->_size);
	}
	void uniquify();
    void traverse(void (*fun)(const T&))
    {
        Node<T>* p = this->header->succ;
        while (p != this->trailer)
        {
            fun(p->data());
            p = p->succ;
        }
    }
	// TODO
	// template <typename FT>
	// void traverse(FT &); // 遍历(使用函数对象)

private:
	Node<T> *mergeSort(Node<T> *node, int len)
	{
		if (len <= 1)
			return node;

		Node<T> *header = node->pred;

		int mid = len / 2;
		Node<T> *right = node;
		for (int i = 0; i < mid; ++i)
			right = right->succ;

		Node<T> *left = mergeSort(node, mid);
		right = mergeSort(right, len - mid);

		// merge
		int l = 0, r = 0;
		while (l < mid && r < len - mid)
		{
			if (*left > *right)
			{
				right = right->succ;
				r++;
				this->moveNode(right, right->pred);
			}
			else
			{
				left = left->succ;
				l++;
			}
		}
		return header->succ;
	}
	void moveNode(Node<T> *dst, Node<T> *src) // 将src插入到dst前
	{
		src->pred->succ = src->succ;
		src->succ->pred = src->pred;

		src->pred = dst->pred;
		src->succ = dst;

		dst->pred->succ = src;
		dst->pred = src;
	}

private:
	Node<T> *header{nullptr}; // 头节点与尾节点作为哨兵，不保存实际元素，主要为了方便算法实现
	Node<T> *trailer{nullptr};
	int _size{0};
};