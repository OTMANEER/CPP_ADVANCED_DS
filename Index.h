#ifndef INDEX_H
#define INDEX_H

#include <iostream>
#include <cassert>
#include <vector>
#include "Element.h"
#include "Node.h"
#include <algorithm>

template <typename K, typename V> // added
class Index
{
private:
    int nbElements{};
    std::vector<Node<K, V> *> noeuds;

public:
    Index()
    {
        nbElements = 0;
    }
    ~Index()
    {
        for (Node<K, V> *n : noeuds)
        {
            delete *n;
        }
        delete *noeuds;
    }

    void addNode(Node<K, V> *n)
    {
        if (n != nullptr)
        {
            noeuds.push_back(n);
            nbElements++;
        }
    }

    //------------------------print them out
    void printElement()
    {
        std::cout << " ******************* Start Printing out ***********************************" << endl;
        std::cout << "\nYou have Created: " << this->getNbElements() << " Nodes \n";
        if (noeuds.size() != 0)
            for (Node<K, V> *e : noeuds)
            {
                std::cout << "\n------------------------- " << endl;
                std::cout << "Printing Node of key: " << e->getKey() << endl;
                std::cout << "--------------------------- " << endl;

                e->printElement();
            }
        else
            std::cout << "\n Nothing to print :(\n"
                      << endl;
        std::cout << " ******************* End  Printing out ***********************************" << endl;
    }

    Node<K, V> *getNode(K key)
    {
        Node<K, V> *tempNode = new Node<K, V>();
        tempNode->setKey(key);

        for (Node<K, V> *n : noeuds)
        {
            if (n->getKey() == key)
            {
                tempNode = n;
                break;
            }
        }
        return tempNode;
    }

    void deleteNode(K key)
    {
        //children.erase(std::remove(children.begin(), children.end(), e), children.end());
        // std::vector<Element<K, V> *>::iterator *a;
        typename vector<Node<K, V> *>::iterator it;
        it = noeuds.begin();
        for (Node<K, V> *e : noeuds)
        {
            if (key == e->getKey() && it != noeuds.end())
            {
                it = noeuds.erase(it);
            }
            ++it;
        }
        nbElements = noeuds.size();
        if (nbElements == 0)
        {
            std::cout << " Zero Nodes are attached to your INDEX! " << endl;
        }
    }

    std::vector<Element<K, V> *> getElements(K keya)
    {
        std::vector<Element<K, V> *> subChildren;

        for (Node<K, V> *n : noeuds)
        {
            if (n->getKey() == keya)
            {
                subChildren = n->getElements(keya);
            }
        }
        return subChildren;
    }

    void addElement(Element<K, V> *el)
    {
        typename vector<Node<K, V> *>::iterator it;
        it = noeuds.begin();

        for (Node<K, V> *node : noeuds)
        {

            if (node->getKey() == el->getKey() && it != noeuds.end())
            {
                cout << " Element Found" << node->getKey() << endl;
                node->addElement(el);
                this->deleteNode(node->getKey());
                this->addNode(node);
            }
            it++;
        }
    }

    void deleteElement(Element<K, V> *el)
    {
        typename vector<Node<K, V> *>::iterator it;
        it = noeuds.begin();

        for (Node<K, V> *node : noeuds)
        {
            if (node->getKey() == el->getKey() && it != noeuds.end())
            {
                cout << " Element Found key: " << node->getKey() << endl;
                node->deleteElement(el);
                this->deleteNode(node->getKey());
                this->addNode(node);
            }
            it++;
        }
    }

    int getNbElements()
    {
        return nbElements;
    }
};

#endif