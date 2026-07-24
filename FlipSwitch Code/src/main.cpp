/*
File:     main.cpp

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
const int SERVO_ACTIVE_POSITION = 0; //angle in degrees
const int SERVO_LOCK_POSITION = 50; //angle in degrees

const int ALARM_HOUR = 7;
const int ALARM_MINUTE = 26;

const bool LOCK = true; // IF YOU WANT THE SERVO TO PREVENT YOU FROM TURNING THE LIGHT OFF, CHANGE THE LOCK to TRUE AND SET THE UNLOCK TIME
// Make sure the UNLOCK time is after the ALARM time.
const int UNLOCK_HOUR = 8; // Make sure there is a value here even if you do not want the lightswitch locked
const int UNLOCK_MINUTE = 6; // Make sure there is a value here even if you do not want the lightswitch locked


const int ALARM_TIME_MINUTES = (ALARM_HOUR * 60) + ALARM_MINUTE;
const int UNLOCK_TIME_MINUTES = (UNLOCK_HOUR * 60) + UNLOCK_MINUTE;


// Object Declarations
Servo lightServo;

RTC_DS1307 rtc;

bool alarmFired;

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

  delay(500);

  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  DateTime now = rtc.now();

  int currentTime_Minutes = (now.hour() * 60) + now.minute();

  if (currentTime_Minutes == ALARM_TIME_MINUTES && alarmFired == false){
    lightServo.write(SERVO_ACTIVE_POSITION);
    delay(2000);

    alarmFired = true;
  } 
  
  if (alarmFired && currentTime_Minutes < UNLOCK_TIME_MINUTES && LOCK){
    lightServo.write(SERVO_LOCK_POSITION);
  } else {
    lightServo.write(SERVO_RESTING_POSITION);
  }

  if (currentTime_Minutes > UNLOCK_TIME_MINUTES){
    alarmFired = false;
  }

  delay(1000); 
}


