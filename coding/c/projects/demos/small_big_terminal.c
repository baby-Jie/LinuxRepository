#include <stdio.h>

int main()
{
    int x = 0x12345678;
    char* c = &x;
    printf("%x, %x, %x, %x\n", *c, *(c+1), *(c+2), *(c+3));
    return 0;
}
