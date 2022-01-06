#include <SoftwareSerial.h>

SoftwareSerial blue (2,4);


void setup() {
  Serial.begin(9600);
  blue.begin(9600);

  

  
    
}
void loop() {
  
  if(blue.available())
  Serial.write(blue.read());
  
  if(Serial.available())
  blue.write(Serial.read());
}
