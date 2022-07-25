#include "PinDefines.h"
#include "TestFramework.h"
#include "MotorControl.h"

void setup() 
{
  Serial.begin(115200);
  PinDefines_Initialize();

  MotorControl_AutoHome();
}

void loop() 
{
//  TestFramework_TestSwitchFunctionality();

TestFramework_TestMovement();


}
