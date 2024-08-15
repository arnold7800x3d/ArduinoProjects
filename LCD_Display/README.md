# DIY LCD_Display

This is a simple project that isn't much of a project actually, just like a learning tutorial for a 16 x 2 LCD display.

## Requirements
- 16 x 2 LCD display
- Arduino UNO R3 board
- Breadboard
- 12 jumper wires ( preferrably male - female)
- 4 jumper wires ( male - male)
- Potentiometer

## LCD Display Pinout
| Pin No | Symbol | Arduino Pin Connection [ Description ] |

| 1 | VSS | GND |
| 2 | VDD | 5V |
| 3 | V0 | Power Pin for Contrast on Potentiometer |
| 4 | RS | Pin 12 [Register Selection] |
| 5 | RW | Pin 11 [Read/Write selection] |
| 6 | E | GND [Enable signal] |
| 4 - 7 | D4 - D7 | Pin 5 - Pin 2 respectively [Data bus lines] |
| 15 | LEDA | 5V [Power Anode] |
| 16 | LEDK | GND [Power Cathode] |

## Project Demo
- Connect the setup as shown in the Tinkercad image.
- Upload the code to the Arduino board.
- Use the potentiometer to change the LCD's contrast

