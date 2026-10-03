#include <assert.h>
#include <stdbool.h>



int iSetBit(int inVal, int iBit, bool boSetVal)
{
    //1. "x" = inVal & (~(0x01 << iBit)  // clears iBit in inVal  ) 
    //2. "y" ="x" | (boSetVal << iBit)   // set the iBit with boSetVal into inVal)
    //3. return (int) y
    return (int)((inVal & (~(0x01 << iBit))) | (boSetVal << iBit));

}

int main (void)
{

    int myregister = 0x100;

    myregister = iSetBit(myregister, 8, 0);

    assert((myregister & (0 << 8)) == 0);

    myregister = iSetBit(myregister, 8, 1);

    assert((myregister & (1 << 8)) == 0x100);

}
