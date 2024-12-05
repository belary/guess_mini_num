#include <iostream>
int i = 100, sum = 0;
int main() 
{
    for (int i = 0; i != 10; i++) 
        sum += i;
    std::cout << "sum = " << sum << std::endl
        << "i = " << i << std::endl;
    return 0;
}