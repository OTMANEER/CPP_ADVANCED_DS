#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>

template <typename K, typename V>

class Element
{
private:
    K key;
    V value;

public:
    Element(K keya, V valuea)
    {
        key = keya;
        value = valuea;
    }

    ~Element()
    {
    }

    K getKey()
    {
        return key;
    }

    V getValue()
    {
        return value;
    }

    void setKey(K keya)
    {
        key = keya;
    }

    void setValue(V valuea)
    {
        value = valuea;
    }

    void printElement()
    {
        std::cout << " key: " << key << ", value: " << value << "\t \n";
    }
};

#endif