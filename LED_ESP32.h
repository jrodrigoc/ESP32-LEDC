/*
** LED_ESP32.h
** Jaime Rodrigo
** PanamaHitek
*/

#ifndef LED_ESP32_h

#define LED_ESP32_h
#include "Arduino.h"

class LED_ESP32
{
  public:
    LED_ESP32(uint8_t pin, uint8_t channel, uint32_t valueMax = 255, uint32_t freq = 5000 , uint8_t precision = 13);
    void setup();
    void set(uint32_t value);
    void on();
    void off();
    void updateBaseFreq(uint32_t freq);
    void updateMaxValue(uint32_t valueMax);
  private:
    void _analogWrite(uint32_t value);
    int _BASE_FREQ;
    byte _TIMER_PRECISION;
    byte _PIN;
    int _MAX_VALUE;
    int _DUTY_MAX;
    byte _CHANNEL;
    byte _isWorking = 0;
    int currentValue;
};

#endif
