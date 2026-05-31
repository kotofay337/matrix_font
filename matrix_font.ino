
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "MatrixFont.h"

// create TFT screen
#define TFT_DC 15
#define TFT_CS 13
#define TFT_MOSI 7
#define TFT_MISO 4
#define TFT_SCLK 6
#define TFT_RST 14
Adafruit_ILI9341 tft(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST, TFT_MISO);
MatrixFont mFont( &tft );

#define FGC ILI9341_ORANGE
#define BGC 0x0000

const char* text = "В Чащах Юга Жил Был Цитрус, Да, Но Фальшивый Экземпляр!";

void init(){
  tft.begin();
  tft.setSPISpeed(115200);
  tft.setTextWrap( false );
  tft.setRotation(135); // 0, 180, 90, 45, 135
  tft.fillRect(0, 0, tft.width(), tft.height(), BGC);
  tft.drawRect(0, 0, tft.width(), tft.height(), FGC);
}
void setup() {
  Serial.begin(1000000);
  init();
  
  int x = 2, y = 16;
  tft.setCursor(x, y);
  mFont.printf( FGC, BGC, "%s", text);
}
void loop() { 
}
