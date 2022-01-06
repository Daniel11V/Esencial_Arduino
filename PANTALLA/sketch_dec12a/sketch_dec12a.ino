
#define TFT_DC    7
#define TFT_RST   8 
#define SCR_WD   240
#define SCR_HT   240   
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Arduino_ST7789_Fast.h>
Arduino_ST7789 pan = Arduino_ST7789(TFT_DC, TFT_RST);

void setup(void) 
{
  Serial.begin(9600);
  pan.init(SCR_WD, SCR_HT);
  pan.fillScreen(WHITE);
  pan.setCursor(90,57);
  pan.setTextColor(BLACK,WHITE);
  pan.setTextSize(2);
  pan.println("domingo");
  pan.setCursor(40,80);
  pan.setTextColor(BLACK,WHITE);
  pan.setTextSize(5);
  pan.println("22:11");
  pan.setCursor(185,100);
  pan.setTextColor(BLACK,WHITE);
  pan.setTextSize(2);
  pan.println(".47");
  pan.fillCircle(50,180,30,MAGENTA);
  pan.fillCircle(45,190,7,WHITE);
  pan.fillRect(48,162,5,30,WHITE);
  pan.fillRect(48,162,12,5,WHITE);
 }
void loop()
{
}
