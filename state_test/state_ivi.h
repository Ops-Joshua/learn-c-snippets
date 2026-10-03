// IVI State Machine Header

typedef enum
{
   enEvBT,
   enEvTuner,
   enNumOfEvs
}tenEventId;

/* signals used by the Keyboard FSM */
typedef enum
{
   enMode_Tuner,
   enMode_BT,
   enNumOfMode
} tenModeId;

typedef void (*tpfvAction) (void);

void vTunerToBTEvBT (void);
void vBTToTunerEvTuner (void);
