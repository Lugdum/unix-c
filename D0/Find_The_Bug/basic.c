#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = NULL;
    *p = 42;

    printf("*p = %d\n", *p);

    return 0;
}

/*
Program received signal SIGSEGV, Segmentation fault.
0x000055555555514d in main () at basic.c:6
6	    *p = 42;
*/
