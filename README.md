# FlipSwitch

An Arduino Uno R3 based device that automatically switches on the light at a programmable time to help people wake up at the right time through exposure to bright lights right before and during wake up. 

It uses a DS1307 RTC Module for keeping accurate track of time for a longer duration, although after long duration usage, the clock may shift requiring resetting it to the current time through re uploading the files in the specified order. 

The actuator is a SG90 Micro Servo although any servo that can be controlled using PWM is compatible, just note that larger servos may cause brownouts as the servo is directly powered by the Arduino Uno, although you may alter this as needed.

**NOTES:**
This project uses an Arduino Uno R3, purely because that was the microcontroller I had available at hand. if you wish to use a cheaper or a different microcontroller, it is probably fine for this project as long as the microcontroller supports I2C for compatibility with the DS1307. The code that is provided is ***ONLY compatible*** with the Arduino Uno R3 and while using the DS1307 RTC Module.

**INSTRUCTIONS:**
