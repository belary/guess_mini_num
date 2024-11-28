#include <iostream>
int main() 
{
    int currVal = 0, val = 0;
    /*
     * 回车键告诉输入流这一行结束了，当按完回车之后
     * std::cin才能实际读取到用户的输入
     * 程序在处理完这行输入才会进行输出结果          
    */
    if (std::cin >> currVal) 
    {
        int cnt = 1;
        while (std::cin >> val)
        {
            if ( val == currVal)
                ++cnt;
            else
            {
                std::cout << currVal << " occurs " << cnt << " times" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        // 最后一个数
        std::cout << currVal << " occurs " << cnt << " times " << std::endl;
    }
    return 0;
}