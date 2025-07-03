#include "DelayPersonalizado.h"

void DelayPersonalizado::delayMs(unsigned long tempo) {
  delay(tempo);
}

void DelayPersonalizado::delayComMensagem(unsigned long tempo) {
  unsigned long start = millis();
  while (millis() - start < tempo) {
    Serial.print(".");
    delay(500);  // mostra "." a cada meio segundo
  }
  Serial.println();
}
