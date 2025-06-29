#include "MeuServo.h"

MeuServo::MeuServo() {
  ligado = false;
}

void MeuServo::attach(uint8_t pino) {
  pin = pino;
  pinMode(pin, OUTPUT);
  ligado = true;
}

void MeuServo::write(int angulo) {
  if (!ligado) return;

  // Converte o ângulo (0-180) para largura de pulso (em microssegundos)
  int pulso = map(angulo, 0, 180, 544, 2400);

  // Gera o pulso manualmente (PWM de 20ms com HIGH entre 544-2400µs)
  digitalWrite(pin, HIGH);
  delayMicroseconds(pulso);
  digitalWrite(pin, LOW);

  // Aguarda o restante do ciclo PWM (20ms no total)
  delay(20);
}
