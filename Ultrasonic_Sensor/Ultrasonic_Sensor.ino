
#include <LiquidCrystal.h>

const int ledPin = 13;
const int buzzerPin = 6;
const int trigPin = 8;
const int echoPin = 7;
long duration, cm, inches;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16,2);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  cm = (duration / 2) / 29.1;
  inches = (duration / 2) / 74;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(inches);
  lcd.print("in, ");
  lcd.print(cm);
  lcd.print("cm");
  lcd.println();

  delay(250);

  if (cm <= 20) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }

  if (cm <= 5) {
    tone(buzzerPin, 2000);
    delay(100);
    noTone(buzzerPin);
    delay(100);
  }

  delay(250);

}
