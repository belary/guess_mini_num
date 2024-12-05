#include <iostream>

int main()
{
    unsigned int u = 10, u1 = 42, u2 = 10;
    int i = -42;
    /* 无符号 + 有符号 会转为无符号运算
        i=-42 转为无符号为 4294967254(2^32 - 42)
        再加上10 为 429496726
    */
    std::cout << u + i << std::endl;
    std::cout << i + i << std::endl;

    std::cout << u1 - u2 << std::endl;
    /*
        u1 - u2 = -32 转为无符号数为(2^32 -32) 4294967264
    */
    std::cout << u2 - u1 << std::endl;

    // 当u=0的时候，u变成-1不满足无符号的要求，会被自动转换为4294967295
    for (unsigned int u = 10; u > 0; --u)
    {
        std::cout << u << std::endl;
    }
    return 0;
}