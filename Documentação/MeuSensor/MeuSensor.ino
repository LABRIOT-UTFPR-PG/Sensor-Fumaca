#include "MeuADC.h"
#include "MeuServo.h"
#include "MeuBuzzer.h"
#include "MeuGPIO.h"  // ← Biblioteca para controle de I/O

// ===============================
// Definições de hardware
// ===============================
#define PinSensor        0   // Canal A0 (ADC0)

// ===============================
// Instâncias de periféricos
// ===============================
MeuADC adc;
MeuServo exaustor;
MeuBuzzer buzzer;
MeuGPIO ledVermelho;
MeuGPIO ledVerde;

// ===============================
// Configuração inicial
// ===============================
void setup() {
  Serial.begin(9600);

  // LEDs como saída usando MeuGPIO
  ledVermelho.configurarSaida('B', 5); // PB5 → pino 13
  ledVerde.configurarSaida('B', 4);    // PB4 → pino 12

  // Inicializações
  adc.iniciarADC();

  exaustor.attach('B', 1);   // PB1 = pino 9
  exaustor.write(90);        // posição neutra

  buzzer.iniciar('B', 3);    // PB3 = pino 11
  buzzer.desligar();
}

// ===============================
// Laço principal
// ===============================
void loop() {
  uint16_t valorSensor = adc.lerCanal(PinSensor);

  Serial.print("Valor do sensor: ");
  Serial.println(valorSensor);

  // =============================
  // Situação: Gás/Fumaça detectado
  // =============================
  if (valorSensor >= 200) {
    ledVerde.escrever(false);
    ledVermelho.escrever(true);
    buzzer.tocarPor(300);
    exaustor.write(120);
  }
  // =============================
  // Situação: Ambiente normal
  // =============================
  else {
    ledVerde.escrever(true);
    ledVermelho.escrever(false);
    buzzer.desligar();
    exaustor.write(90);
  }

  _delay_ms(500); // Aguarda 500ms entre leituras
}
