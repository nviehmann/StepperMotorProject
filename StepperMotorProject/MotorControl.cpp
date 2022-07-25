#include "MotorControl.h"
#include "PinDefines.h"
#include "SpeedControl.h"

#define MOTOR_SWITCHING_SPEED_MS 1 //TODO: Should this be configurable????

/* Static Function Calls */
static void DriveBothMotors(int steps);
static void DriveMotorOne(int steps);
static void DriveMotorTwo(int steps);
static void SetClockWise(uint8_t pin);
static void SetCounterClockWise(uint8_t pin);


void MotorControl_AutoHome() //TODO: Add this fucntionality
{
  Serial.println("AutoHome Beginning...");
  
  /*  Home the Right to Left Sensor */
  //Move towards the switch until pressed at Half Speed
  while(digitalRead(switchTwo) != HIGH)
  {
    MotorControl_MoveCarriageEast(SPEED_HALF,1);
  }

  //Move away from the switch until NOT pressed at Half Speed
  while(digitalRead(switchTwo) == HIGH)
  {
    MotorControl_MoveCarriageWest(SPEED_HALF,1);
  }

  //Slowly move back to press the switch
  while(digitalRead(switchTwo) != HIGH)
  {
    MotorControl_MoveCarriageEast(SPEED_SIXTEENTH,1);
  }
  
  /*  Home the Up and Down Sensor */
  while(digitalRead(switchOne) != HIGH)
  {
    MotorControl_MoveCarriageSouth(SPEED_HALF,1);
  }

  while(digitalRead(switchOne) == HIGH)
  {
    MotorControl_MoveCarriageNorth(SPEED_HALF,1);
  }


  while(digitalRead(switchOne) != HIGH)
  {
    MotorControl_MoveCarriageSouth(SPEED_SIXTEENTH,1);
  }

  Serial.println("AutoHome Complete!");

}

void MotorControl_MoveCarriageNorth(uint8_t speedVal, int steps)
{
  SetCounterClockWise(dirPinOne);
  SetClockWise(dirPinTwo);

  SpeedControl_SetSpeed(speedVal);

  DriveBothMotors(steps); 
}

void MotorControl_MoveCarriageSouth(uint8_t speedVal, int steps)
{
  SetClockWise(dirPinOne);
  SetCounterClockWise(dirPinTwo);

  SpeedControl_SetSpeed(speedVal);

  DriveBothMotors(steps);
}

void MotorControl_MoveCarriageWest(uint8_t speedVal, int steps)
{
  SetClockWise(dirPinOne);
  SetClockWise(dirPinTwo);

  SpeedControl_SetSpeed(speedVal);

  DriveBothMotors(steps);
}

void MotorControl_MoveCarriageEast(uint8_t speedVal, int steps)
{
  SetCounterClockWise(dirPinOne);
  SetCounterClockWise(dirPinTwo);

  SpeedControl_SetSpeed(speedVal);
  
  DriveBothMotors(steps);
}

void MotorControl_MoveCarriageNorthEast(uint8_t speedVal, int steps)
{
  SetCounterClockWise(dirPinOne);

  SpeedControl_SetSpeed(speedVal);
  
  DriveMotorOne(steps);
}

void MotorControl_MoveCarriageSouthEast(uint8_t speedVal, int steps)
{
  SetCounterClockWise(dirPinTwo);

  SpeedControl_SetSpeed(speedVal);
  
  DriveMotorTwo(steps);
}

void MotorControl_MoveCarriageNorthWest(uint8_t speedVal, int steps)
{
  SetClockWise(dirPinTwo);

  SpeedControl_SetSpeed(speedVal);
  
  DriveMotorTwo(steps);
}

void MotorControl_MoveCarriageSouthWest(uint8_t speedVal, int steps)
{
  SetClockWise(dirPinOne);

  SpeedControl_SetSpeed(speedVal);
  
  DriveMotorOne(steps);
}



static void DriveBothMotors(int steps)
{
  for(int i =0; i < steps; i++)
  {
    digitalWrite(stepPinOne,   HIGH);
    digitalWrite(stepPinTwo,   HIGH);
    delay(MOTOR_SWITCHING_SPEED_MS);
    digitalWrite(stepPinOne,   LOW);
    digitalWrite(stepPinTwo,   LOW);
  }
}

static void DriveMotorOne(int steps)
{
  for(int i =0; i < steps; i++)
  {
    digitalWrite(stepPinOne,   HIGH);
    delay(MOTOR_SWITCHING_SPEED_MS);
    digitalWrite(stepPinOne,   LOW);
  }
}

static void DriveMotorTwo(int steps)
{
  for(int i =0; i < steps; i++)
  {
    digitalWrite(stepPinTwo,   HIGH);
    delay(MOTOR_SWITCHING_SPEED_MS);
    digitalWrite(stepPinTwo,   LOW);
  }
}


static void SetClockWise(uint8_t pin)
{
  digitalWrite(pin,   HIGH);
}

static void SetCounterClockWise(uint8_t pin)
{
  digitalWrite(pin,   LOW);
}
