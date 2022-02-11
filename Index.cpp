#include <iostream>
#include <vector>
#include "Element.h"
#include "Node.h"
#include "Index.h"

int main(int argc, char const *argv[])
{

    Node<int, char *> *node1 = new Node<int, char *>();
    Node<int, char *> *node2 = new Node<int, char *>();

    char a[]{"OTMANE"};
    char aa[]{"SALEH"};
    char aaa[]{"ZAKIA"};
    char aaaa[]{"Belal"};

    node1->addChild(1, aaa);
    node1->addChild(1, a);
    node1->addChild(2, a);
    node1->addChild(3, aa);
    node2->addChild(4, aaaa);

    Element<int, char *> *e = new Element<int, char *>(1, a);
    Element<int, char *> *ee = new Element<int, char *>(1, a);
    Element<int, char *> *eee = new Element<int, char *>(4, a);
    node2->addElement(e);
    node2->addElement(ee);

    Index<int, char *> *index = new Index<int, char *>();
    index->addNode(node1);
    index->addNode(node2);
    //index->printElement();

    Node<int, char *> *tempNode = index->getNode(1);
    // tempNode->printElement();

    // index->deleteNode(1);
    //index->deleteNode(4);
    //std::cout << " \n after delete\n\n";

    //index->printElement();

    // std::vector<Element<int, char *> *> elements = index->getElements(1);

    // for (Element<int, char *> *el : elements)
    // {
    //     el->printElement();
    // }

    index->addElement(eee);
    index->printElement();
    index->deleteElement(eee);
    index->deleteElement(ee);
    index->printElement();

    //    // node1->printElement();
    //     node1->deleteElement(e);
    //     node1->printElement();

    return 0;
}
