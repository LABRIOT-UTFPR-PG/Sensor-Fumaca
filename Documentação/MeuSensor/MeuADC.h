#ifndef MEUADC_H
#define MEUADC_H

#include <avr/io.h>
#include <stdint.h>

class MeuADC {
  public:
    void iniciarADC();
    uint16_t lerCanal(uint8_t canal);
};

#endif
