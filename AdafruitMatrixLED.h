//
// AdafruitのマトリックスLEDの制御ライブラリ用ヘッダファイル
// 2014/11/09 ひね
//
// 利用したマトリックスLEDボードはこちら
// http://www.adafruit.com/products/870
//
// 制御のHT16K33のデータシートはこちら
// http://www.holtek.com.tw/pdf/consumer/ht16K33v110.pdf
//

// LEDの状態
#define LED_ON 1
#define LED_OFF 0

// AdafruitのマトリックスLED用の定数(ボードの設定で変更した場合は変更すること)
#define I2C_ADDR 0x70

// AdafruitのマトリックスLEDの命令
#define HT16K33_SETUP_CMD 0x20
#define HT16K33_SETUP_OSCILLATORON 0x01
#define HT16K33_SETUP_OSCILLATOROFF 0x00
#define HT16K33_BLINK_CMD 0x80
#define HT16K33_BLINK_DISPLAYON 0x01
#define HT16K33_BLINK_OFF 0
#define HT16K33_BLINK_2HZ 1
#define HT16K33_BLINK_1HZ 2
#define HT16K33_BLINK_HALFHZ 3
#define HT16K33_BRIGHTNESS_CMD 0xE0
#define HT16K33_BRIGHTNESS_MIN 0
#define HT16K33_BRIGHTNESS_MAX 15
#define HT16K33_DISPLAYMEMORY_STARTADDR 0x00

