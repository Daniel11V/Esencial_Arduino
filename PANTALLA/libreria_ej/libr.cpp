#include "libr.h"
#include "arduino.h"


libr::libr(int led)
{
  pinMode(led,OUTPUT);
  _pin=led;  
}

void libr::lento()
{
  digitalWrite(_pin,HIGH);
  delay(2000);
  digitalWrite(_pin,LOW);
  delay(2000);
}
void libr::rapido()
{
  digitalWrite(_pin,HIGH);
  delay(200);
  digitalWrite(_pin,LOW);
  delay(200);
}
void libr::velocidad(int vel)
{
  digitalWrite(_pin,HIGH);
  delay(vel);
  digitalWrite(_pin,LOW);
  delay(vel);
}
String libr::estadoPin()
{
  if(digitalRead(_pin)==HIGH)
    return "encendido";
  else
    return "apagado";
}
