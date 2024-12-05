#include <iostream>

int main() 
{
    std::cout << "Hi \x4dO\115!" << std::endl;
    std::cout << "\123" << std::endl;
    std::cout << "\1234" << std::endl;

    std::cout << L'a' << std::endl;
    std::cout << u8"hi!" << std::endl;
    std::cout << 42ULL << std::endl;
    std::cout << 1E-3F << std::endl;
    std::cout << 3.14150L << std::endl;

    std::cout << "Who goes with F\145rgus?\012" << std::endl;

    std::cout << "2\115" << std::endl;
    std::cout << "2\t\115" << std::endl;
    return 0;
}