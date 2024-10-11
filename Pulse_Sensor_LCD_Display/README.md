# DIY PulseSensor_LCD_LED_Buzzer

This is a simple pulse sensor project to detect heartbeats and display the heartbeat values on the LCD display. Upon detection of a valid heartbeat, the buzzer produces a sound and the LED blinks.

## Requirements
- Arduino UNO R3 board
- 16 x 2 LCD Display
- Pulse sensor
- 10k potentiometer
- 1 LED
- 1 Piezzo Buzzer
- 2 220k Ohm resistors
- Breadboard

## Setup

Set up the circuit as in the Tinkercad image. The LCD pinout might be a bit confusing, refer here for a relatively better explanation. 
For the pulse sensor, Tinkercad lacks this sensor, but check the image provided for its pinout as well.

## Project Demo
After connecting the setup as shown in the Tinkercad image, upload the code to the Arduino board. If the pulse sensor object is created successfully, this feedback is provided and if not, the LED blinks infinitely and an error message is displayed. Place your hand on the pulse sensor to record your heartbeat and if a valid heartbeat is detected, the heartbeat is displayed, the LED blinks and the buzzer produces a sound. After 5 heatbeats are detected, the average BPM is calculated and displayed. In case of contrast issues, use the potentiometer to achieve the desired contrast.