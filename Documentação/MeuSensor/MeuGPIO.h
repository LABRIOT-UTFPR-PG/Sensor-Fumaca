#ifndef MEUGPIO_H
#define MEUGPIO_H

#include <avr/io.h>

class MeuGPIO {
  private:
    volatile uint8_t* ddr;
    volatile uint8_t* port;
    volatile uint8_t* pin;
    uint8_t bit;

  public:
    MeuGPIO();
    void configurarSaida(char porta, uint8_t pino);
    void configurarEntrada(char porta, uint8_t pino);
    void escrever(bool valor);
    bool ler();
};

#endif
