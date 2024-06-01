# DIY TRAFFIC LIGHTS

The project is a simple program that mimics a real-world traffic light system. 

## Requirements

~ 1 Arduino Uno R3
~ 1 Pushbutton
~ 2 Red LEDs
~ 1 Yellow LED
~ 2 Green LED
~ 5 220k Ohms Resistors
~ 1 10k Ohms Resistor

## Setup

Refer to Traffic_Lights_jpg or Traffic_Lights_Tinkercad.png for the setup and assembly.

## Operation

There are 5 LEDs in total for the project, red and green for pedestrians and red, yellow and green for cars. Normally, the green LED for the cars is on and the red LED for pedestrians is off. When the pushbutton is pressed, the yellow LED is on then finally the red to indicate the cars should halt. The green LED for pedestrians then turns on for 3 seconds, then flashes before the red LED turns on signaling the end of the time to cross and reverts to the initial state. 