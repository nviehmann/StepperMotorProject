#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H
#include <Arduino.h>
#include <stdio.h>

void MotorControl_AutoHome();


void MotorControl_MoveCarriageNorth(uint8_t speedVal, int steps);
void MotorControl_MoveCarriageSouth(uint8_t speedVal, int steps);
void MotorControl_MoveCarriageWest(uint8_t speedVal, int steps);
void MotorControl_MoveCarriageEast(uint8_t speedVal, int steps);

void MotorControl_MoveCarriageNorthEast(uint8_t speedVal, int steps);
void MotorControl_MoveCarriageSouthEast(uint8_t speedVal, int steps);
void MotorControl_MoveCarriageNorthWest(uint8_t speedVal, int steps);
void MotorControl_MoveCarriageSouthWest(uint8_t speedVal, int steps);


#endif //MOTORCONTROL_H
