#ifndef MEU_LCD_H
#define MEU_LCD_H

#include <Arduino.h>
#include <Wire.h>

class MeuLCD {
  private:
    uint8_t enderecoI2C;
    uint8_t backlightVal;
    void enviaComando(uint8_t valor);
    void enviaDado(uint8_t valor);
    void enviaNibble(uint8_t nibble, uint8_t modo);

  public:
    MeuLCD(uint8_t endereco = 0x27); // Endereço padrão
    void iniciar();
    void limpar();
    void setCursor(uint8_t col, uint8_t row);
    void print(const String &texto);
};

#endif
