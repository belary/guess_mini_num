#include <iostream>

std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_str;

    std::cout << "global_str: " << global_str
              << ";local_str: " << local_str << std::endl
              << ";global_int: " << global_int << ";local_int: " 
              << local_int << "" << std::endl;
    return 0;
}