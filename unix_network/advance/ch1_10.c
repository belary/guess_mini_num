#include "apue.h"

#include <sys/wait.h>
#include <errno.h>
#include <string.h>

static void sig_int(int signo);
static volatile sig_atomic_t sigint_received = 0;

int main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("程序启动，PID: %d\n", getpid());
    printf("(输入 'exit' 或 'quit' 可以退出程序)\n");
    
    //signal() 用于设置一个信号处理函数，当程序收到 SIGINT 信号（通常是 Ctrl + C 产生的信号）时，会调用 sig_int() 函数进行处理。
    if (signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal error");

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
    for (;;) { // 使用无限循环替代while
        if (fgets(buf, MAXLINE, stdin) == NULL) {
            if (errno == EINTR) { // 如果是因为信号中断
                errno = 0;        // 重置errno
                if (sigint_received) {
                    sigint_received = 0;
                    continue;     // 重新尝试读取
                }
            }
            break;               // 其他错误或EOF则退出
        }

        //有换行符，则将其替换为字符串结束符 
        /*
        1. 检查字符串末尾是否有换行符：
            strlen(buf) 计算字符串 buf 的长度
            strlen(buf) - 1 得到最后一个字符的索引
            buf[strlen(buf) - 1] 获取字符串的最后一个字符
            == '\n' 检查这个字符是否是换行符
        2.如果有换行符，则将其替换为字符串结束符：
            buf[strlen(buf) - 1] = 0 将最后一个字符（换行符）替换为 \0（字符串结束符）
        3. 为什么要这样做：
            当用户在终端输入命令并按下回车键时，fgets() 函数会读取包括换行符在内的整行内容
            但在执行命令时，我们不需要这个换行符
            这段代码的目的就是去掉输入字符串末尾的换行符
        4. 实际效果：
            输入："ls\n"（用户输入"ls"并按回车）
            处理后："ls\0"（可执行的命令字符串）
            这是命令行程序中常见的输入处理技巧，确保从用户那里获取的命令可以正确传递给 execlp() 函数执行
        */
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0;

        // 检查是否是退出命令
        if (strcmp(buf, "exit") == 0 || strcmp(buf, "quit") == 0) {
            printf("收到退出命令，程序结束\n");
            break;
        }

        printf("读取到输入: %s\n", buf);
        
        if ((pid = fork()) < 0) { // 这里fork() 返回时，子进程已经存在
            err_sys("fork error");
        } else if (pid == 0) {
            printf("子进程启动，PID: %d\n", getpid());
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        printf("父进程等待子进程，子进程PID: %d\n", pid);
        if (waitpid(pid, &status, 0) < 0) // 这里waitpid() 返回时，子进程已经结束
            err_sys("waitpid error");
        printf("子进程已结束\n%% ");
    }
    printf("主循环结束，程序退出\n");
    return 0;
}

static void sig_int(int signo)
{
    sigint_received = 1;  // 设置标志
    printf("\n信号处理函数被调用，信号编号: %d\n", signo);
    printf("interrupt\n%% ");
    fflush(stdout);  // 确保输出被刷新
    
    // 在某些系统上可能需要重新注册信号处理器
    if (signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal error");
}