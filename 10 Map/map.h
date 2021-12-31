#ifndef MAP_H
#define MAP_H
#define CAPACITY 10
#include <list>
#include <sstream>

template <typename Key, typename T>
class map
{
    typedef std::pair<Key, T> pair;

    pair *arr = nullptr;
    size_t _capacity = 0, _size = 0;

    void resize(size_t cop);

public:
    class iterator;

    map() noexcept = default;
    map(const std::initializer_list <pair>& list);
    map(const map& other);
    map(map&& other) noexcept;
    ~map();

    void insert(const pair& elem);
    iterator erase (iterator it);
    iterator erase (const Key& key);
    iterator find(const Key& key) const noexcept;

    [[nodiscard]] std::string toJSON() const noexcept;
    std::list<T> values() const noexcept;
    std::list<Key> keys() const noexcept;

    const T& value(const Key& key, const T& defvalue) const noexcept;
    T& at(const Key& key);
    const T& at(const Key& key) const;
    T& operator[](const Key& key) noexcept;

    [[nodiscard]] bool empty() const noexcept;
    [[nodiscard]] size_t size() const noexcept;
    [[nodiscard]] size_t max_size() const noexcept;
    void clear() noexcept;

    iterator begin() const noexcept { return iterator(arr);}
    iterator end() const noexcept { return iterator(arr + _size);}

    class iterator
    {
    private:
        mutable pair *p;
    public:
        explicit iterator(pair* p) noexcept;
        iterator(const iterator &it) noexcept;
        pair& operator++(int) noexcept;
        pair& operator--(int) noexcept;
        pair& operator--() noexcept;
        pair& operator++() noexcept;
        pair& operator* () const noexcept;
        pair* operator->() const noexcept;
        bool operator!=(iterator const& other) const noexcept;
        bool operator==(iterator const& other) const noexcept;
        bool operator <(iterator const& other) const noexcept;
        bool operator >(iterator const& other) const noexcept;
        bool operator<=(iterator const& other) const noexcept;
        bool operator>=(iterator const& other) const noexcept;
    };
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename Key, typename T>
map<Key, T>::iterator::iterator(pair *p) noexcept :p(p){}

template<typename Key, typename T>
map<Key, T>::iterator::iterator(const map::iterator &it) noexcept: p(it.p){}

template<typename Key, typename T>
std::pair<Key, T> &map<Key, T>::iterator::operator++(int) noexcept {return *p++;}

template<typename Key, typename T>
std::pair<Key, T> &map<Key, T>::iterator::operator--(int) noexcept {return *p--;}
template<typename Key, typename T>
std::pair<Key, T> &map<Key, T>::iterator::operator++() noexcept {return *++p;}

template<typename Key, typename T>
std::pair<Key, T> &map<Key, T>::iterator::operator--() noexcept {return *--p;}

template<typename Key, typename T>
bool map<Key, T>::iterator::operator!=(iterator const& other) const noexcept {return p != other.p;}

template<typename Key, typename T>
bool map<Key, T>::iterator::operator==(iterator const& other) const noexcept {return p == other.p;}

template<typename Key, typename T>
bool map<Key, T>::iterator::operator<(const map::iterator &other) const noexcept {return p < other.p;}

template<typename Key, typename T>
bool map<Key, T>::iterator::operator>(const map::iterator &other) const noexcept {return p > other.p;}

template<typename Key, typename T>
bool map<Key, T>::iterator::operator<=(const map::iterator &other) const noexcept {return p <= other.p;}

template<typename Key, typename T>
bool map<Key, T>::iterator::operator>=(const map::iterator &other) const noexcept {return p >= other.p;}

template<typename Key, typename T>
std::pair<Key, T>& map<Key, T>::iterator::operator*()const noexcept{return *p;}

template<typename Key, typename T>
std::pair <Key, T>* map<Key, T>::iterator::operator->()const noexcept {return p;}



template<typename Key, typename T>
map<Key, T>::map(const std::initializer_list<pair> &list)
{
    for (auto &elem:list)
        insert(elem);
}


template<typename Key, typename T>
map<Key, T>::map(const map &other)
{
    if(!other.empty())
        for(int i = 0; i < other._size; i++)
            insert(other.arr[i]);
}


template<typename Key, typename T>
map<Key, T>::map(map &&other) noexcept: arr(arr), _size(other._size), _capacity(other._capacity)
{
    other.arr = nullptr;
    other._size = other._capacity = 0;
}


template<typename Key, typename T>
map<Key, T>::~map(){ clear(); }


template<typename Key, typename T>
void map<Key, T>::resize(size_t cop)
{
    pair* temp = new pair[_size];
    if (temp == nullptr)
        throw std:: logic_error("No memory!");

    for(int i = 0; i < _size; i++)
        temp[i] = arr[i];

    delete [] arr;

    _capacity = cop;
    arr = new pair[_capacity];
    if (arr == nullptr)
        throw std:: logic_error("No memory!");

    for(int i = 0; i < _size; i++)
        arr[i] = temp[i];

    delete [] temp;
}


template<typename Key, typename T>
void map<Key, T>::insert(const pair& elem)
{
    if(find(elem.first) == end())
    {
        if(empty())
        {
            arr = new pair[_capacity = CAPACITY];
            if (arr == nullptr)
                throw std:: logic_error("No memory!");
        }

        if (_size == _capacity)
            resize(_capacity + CAPACITY);

        arr[_size++] = elem;
    }
}


template<typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::find(const Key &key) const noexcept
{
    for(int i = 0; i < _size; i++)
        if(key == arr[i].first)
            return iterator(arr + i);

    return end();
}

template<typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::erase(map::iterator it)
{
    if(it == end())
        throw std:: logic_error("Key not found");

    int ret = (&(*it)) - arr;

    if(_size == 1)
        clear();

    else
    {
        pair* new_arr = new pair[_size--];
        if (new_arr == nullptr)
            throw std:: logic_error("No memory!");

        for(int i = 0, j = 0; i <_size+1; i++, j++)
        {
            if(i == ret) i++;
            new_arr[j] = arr[i];
        }
        delete [] arr;
        arr = new_arr;
    }
    return iterator(arr + ret);
}


template<typename Key, typename T>
typename map<Key, T>::iterator  map<Key, T>::erase(const Key& key){return erase(find(key));}


template<typename Key, typename T>
T &map<Key, T>::operator[](const Key &key) noexcept
{
    if(find(key) == end())
    {
        T a;
        insert(std::make_pair(key, a));
    }
    return (*find(key)).second;
}


template<typename Key, typename T>
T &map<Key, T>::at(const Key &key)
{
    if(find(key) == end())
        throw std:: logic_error("Key not found!");

    return (*find(key)).second;
}

template<typename Key, typename T>
const T &map<Key, T>::at(const Key &key) const {
    if(find(key) == end())
        throw std:: logic_error("Key not found!");

    return (*find(key)).second;
}
template<typename Key, typename T>
const T &map<Key, T>::value(const Key &key, const T &defvalue)const noexcept
{
    if(find(key) != end())
        return (*find(key)).second;

    return defvalue;
}


template<typename Key, typename T>
std::list<Key> map<Key, T>::keys() const noexcept
{
    std::list<Key> res;
    for(int i = 0; i < _size; i++)
        res.push_back(arr[i].first);

    return res;
}


template<typename Key, typename T>
std::list<T> map<Key, T>::values() const noexcept
{
    std::list<T> res;
    for(int i = 0; i < _size; i++)
        res.push_back(arr[i].second);

    return res;
}


template<typename Key, typename T>
std::string map<Key, T>::toJSON() const noexcept
{
    std::string res = "{";

    for(int i = 0; i <_size; i++)
    {
        std::stringstream ss;
        ss << '\"' << arr[i].first << "\":\"" << arr[i].second << '\"';
        if (i != _size - 1) ss << ',';
        res += ss.str();
    }

    return res + '}';
}


template<typename Key, typename T>
bool map<Key, T>::empty() const noexcept{ return _size == 0; }


template<typename Key, typename T>
size_t map<Key, T>::size() const noexcept{ return _size; }


template<typename Key, typename T>
size_t map<Key, T>::max_size() const noexcept{ return _capacity; }


template<typename Key, typename T>
void map<Key, T>::clear() noexcept
{
    if(!empty())
    {
        delete [] arr;
        arr = nullptr;
        _size = _capacity = 0;
    }
}

#endif //MAP_H