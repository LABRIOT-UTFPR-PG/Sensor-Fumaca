# 🚨 Projeto Arduino – Sensor de Fumaça com Alarme e Exaustor Simulado

Este projeto utiliza um **Arduino Uno (ATmega328P)** para detectar a presença de fumaça ou gás no ambiente, acionando um alarme sonoro, LEDs indicadores e simulando um exaustor com um servo motor.

---

## ⚙️ Funcionamento do Sistema

1. O sensor de fumaça detecta a presença de gás no ambiente.
2. Se for detectado um nível acima do limite:
   - O **LED vermelho acende** (alerta visual).
   - O **buzzer é ativado** (alerta sonoro).
   - O **servo motor gira**, simulando a ativação de um exaustor.
3. Se não houver gás, o **LED verde permanece aceso**, indicando normalidade.

---

## 🧰 Componentes Utilizados

| Componente            | Quantidade | Descrição                                     |
|----------------------|------------|-----------------------------------------------|
| Arduino Uno (ATmega328P) | 1          | Microcontrolador principal do projeto         |
| Sensor de fumaça/gás (MQ-x) | 1          | Sensor analógico para detecção de fumaça      |
| LED vermelho          | 1          | Indica situação de perigo                     |
| LED verde             | 1          | Indica situação normal                        |
| Resistores (220Ω ou 330Ω) | 2          | Limita corrente para os LEDs                  |
| Servo motor (SG90)    | 1          | Simula o funcionamento de um exaustor         |
| Buzzer piezoelétrico  | 1          | Alerta sonoro em caso de detecção de fumaça   |
| Protoboard            | 1          | Para montagem dos componentes                 |
| Jumpers               | Vários     | Para ligações entre o Arduino e os sensores   |

---

## 🧠 Microcontrolador: ATmega328P

O projeto é baseado no **Arduino Uno**, que utiliza o microcontrolador **ATmega328P**, um chip de 8 bits da família AVR. Ele oferece:

- 14 pinos digitais (6 com PWM)
- 6 entradas analógicas
- Memória flash de 32 KB
- Velocidade de 16 MHz

Este chip é responsável por:
- Ler sinais analógicos do sensor de fumaça
- Controlar os LEDs, buzzer e servo
- Processar a lógica de detecção e resposta

---

## 🔄 Comparação com Microcontroladores PIC (contexto da disciplina)

A disciplina tem foco em microcontroladores PIC. Aqui está uma comparação para contextualizar:

| Característica         | ATmega328P (Arduino) | Exemplo PIC (ex: PIC16F877A) |
|------------------------|----------------------|------------------------------|
| Arquitetura            | AVR (8-bit RISC)     | PIC (8-bit RISC)             |
| IDE                    | Arduino IDE          | MPLAB X + XC8                |
| Linguagem              | C++ simplificado     | C (mais próximo do hardware) |
| Facilidade de uso      | Muito alta           | Média (mais manual)          |
| Programação            | USB (via bootloader) | Requer gravador externo      |
| Periféricos            | PWM, ADC, UART etc.  | Também oferece recursos similares |

> 💡 **Nota:** O mesmo projeto poderia ser implementado em um PIC, mas exigiria maior detalhamento no controle do ADC, PWM e GPIOs.

---

## 🧪 Testes Realizados

- ✅ Detecção de fumaça artificial (isqueiro/álcool)
- ✅ Acionamento do buzzer e servo motor
- ✅ Mudança correta dos LEDs
- ✅ Reset do sistema após retirada da fumaça

---

## 📷 Imagens e Esquema do Projeto

> *(Adicionar aqui imagens da montagem, e esquema do circuito se tiver feito no Fritzing ou similar)*

---

## 📁 Organização do Código

O código foi dividido em:
- `SensorFumaca.ino` – lógica principal do sistema
- `LeituraAnalogica` – biblioteca personalizada para leitura do sensor
- `ControleExaustor` – biblioteca para acionar o servo motor

---

## 📌 Possíveis Melhorias

- Adicionar display para mostrar valores do sensor
- Enviar alertas via Wi-Fi com ESP8266
- Integrar bateria ou fonte externa

---

## 📜 Licença

Este projeto é de uso livre para fins educacionais.

---

