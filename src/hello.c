// g++ -c hello.cpp -o hello.o
// ar cr libhello.a hello.o
// g++ -shared -o hello.so hello.o
// gcc/g++ -fPIC hello.c -shared -o libhello.so
#include <stdio.h>
#include "hello.h"

void say(const char* s)
{
    printf("Hello %s\n", s);
}