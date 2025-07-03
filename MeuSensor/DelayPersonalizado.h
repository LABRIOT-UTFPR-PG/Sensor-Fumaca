#ifndef DELAYPERSONALIZADO_H
#define DELAYPERSONALIZADO_H

#include <Arduino.h>

class DelayPersonalizado {
public:
  DelayPersonalizado();  // Construtor

  void delayMs(unsigned long tempo);           // Delay tradicional
  void delayComMensagem(unsigned long tempo);  // Delay com LED ou print

};

#endif
