#include <iostream>
#include "Node.h"

int main(int argc, char const *argv[])
{
    Node<int, char *> *node1 = new Node<int, char *>();

    char a[]{"OTMANE"};
    char aa[]{"SALEH"};
    char aaa[]{"ZAKIA"};
    char aaaa[]{"Belal"};

    node1->addChild(1, aaa);
    node1->addChild(2, a);
    node1->addChild(3, aa);
    node1->addChild(4, aaaa);

    Element<int, char *> *e = new Element<int, char *>(5, a);
    Element<int, char *> *ee = new Element<int, char *>(5, a);
    node1->addElement(e);
    node1->addElement(ee);

    node1->printElement();
    node1->deleteElement(e);
    node1->deleteElement(ee);
    node1->printElement();

    // std::vector<Element<int, char *> *> subChildren;
    // subChildren = node1->getElements(12);

    // for (Element<int, char *> *e : subChildren)
    // {
    //     e->printElement();
    // }

    // node1->deleteElement(e);
    //std::cout << " \n after delete element" << endl;
    //node1->printElement();
    // std::cout << subChildren[0]->getKey() << endl;
    // std::cout << subChildren[0]->getValue() << endl;

    return 0;
}
