#include <iostream>
int main()
{
    int currVal = 43;
    const int *pi = &currVal;
    const int &ri = currVal;
    // *pi = 42; //error: read-only variable not assignable
    // ri = 42; //error: cannot assign to variable 'ri' with const-qualified type 'const int &'
    std::cout << "pi = " << pi << std::endl;
    std::cout << "*pi = " << *pi << std::endl;
    std::cout << "ri = " << ri << std::endl;
    return 0;
}