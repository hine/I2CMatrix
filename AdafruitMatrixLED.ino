//
// AdafruitのマトリックスLEDの制御ライブラリ
// 2014/11/09 ひね
//
// 利用したマトリックスLEDボードはこちら
// http://www.adafruit.com/products/870
//
// 制御のHT16K33のデータシートはこちら
// http://www.holtek.com.tw/pdf/consumer/ht16K33v110.pdf
//

#include "AdafruitMatrixLED.h"

uint8_t displaybuffer[8];

void Matrix_init(void) {
  I2C_Start();
  I2C_Write(I2C_ADDR<<1);
  I2C_ReadBit();
  I2C_Write(HT16K33_SETUP_CMD | HT16K33_SETUP_OSCILLATORON);
  I2C_ReadBit();
  I2C_Stop;
}

void Matrix_setBlink(uint8_t blink) {
  I2C_Start();
  I2C_Write(I2C_ADDR<<1);
  I2C_ReadBit();
  I2C_Write(HT16K33_BLINK_CMD | (blink << 1) | HT16K33_BLINK_DISPLAYON);
  I2C_ReadBit();
  I2C_Stop;
}

void Matrix_setBrightness(uint8_t brightness) {
  I2C_Start();
  I2C_Write(I2C_ADDR<<1);
  I2C_ReadBit();
  I2C_Write(HT16K33_BRIGHTNESS_CMD | brightness);
  I2C_ReadBit();
  I2C_Stop;
}

void Matrix_writeDisplay(void) {
  I2C_Start();
  I2C_Write(I2C_ADDR<<1);
  I2C_ReadBit();
  I2C_Write(HT16K33_DISPLAYMEMORY_STARTADDR);
  I2C_ReadBit();
  for (uint8_t i=0; i<8; i++) {
    I2C_Write(displaybuffer[i]);
    I2C_ReadBit();
    I2C_Write(0x00);
    I2C_ReadBit();
  }
  I2C_Stop;
}

void Matrix_setPixel(uint8_t x, uint8_t y, uint8_t color) {
  // wrap around the x
  x += 7;
  x %= 8;

  if (color) {
    displaybuffer[y] |= 1 << x;
  } else {
    displaybuffer[y] &= ~(1 << x);
  }
}

void Matrix_clearPixel(void) {
  for (uint8_t i=0; i<8; i++) {
    displaybuffer[i] = 0;
  }
}

