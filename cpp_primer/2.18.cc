#include <iostream>

int main() 
{
    int i = 1, *pi = &i;
    *pi = 2;
    std::cout << "i = " << i << std::endl
        << "pi = " << pi << std::endl;
    pi += 1;
    std::cout << "changed pi = " << pi << std::endl;
    return 0;
    
}