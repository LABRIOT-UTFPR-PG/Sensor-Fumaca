#include <EEPROM.h>

#include "MeuServo.h"
#include "MeuADC.h"
#include "DelayPersonalizado.h"

#define PinSensor 0 
#define PinLedVermelho 13
#define PinLedVerde 12
#define PinBuzzer 11
#define PinServo 9

int valorLeituraSensor;
MeuServo exaustor;
MeuADC adc;
DelayPersonalizado meuDelay;

void setup() {
  Serial.begin(9600);

  pinMode(PinLedVermelho, OUTPUT);
  pinMode(PinLedVerde, OUTPUT);
  pinMode(PinBuzzer, OUTPUT);
  pinMode(PinServo, OUTPUT); 

  adc.iniciarADC();
  exaustor.attach(PinServo);
  exaustor.write(90); 
}

void loop() {
  valorLeituraSensor = adc.lerCanal(PinSensor);

  Serial.print("Valor detectado pelo sensor: ");
  Serial.println(valorLeituraSensor);

  if (valorLeituraSensor >= 200) {
    Serial.println("Fumaça/gás detectado");
    digitalWrite(PinLedVerde, LOW);
    digitalWrite(PinLedVermelho, HIGH);
    digitalWrite(PinBuzzer, HIGH);
    meuDelay.delayComMensagem(3000); 
    digitalWrite(PinBuzzer, LOW);

    for (int pos = 60; pos <= 120; pos += 1) {
      exaustor.write(pos);
      meuDelay.delayMs(3000); 
    }
    for (int pos = 120; pos >= 60; pos -= 1) {
      exaustor.write(pos);
      delay(15);
    }
  } else {
    Serial.println("Fumaça/gás não detectado");
    digitalWrite(PinLedVerde, HIGH);
    digitalWrite(PinLedVermelho, LOW);
    digitalWrite(PinBuzzer, LOW);
    exaustor.write(90);
  }

  meuDelay.delayMs(1000); 
}
