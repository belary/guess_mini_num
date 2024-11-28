#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item currItem, item2;
    std::cout << "Please input books for add: " << std::endl;
    if (std::cin >> currItem)
    {
        int cnt = 1;
        while (std::cin >> item2)
        {
            if (currItem.isbn() == item2.isbn())
            {
                cnt++;
            }
            else
            {
                std::cout << "Item: " << currItem << " occurs " << cnt
                          << " times" << std::endl;
                cnt = 1;
                currItem = item2;
            }
        }
        std::cout << "Item: " << currItem << " occurs " << cnt
                  << " times" << std::endl;
    }
}