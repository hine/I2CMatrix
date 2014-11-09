#include <util/delay.h>
#include "AdafruitMatrixLED.h"

void setup( ) {
  I2C_Init();
  Matrix_init();
  Matrix_setBlink(HT16K33_BLINK_OFF);
  Matrix_setBrightness(2);
}
 
void loop( ) {
  Matrix_setPixel(2, 0, 1);
  Matrix_setPixel(3, 0, 1);
  Matrix_setPixel(4, 0, 1);
  Matrix_setPixel(5, 0, 1);
  Matrix_setPixel(1, 1, 1);
  Matrix_setPixel(6, 1, 1);
  Matrix_setPixel(0, 2, 1);
  Matrix_setPixel(2, 2, 1);
  Matrix_setPixel(5, 2, 1);
  Matrix_setPixel(7, 2, 1);
  Matrix_setPixel(0, 3, 1);
  Matrix_setPixel(7, 3, 1);
  Matrix_setPixel(0, 4, 1);
  Matrix_setPixel(2, 4, 1);
  Matrix_setPixel(5, 4, 1);
  Matrix_setPixel(7, 4, 1);
  Matrix_setPixel(0, 5, 1);
  Matrix_setPixel(3, 5, 1);
  Matrix_setPixel(4, 5, 1);
  Matrix_setPixel(7, 5, 1);
  Matrix_setPixel(1, 6, 1);
  Matrix_setPixel(6, 6, 1);
  Matrix_setPixel(2, 7, 1);
  Matrix_setPixel(3, 7, 1);
  Matrix_setPixel(4, 7, 1);
  Matrix_setPixel(5, 7, 1);
  Matrix_writeDisplay();
  delay(1000);
  Matrix_clearPixel();
  Matrix_writeDisplay();
  delay(500);
}
