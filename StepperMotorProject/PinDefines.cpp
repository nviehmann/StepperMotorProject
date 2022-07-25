#include "PinDefines.h"

static void PinEnable();

void PinDefines_Initialize()
{
  PinEnable();
  
  // Initialize Stepper Motor Control Pins - LOW
  digitalWrite(dirPinOne,   LOW);
  digitalWrite(stepPinOne,  LOW);
  digitalWrite(dirPinTwo,   LOW);
  digitalWrite(stepPinTwo,  LOW);

  //Initialize Speed Control Pins - Full Step
  digitalWrite(MS1,   LOW);
  digitalWrite(MS2,   LOW);
  digitalWrite(MS3,   LOW);
}

static void PinEnable()
{
  // Stepper Motor Control Pins
  pinMode(dirPinOne,  OUTPUT);
  pinMode(stepPinOne, OUTPUT);
  pinMode(dirPinTwo,  OUTPUT);
  pinMode(stepPinTwo, OUTPUT);

  // Step Speed Control Pins
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(MS3, OUTPUT);

  // Switch Control Pins
  pinMode(switchOne, INPUT);
  pinMode(switchTwo, INPUT);
}
