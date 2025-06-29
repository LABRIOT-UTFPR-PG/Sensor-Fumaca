#include <EEPROM.h>

#include "MeuServo.h"
#include "MeuADC.h"

#define PinSensor 0 // A0 = canal 0 do ADC
#define PinLedVermelho 13
#define PinLedVerde 12
#define PinBuzzer 11
#define PinServo 9

int valorLeituraSensor;
MeuServo exaustor;
MeuADC adc;

void setup() {
  Serial.begin(9600);

  pinMode(PinLedVermelho, OUTPUT);
  pinMode(PinLedVerde, OUTPUT);
  pinMode(PinBuzzer, OUTPUT);
  pinMode(PinServo, OUTPUT); // Pode ser opcional se já setado em attach()

  adc.iniciarADC();
  exaustor.attach(PinServo);
  exaustor.write(90); // posição inicial
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
    delay(300);
    digitalWrite(PinBuzzer, LOW);

    for (int pos = 60; pos <= 120; pos += 1) {
      exaustor.write(pos);
      delay(15);
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

  delay(1000);
}
