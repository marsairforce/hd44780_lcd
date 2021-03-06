/*
   - 20x4 LCD display, 4 bit mode, driven by 74HC595 shift register
   The version 2 (current) of the API.
*/


// LCD Display on a 74HC595, 4 bit data mode
#define PIN_SER       5
#define PIN_SRCLK     6
#define PIN_RCLK      7

#include "LCD.h"
Serial_595_lcd lcd(PIN_SER, PIN_SRCLK, PIN_RCLK);

void setup() {
    lcd.begin(20,2);
}

int offset = 0;
int dir = +1;
void loop() {

  char msg[] = "-= Hello =-";
  if (offset + strlen(msg) + 1 > 20) {
    dir = -1;
  }
  if (offset -1 < 0) {
    dir = +1;
  }

  lcd.clear();
  lcd.setCursor(offset, 1);
  lcd.print(msg);
  offset += dir;

  delay(500);

}