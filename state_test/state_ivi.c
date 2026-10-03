#include <stdio.h>
#include <stdlib.h>


#include "state_ivi.h"



typedef struct
{
   tenModeId enNextMode;
   tpfvAction pfvAction;
} tenStateElement;

const tenStateElement enModeSwitchTable[enNumOfMode][enNumOfEvs] = {
   {{enMode_BT, vTunerToBTEvBT}, {enMode_Tuner, NULL}},
   {{enMode_BT, NULL}, {enMode_Tuner, vBTToTunerEvTuner}},
};

tenModeId enCurrentModeId = enMode_Tuner;

void vTunerToBTEvBT(void)
{
   //
   //Load  BT SM
   enCurrentModeId = enMode_BT;
   printf("\nMode Entered: %d\n",enCurrentModeId );
}

void vBTToTunerEvTuner(void)
{
   //
   //Load Tuner SM
   enCurrentModeId = enMode_Tuner;
   printf("\nMode Entered: %d\n",enCurrentModeId );
}

void vHandleEvent (tenEventId enEventRec)
{
   //Error handling
   if (enEventRec < enNumOfEvs)
   {
      if (NULL != enModeSwitchTable[enCurrentModeId][enEventRec].pfvAction)
      {
         enModeSwitchTable[enCurrentModeId][enEventRec].pfvAction();

      }
      else
      {
         /* code */
         printf ("Null Action");
      }
      
   }
{
   /* code */
}


}

int main(void)
{
   tenEventId enModeEventID = 0;
   char input[]="00";
   while (1)
   {
      printf("\nCurrent Mode ID: %d\n",enCurrentModeId );
      input = getc(stdin);
//   getline();

      getc(stdin);
      enModeEventID = atoi(input[0]);
      printf("\nChar input: %c. converted ID : %d\n",input[0], enModeEventID );

      vHandleEvent(enModeEventID);
   }


}
