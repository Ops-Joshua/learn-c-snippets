#include <stdio.h>

extern int var_glob;


void func_a(void)
{
    printf ("in func_a() var_glob = %d\n", var_glob);

}


