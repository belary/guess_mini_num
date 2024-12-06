#include "unp.h"
int main(int argc, char **argv)
{
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in serveraddr;
    
    if (argc != 2) 
    {
        err_quit("usage: a.out <IPaddress>");
    }

    if( (sockfd = socket(AF_INET, SOCK_STREAM, 0 )) < 0 )
    {
        err_sys("socket error");
    }

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(13);

    if (inet_pton(AF_INET, argv[1], &serveraddr.sin_addr) <= 0)
        err_quit("inet_pton error for %s", argv);
    if (connect(sockfd, (SA*)&serveraddr, sizeof(serveraddr))<0)
        err_sys("connect error");

    // 消息循环
    while ( (n = read(sockfd, recvline, MAXLINE)) > 0 )
    {
        recvline[n] = 0;
        if (fputs(recvline, stdout) == EOF)
        {
            err_sys("fput error");
        }
    }

    if (n < 0) 
        err_sys("read error");

    exit(0);
}