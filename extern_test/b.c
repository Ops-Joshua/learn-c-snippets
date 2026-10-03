#include <stdio.h>

extern void func_a(void);

int var_glob;

int main(void)
{
    var_glob=10;

    printf ("var_glob is %d \n", var_glob);

    func_a();

    return 0;
}
