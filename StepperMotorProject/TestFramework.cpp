#include "TestFramework.h"
#include "PinDefines.h"
#include "SpeedControl.h"
#include "MotorControl.h"

void TestFramework_TestSwitchFunctionality()
{
  int readVal = 0;
  SpeedControl_SetSpeed(SPEED_HALF);

  readVal = digitalRead(switchOne);

  if(readVal == HIGH)
  {
//    Serial.println("Move Carriage Right");
    MotorControl_MoveCarriageRight(SPEED_HALF,10);
  }

  readVal = digitalRead(switchTwo);

  if(readVal == HIGH)
  {
    MotorControl_MoveCarriageLeft(SPEED_HALF,10);
  }
  
  delay(1);
}


void TestFramework_TestMovement()
{
  uint8_t incomingByte = 0;
  if( Serial.available() > 0)
  {
    incomingByte = Serial.read();
  
    if( incomingByte == 'w')
    {
      Serial.println("Up");
      MotorControl_MoveCarriageUp(SPEED_HALF, 100);
    }
    else if(incomingByte == 's')
    {
      Serial.println("Down");
      MotorControl_MoveCarriageDown(SPEED_HALF, 100);
    }
    else if(incomingByte == 'a')
    {
      Serial.println("Right");
      MotorControl_MoveCarriageLeft(SPEED_HALF, 100);

    }
    else if(incomingByte == 'd')
    {
      Serial.println("Left");
      MotorControl_MoveCarriageRight(SPEED_HALF, 100);
    }
    else if(incomingByte == 'h')
    {
     MotorControl_AutoHome(); 
    }
    else if(incomingByte == '\n')
    {
//      Serial.println("Ignore NewLine");
      //DO NOTHING
    }
    else
    {
      Serial.println("Invalid Input");
    }
    
  }
  
}
