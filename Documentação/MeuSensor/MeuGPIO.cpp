#include "MeuGPIO.h"

MeuGPIO::MeuGPIO() {}

void MeuGPIO::configurarSaida(char porta, uint8_t pino) {
  bit = pino;
  switch (porta) {
    case 'B':
      ddr = &DDRB; port = &PORTB; pin = &PINB; break;
    case 'C':
      ddr = &DDRC; port = &PORTC; pin = &PINC; break;
    case 'D':
      ddr = &DDRD; port = &PORTD; pin = &PIND; break;
  }
  *ddr |= (1 << bit);
}

void MeuGPIO::configurarEntrada(char porta, uint8_t pino) {
  bit = pino;
  switch (porta) {
    case 'B':
      ddr = &DDRB; port = &PORTB; pin = &PINB; break;
    case 'C':
      ddr = &DDRC; port = &PORTC; pin = &PINC; break;
    case 'D':
      ddr = &DDRD; port = &PORTD; pin = &PIND; break;
  }
  *ddr &= ~(1 << bit);
}

void MeuGPIO::escrever(bool valor) {
  if (valor)
    *port |= (1 << bit);
  else
    *port &= ~(1 << bit);
}

bool MeuGPIO::ler() {
  return (*pin & (1 << bit));
}
