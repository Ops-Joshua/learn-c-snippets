#include <stdio.h>
#include <stdlib.h>
// Write a code to reverse 
// 11010001 --> 10001011




int main (void)
{

    unsigned char var1 = 0xD1;
    unsigned char var2 = 0;
    unsigned int datahalves;
    
    datahalves = (sizeof(var1)*4);

    //printf("size= %d\n", sizeof(var2));

    //var1 = var1 >> datahalves | var1 << datahalves;
    printf("Swap halves var1= 0x%x\n", var1);

    //temp:
    datahalves = 8;
    int var3 = 0;

    for (int loop = datahalves-1; loop>=0; loop--)
    {
        
        var2 = var1 & (0x80 >> loop);    //get 1bit
        printf ("var2 = 0x%x (loop: %d)\n", var2, loop);
        printf ("var2 << loop = 0x%x\n", (var2 << loop ));
        var3 = var3 | (var2 << loop);
        printf ("var3 = 0x%x\n\n", var3);
    }
    

    

    return 0;
}