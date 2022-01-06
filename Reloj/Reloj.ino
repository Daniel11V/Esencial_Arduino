#include <TimeLib.h>
#include <SoftwareSerial.h>
#define TFT_DC    7
#define TFT_RST   8 
#define SCR_WD   240
#define SCR_HT   240   
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Arduino_ST7789_Fast.h>
Arduino_ST7789 pan = Arduino_ST7789(TFT_DC, TFT_RST);

// conf bluetooth
SoftwareSerial blue (2,4);
// conf pantalla 
  String fecha = "sabado";
  int hora = 0;
  int minu = 0;
  int seg = 0;
  String tr = __TIME__;
  
void setup(){
  Serial.begin(9600);

  // conf bluetooth
  blue.begin(9600);
 int v1 = (String(tr[0])+String(tr[1])).toInt();
 int v2 = (String(tr[3])+String(tr[4])).toInt();
 int v3 = (String(tr[6])+String(tr[7])).toInt();
  // conf pantalla
  setTime(v1,v2,v3,18,12,2021);
  pan.init(SCR_WD, SCR_HT);
  pan.fillScreen(BLACK);
  pan.setCursor(90,57);
  pan.setTextColor(WHITE,BLACK);
  pan.setTextSize(2);
  pan.println(fecha);
  pan.fillCircle(50,180,30,MAGENTA);
  pan.fillCircle(45,190,7,BLACK);
  pan.fillRect(48,162,5,30,BLACK);
  pan.fillRect(48,162,12,5,BLACK);
  imprimirReloj();
}
void loop(){


  if(second() == 0){
    imprimirReloj();
  }
  
  if(blue.available()){
    Serial.write(blue.read());
    hora = int(blue.read());
  };
  
  
  if(Serial.available())
  blue.write(Serial.read());
  
};
void imprimirReloj(){
  
  pan.setCursor(40,80);
  pan.setTextColor(WHITE,BLACK);
  pan.setTextSize(5);
  if(hour() <= 9){
      pan.print("0"+String(hour()));
    }else{
      pan.print(String(hour()));
    };
  pan.setCursor(100,80);
  pan.setTextColor(WHITE,BLACK);
  pan.setTextSize(5);
  pan.print(":");
  pan.setCursor(130,80);
  pan.setTextColor(WHITE,BLACK);
  pan.setTextSize(5);
  if(minute() <= 9){
      pan.print("0"+String(minute()));
    }else{
      pan.print(String(minute()));
    };
/*  pan.setCursor(185,100);
  pan.setTextColor(WHITE,BLACK);
  pan.setTextSize(2);
  if(second() <= 9){
      pan.print(".0"+String(second()));
    }else{
      pan.print("."+String(second()));
    };  */
};
