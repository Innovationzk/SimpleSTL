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

    BinNode<T> *insertAsLc(const T &e)
    {
        this->lc = new BinNode<T>(e, this);
    }
    BinNode<T> *insertAsRc(const T &e)
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
    void travPre(VST& visit)
    {
        visit(this->data);
        if (this->lc) this->lc->travPre(visit);
        if (this->rc) this->rc->travPre(visit);
    }
    template<typename VST>
    void travIn(VST& visit)
    {
        if (this->lc) this->lc->travIn(visit);
        visit(this->data);
        if (this->rc) this->rc->travIn(visit);
    }
    template<typename VST>
    void travPost(VST& visit)
    {
        if (this->lc) this->lc->travPost(visit);
        if (this->rc) this->rc->travPost(visit);
        visit(this->data);
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
    BinNode<T> *insert(const T &e)
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
    void travPre(VST& visit)
    {
        if (root) root->travPre(visit);
    }
    template<typename VST>
    void travIn(VST& visit)
    {
        if (root) root->travIn(visit);
    }
    template<typename VST>
    void travPost(VST& visit)
    {
        if (root) root->travPost(visit);
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