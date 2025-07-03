#include "MeuBuzzer.h"

void MeuBuzzer::iniciar(char porta, uint8_t pino) {
  bit = pino;

  switch (porta) {
    case 'B':
      port = &PORTB;
      DDRB |= (1 << bit);
      break;
    case 'C':
      port = &PORTC;
      DDRC |= (1 << bit);
      break;
    case 'D':
      port = &PORTD;
      DDRD |= (1 << bit);
      break;
  }

  desligar();
}

void MeuBuzzer::ligar() {
  *port |= (1 << bit);
}

void MeuBuzzer::desligar() {
  *port &= ~(1 << bit);
}

void MeuBuzzer::tocarPor(uint16_t ms) {
  ligar();
  while (ms--) _delay_ms(1);
  desligar();
}
