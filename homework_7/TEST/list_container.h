#include <stdexcept>
#include <iostream>

template <typename T>
struct Node
{
    Node();
    T m_Value;
    Node<T>* prev = nullptr;
    Node<T>* next = nullptr;
};

template <typename T>
Node<T>::Node()
{
    prev = nullptr;
    next = nullptr;
}

template <typename T>
class ListContainer
{

private:
    Node<T>* head;
    Node<T>* tail;
    size_t sz;

public:
    ListContainer();
    ~ListContainer();

    void push_back(const T& val);

    void erase(std::size_t position);

    void pop_back();

    size_t size() const;

    void insert(std::size_t position, const T& val);

    T operator[](std::size_t position);

    void display();
};

template <typename T>
ListContainer<T>::ListContainer() : head(nullptr), tail(nullptr), sz(0) {}

template <typename T>
ListContainer<T>::~ListContainer()
{
    while (nullptr != head)
    {
        pop_back();
    }
}

template <typename T>
void ListContainer<T>::push_back(const T& val)
{
    Node<T>* node = new Node<T>;
    node->m_Value = val;

    if (sz > 0)
    {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    else
    {
        head = tail = node;
    }

    sz++;
}

template <typename T>
void ListContainer<T>::pop_back()
{
    if (sz > 0)
    {
        sz--;
        Node<T>* delNode = tail;
        tail = tail->prev;
        if (nullptr == tail)
        {
            head = nullptr;
            if (delNode != nullptr)
            {
                delete delNode;
            }
            return;
        }

        tail->next = nullptr;

        if (delNode != nullptr)
        {
            delete delNode;
        }
    }
    else
    {
        std::cout << "pop_back() error: container is empty" << std::endl;
    }
}

template <typename T>
void ListContainer<T>::erase(std::size_t position)
{
    if (position < 0)
    {
        std::cout << "erase() error: invalid position" << std::endl;
        return;
    }

    if (nullptr == head)
    {
        std::cout << "erase() error: empty container" << std::endl;
        return;
    }

    if (0 == position)
    {
        head = head->next;
        if (nullptr != head)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
    }

    else
    {
        Node<T>* temp = head;
        size_t n = 0;

        while (nullptr != temp && n < position)
        {
            temp = temp->next;
            n++;
        }
        if (nullptr == temp)
        {
            std::cout << "erase() error: deleted node position are not found" << std::endl;
        }
        else
        {
            temp->prev->next = temp->next;
            if (nullptr != temp->next)
            {
                temp->next->prev = temp->prev;
            }
            else
            {
                tail = temp->prev;
            }
            delete temp;
        }
    }
    sz--;
}

template <typename T>
void ListContainer<T>::insert(std::size_t position, const T& val)
{
    Node<T>* node = new Node<T>;
    node->m_Value = val;
    node->next = nullptr;
    node->prev = nullptr;
    if (position < 0)
    {
        std::cout << "insert() error: invalid position" << std::endl;
    }
    else if (0 == position)
    {
        node->next = head;
        head->prev = node;
        head = node;
        sz++;
    }
    else
    {
        Node<T>* temp = head;
        for (size_t i = 0; i < position - 1; i++)
        {
            if (nullptr != temp)
            {
                temp = temp->next;
            }
        }
        if (nullptr != temp)
        {
            node->next = temp->next;
            node->prev = temp;
            temp->next = node;
            if (nullptr != node->next)
            {
                node->next->prev = node;
            }
            sz++;
        }
        else
        {
            std::cout << "insert() error: the previous node is null" << std::endl;
        }
    }
}

template <typename T>
void ListContainer<T>::display()
{
    if (nullptr == head)
    {
        std::cout << "print() warning: empty container" << std::endl;
    }
    else
    {
        Node<T>* temp = head;
        std::cout << "container elements are:" << std::endl;
        while (nullptr != temp)
        {
            std::cout << "  " << temp->m_Value;
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

template <typename T>
T ListContainer<T>::operator[](std::size_t position)
{
    if (position < 1)
    {
        throw std::runtime_error("operator[] error: invalid position");
    }
    if (nullptr == head)
    {
        throw std::runtime_error("operator[] error: empty container");
    }
    Node<T>* temp = head;
    int n = 0;
    while (nullptr != temp && n < position)
    {
        temp = temp->next;
        n++;
    }
    if (nullptr == temp)
    {
        throw std::runtime_error(
        "operator[] error: element position are not found");
    }
    else
    {
        return (temp->next->m_Value);
    }
}

template <typename T>
size_t ListContainer<T>::size() const
{
    return sz;
}
