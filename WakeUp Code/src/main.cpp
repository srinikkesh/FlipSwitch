/*
File:     main.py

Author:   Srinikkesh Senthilkumar
Date:     July 21, 2026
License:  MIT License (see LICENSE in root directory)
Copyright (c) 2026 Srinikkesh Senthilkumar

Summary of File:

  This file is the primary code for controlling the basic Arduino Uno R3 based light switch automater, 
  which flips the switch to aid wake up at a pre-specified time. It integrates an RTC Module for greater time accuracy.
*/

#include <Arduino.h>
#include <Servo.h>
#include <RTClib.h>


// Pins
const int SERVO_PIN = 11;


// Constants
const int SERVO_RESTING_POSITION = 180; //angle in degrees
const int SERVO_LOCK_POSITION = 50; //angle in degrees
const int SERVO_ACTIVE_POSITION = 0; //angle in degrees

const int SWITCH_HOUR = 4;
const int SWITCH_MINUTE = 30;

const bool LOCK = false; // IF YOU WANT THE SERVO TO PREVENT YOU FROM TURNING THE LIGHT OFF, CHANGE THE LOCK to TRUE AND SET THE UNLOCK TIME
const int UNLOCK_HOUR = 6;
const int UNLOCK_MINUTE = 0;


// Object Declarations
Servo lightServo;

RTC_DS1307 rtc;

bool lockState = false;

 
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  Serial.begin(9600);
  while(!Serial){
    ;
  }
  
  lightServo.attach(SERVO_PIN);
  lightServo.write(SERVO_RESTING_POSITION);

  if(! rtc.begin()){
    Serial.println("Could not find RTC");
    Serial.flush();
    while(1);
  }

  // DateTime compileTime = DateTime(F(__DATE__), F(__TIME__));
  // rtc.adjust(compileTime + TimeSpan(0, 0, 0, 5)); //Its for the consistent offset that happens when setting rtc

  delay(500);

  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  DateTime now = rtc.now();

  if(lockState){
    lightServo.write(SERVO_LOCK_POSITION);
  }
  else {
    lightServo.write(SERVO_RESTING_POSITION);
  }

  if((now.hour() == SWITCH_HOUR) && (now.minute() == SWITCH_MINUTE)){
    lightServo.write(SERVO_ACTIVE_POSITION);
    delay(3000);
    lightServo.write(SERVO_RESTING_POSITION);
    if (LOCK){
      lockState = true;
    };
  };

  if((now.hour() == UNLOCK_HOUR) && (now.minute() == UNLOCK_MINUTE)){
    lockState = false;
  };


  delay(100); 
}