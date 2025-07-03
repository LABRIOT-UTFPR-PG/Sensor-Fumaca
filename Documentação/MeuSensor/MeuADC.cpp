#include "MeuADC.h"

void MeuADC::iniciarADC() {
  ADMUX = (1 << REFS0); // REFS0 = 1 → AVcc como referência
  ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1); // Prescaler 64
}

uint16_t MeuADC::lerCanal(uint8_t canal) {
  ADMUX = (ADMUX & 0xF0) | (canal & 0x0F); // Seleciona canal 

  ADCSRA |= (1 << ADSC); // Inicia conversão

  while (ADCSRA & (1 << ADSC)); // Espera terminar

  return ADC;
}
