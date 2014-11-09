//
// ATtiny13用I2Cライブラリ  tinyI2Clib for Arduino IDE
// 2014/11/04 たま吉さん
// URL:http://nuneno.cocolog-nifty.com/blog/2014/11/attiny13ai2clcd.html
//  参考HP
//   オリジナルソース I2C on an AVR using bit banging
//    http://codinglab.blogspot.jp/2008/10/i2c-on-avr-using-bit-banging.html
//   オリジナル応用例 bvdeenen/arduino-ethernet-tmp102
//    https://github.com/bvdeenen/arduino-ethernet-tmp102/blob/master/temp_humidity.ino
//

#include <avr/io.h>
#include <util/delay.h>

// 以下の設定は、
// ATTINY13A /

// Port for the I2C
#define I2C_DDR 	DDRB
#define I2C_PIN 	PINB
#define I2C_PORT 	PORTB

// Pins to be used in the bit banging
#define I2C_CLK 3
#define I2C_DAT 4

#define I2C_DATA_HI()   I2C_DDR &= ~(1 << I2C_DAT);I2C_PORT |= (1 << I2C_DAT);
#define I2C_DATA_LO()   I2C_DDR |= (1 << I2C_DAT);I2C_PORT &= ~(1 << I2C_DAT);
#define I2C_CLOCK_HI()  I2C_DDR &= ~(1 << I2C_CLK);I2C_PORT |= (1 << I2C_CLK);
#define I2C_CLOCK_LO()  I2C_DDR |= (1 << I2C_CLK);I2C_PORT &= ~(1 << I2C_CLK);

void I2C_WriteBit(unsigned char c) {
    if (c > 0) {
        I2C_DATA_HI();
    } else {
        I2C_DATA_LO();
    }
    I2C_CLOCK_HI();
    while ((I2C_PIN & (1 << I2C_CLK)) == 0);
    _delay_us(200);
    I2C_CLOCK_LO();
    _delay_us(200);        
    if (c > 0) {
        I2C_DATA_LO();
    }
    _delay_us(200);    
}

unsigned char I2C_ReadBit() {
    I2C_DATA_HI();
    I2C_CLOCK_HI();
    while ((I2C_PIN & (1 << I2C_CLK)) == 0);
    _delay_us(200);   
    unsigned char c = I2C_PIN;
    I2C_CLOCK_LO();
    _delay_us(200); 
    return (c >> I2C_DAT) & 1;
}

// Inits bitbanging port, must be called before using the functions below
//
void I2C_Init() {
    I2C_PORT &= ~((1 << I2C_DAT) | (1 << I2C_CLK));
    I2C_CLOCK_HI();
    I2C_DATA_HI();
}

// Send a START Condition
//
void I2C_Start() {
    // set both to high at the same time
    I2C_DDR &= ~((1 << I2C_DAT) | (1 << I2C_CLK));
    _delay_us(100); 
    I2C_DATA_LO();
    _delay_us(100);   
    I2C_CLOCK_LO();
    _delay_us(100);   
}

// Send a STOP Condition
//
void I2C_Stop(){
    I2C_CLOCK_HI();
    _delay_us(100);   
    I2C_DATA_HI();
    _delay_us(100);   
}

// write a byte to the I2C slave device
//
void I2C_Write(unsigned char c) {
    for (char i = 0; i < 8; i++){
        I2C_WriteBit(c & 0x80);
        c <<= 1;
    }
}

// read a byte from the I2C slave device
//
unsigned char I2C_Read(unsigned char ack) {
    unsigned char res = 0;
    for (char i = 0; i < 8; i++) {
        res <<= 1;
        res |= I2C_ReadBit();
    }
    if (ack > 0) {
      I2C_WriteBit(0);
    } else {
      I2C_WriteBit(1);
    }
    return res;
}

