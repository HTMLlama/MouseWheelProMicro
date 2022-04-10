#include <Arduino.h>
#include <Mouse.h>
#include <RotaryEncoder.h>

#define CLK 3
#define DT 2

volatile unsigned int encoderPos = 0;

RotaryEncoder *encoder = nullptr;

void readEncoder() {
  int direction = (int)encoder->getDirection();
  Mouse.move(0,  0, direction);
}

void encoderAction() {
  encoder->tick();
}

void setup() {
  attachInterrupt(0, encoderAction, CHANGE);
  attachInterrupt(1, encoderAction, CHANGE);

  Mouse.begin();

  encoder = new RotaryEncoder(CLK, DT, RotaryEncoder::LatchMode::FOUR3);
}

void loop() {
  int direction = (int)encoder->getDirection();
  Mouse.move(0,  0, direction);
}