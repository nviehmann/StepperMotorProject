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
    MotorControl_MoveCarriageEast(SPEED_HALF,10);
  }

  readVal = digitalRead(switchTwo);

  if(readVal == HIGH)
  {
    MotorControl_MoveCarriageWest(SPEED_HALF,10);
  }
  
  delay(1);
}


void TestFramework_TestMovement()
{
  uint8_t incomingByte = 0;
  if( Serial.available() > 0)
  {
    incomingByte = Serial.read();
  
    if( incomingByte == '8')
    {
      Serial.println("North");
      MotorControl_MoveCarriageNorth(SPEED_HALF, 100);
    }
    else if(incomingByte == '2')
    {
      Serial.println("South");
      MotorControl_MoveCarriageSouth(SPEED_HALF, 100);
    }
    else if(incomingByte == '4')
    {
      Serial.println("East");
      MotorControl_MoveCarriageWest(SPEED_HALF, 100);

    }
    else if(incomingByte == '6')
    {
      Serial.println("West");
      MotorControl_MoveCarriageEast(SPEED_HALF, 100);
    }
    else if(incomingByte == '7')
    {
      Serial.println("NorthWest");
      MotorControl_MoveCarriageNorthWest(SPEED_FULL, 100);
    }
    else if(incomingByte == '9')
    {
      Serial.println("NorthEast");
      MotorControl_MoveCarriageNorthEast(SPEED_FULL, 100);
    }
    else if(incomingByte == '1')
    {
      Serial.println("SouthWest");
      MotorControl_MoveCarriageSouthWest(SPEED_FULL, 100);
    }
    else if(incomingByte == '3')
    {
      Serial.println("SouthEast");
      MotorControl_MoveCarriageSouthEast(SPEED_FULL, 100);
    }



    
    else if(incomingByte == '5')
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
