🚨 Projeto Arduino – Sensor de Fumaça com Alarme e Exaustor Simulado (Baixo Nível – ATmega328P)
Este projeto utiliza um Arduino Uno com ATmega328P, programado em baixo nível, para detectar a presença de fumaça ou gás, acionando um alarme sonoro, LEDs indicadores e um servo motor que simula um exaustor.

O diferencial está no uso direto dos registradores (PORTx, DDRx, PINx, ADMUX, etc.), sem funções da API do Arduino (digitalWrite, analogRead, pinMode, etc.), por meio de bibliotecas personalizadas.

⚙️ Funcionamento do Sistema
Um sensor analógico detecta a presença de gás/fumaça.

Se o nível ultrapassar o limite:

O LED vermelho acende (alerta visual).

O buzzer é ativado (alerta sonoro).

O servo motor gira, simulando um exaustor ligado.

Se o ambiente estiver normal:

O LED verde permanece aceso.

O sistema mantém o servo na posição neutra e o buzzer desligado.

🧰 Componentes Utilizados
Componente	Quantidade	Descrição
Arduino Uno (ATmega328P)	1	Microcontrolador principal do projeto
Sensor de fumaça/gás (MQ-x)	1	Sensor analógico
LED vermelho	1	Indica situação de risco
LED verde	1	Indica situação normal
Resistores (220Ω ou 330Ω)	2	Para os LEDs
Servo motor (SG90)	1	Simula a ventilação (exaustor)
Buzzer piezoelétrico	1	Emite alarme sonoro
Protoboard	1	Montagem do circuito
Jumpers	Vários	Conexões

🧠 Projeto em Baixo Nível com ATmega328P
Diferente de projetos convencionais com Arduino, aqui o foco é manipular diretamente os registradores do ATmega328P, como:

DDRx, PORTx, PINx → para GPIO

ADMUX, ADCSRA → para leitura analógica (ADC)

_delay_ms, _delay_us → para temporizações com precisão

📦 Bibliotecas Personalizadas
O projeto foi modularizado em bibliotecas de baixo nível criadas do zero:

Biblioteca	Função
MeuADC	Leitura do sensor analógico via registradores do ADC
MeuGPIO	Manipulação direta de GPIO (entrada e saída)
MeuBuzzer	Controle de alarme sonoro com PORTx direto
MeuServo	Geração manual de PWM com _delay_us

Todas essas bibliotecas usam apenas registradores e comandos da AVR, sem dependência da API Arduino.

🧪 Testes Realizados
✅ Simulação de fumaça (com isqueiro ou álcool)

✅ Acionamento correto do buzzer e servo

✅ Mudança precisa entre LEDs verde e vermelho

✅ Retorno ao estado normal após dissipação do gás

📁 Organização do Código
Arquivo/Função	Descrição
MeuSensor.ino	Lógica principal do sistema
MeuADC.{h,cpp}	Leitura analógica via registradores
MeuBuzzer.{h,cpp}	Alarme com buzzer usando PORTx
MeuServo.{h,cpp}	Controle de servo por PWM manual
MeuGPIO.{h,cpp}	Controle de LEDs (e qualquer GPIO) via registradores

📷 Esquema do Circuito
(Adicione aqui imagem do circuito feito no Fritzing ou foto da montagem)

📌 Melhorias Futuras
Adicionar um display LCD com I2C (ou SPI via TWI em baixo nível)

Implementar sistema de logs via UART ou EEPROM

Criar versão com interrupções e timers (PWM/ADC com Timer1)

---

## 📜 Licença

Este projeto é de uso livre para fins educacionais.

---
## 📜 Link Relatório

[Acesse Aqui](https://docs.google.com/document/d/1A4-A4iQ7DwhCGCf_uaStVyo3oVHcT0FxglDkav4sL4Y/edit?usp=sharing)


