#ifndef STACK_QUEUE
#define STACK_QUEUE
#include <iostream>
#include "stack.h"

template <typename T>
struct Elem
{
    T elem;
    Elem *next;
    Elem(T el): elem(el), next(nullptr){};
};

template<typename T>
class Queue
{
    Elem<T> *head = nullptr, *tail = nullptr;

public:
    Queue() noexcept = default;
    Queue(const std:: initializer_list<T> &);
    Queue(const Queue&);
    Queue(Queue&&) noexcept;
    ~Queue() noexcept;

    T pop();
    T checkpop() const;
    void push(const T &);

    bool empty() const noexcept;
    int length() const noexcept;
    void erase() noexcept;
    bool find(const T &elem) const noexcept;

    Queue <T> &operator = (const Queue &);

    Queue <T> & operator >> (const T &elem);
    Queue <T> & operator << (const T &elem);

    template <typename In>
    friend std:: ostream& operator << (std:: ostream &, const Queue <In> &);
    template <typename In>
    friend Stack<In> Queue_to_Stack(const Queue<In> &);
    template <typename In>
    friend Queue<In> Stack_to_Queue(const Stack<In> &);
};

template<typename T>
Queue<T>::Queue(const std::initializer_list<T> & list)
{
    for(auto &el: list)
        push(el);
}

template<typename T>
Queue<T>::Queue(const Queue &other)
{
    *this = other;
}

template<typename T>
Queue<T>::Queue(Queue && queue)noexcept: head(queue.head), tail(queue.tail)
{
    queue.head = queue.tail = nullptr;
}

template<typename T>
Queue<T>::~Queue() noexcept
{
    erase();
}

template<typename T>
T Queue<T>::pop()
{
    if(empty())
        throw std:: logic_error("queue empty");

    auto del = head;
    T temp = head -> elem;
    head = head -> next;
    delete del;
    return temp;
}

template<typename T>
T Queue<T>::checkpop() const
{
    if(empty())
        throw std:: logic_error("queue empty");

    return head -> elem;
}

template<typename T>
void Queue<T>::push(const T &el)
{
    auto temp = new Elem<T>(el);
    if(temp == nullptr)
        throw std:: logic_error("queue empty");

    if(head == nullptr)
        head = tail = temp;
    else
    {
        tail -> next = temp;
        tail = tail -> next;
    }
}

template<typename T>
bool Queue<T>::empty() const noexcept
{
    return head == nullptr;
}

template<typename T>
int Queue<T>::length() const noexcept
{
    int len;
    for(auto el = head; el != nullptr; el = el -> next, len++);

    return len;
}

template<typename T>
void Queue<T>::erase() noexcept
{
    while(head != nullptr)
        pop();
}

template<typename T>
Queue<T> &Queue<T>::operator=(const Queue &other)
{
    if (this!= &other)
    {
        if (!empty())
            erase();

        for(auto i = other.head; i != nullptr; i = i -> next)
            push(i -> elem);
    }
    return *this;
}

template<typename In>
std::ostream &operator<<(std::ostream &out, const Queue<In> &other)
{
    for(auto i = other.head; i != nullptr; i = i -> next)
        out << i -> elem << "\t";

    return out;
}

template<typename In>
Stack<In> Queue_to_Stack(const Queue<In> &queue)
{
    Stack<In> res;
    res.size = res.capacity = queue.length();
    res.stack = new In[res.capacity];
    if(res.stack == nullptr)
        throw std:: logic_error("not memory");

    for(auto i = queue.head, j = 0; i != nullptr; i = i -> next, j++)
        res.stack[j] = i -> elem;

    return res;
}

template<typename In>
Queue<In> Stack_to_Queue(const Stack<In> &stack)
{
    Queue<In> res;
    for(int i = 0; i < stack.length(); i++)
        res.push(stack.stack[i]);

    return res;
}

template<typename T>
bool Queue<T>::find(const T &elem) const noexcept
{
    for(auto i = head; i != nullptr; i = i -> next)
        if(i -> elem == elem)
            return true;

    return false;
}

template<typename T>
Queue<T> &Queue<T>::operator>>(const T &elem)
{
    push(elem);
    return *this;
}

template<typename T>
Queue<T> &Queue<T>::operator<<(const T &elem)
{
    if(find(elem))
    {
        bool check = false;
        Queue<T> temp;
        for(auto i = head; i != nullptr; i = i -> next)
        {
            if(i -> elem != elem || check)
                temp.push(i->elem);
            else check = true;
        }
        *this = temp;
    }
    return *this;
}

#endif //STACK_QUEUE