/*********TACHLOG powered********
*********www.troncart.com*******
**electronics components online**
***********LCD & keypad**************
*************************
*/
 
#include <LiquidCrystal.h>
#include <Keypad.h>
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
const byte ROWS = 4; // Four rows
const byte COLS = 3; // Three columns
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3}; 
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
void setup() 
{
 Serial.begin(9600);
 lcd.begin(16, 2);
 lcd.setCursor(0, 0);
 lcd.print("TRONCART"); 
 delay(2000);
 lcd.clear();
 lcd.setCursor(0, 1);
 lcd.print("www.troncart.com"); 
 delay(2000);
 lcd.clear();
 lcd.setCursor(0, 1);
 lcd.print("www.tachlog.com"); 
 delay(2000);
 lcd.clear();
 lcd.print("PRESS ANY KEY"); 
 
}
void loop() 
{
    char customKey = customKeypad.getKey();
  
  if (customKey)
  {
  lcd.clear();
  Serial.print("PRESSED KEY=");
  Serial.println(customKey);
  }
//char key = customKeypad.getKey();
lcd.setCursor(0, 1);
if(customKey)  
{
lcd.setCursor(0, 1);
lcd.print("PRESSED KEY= ");
lcd.print(customKey);
//Serial.println(Key);
}  
}
