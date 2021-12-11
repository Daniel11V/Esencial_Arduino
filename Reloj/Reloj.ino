#include <SoftwareSerial.h>

SoftwareSerial miBT(10,11);

void setup(){
  Serial.begin(9600);
  Serial.println("listo")
  miBT.begin(38400);
  }

void loop(){
  if (miBT.avaible())
  Serial.write(miBT.read());

  if (Serial.avaible())
  miBT.write(Serial.read());
  
}
