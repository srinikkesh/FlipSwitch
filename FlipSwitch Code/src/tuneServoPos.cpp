/*
File:     tuneServoPos.cpp

Author:   Srinikkesh Senthilkumar
Date:     July 23, 2026
License:  MIT License (see LICENSE in root directory)
Copyright (c) 2026 Srinikkesh Senthilkumar

Summary of File:

  This files allows the user to set the servo the specified positions for tuning purposes.
*/

#include <Arduino.h>
#include <Servo.h>

// Pins
const int SERVO_PIN = 11;


// Constants
const int SERVO_POSITION = 0;


// Object Declarations
Servo lightServo;


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  Serial.begin(9600);
  while(!Serial){
    ;
  }
  
  lightServo.attach(SERVO_PIN);

  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  
    lightServo.write(SERVO_POSITION);

  delay(100); 
}
