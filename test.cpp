#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include "Element.h"
#include "Node.h"
#include "Index.h"

// Tokenize the file into tokens ready to use them in our Project as Elements
void tokenize(std::string const &str, const char delim, std::vector<std::string> &out)
{
    std::stringstream ss(str);
    std::string s;
    while (std::getline(ss, s, delim))
    {
        out.push_back(s);
    }
}

int main()
{
    std::ifstream file("test.txt");
    std::string str;
    const char delim = ' ';

    // The base Index
    Index<int, const char *> *index = new Index<int, const char *>();
    Node<int, const char *> *node = new Node<int, const char *>();

    while (std::getline(file, str))
    {
        std::vector<std::string> out;
        tokenize(str, delim, out);
        int key = stoi(out[0]);
        const char *value = out[1].c_str();
        // Start Testing

        //   std::cout << key << value << endl;
        Element<int, const char *> *tempElement = new Element<int, const char *>(key, value);
        //tempElement->printElement();
        node->addElement(tempElement);
        // node->printElement();
        value = NULL;
        key = 0;
    }

    // node->printElement();
    return 0;
}