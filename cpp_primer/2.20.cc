#include <iostream>

int main()
{
    int i = 42, *pi = &i;
    *pi = *pi * *pi;
    std::cout << "i = " << i << std::endl
        << "pi = " << pi << std::endl
        << "*pi = " << *pi << std::endl;
    return 0;
}