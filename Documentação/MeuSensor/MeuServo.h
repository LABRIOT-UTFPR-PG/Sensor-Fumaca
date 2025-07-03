#ifndef MEUSERVO_H
#define MEUSERVO_H

#include <Arduino.h>
#include <avr/io.h>

class MeuServo {
  private:
    volatile uint8_t* port;
    uint8_t bitmask;
    bool ligado;

  public:
    MeuServo();
    void attach(char porta, uint8_t pino);
    void write(uint8_t angulo);
};

#endif
