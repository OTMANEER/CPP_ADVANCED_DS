#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cassert>
#include <vector>
#include "Element.h"
#include <algorithm>

using namespace std;

template <typename K, typename V> // added
class Node
{

private:
    int nbElements{};
    K key;
    std::vector<Element<K, V> *> children;

public:
    Node()
    {
        nbElements = 0;
    }

    ~Node()
    {
        for (Element<K, V> *e : children)
        {
            delete *e;
        }
        delete *children;
    }

    void erase()
    {
        delete &children;
        //  children = nullptr;
        nbElements = 0;
    }

    // add Children to the dynamic array-------------------------------------------

    void addElement(Element<K, V> *e)
    {
        if (e != nullptr)
        {
            e->printElement();
            children.push_back(e);
            setKey(children[0]->getKey());
            this->printElement();
            nbElements++;
        }

        // addChild(e->getKey(), e->getValue());
    }

    // void addChild(K key, V value)
    // {
    //     children.push_back(new Element<K, V>(key, value));
    //     setKey(children[0]->getKey());
    //     this->printElement();
    //     nbElements++;
    // }

    void deleteElement(Element<K, V> *ee)
    {
        //children.erase(std::remove(children.begin(), children.end(), e), children.end());
        // std::vector<Element<K, V> *>::iterator *a;
        typename vector<Element<K, V> *>::iterator it;
        it = children.begin();
        // = children.begin();
        // std::cout << " keyeeee" << a->getKey();
        for (Element<K, V> *e : children)
        {
            if (ee->getKey() == e->getKey() && ee->getValue() == e->getValue() && it != children.end())
            {
                it = children.erase(it);
            }
            ++it;
        }
        nbElements = children.size();
        if (nbElements == 0)
            this->erase();
    }

    // add Children to the dynamic array -------------------------------------------------

    void printElement()
    {

        std::cout << "\nthe current Node has: " << this->getLength() << " elements \n"
                  << std::endl;
        for (Element<K, V> *e : children)
        {
            e->printElement();
        }
    }

    K getKey()
    {
        return key;
    }

    void setKey(K keya)
    {
        this->key = keya;
    }

    std::vector<Element<K, V> *> getElements(K keya)
    {
        std::vector<Element<K, V> *> subChildren;
        for (Element<K, V> *e : children)
        {
            if (e->getKey() == keya)
            {
                subChildren.push_back(new Element<K, V>(e->getKey(), e->getValue()));
            }
        }
        return subChildren;
    }

    // templated getLength() function defined below
    int getLength() const;
};

// member functions defined outside the class need their own template declaration
template <typename K, typename V>
int Node<K, V>::getLength() const // note class name is Array<T>, not Array
{
    return children.size();
}

#endif