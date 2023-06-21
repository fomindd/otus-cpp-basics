#include <iostream>

template <class T>
class SeqContainer {

private:

    size_t sz;
    size_t cap;
    T* buff;

public:

    typedef T* iterator;

    SeqContainer();
    ~SeqContainer();

    SeqContainer<T>& operator=(const SeqContainer<T>&);

    size_t capacity() const;
    size_t size() const;

    bool empty() const;

    iterator begin();
    iterator end();

    void push_back(const T& value);

    void insert(std::size_t position, const T& value);

    void erase(std::size_t position);

    void reserve(size_t capacity);
    void resize(size_t size);

    T& operator[](size_t index) const;

    void display();
};

template <class T>
SeqContainer<T>::SeqContainer()
{
    cap = 0;
    sz = 0;
    buff = nullptr;
}

template <class T>
bool SeqContainer<T>::empty() const
{
    return sz == 0;
}

template <class T>
typename SeqContainer<T>::iterator SeqContainer<T>::begin()
{
    return buff;
}

template <class T>
typename SeqContainer<T>::iterator SeqContainer<T>::end()
{
    return buff + sz;
}

template <class T>
void SeqContainer<T>::push_back(const T& value)
{
    if (sz >= cap)
    {
        if (cap == 0)
            reserve(cap + 1);
        else
            reserve(cap * 2);
    }
    buff[sz++] = value;
}

template <class T>
void SeqContainer<T>::insert(std::size_t position, const T& value)
{
    resize(sz + 1);

    typename SeqContainer<T>::iterator result = end();

    if (position < size())
    {
        result = std::copy_backward(std::next(begin(), position), std::prev(end()), end());
    }
    else
    {
        std::cout << "insert() error: invalueid position" << std::endl;
    }

    auto iter = std::prev(result);
    *iter = value;
}

template <class T>
void SeqContainer<T>::erase(std::size_t position)
{
    typename SeqContainer<T>::iterator start = &buff[position];

    for (auto iter = start; iter != (end() - 1); ++iter)
    {
        *iter = *(iter + 1);
    }
    resize(sz - 1);
}

template <class T>
void SeqContainer<T>::reserve(std::size_t capacity)
{
    T* new_buff = new T[capacity];

    std::copy(buff, buff + sz, new_buff);

    cap = capacity;
    delete[] buff;
    buff = new_buff;
}

template <class T>
std::size_t SeqContainer<T>::size() const
{
    return sz;
}

template <class T>
void SeqContainer<T>::resize(std::size_t size)
{
    reserve(size);
    sz = size;
}

template <class T>
T& SeqContainer<T>::operator[](std::size_t index) const
{
    return buff[index];
}

template <class T>
std::size_t SeqContainer<T>::capacity() const
{
    return cap;
}

template <class T>
void SeqContainer<T>::display()
{
    if (empty())
    {
         std::cout << "Похоже, контейнер-то пустой" << std::endl;
    }

    std::cout << "Вывод содержимого контейнера на экран:" << std::endl;

    for (typename SeqContainer<T>::iterator iter = begin(); iter != end(); ++iter)
    {
        std::cout << " " << *iter;
    }
    std::cout << std::endl << std::endl;
}

template <class T>
SeqContainer<T>::~SeqContainer()
{
    delete[] buff;
}
