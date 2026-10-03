#include <stdio.h>
//Assume little endian and 32-bit system

struct
{
   char a[20];
   int b;
   union
   {
        double c;
        struct
        {
            char d[15];
            float e;
        }x;
   }y;
}z;

struct
{
    char d[10]; //13
    char e; //1
} w;


struct
{
    char d[15];
    float e;
}testx;

int main(void)
{
    static int x;
    printf("Hello\n");
    printf("%u   %u   %u", sizeof(z.y.x), sizeof(z.y), sizeof(z));
    printf("\nfloat: %u; double %u  ", sizeof(float), sizeof(double));
    printf("\nfloat e: %u", sizeof(z.y.x.e));
    printf("\nw: %u;\tw.e: %u\tw.d: %u", sizeof(w), sizeof(w.e), sizeof(w.d));
    printf("\ntestx: %u;\ttestx.e: %u\ttestx.d: %u", sizeof(testx), sizeof(testx.e), sizeof(testx.d));
    printf("\n%d",1U&(~0));
}


