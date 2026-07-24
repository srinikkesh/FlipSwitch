# FlipSwitch

An Arduino Uno R3 based device that automatically switches on the light at a programmable time to help people wake up at the right time through exposure to bright lights right before and during wake up. 

It uses a DS1307 RTC Module for keeping accurate track of time for a longer duration, although after long duration usage, the clock may shift requiring resetting it to the current time through re uploading the files in the specified order. 

The actuator is a SG90 Micro Servo although any servo that can be controlled using PWM is compatible, just note that larger servos may cause brownouts as the servo is directly powered by the Arduino Uno, although you may alter this as needed.

**INSTRUCTIONS:**
1. Wire components as directed by the wiring schematic and layout.

<img width="1867" height="1584" alt="FlipSwitch Wiring Schematic-schematic" src="https://github.com/user-attachments/assets/eeffe09a-ee0c-499b-a6fb-aeb21a32c379" />

<img width="3360" height="2452" alt="FlipSwitch Wiring Schematic-layout" src="https://github.com/user-attachments/assets/8fd977b1-69fa-4a66-bd39-0a794e9ace73" />

2. Mount the components in such a way that the following conditions are met:
    - All components are secure and not able to freely move.
    - None of the wires are bent sharply, extremely taut, or extremely loose.
    - The servo is mounted in such a way that it's range of motion allows it to contact the switch ONLY if the switch is in the off position and completely be clear of switch when the light is turned on.
    - The servo is securely mounted in such a way that even under load it will not shear off or fall.
    - The Arduino is able to get constant power from a powersupply that is ideally connected to the wall outlet, I personally have not tried to use this with batteries, so I do not know how quickly the device will deplete the battery.
    - The connection of the powersupply to the Arduino is easily accessible in the case of a situation where the servo is preventy the light from turning off and you need to turn the light off.
    - Ideally I would recommend the addition of a protective covering for the electronics to prevent dust from shorting the circuits, especially if using a breadboard instead of soldering to perboard.

3. Download and open the "FlipSwitch Code" folder as a project in PlatformIO. If you are not using PlatformIO, you can use Arduino's IDE and the code is inside the FlipSwitch Code/src folder.

4. First build and upload the setupRTC.cpp file to program the right time for the RTC module. 

     *IMPORTANT:* In this step you will need to build and upload the setupRTC.cpp file, to do so in Platform.io, open the extension on the left hand side in VS Code and inside of uno_rtc_setup/General, use the Build and Upload tasks to build and upload to the device.

   - Open the serial monitor to check the outputs and compare them to your system's time. If there is a significant discrepancy you can increase the RTC_SETUP_OFFSET and reupload until that difference minimizes and the serial monitor is printing the same time as your system's time.

6. Afterwards, in the main.cpp folder there a few constants that must be configured prior to uploading the code.
   
   5a. There are 3 hardcoded servo positions: SERVO_RESTING_POSITION, SERVO_ACTIVE_POSITION, SERVO_LOCK_POSITION.
   - The SERVO_RESTING_POSITION is the position the servo will stay in for the majority of the day.
   - The SERVO_ACTIVE_POSITION is the position the servo will go to to flick the light switch.
   - The SERVO_LOCK_POSITION is the position the servo will go to prevent the light from being turned off.
   To tune the servo positions, first open the tuneServoPos.cpp file. This file moves the servo's horn to the position specified by SERVO_POSITION.

    *IMPORTANT:* In the following steps you will need to build and upload the tuneServoPos.cpp file, to do so in Platform.io, open the extension on the left hand side in VS Code and inside of uno_servo_alignment/General, use the Build and Upload tasks to build and upload to the device.
   
   5b. Secondly with SERVO_POSITION set to 0, build and upload the code, the position the servo horn moves to should act as the resting position, try to reattach the servo horn such that in this 0 degree position, the horn faces directly down to the floor and parallel to the wall.
   
   5c. Thirdly, set the SERVO_POSITION to 180, build and upload the code, the position of the servo horn should move upwards to flick the switch on. Should the servo move the opposite direction, or get stuck on the switch after turning it on, you may need to either reposition the servo horn relative to the servo or reposition the servo such that when the switch is in the "on" position, the servo misses the switch completely.

   5d. Fourthly, keep changing the SERVO_POSITION until you reach a value where the light switch is not being contact but the light switch is also unable to be turned off.

7. Set the SERVO_RESTING_POSITION to the value where the servo is not contacting anything and facing the ground or the value from step 5b.

8. Set the SERVO_ACTIVE_POSITION to the value where the servo turns the light on if the light is off or the value from step 5c.

9. Set the SERVO_LOCK_POSITION to the value where the light is prevented from being turned off or the step from 5d.

10. Now set the time in the morning you wish to wake up by changing the variable ALARM_HOUR to the hour you want the light turned on in 24h format. Then change the ALARM_MINUTE to the minute you want the light turned on as a value between 0-60.
   For example, if you wish to wake up at 7:26 AM, you would set ALARM_HOUR to 7 and ALARM_MINUTE to 26.

11. If you wish for the device to also prevent you from turning the light off and going back to bed, set the LOCK variable to true; set the UNLOCK_HOUR and UNLOCK_MINUTE to the time you want the lock to be lifted.
   For example, if you wish to wake up at 7:26 AM but you also want the lights on until 8:06 AM, you would set UNLOCK_HOUR to 8 and UNLOCK_MINUTE to 6.

12. *IMPORTANT:* In this step you will need to build and upload the main.cpp file, to do so in Platform.io, open the extension on the left hand side in VS Code and inside of uno_main/General, use the Build and Upload tasks to build and upload to the device.
   

**EXAMPLE IMAGES**

https://github.com/user-attachments/assets/af03e7c3-c9e4-406b-838e-41f89b5f27dd

<img width="3024" height="4032" alt="Electronics" src="https://github.com/user-attachments/assets/f0030545-5931-4b4e-95fe-31eabf7865f6" />
<img width="3024" height="4032" alt="Overall Picture" src="https://github.com/user-attachments/assets/28ab0cf3-90e8-42c0-ab67-9923b7e51e59" />
<img width="3024" height="4032" alt="Servo" src="https://github.com/user-attachments/assets/c365a86c-3a01-41e0-ad5c-8091117a2b06" />



**NOTES:**
This project uses an Arduino Uno R3, purely because that was the microcontroller I had available at hand. if you wish to use a cheaper or a different microcontroller, it is probably fine for this project as long as the microcontroller supports I2C for compatibility with the DS1307. The code that is provided is ***ONLY compatible*** with the Arduino Uno R3 and while using the DS1307 RTC Module.

If you need to turn the device off, simply remove the power source.

If you change the pin for the servo be sure to change the SERVO_PIN variable in both the main.cpp and the tuneServoPos.cpp files.
