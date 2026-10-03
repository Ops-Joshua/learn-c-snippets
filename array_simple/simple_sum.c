#include <stdio.h>

int main() {
    int values []={6,1,9,8,9};
    int x,z,sum = 0;

    for (z=5; z>=0; z--)
    {
        sum = sum + values[z];
    }
    printf ("sum is %d", sum);
}