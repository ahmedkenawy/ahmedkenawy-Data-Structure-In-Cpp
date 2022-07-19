#include <iostream>
using namespace std;
template <typename T>
class Entry
{
    int key;
    T value;
    Entry *next;

public:
    Entry(int key, T value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    Entry()
    {
        next = NULL;
    }

    int getKey()
    {
        return key;
    }

    T getValue()
    {
        return value;
    }
};

template <typename T>
class HashTable
{
    Entry<T> **ptr;
    int size;

public:
    HashTable(int size)
    {
        this->size = size;
        ptr = new Entry<T>[this->size];
        for (int i = 0; i < this->size; i++)
        {
           ptr[i] =new Entry<T>();
        }
        
    }
};
int main()
{
    HashTable<int> t(10);
}