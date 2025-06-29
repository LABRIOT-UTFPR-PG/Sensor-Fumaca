#include "MeuLCD.h"

#define LCD_BACKLIGHT 0x08
#define LCD_ENABLE    0x04
#define LCD_COMMAND   0
#define LCD_DATA      1

MeuLCD::MeuLCD(uint8_t endereco) {
  enderecoI2C = endereco;
  backlightVal = LCD_BACKLIGHT;
}

void MeuLCD::iniciar() {
  Wire.begin();
  delay(50); // Espera inicial do LCD

  // Inicialização 4 bits (sequência obrigatória)
  enviaNibble(0x03, LCD_COMMAND);
  delay(5);
  enviaNibble(0x03, LCD_COMMAND);
  delay(5);
  enviaNibble(0x03, LCD_COMMAND);
  delay(1);
  enviaNibble(0x02, LCD_COMMAND); // Modo 4 bits

  enviaComando(0x28); // 2 linhas, fonte 5x8
  enviaComando(0x0C); // LCD on, cursor off
  enviaComando(0x06); // Entrada de texto à direita
  limpar();
}

void MeuLCD::limpar() {
  enviaComando(0x01);
  delay(2);
}

void MeuLCD::setCursor(uint8_t col, uint8_t row) {
  static uint8_t linhas[] = {0x00, 0x40};
  enviaComando(0x80 | (col + linhas[row]));
}

void MeuLCD::print(const String &texto) {
  for (uint8_t i = 0; i < texto.length(); i++) {
    enviaDado(texto[i]);
  }
}

void MeuLCD::enviaComando(uint8_t valor) {
  enviaNibble(valor >> 4, LCD_COMMAND);
  enviaNibble(valor & 0x0F, LCD_COMMAND);
}

void MeuLCD::enviaDado(uint8_t valor) {
  enviaNibble(valor >> 4, LCD_DATA);
  enviaNibble(valor & 0x0F, LCD_DATA);
}

void MeuLCD::enviaNibble(uint8_t nibble, uint8_t modo) {
  uint8_t dados = (nibble << 4) | backlightVal;
  if (modo == LCD_DATA) dados |= 0x01;

  // Pulso do enable
  Wire.beginTransmission(enderecoI2C);
  Wire.write(dados | LCD_ENABLE);
  Wire.endTransmission();
  delayMicroseconds(1);

  Wire.beginTransmission(enderecoI2C);
  Wire.write(dados & ~LCD_ENABLE);
  Wire.endTransmission();
  delayMicroseconds(50);
}
