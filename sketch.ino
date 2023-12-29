#include <LiquidCrystal_I2C.h>
#include <stdio.h>
#include <stdlib.h>

// Set the I2C address for the display
#define I2C_ADDRESS 0x27

// Set the number of columns and rows on the LCD
#define LCD_COLUMNS 16
#define LCD_ROWS 2
LiquidCrystal_I2C lcd(I2C_ADDRESS, LCD_COLUMNS, LCD_ROWS);

const int red = 2;
const int yellow = 3;
const int green = 4;
const int walkLight = 5;
const int walkBTN = 6;
const int BTNWait = 0;


void setup(){
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(walkLight, OUTPUT);
  pinMode(walkBTN, INPUT_PULLUP);

  // Initialize the LCD
  lcd.begin(I2C_ADDRESS, LCD_COLUMNS, LCD_ROWS);
  lcd.setBacklight(HIGH);
  
}



void loop() {
  digitalWrite(green, HIGH);
  lcd.setCursor(2,0);
  lcd.print("Please Wait");

  if(digitalRead(walkBTN) == 0){
    int count = 0;
    while(true){
      lcd.setCursor(7,1);
      lcd.print(count);
      delay(1000);
      count++;
      if(count == 11){
        break;
      }
    }
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    while(true){
      lcd.setCursor(7,1);
      lcd.print(count);
      delay(1000);
      count++;
      if(count == 21){
        break;
      }
    }
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    walk();
    lcd.clear();


  }
  
}

void walk(){
  int count = 0;

  while(count < 31){
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("WALK");
    lcd.setCursor(6,1);
    lcd.print(count);
    digitalWrite(walkLight, HIGH);
    delay(500);
    digitalWrite(walkLight, LOW);
    lcd.clear();
    delay(500);
    count ++;
  }
  digitalWrite(red, LOW);
}


