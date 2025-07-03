#ifndef MEUBUZZER_H
#define MEUBUZZER_H

#include <avr/io.h>
#include <util/delay.h>

class MeuBuzzer {
  private:
    volatile uint8_t* port;
    uint8_t bit;

  public:
    void iniciar(char porta, uint8_t pino);
    void ligar();
    void desligar();
    void tocarPor(uint16_t ms);
};

#endif
