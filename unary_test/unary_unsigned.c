#include <stdio.h>

int main ()
{

    __UINT8_TYPE__ x,y;

    x = 10;
    y = -x;
    printf("x = %d, y=%d\n", x ,y);
    printf(" (int8)y=%d\n", (__INT8_TYPE__) y);
}