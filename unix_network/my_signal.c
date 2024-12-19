#include <unistd.h>
#include <signal.h>
#include <sys/epoll.h>
#include <assert.h>
#include <stdio.h>

int pipe_fd[2];

void sig_handler(int sig) 
{
    // 信号处理函数 (sig_handler) 将信号事件主动写入了管道的写端 pipe_fd[1]，
    // 从而实现了在主程序中通过 pipe_fd[0] 读取信号事件的机制。
    write(pipe_fd[1], &sig, sizeof(sig));
}

int main()
{
    int epoll_fd = epoll_create(1);
    assert(epoll_fd != -1);

    // 创建管道
    pipe(pipe_fd);

    // 捕捉信号ALRM
    signal(SIGALRM, sig_handler);

    // 将管道的读端添加到epoll监听表
    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = pipe_fd[0];
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, pipe_fd[0], &ev);

    // 设置定时器
    // 在 2秒后，操作系统会向进程发送 SIGALRM 信号。
    // 当信号触发时，会调用用户定义的信号处理函数 sig_handler。
    // alarm 函数本身并不直接和管道相关联。它仅仅是触发 SIGALRM 信号。
    // 因此，主程序能够从管道中读取信号，是因为信号处理函数被设计为将信号编号写入管道
    alarm(2);


    while(1)
    {
        struct epoll_event events[10];
        int n = epoll_wait(epoll_fd, events, 10, -1);
        for (int i = 0; i < n; i++)
        {
            // 处理读端就绪事件
            if (events[i].data.fd == pipe_fd[0])
            {
                int sig;
                read(pipe_fd[0], &sig, sizeof(sig));
                printf("received signal %d\n", sig);
            }
        }
    }
    printf("hello world");
}