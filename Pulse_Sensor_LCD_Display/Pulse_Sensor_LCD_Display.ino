/*
  Pulse sensor + LCD Display + LED + Buzzer
*/

#include <LiquidCrystal.h>
#include <PulseSensorPlayground.h>

// Project Variables
const int sensorPin = A0;
const int ledPin = 13;
const int buzzerPin = 7;
const int arraySize = 5;
int threshold = 550;
int sensorReadings[arraySize];
int readingSum = 0;
int validReadings = 0;

// Timing Variables
unsigned long lastBeatTime = 0;
unsigned long readingInterval = 2000;
unsigned long lastLoopTime = 0;
unsigned long loopDelay = 3000;


PulseSensorPlayground pulseSensor;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  
  pulseSensor.analogInput(sensorPin);
  pulseSensor.setThreshold(threshold);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  if(pulseSensor.begin()) {
    lcd.setCursor(0, 0);
    lcd.print("The pulseSensor object has successfully been created!!");
    delay(2000);
    lcd.clear();
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Error in creating the PulseSensor object");
    while(1);

    for(;;) {
      digitalWrite(ledPin, LOW);
      delay(50);
      digitalWrite(ledPin, HIGH);
      delay(50);
    }
  }

  lastLoopTime = millis();
}

void loop() {
  readingSum = 0;
  validReadings = 0;

  for(int i = 0; i < 50; i++) {
    lcd.scrollDisplayLeft();
    delay(500);
  }

  while(validReadings < arraySize) {
    if(pulseSensor.sawStartOfBeat()) {
      int bpm = pulseSensor.getBeatsPerMinute();

      if(bpm > 40 && bpm < 100) {
        sensorReadings[validReadings] = bpm;
        lcd.clear();
        lcd.print("Heartbeat Recorded!!");
        lcd.setCursor(0,1);
        lcd.print("BPM: ");
        lcd.print(sensorReadings[validReadings]);
        readingSum += sensorReadings[validReadings];
        validReadings++;

        digitalWrite(ledPin, HIGH);
        delay(1000);
        digitalWrite(ledPin, LOW);

        tone(buzzerPin, 1000);
        delay(1000);
        noTone(buzzerPin);
        delay(1000);
      }

      lastBeatTime = millis();
    }

    if(millis() - lastBeatTime >= readingInterval) {
      lastBeatTime = millis();
    }

  }

  if(validReadings > 0) {
    int averageBpm = readingSum / validReadings;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("The average BPM is: ");
    lcd.print(averageBpm);
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No valid readings");
  }

  lastLoopTime = millis();
  delay(loopDelay);  
}