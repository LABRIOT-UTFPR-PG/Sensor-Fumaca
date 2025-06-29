#ifndef MEUSERVO_H
#define MEUSERVO_H

#include <Arduino.h>

class MeuServo {
  private:
    uint8_t pin;
    bool ligado;

  public:
    MeuServo();
    void attach(uint8_t pino);
    void write(int angulo);
};

#endif
