#include <stdio.h>
#include <stdlib.h>

#define MODULE_mCmdSize(CMD_SET)   sizeof(CMD_SET)/sizeof(CMD_SET[0])
typedef unsigned int uint16;

uint16 au16SetACmd[]      = {                                                                           \
                                                0x00DE, 0x0101, 0x0100, 0x0100, 0x0102, 0x0100,                         \
                                                0x0100, 0x0100, 0x0100, 0x0100, 0x0109, 0x0100,                         \
                                                0x0100, 0x017F, 0x0100, 0x01FF, 0x0101, 0x01DF,                         \
                                                0x0101, 0x010D, 0x0105, 0x019F, 0x0103, 0x0129                          \
                                            };

uint16 au16SetBCmd[]  = { 0x00DE, 0x0100};
uint16 au16SetCCmd[]     = {0x0029};


int main (void) {
    printf("Sizes: \n%d\n%d\n%d\n", sizeof(au16SetACmd)/sizeof(uint16)\
                                , sizeof(au16SetBCmd)/sizeof(uint16)\
                                , sizeof(au16SetCCmd)/sizeof(uint16));


    printf("Sizes with macro: \n%d\n%d\n%d\n", MODULE_mCmdSize(au16SetACmd)\
                                , MODULE_mCmdSize(au16SetBCmd)\
                                , MODULE_mCmdSize(au16SetCCmd));
typedef unsigned char boolean;
boolean boPdb = 1;

printf("boPdb = %d\n", boPdb);
boPdb = !boPdb;
printf("post invert boPdb = %d\n", boPdb);

}