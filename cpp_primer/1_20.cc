#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item;
    std::cout << "Please input books for sale: " << std::endl;
    while (std::cin >> item) 
    {
        std::cout << "item: " << item << std::endl;
    }
    return 0;
}