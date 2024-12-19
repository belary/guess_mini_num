#include <iostream>

struct Node {
    int id;
};
int main()
{
    Node nodeList[10];
    Node *p = nodeList;
    for (int i = 0; i < 10; i++) {
        nodeList[i].id = i;
    }

    std::cout << "Node[1]=" << nodeList[1].id << std::endl;

    std::cout << "typeof(*(p+1)) = " << typeid(*(p+1)).name() << ", typeid(p) = " << typeid(p).name() << std::endl;
    std::cout << " *(p+1) =" << (*(p+1)).id << std::endl;
    std::cout << " *(p+2) =" << (*(p+2)).id << std::endl;
    return 0;
}