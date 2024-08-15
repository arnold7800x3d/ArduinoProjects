//basic LCD display

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); //initialize the LCD i.e 16 columns 2 rows

  lcd.setCursor(0, 0); //set cursor at column 0 row 0
  lcd.print("I make stuff with Arduino");

  lcd.setCursor(1, 1); //set cursor at column 0 row 1
  lcd.print("Github @ arnold7800x3d");

  delay(1000); //delay before scroll begins
}

void loop() {
  //scrolling the text to the left
  for (int counter = 0; counter < 26; counter++){
    lcd.scrollDisplayLeft();
    delay(500);
  }
}