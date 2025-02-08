#include "apue.h"
#include <errno.h>

int main(int argc, char *argv[])
{
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    // errno：这是一个全局变量，定义在 `<errno.h>` 头文件中。它用于指示最近一次系统调用或库函数的错误类型。
    // ENOENT：表示“没有这样的文件或目录”。
    errno = ENOENT;
    //  perror() 函数：用于将错误消息打印到标准错误流（通常是 stderr）。它将 errno 的值转换为相应的错误消息，并添加到提供的字符串后面。
    perror(argv[0]);
    exit(0);
}