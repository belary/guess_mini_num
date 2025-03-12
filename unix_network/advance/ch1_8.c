#include "apue.h"
#include <errno.h>

int main(int argc, char *argv[])
{
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    // errno：这是一个全局变量，定义在 `<errno.h>` 头文件中。它用于指示最近一次系统调用或库函数的错误类型。
    // ENOENT：表示“没有这样的文件或目录”。
    errno = ENOENT;
    // 将程序名（argv[0]）作为参数传递给 perror，可以在错误输出中添加一个明确的标识，
    // 使得在程序作为管道一部分执行时，用户可以快速判断出哪个程序产生了具体的错误消息。
    // 这种做法符合 UNIX 标准惯例，有助于提高调试效率和程序的可维护性。
    // e.g. prog1 <inputfile | prog2 | prog3 > outputfile
    /*
        数据流动
        - - - - - - - 
        prog1 从 inputfile 中读取数据。
        prog1 处理后，将结果输出到管道中。
        prog2 从这个管道中读取 prog1 的输出，进行进一步处理，并将结果再次通过管道传给 prog3。
        prog3 处理后，将最终结果输出，重定向保存到 outputfile 文件中。

        错误输出（stderr）的处理
        - - - - - - - 
        默认情况下，错误输出（stderr）不会经过管道传递，而是直接输出到终端（或父进程所指定的目标）。
        如果每个程序在出错时使用 perror(argv[0]) 打印错误消息，那么错误信息前缀会包含程序名（例如 prog1:、prog2: 或 prog3:），
        从而在混合的错误信息中能够分辨出是哪个程序产生的错误。这在多个程序协作处理数据时非常有用，便于定位问题。
    */

    perror(argv[0]);
    exit(0);
}