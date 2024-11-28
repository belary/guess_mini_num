#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item currItem, item2;
    std::cout << "Please input books for add: " << std::endl;
    if (std::cin >> currItem)
    {
        Sales_item totalItem = currItem;
        while (std::cin >> item2)
        {
            if (currItem.isbn() == item2.isbn())
            {
                totalItem += item2;
            }
            else
            {
                std::cout << "totalItem: " << totalItem << std::endl;
                totalItem = item2;
            }
        }
        std::cout << "totalItem: " << totalItem << std::endl;
    }
}