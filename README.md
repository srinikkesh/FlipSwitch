# FlipSwitch

An Arduino Uno R3 based device that automatically switches on the light at a programmable time to help people wake up at the right time through exposure to bright lights right before and during wake up. 

It uses a DS1307 RTC Clock Module for keeping accurate track of time for a longer duration, although after long duration usage, the clock may shift requiring resetting it to the current time through re uploading the files in the specified order. 

The actuator is a SG90 Micro Servo although any servo that can be controlled using PWM is compatible, just note that larger servos may cause brownouts as the servo is directly powered by the Arduino Uno, although you may alter this as needed.
