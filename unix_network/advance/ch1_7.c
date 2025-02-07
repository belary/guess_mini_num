#include "apue.h"

#include <sys/wait.h>

int main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");

/*
1.fork() 是创建新进程的时刻，在这个时刻之前：
    - 只有父进程在运行
    - 子进程还不存在
2.fork() 执行时：
    - 创建子进程
    - 复制父进程的内存空间（包括代码和数据）
    - 子进程从 fork() 返回处开始执行
*/
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0;

        if ( (pid = fork()) < 0) {
            err_sys("fork error");
        } else if (pid == 0) {
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        if (waitpid(pid, &status, 0) < 0)
            err_sys("waitpid error");
        printf("%% ");
    }
    return 0;
}