#ifndef libr_h
#define libr_h
#include "arduino.h"

class libr
{
  private:
    int _pin;
  public:
    libr(int led);
    void lento();
    void rapido();
    void velocidad(int vel);
    String estadoPin();
};

#endif
