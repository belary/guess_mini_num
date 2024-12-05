#include <iostream>

int main() 
{
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;
    r2 = 3.14159;
    // r2 = r1;
    // i = r2;
    r1 = d;
    std::cout << "d = " << d << ", "
    << "r2 = " << r2 << ", " 
    << "r1 = " << r1 << std::endl;
    return 0;
}