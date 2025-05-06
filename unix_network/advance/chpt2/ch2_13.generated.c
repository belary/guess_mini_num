#include <unistd.h>
#include <stdio.h>
int main(void) {
#ifdef _SC_ARG_MAX
    printf("_SC_ARG_MAX defined to be %d\n", _SC_ARG_MAX);
    printf("_SC_ARG_MAX = %ld\n", sysconf(_SC_ARG_MAX));
#else
    printf("no symbol for _SC_ARG_MAX\n");
#endif
#ifdef _SC_OPEN_MAX
    printf("_SC_OPEN_MAX defined to be %d\n", _SC_OPEN_MAX);
    printf("_SC_OPEN_MAX = %ld\n", sysconf(_SC_OPEN_MAX));
#else
    printf("no symbol for _SC_OPEN_MAX\n");
#endif
#ifdef _PC_NAME_MAX
    printf("_PC_NAME_MAX defined to be %d\n", _PC_NAME_MAX);
    printf("_PC_NAME_MAX = %ld\n", pathconf("/", _PC_NAME_MAX));
#else
    printf("no symbol for _PC_NAME_MAX\n");
#endif
#ifdef _PC_PATH_MAX
    printf("_PC_PATH_MAX defined to be %d\n", _PC_PATH_MAX);
    printf("_PC_PATH_MAX = %ld\n", pathconf("/", _PC_PATH_MAX));
#else
    printf("no symbol for _PC_PATH_MAX\n");
#endif
    return 0;
}
