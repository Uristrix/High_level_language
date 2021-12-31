#ifndef QUEUE_STACK_H
#define QUEUE_STACK_H
#include <iostream>

template <typename T>
class Queue;

template <typename T>
class Stack
{
private:
    T* stack = nullptr;
    int size = 0, capacity = 0;

    void resize (int newcop);
public:
    Stack () noexcept = default;
    ~Stack() noexcept;
    Stack (const std:: initializer_list<T> &list);
    Stack (const Stack &other);
    Stack (Stack &&other) noexcept;

    void push (const T &el);
    T pop();
    T checkpop() const;

    bool empty() const noexcept;
    int length() const noexcept;
    void erase() noexcept;
    bool find(const T &elem) const noexcept;

    Stack <T> &operator = (const Stack &other);

    Stack <T> &operator >> (const T &elem);

    Stack <T> &operator << (const T &elem);
    template <typename In>
    friend std:: ostream& operator << (std:: ostream &out, const Stack <In> &stack);
    template <typename In>
    friend Stack<In> Queue_to_Stack(const Queue<In> &);
    template <typename In>
    friend Queue<In> Stack_to_Queue(const Stack<In> &);

};
template <typename T>
Stack <T>:: Stack (const Stack &other)
{
    *this = other;
}

template <typename T>
Stack <T>:: Stack (const std:: initializer_list<T> &list)
{
    stack = new T [capacity = list.size()];
    if (stack == nullptr)
        throw std:: logic_error ("\nnot memory");

    for (auto &elem:list)
        push(elem);
}

template<typename T>
Stack<T>:: Stack(Stack &&other)noexcept: stack(other.stack), size(other.size), capacity(other.capacity)
{
    other.stack = nullptr;
    other.size = other.capacity = 0;
}
template <typename T>
Stack <T>:: ~Stack() noexcept
{
    delete []stack;
}
template <typename T>
void Stack <T>:: push(const T &el)
{
    if (stack == nullptr)
    {
        stack = new T [capacity = 10];
        if (stack == nullptr)
            throw std:: logic_error ("\nnot memory");
    }
    if (capacity == size)
        resize(capacity + 10);

    stack [size++] = el;
}
template <typename T>
T Stack <T>:: pop()
{
    if (empty())
        throw std:: logic_error ("\nstack is empty");

    T temp = stack[size - 1];
    resize(capacity = --size);

    return temp;

}
template <typename T>
T Stack <T>:: checkpop() const
{
    if (stack == nullptr)
        throw std:: logic_error ("\nnot memory");

    return stack [size - 1];
}
template <typename T>
bool Stack <T>:: empty() const noexcept
{
    return size == 0;
}
template <typename T>
int Stack <T>:: length() const noexcept
{
    return size;
}
template <typename T>
void Stack <T>:: erase() noexcept
{
    delete [] stack;
    capacity = size = 0;
    stack = nullptr;
}
template <typename T>
Stack <T>  &Stack <T>:: operator = (const Stack &other)
{
    if (this!= &other)
    {
        if (stack != nullptr)
            erase ();

        capacity = other.capacity;
        if (other.stack != nullptr)
        {
            stack = new T [capacity];
            if (stack == nullptr)
                throw std:: logic_error ("\nnot memory");

            else
                for(int i = 0; i < other.size; i++)
                    push (other.stack[i]);
        }
        else stack = nullptr;
    }
    return *this;
}


template <typename In>
std::ostream  & operator << (std::ostream &out, const Stack <In> &stack)
{
    for (int i = 0; i < stack.size; i++)
        out << stack.stack[i] << "\t";

    return out;
}

template <typename T>
void Stack <T> :: resize(int newcop)
{
    Stack newstack (*this);
    delete [] stack;
    stack = new T [capacity = newcop];

    if (stack == nullptr)
        throw std:: logic_error ("\nnot memory");

    for (int i = 0; i < size; i++)
        stack[i] = newstack.stack[i];
}

template<typename T>
bool Stack<T>::find(const T &elem) const noexcept
{
    for(int i = 0; i < size; i++)
        if(stack[i] == elem)
            return true;

    return false;
}

template<typename T>
Stack<T> &Stack<T>::operator>>(const T &elem)
{
    push(elem);
    return *this;
}

template<typename T>
Stack<T> &Stack<T>::operator<<(const T &elem)
{
    if(find(elem))
    {
        bool check = false;
        Stack<T>temp;
        for(int i = 0; i < size; i++)
            if(stack[i] != elem || check)
                temp.push(stack[i]);
            else check = true;
        *this = temp;
    }
    return *this;

}
#endif //QUEUE_STACK_H