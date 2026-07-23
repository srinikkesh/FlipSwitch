# FlipSwitch

An Arduino Uno R3 based device that automatically switches on the light at a programmable time to help people wake up at the right time through exposure to bright lights right before and during wake up. 

It uses a DS1307 RTC Module for keeping accurate track of time for a longer duration, although after long duration usage, the clock may shift requiring resetting it to the current time through re uploading the files in the specified order. 

The actuator is a SG90 Micro Servo although any servo that can be controlled using PWM is compatible, just note that larger servos may cause brownouts as the servo is directly powered by the Arduino Uno, although you may alter this as needed.

**NOTES:**
This project uses an Arduino Uno R3, purely because that was the microcontroller I had available at hand. if you wish to use a cheaper or a different microcontroller, it is probably fine for this project as long as the microcontroller supports I2C for compatibility with the DS1307. The code that is provided is ***ONLY compatible*** with the Arduino Uno R3 and while using the DS1307 RTC Module.

**INSTRUCTIONS:**
1. Wire components as directed by the wiring schematic and layout.

<img width="1867" height="1584" alt="FlipSwitch Wiring Schematic-schematic" src="https://github.com/user-attachments/assets/eeffe09a-ee0c-499b-a6fb-aeb21a32c379" />

<img width="3360" height="2452" alt="FlipSwitch Wiring Schematic-layout" src="https://github.com/user-attachments/assets/8fd977b1-69fa-4a66-bd39-0a794e9ace73" />

2. Download and open the "WakeUp Code" folder as a project in PlatformIO. If you are not using PlatformIO, you can use Arduino's IDE and the code is inside the WakeUp Code/src folder.

3. First build and upload the setupRTC.cpp file to program the right time for the RTC module.

4. Afterwards, in the main.cpp folder there a few constants that must be configured prior to uploading the code.
   4a. Firstly, there are 3 hardcoded servo positions: SERVO_RESTING_POSITION, SERVO_ACTIVE_POSITION, SERVO_LOCK_POSITION.
   - The SERVO_RESTING_POSITION is the position the servo will stay in for the majority of the day.
   - The SERVO_ACTIVE_POSITION is the position the servo will go to to flick the light switch.
   - The SERVO_LOCK_POSITION is the position the servo will go to prevent the light from being turned off.
   Using 
