#include "apue.h"

int main(void)
{
    printf("hello from process ID %ld\n", (long)getpid());
    exit(0);
}