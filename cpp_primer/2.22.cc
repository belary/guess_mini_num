#include <iostream>

int main()
{
    int i = 0, *p = &i;
    int *p2 = 0;
    if(p) {
        std::cout << "p is not null" << std::endl;
    } else {
        std::cout << "p is null" << std::endl;
    }

    if (*p) {
        std::cout << "*p is not null" << std::endl;
    } else {
        std::cout << "*p is null" << std::endl;
    }

    if (p2) {
        std::cout << "p2 is not null" << std::endl;
    } else {
        std::cout << "p2 is null" << std::endl;
    }
    return 0;
}