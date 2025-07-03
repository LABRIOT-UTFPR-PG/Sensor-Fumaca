#include "MeuServo.h"

MeuServo::MeuServo() {
  ligado = false;
}

void MeuServo::attach(char porta, uint8_t pino) {
  ligado = false;

  switch (porta) {
    case 'B':
      port = &PORTB;
      DDRB |= (1 << pino);
      break;
    case 'C':
      port = &PORTC;
      DDRC |= (1 << pino);
      break;
    case 'D':
      port = &PORTD;
      DDRD |= (1 << pino);
      break;
    default:
      return; // Porta inválida
  }

  bitmask = (1 << pino);
  ligado = true;
}

void MeuServo::write(uint8_t angulo) {
  if (!ligado) return;

  int pulso = map(angulo, 0, 180, 544, 2400);

  *port |= bitmask;
  delayMicroseconds(pulso);
  *port &= ~bitmask;

  delay(20);
}
