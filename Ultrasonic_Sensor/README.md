# DIY Ultrasonic Sensor

Simple ultasonic sensor project to measure distances and display the distance between the sensor and an object on the LCD Display. If the distance is less than 20cm, the LED blinks continously and if the distance is less than 5cm, the buzzer produces a sound.

## Requirements

- Arduino R3 board
- 16 x 2 LCD Display
- Ultrasonic sensor
- 10k potentiometer
- 1 LED
- 1 Piezzo Buzzer
- 2 220k Ohm resistors
- Breadboard
- 23 jumper wires ( all 23 preferrably male to male )
- Liquid Crystal software library

## Working Principle of the Ultrasonic Sensor

The trug pin acts as the transmitter. It sends a high frequency sound which reflects from an object and the echo pin receives the signal. The distance is then calculated from the time between the transmission and reception of the sigbal since the velocity of sound in air is a known value.

## Setup 

Assemble the circuit as in the Tinkercad image.

LCD Pinout here
Ultrasonic sensor pinout
- VCC - 5V
- Echo - 7
- Trig - 8
- GND - GND
LED connected to pin 13

## Project Demo

After assembling the circuit, upload the code to the Arduino board. Place an object in front of the ultrasonic sensor. The sensor measures the distance between itself and the object and displays this distance as cm and inches on the LCD display. Bring the object closer to the sensor. When the distance is less than 20 cm, the LED blinks continuously. Bring the object closer to the sensor and when the distance is less than 5 cm, the buzzer produces a sound continously.
