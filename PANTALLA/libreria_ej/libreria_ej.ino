#include "libr.h"
int led=13;
String estado;

libr obj(led);

void setup(){
  Serial.begin(9600);
  
}

void loop(){
  obj.lento();
  obj.lento();

  obj.rapido();
  obj.rapido();
  obj.rapido();
  obj.rapido();
  obj.velocidad(700);
  obj.velocidad(700);
  obj.velocidad(700);
  obj.velocidad(700);
  estado=obj.estadoPin();
  Serial.print("El pin esta ");
  Serial.print(estado);
}
