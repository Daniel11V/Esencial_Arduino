#include <SoftwareSerial.h>

// conf bluetooth
SoftwareSerial miBT(3,4);
// conf pantalla
#define TFT_DC    7
#define TFT_RST   8 
#define SCR_WD   240
#define SCR_HT   240   // 320 - to allow access to full 240x320 frame buffer
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Arduino_ST7789_Fast.h>
Arduino_ST7789 lcd = Arduino_ST7789(TFT_DC, TFT_RST);

void setup(){
  Serial.begin(9600);
  Serial.println("listo");

  // conf bluetooth
  miBT.begin(38400);

  // conf pantalla
  lcd.init(SCR_WD, SCR_HT);
  lcd.fillScreen(BLACK);
  lcd.setCursor(0, 0);
  lcd.setTextColor(WHITE,BLUE);
  lcd.setTextSize(3);
  lcd.println("HELLO WORLD");
  }

void loop(){
  if (miBT.available())
  Serial.write(miBT.read());

  if (Serial.available())
  miBT.write(Serial.read());
  
}
