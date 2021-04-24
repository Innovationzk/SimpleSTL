#pragma once
#include "queue.hpp"
#include "stack.hpp"

template <class T>
class BinNode
{
public:
    enum RBColor{
        RED,
        BLACK
    };
public:
    BinNode(T e,
            BinNode<T> *p = nullptr,
            BinNode<T> *l = nullptr,
            BinNode<T> *r = nullptr,
            int h = 0,
            int npl = 1,
            RBColor color = RED) : data(e),
                                   parent(p),
                                   lc(l),
                                   rc(r),
                                   height(h),
                                   npl(npl),
                                   color(color) {}

    void insertAsLc(const T &e)
    {
        this->lc = new BinNode<T>(e, this);
    }
    void insertAsRc(const T &e)
    {
        this->rc = new BinNode<T>(e, this);
    }
    void updateHigh() {
        if (this->lc) {
            if (this->rc) {
                this->height = this->lc->height > this->rc->height ? this->lc->height + 1 : this->rc->height + 1;
            }
            else this->height = this->lc->height + 1;
        }
        if (this->rc) this->height = this->rc->height + 1;
        else this->height = 0;
    }

    bool operator<(const BinNode<T> &e)
    {
        return this->data < e.data;
    }

    template<typename VST>
    void travPreRecurse(VST& visit)
    {
        visit(this->data);
        if (this->lc) this->lc->travPreRecurse(visit);
        if (this->rc) this->rc->travPreRecurse(visit);
    }
    template<typename VST>
    void travInRecurse(VST& visit)
    {
        if (this->lc) this->lc->travInRecurse(visit);
        visit(this->data);
        if (this->rc) this->rc->travInRecurse(visit);
    }
    template<typename VST>
    void travPostRecurse(VST& visit)
    {
        if (this->lc) this->lc->travPostRecurse(visit);
        if (this->rc) this->rc->travPostRecurse(visit);
        visit(this->data);
    }
    template<typename VST>
    void travPreIterate(VST& visit)
    {
        Stack<BinNode<T>*> stk;
        stk.push(this);
        while(!stk.empty())
        {
            BinNode<T> *p = stk.pop();
            visit(p->data);
            if (p->rc) stk.push(p->rc);
            if (p->lc) stk.push(p->lc);
        }
    }
    template<typename VST>
    void travInIterate(VST& visit)
    {
        Stack<BinNode<T>*> stk;
        BinNode<T>* p = this;
        while(p)
        {
            stk.push(p);
            p=p->lc;
        }

        while(!stk.empty())
        {
            BinNode<T>* p = stk.pop();
            visit(p->data);
            if (p->rc) 
            {
                BinNode<T>* pp = p->rc;
                while(pp)
                {
                    stk.push(pp);
                    pp=pp->lc;
                }
            }
        }
    }

    void goAloneRL(BinNode<T>* p, Stack<BinNode<T>*>& stk)
    {
        while(true)
        {
            stk.push(p);
            if (p->lc)
            {
                if (p->rc)
                {
                    stk.push(p->rc);
                }
                p = p->lc;
            }
            else if (p->rc)
            {
                p = p->rc;
            }
            else break;
        }
    }

    template<typename VST>
    void travPostIterate(VST& visit)
    {
        Stack<BinNode<T>*> stk;
        BinNode<T>* p = this;
        goAloneRL(p,stk);

        BinNode<T>* pre = stk.pop();
        visit(pre->data);
        while (!stk.empty())
        {
            BinNode<T>* top = stk.pop();
            if (!top->lc && !top->rc)
            {
                visit(top->data);
                pre = top;
            }
            else
            {
                if (top == pre->parent)
                {
                    visit(top->data);
                    pre = top;
                }
                else goAloneRL(top,stk);
            }
        }
    }

    template<typename VST>
    void travLevel(VST& visit)
    {
        Queue<BinNode<T>*> queue;
        queue.push(this);
        while(!queue.empty())
        {
            BinNode<T> *p = queue.pop();
            visit(p->data);
            if (p->lc) queue.push(p->lc);
            if (p->rc) queue.push(p->rc);
        }
    }

    T data;
    BinNode<T> *parent, *lc, *rc;

    // 预留接口
    int height;
    int npl; // null path length (左式堆，也可以直接用height代替)
    RBColor color;
};

template <class T>
class BinTree
{
public:
    BinTree() : root(nullptr), _size(0) {}
    bool empty() { return this->root; }
    int size() { return this->_size; }
    void insert(const T &e)
    {
        if (!this->root) this->root = new BinNode<T>(e);
        else
        {
            BinNode<T>* p = root;
            while(p)
            {
                if(e > p->data)
                {
                    if (!p->rc) 
                    {
                        p->insertAsRc(e);
                        break;
                    }
                    else p=p->rc;
                }
                else
                {
                    if (!p->lc) 
                    {
                        p->insertAsLc(e);
                        break;
                    }
                    else p=p->lc;
                }
            }
            this->updateHeightAbove(p);
        }
    }
    void remove(const T &e);
    template<typename VST>
    void travPreRecurse(VST& visit)
    {
        if (root) root->travPreRecurse(visit);
    }
    template<typename VST>
    void travInRecurse(VST& visit)
    {
        if (root) root->travInRecurse(visit);
    }
    template<typename VST>
    void travPostRecurse(VST& visit)
    {
        if (root) root->travPostRecurse(visit);
    }
    template<typename VST>
    void travPreIterate(VST& visit)
    {
        if (root) root->travPreIterate(visit);
    }
    template<typename VST>
    void travInIterate(VST& visit)
    {
        if (root) root->travInIterate(visit);                 
    }
    template<typename VST>
    void travPostIterate(VST& visit)
    {
        if (root) root->travPostIterate(visit);
    }

    template<typename VST>
    void travLevel(VST& visit)
    {
        if (root) root->travLevel(visit);
    }

private:
    void updateHeightAbove(BinNode<T> *p)
    {
        while(p) 
        {
            p->updateHigh();
            p=p->parent;
        }
    }

private:
    BinNode<T> *root;
    int _size;
};