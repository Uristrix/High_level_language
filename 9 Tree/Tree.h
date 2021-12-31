#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <mutex>

template <typename T>
class Tree
{
public:
    Tree() noexcept;
    Tree(const Tree<T>&);
    Tree(const std::initializer_list<T>&);
    Tree(Tree<T>&&) noexcept;
    ~Tree();

    Tree<T> sub_tree(const T&) const;

    void push(const T&);
    void push(const Tree<T>&);
    void pop(const T&) noexcept;

    bool find(const T&)const noexcept;
    void clear() noexcept;

    void lpk() const noexcept;
    void lkp() const noexcept;
    void klp() const noexcept;

    template<typename In>
    friend std::ostream& operator<< (std::ostream&, const Tree<In>&);
    //template<typename In>
    //friend std::istream& operator>> (std::istream&, Tree<In>&);
    Tree<T>& operator = (const Tree& other);
    Tree<T>& operator = (Tree&& other) noexcept;
private:
    struct Elem
    {
        T inf;
        Elem* left;
        Elem* right;
        explicit Elem(const T& _inf) : inf(_inf), left(nullptr), right(nullptr) {}
    };

    typedef Tree<T>::Elem* pElem;

    mutable std::mutex mutex;
    pElem head;

    void _push(pElem& temp, const T&);
    void _push(pElem& temp, const pElem& tree);
    void _pop(const T&) noexcept;
    pElem _find(const pElem& temp, const T&)const noexcept;
    pElem& _find_pop(pElem& temp, const T&) noexcept;

    static void _lpk(const pElem&) noexcept;
    static void _lkp(const pElem&) noexcept;
    static void _klp(const pElem&) noexcept;

    static void _clear(pElem&) noexcept;

    static pElem _copy(const pElem&);
    static T _max(pElem&) noexcept;
};

template<typename T>
Tree<T>::Tree() noexcept : head(nullptr){}

template<typename T>
Tree<T>::Tree(const std::initializer_list<T>& list) : head(nullptr)
{
    for (auto& el : list)
        push(el);
}

template<typename T>
Tree<T>::Tree(const Tree<T>& other) {
    head = _copy(other.head);
}

template<typename T>
Tree<T>::Tree(Tree<T>&& other) noexcept
{
    head = other.head;
    other.head = nullptr;
}

template<typename T>
Tree<T>::~Tree() { _clear(head); }

template<typename T>
Tree<T> Tree<T>::sub_tree(const T& el) const
{
    std::lock_guard<std::mutex> im_locked(mutex);
    Tree<T> tree;
    tree.head = _copy(_find(head, el));
    return tree;
}

template<typename T>
void Tree<T>::push(const T& el)
{
    std::lock_guard<std::mutex> im_locked(mutex);
    _push(head, el);
}

template<typename T>
void Tree<T>::push(const Tree<T>& el)
{
    std::lock_guard<std::mutex> im_locked(mutex);
    _push(head, el.head);
}

template<typename T>
void Tree<T>::pop(const T& el) noexcept
{
    std::lock_guard<std::mutex> im_locked(mutex);
    _pop(el);
}

template<typename T>
bool Tree<T>::find(const T& el)const noexcept
{
    std::lock_guard<std::mutex> im_locked(mutex);
    return _find(head, el) != nullptr;
}

template<typename T>
void Tree<T>::clear() noexcept
{
    std::lock_guard<std::mutex> im_locked(mutex);
    _clear(head);
}

template<typename T>
void Tree<T>::lpk() const noexcept
{
    std::lock_guard<std::mutex> im_locked(mutex);
    _lpk(head);
}

template<typename T>
void Tree<T>::lkp() const noexcept
{
    std::lock_guard<std::mutex> im_locked(mutex);
    _lkp(head);
}

template<typename T>
void Tree<T>::klp() const noexcept
{
    std::lock_guard<std::mutex> im_locked(mutex);
    _klp(head);
}

template<typename In>
std::ostream& operator<<(std::ostream& out, const Tree<In>& tree)
{
    Tree<In>::_lkp(tree.head);
    return out;
}

template<typename In>
std::istream& operator>>(std::istream& in, Tree<In>& tree)
{
    int size;
    in >> size;
    for (int i = 0; i < size; i++)
    {
        In temp;
        in >> temp;
        tree.push(temp);
    }
    return in;
}
/////////////////////////////////////////////////////////////////////////
template<typename T>
void Tree<T>::_push(pElem& temp, const T& el)
{
    if (temp == nullptr)
        temp = new Elem(el);

    else
    {
        if (el < temp->inf)
            _push(temp->left, el);

        else if (el > temp->inf)
            _push(temp->right, el);
    }
}

template<typename T>
void Tree<T>::_push(pElem& temp, const pElem& tree)
{
    if (temp == nullptr)
        temp = _copy(tree);
    else
    {
        if (tree->inf < temp->inf)
            _push(temp->left, tree);

        else if (tree->inf > temp->inf)
            _push(temp->right, tree);
        else return;
    }
}

template<typename T>
void Tree<T>::_pop(const T& el) noexcept
{
    pElem &temp = _find_pop(head, el);
    if(temp != nullptr)
    {
        pElem pop_el = temp;
        if (temp->left == nullptr || temp->right == nullptr)
        {
            if (temp->right == nullptr)
                temp = temp->left;

            else if (temp->left == nullptr)
                temp = temp->right;

            delete pop_el;
        }
        else
        {
            T max = _max(temp->left);
            _pop(max);
            temp->inf = max;
        }
    }

}

template<typename T>
typename Tree<T>::pElem Tree<T>::_find(const pElem& temp, const T& el)const noexcept
{
    if ((temp != nullptr) && (temp->inf != el))
    {
        if (el < temp->inf)
            return _find(temp->left, el);

        if (el > temp->inf)
            return _find(temp->right, el);
    }
    return temp;
}

template<typename T>
typename Tree<T>::pElem& Tree<T>::_find_pop(pElem& temp, const T& el) noexcept
{
    if ((temp != nullptr) && (temp->inf != el))
    {
        if (el < temp->inf)
            return _find_pop(temp->left, el);

        if (el > temp->inf)
            return _find_pop(temp->right, el);
    }
    return temp;
}

template<typename T>
void Tree<T>::_lkp(const pElem& temp) noexcept
{
    if (temp != nullptr)
    {
        _lkp(temp->left);
        std::cout << temp->inf << ' ';
        _lkp(temp->right);
    }
}

template<typename T>
void Tree<T>::_lpk(const pElem& temp) noexcept
{
    if (temp != nullptr)
    {
        _lpk(temp->left);
        _lpk(temp->right);
        std::cout << temp->inf << ' ';
    }
}

template<typename T>
void Tree<T>::_klp(const pElem& temp) noexcept
{
    if (temp != nullptr)
    {
        std::cout << temp->inf << ' ';
        _klp(temp->left);
        _klp(temp->right);
    }
}

template<typename T>
void Tree<T>::_clear(pElem& temp) noexcept
{
    if (temp != nullptr)
    {
        _clear(temp->left);
        _clear(temp->right);
        delete temp;
        temp = nullptr;
    }
}

template<typename T>
typename Tree<T>::pElem Tree<T>::_copy(const pElem& el)
{
    Tree<T>::pElem temp;
    if (el != nullptr)
    {
        temp = new Elem(el->inf);
        temp->left = _copy(el->left);
        temp->right = _copy(el->right);
    }
    else temp = nullptr;

    return temp;
}

template<typename T>
T Tree<T>::_max(pElem& temp) noexcept
{
    if (temp->right == nullptr)
        return temp->inf;

    _max(temp->right);

}

template<typename T>
Tree<T> &Tree<T>::operator=(const Tree &other)
{
    if(this != &other)
    {
        clear();
        head = _copy(other.head);
    }
    return *this;
}

template<typename T>
Tree<T> &Tree<T>::operator=(Tree &&other) noexcept
{
    if(this != &other)
    {
        clear();
        head = other.head;
        other.head = nullptr;
    }
    return *this;
}

#endif // TREE_H