#include <Servo.h>

#define PinSensor A0
#define PinLedVermelho 13
#define PinLedVerde 12
#define PinBuzzer 11
#define PinServo 9


int valorLeituraSensor;
Servo exaustor;

void setup() {
  Serial.begin(9600);
  pinMode(PinSensor, INPUT);
  pinMode(PinLedVermelho, OUTPUT);
  pinMode(PinLedVerde, OUTPUT);
  pinMode(PinBuzzer, OUTPUT);

  exaustor.attach(PinServo);
  exaustor.write(90); // posição inicial
}

void loop() {
  valorLeituraSensor = analogRead(PinSensor);
  Serial.print("Valor detectado pelo sensor: ");
  Serial.println(valorLeituraSensor);

  if (valorLeituraSensor >= 200) {
    Serial.println("Fumaça/gás detectado");
    digitalWrite(PinLedVerde, LOW);
    digitalWrite(PinLedVermelho, HIGH);
    digitalWrite(PinBuzzer, HIGH);
    digitalWrite(PinBuzzer, HIGH);
    delay(300); // buzina por 300ms
    digitalWrite(PinBuzzer, LOW);  
    
    // Simula movimento do exaustor
  for (int pos = 0; pos <= 120; pos += 1) {
  	exaustor.write(pos);
  	delay(10); // movimento bem suave
   }
  for (int pos = 120; pos >= 60; pos -= 1) {
  	exaustor.write(pos);
  	delay(10);
  }


  } else {
    Serial.println("Fumaça/gás não detectado");
    digitalWrite(PinLedVerde, HIGH);
    digitalWrite(PinLedVermelho, LOW);
    digitalWrite(PinBuzzer, LOW);
    exaustor.write(90); // Volta ao centro
  }

  delay(100);
}