///*
//  LiquidCrystal Library - Hello World
//
//  Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
//  library works with all LCD displays that are compatible with the
//  Hitachi HD44780 driver. There are many of them out there, and you
//  can usually tell them by the 16-pin interface.
//
//  This sketch prints "Hello World!" to the LCD
//  and shows the time.
//
//  The circuit:
//   LCD RS pin to digital pin 12
//   LCD Enable pin to digital pin 11
//   LCD D4 pin to digital pin 5
//   LCD D5 pin to digital pin 4
//   LCD D6 pin to digital pin 3
//   LCD D7 pin to digital pin 2
//   LCD R/W pin to ground
//   LCD VSS pin to ground
//   LCD VCC pin to 5V
//   10K resistor:
//   ends to +5V and ground
//   wiper to LCD VO pin (pin 3)
//
//  Library originally added 18 Apr 2008
//  by David A. Mellis
//  library modified 5 Jul 2009
//  by Limor Fried (http://www.ladyada.net)
//  example added 9 Jul 2009
//  by Tom Igoe
//  modified 22 Nov 2010
//  by Tom Igoe
//  modified 7 Nov 2016
//  by Arturo Guadalupi
//
//  This example code is in the public domain.
//
//  https://docs.arduino.cc/learn/electronics/lcd-displays
//
//*/
//
//// include the library code:
//#include <LiquidCrystal.h>
//
//#include <Keypad.h>
//const byte ROWS = 4; //four rows
//const byte COLS = 4; //four columns
//char keys[ROWS][COLS] = {
//  {'1', '2', '3', 'R'},
//  {'4', '5', '6', 'D'},
//  {'7', '8', '9', 'C'},
//  {'*', '0', '#', 'S'}
//};
//byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
//byte colPins[COLS] = {10, 11, 12, 13}; //connect to the column pinouts of the keypad
////Create an object of keypad
//Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
//
//// initialize the library by associating any needed LCD interface pin
//// with the arduino pin number it is connected to
//const int rs = 5, en = 4, d4 = 3, d5 = 2, d6 = 1, d7 = 0;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//
//void setup() {
//  // set up the LCD's number of columns and rows:
//  lcd.begin(16, 2);
//  // Print a message to the LCD.
//  lcd.print("hello, world!");
//}
//
//void loop() {
//  char key = keypad.getKey();// Read the key
//  if (key) {
//    lcd.setCursor(0, 1);
//    lcd.print(key);
//  }
//}
/*
  LiquidCrystal Library - Hello World

  Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
  library works with all LCD displays that are compatible with the
  Hitachi HD44780 driver. There are many of them out there, and you
  can usually tell them by the 16-pin interface.

  This sketch prints "Hello World!" to the LCD
  and shows the time.

  The circuit:
   LCD RS pin to digital pin 12
   LCD Enable pin to digital pin 11
   LCD D4 pin to digital pin 5
   LCD D5 pin to digital pin 4
   LCD D6 pin to digital pin 3
   LCD D7 pin to digital pin 2
   LCD R/W pin to ground
   LCD VSS pin to ground
   LCD VCC pin to 5V
   10K resistor:
   ends to +5V and ground
   wiper to LCD VO pin (pin 3)

  Library originally added 18 Apr 2008
  by David A. Mellis
  library modified 5 Jul 2009
  by Limor Fried (http://www.ladyada.net)
  example added 9 Jul 2009
  by Tom Igoe
  modified 22 Nov 2010
  by Tom Igoe
  modified 7 Nov 2016
  by Arturo Guadalupi

  This example code is in the public domain.

  https://docs.arduino.cc/learn/electronics/lcd-displays

*/

// include the library code:
#include <LiquidCrystal.h>

#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'R'},
  {'4', '5', '6', 'D'},
  {'7', '8', '9', ''},
  {'*', '0', '#', 'S'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {10, 11, 12, 13}; //connect to the column pinouts of the keypad
//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 5, en = 4, d4 = 3, d5 = 2, d6 = 1, d7 = 0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  char key = keypad.getKey();// Read the key
  if (key) {
    lcd.setCursor(0, 1);
    lcd.print(key);
  }
}
