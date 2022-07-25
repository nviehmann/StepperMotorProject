#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H
#include <Arduino.h>
#include <stdio.h>

void MotorControl_AutoHome();


void MotorControl_MoveCarriageUp(uint8_t speedVal, int steps);
void MotorControl_MoveCarriageDown(uint8_t speedVal, int steps);
void MotorControl_MoveCarriageLeft(uint8_t speedVal, int steps);
void MotorControl_MoveCarriageRight(uint8_t speedVal, int steps);


#endif //MOTORCONTROL_H
