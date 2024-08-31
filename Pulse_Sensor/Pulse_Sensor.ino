#include <PulseSensorPlayground.h> //PulseSensorPlayground library for the pulse sensor
#include <LiquidCrystal.h>

// Variables
const int sensorPin = A0;
// const int buzzerPIn = 
int threshold = 550;
const int arraySize = 5;
int sensorReadings[arraySize];
int readingSum = 0;
int validReadings = 0;

PulseSensorPlayground pulseSensor;
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

// Timing variables
unsigned long lastBeatTime = 0;
unsigned long readingInterval = 2000;
unsigned long lastLoopTime = 0;
unsigned long loopDelay = 3000;

void setup() {
  lcd.begin(16, 2);
  lcd.print("I love Arduino");
  //pinMode(buzzerPin, OUTPUT);
  //Serial.begin(115200);

  // PulseSensor variables and configurations
  pulseSensor.analogInput(sensorPin);
  pulseSensor.setThreshold(threshold);

  // Ensure the pulseSensor object is successfully created and is reading the expected data
  if (pulseSensor.begin()) {
    lcd.setCursor(0, 0);
    lcd.print("The PulseSensor object has successfully been created!!");
    delay(2000);
    lcd.clear();
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Error in creating the PulseSensor object");
    while(1);
    
    /*for (;;) { // LED blinks infinitely
      digitalWrite(ledPin, LOW);
      delay(50);
      digitalWrite(ledPin, HIGH);
      delay(50);
    }*/
  }

  lastLoopTime = millis();
}

void loop() {
  readingSum = 0; // Reset the sum at the beginning of each loop
  validReadings = 0; // Reset the count of valid readings

  while (validReadings < arraySize) {
    if (pulseSensor.sawStartOfBeat()) {  // Test whether a beat occurred and was recorded
      int BPM = pulseSensor.getBeatsPerMinute();  // Calculate the BPM and store the variable

      // Check if BPM value is within a valid range
      if (BPM > 40 && BPM < 100) {
        sensorReadings[validReadings] = BPM;  // Store the valid BPM value in the array
        lcd.clear();
        lcd.print("Heartbeat Recorded!!");
        lcd.setCursor(0, 1);
        lcd.print("BPM: ");
        lcd.println(sensorReadings[validReadings]); // Print the BPM value
        readingSum += sensorReadings[validReadings];  // Get the sum of the readings
        validReadings++;  // Increment the count of valid readings

      
        // Manually blink the LED
       /*digitalWrite(ledPin, HIGH);
        delay(1000);
        digitalWrite(ledPin, LOW);*/
      }
      lastBeatTime = millis();
    }

    // Use non-blocking delay to allow continuous checking for beats
    if (millis() - lastBeatTime >= readingInterval) {
      lastBeatTime = millis();  // Reset last beat time
    }
  }

  // Calculate and print the average BPM if there are valid readings
  if (validReadings > 0) {
    int averageBPM = readingSum / validReadings;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("The average BPM is: ");
    lcd.print(averageBPM);
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No valid BPM readings.");
  }

  lastLoopTime = millis(); // Reset loop start time
  delay(loopDelay); // Add a delay before starting the next set of readings
}

