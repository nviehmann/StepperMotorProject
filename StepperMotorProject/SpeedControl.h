#ifndef SPEEDCONTROL_H
#define SPEEDCONTROL_H

/* Table pulled from the A4988 DataSheet */  
  /* MS1 MS2 MS3 | Resolution */
  /*  H   H   H  | Sixteenth  */
  /*  H   H   L  | Eighth      */
  /*  L   H   L  | Quarter    */
  /*  H   L   L  | Half       */
  /*  L   L   L  | Full       */
/* ==================================== */
#include <Arduino.h>
#include <stdio.h> // Needed for the uint8_t definition  

//Enumeration for Speed Options
enum
{
  SPEED_SIXTEENTH   = 0,
  SPEED_EIGHTH      = 1,
  SPEED_QUARTER     = 2,
  SPEED_HALF        = 3,
  SPEED_FULL        = 4,

  SPEED_NUM
};

//Type for Microstep Array
typedef struct
{
  uint8_t MicroStep1;
  uint8_t MicroStep2;
  uint8_t MicroStep3;
} MicroStepType;



// Speed Control Functions
uint8_t SpeedControl_GetCurrentSpeed();
void SpeedControl_SetSpeed(uint8_t speedVal);

#endif //SPEEDCONTROL_H
