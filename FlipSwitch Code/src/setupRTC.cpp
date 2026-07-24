/*
File:     setupRTC.cpp

Author:   Srinikkesh Senthilkumar
Date:     July 23, 2026
License:  MIT License (see LICENSE in root directory)
Copyright (c) 2026 Srinikkesh Senthilkumar

Summary of File:

  This file is the code to configure the DS1307 RTC to the correct time.
*/

#include <Arduino.h>
#include <RTClib.h>

// Constants
const float RTC_SETUP_OFFSET = 5.0; // OPTIONAL: Use to offset the time until the Serial monitor displays the same time +- 1 second as the device

// Object Declarations
RTC_DS1307 rtc;

 
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  Serial.begin(9600);
  while(!Serial){
    ;
  }

  if(! rtc.begin()){
    Serial.println("Could not find RTC");
    Serial.flush();
    while(1);
  }

  DateTime compileTime = DateTime(F(__DATE__), F(__TIME__));
  rtc.adjust(compileTime + TimeSpan(0, 0, 0, RTC_SETUP_OFFSET)); //Its for the consistent offset that happens when setting rtc

  delay(500);

  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  DateTime now = rtc.now();

  Serial.println("");
  Serial.print("Current Time: ");

  if(now.hour() < 10) Serial.print("0");
  Serial.print(now.hour());
  Serial.print(":");

  if(now.minute() < 10) Serial.print("0");
  Serial.print(now.minute());
  Serial.print(":");

  if(now.second() < 10) Serial.print("0");
  Serial.print(now.second());

  delay(100); 
}