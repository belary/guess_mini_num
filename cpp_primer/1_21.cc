#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item1, item2;
    std::cout << "Please input books for add: " << std::endl;
    std::cin >> item1 >> item2;
    if (item1.isbn() == item2.isbn())
    {
        std::cout << item1 + item2 << std::endl;
        return 0;
    } else {
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1;
    }
}