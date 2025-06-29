#include "MeuADC.h"

void MeuADC::iniciarADC() {
  // Referência AVcc, resultado justificado à direita
  ADMUX = (1 << REFS0); // REFS0 = 1 → AVcc como referência
  // Habilita o ADC e define prescaler de 64 (frequência de clock: 16 MHz / 64 = 250 kHz)
  ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);
}

uint16_t MeuADC::lerCanal(uint8_t canal) {
  // Seleciona canal ADC (0 a 5 normalmente no ATmega328)
  ADMUX = (ADMUX & 0xF0) | (canal & 0x0F);

  // Inicia conversão
  ADCSRA |= (1 << ADSC);

  // Aguarda fim da conversão
  while (ADCSRA & (1 << ADSC));

  return ADC;
}
