#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foo(char *str) {
    char buf[8];
    strcpy(buf, str);

    printf("buf: %s\n", buf);
}

int main() {
    char str[32];

    for (size_t i = 0; i < 31; i++)
        str[i] = 'a';

    str[31] = 0;

    foo(str);
    return 0;
}

/*
==8676==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7ffd76f98c48 at pc 0x7f5cfffb4e16 bp 0x7ffd76f98c00 sp 0x7ffd76f983a8
WRITE of size 32 at 0x7ffd76f98c48 thread T0
    #0 0x7f5cfffb4e15 in __interceptor_strcpy /build/gcc/src/gcc/libsanitizer/asan/asan_interceptors.cpp:438
    #1 0x55a958e02268 in foo /home/victor.buthod/D0/Find_The_Bug/overflow.c:7
    #2 0x55a958e02414 in main /home/victor.buthod/D0/Find_The_Bug/overflow.c:20
    #3 0x7f5cffdc0151 in __libc_start_main (/usr/lib/libc.so.6+0x28151)
    #4 0x55a958e020fd in _start (/home/victor.buthod/D0/Find_The_Bug/overflow+0x10fd)

Address 0x7ffd76f98c48 is located in stack of thread T0 at offset 40 in frame
    #0 0x55a958e021d8 in foo /home/victor.buthod/D0/Find_The_Bug/overflow.c:5

  This frame has 1 object(s):
    [32, 40) 'buf' (line 6) <== Memory access at offset 40 overflows this variable
*/
