#include <iostream>

int main()
{
    int *ip, i, &r = i;
    std::cout <<"type i = " << typeid(i).name() << std::endl 
    << "type ip = " << typeid(ip).name() << std::endl 
    << "type r = " << typeid(r).name() << std::endl 
    << std::endl << "i = " << i << std::endl;
    std::cout << "ip = " << ip << std::endl;
    std::cout << "r = " << r << std::endl;
    return 0;
}