#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\\:n", argv[0]);
        exit(1);
    }
    
    struct in_addr addr;
    if (inet_pton(AF_INET, argv[1], &addr) <= 0) {
        fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
        exit(1);
    }
    
    printf("IP address is valid.\n");
    return 0;
}