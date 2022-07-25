#include "SpeedControl.h"
#include "PinDefines.h"

static uint8_t mCurrentSpeed = SPEED_NUM;

const MicroStepType SpeedControl_SpeedOptionArray[SPEED_NUM] = { 
  { 1, 1, 1 },
  { 1, 1, 0 },
  { 0, 1, 0 },
  { 1, 0, 0 },
  { 0, 0, 0 },
  };

uint8_t SpeedControl_GetCurrentSpeed()
{
  return mCurrentSpeed;
}

void SpeedControl_SetSpeed(uint8_t speedVal)
{
  if( mCurrentSpeed != speedVal)
  {
    mCurrentSpeed = speedVal;
    digitalWrite(MS1, SpeedControl_SpeedOptionArray[speedVal].MicroStep1);
    digitalWrite(MS2, SpeedControl_SpeedOptionArray[speedVal].MicroStep2);
    digitalWrite(MS3, SpeedControl_SpeedOptionArray[speedVal].MicroStep3);
  }
}
