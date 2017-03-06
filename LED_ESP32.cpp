/*
** LED_ESP32.h
** Jaime Rodrigo
** PanamaHitek
*/

#include "LED_ESP32.h"
#include "Arduino.h"

 LED_ESP32::LED_ESP32(uint8_t pin, uint8_t channel, uint32_t valueMax, uint32_t freq , uint8_t precision) {
      _PIN = pin;
      _CHANNEL = channel;
      _MAX_VALUE = valueMax;
      _TIMER_PRECISION = precision;
      _BASE_FREQ = freq;
      _DUTY_MAX  = _BASE_FREQ / _MAX_VALUE;
    }
 void LED_ESP32::setup() {
      ledcSetup(_CHANNEL, _BASE_FREQ, _TIMER_PRECISION);
      ledcAttachPin(_PIN, _CHANNEL);
    }
 void LED_ESP32::set(uint32_t value) {
       _isWorking = (value>0 && value<=_MAX_VALUE) ? 1 : 0;
       currentValue = value;
      _analogWrite(value);
    }
 void LED_ESP32::on() {
       _isWorking = 1;
       currentValue = _MAX_VALUE;
      _analogWrite(currentValue);
    }
 void LED_ESP32::off() {
       _isWorking = 0;
       currentValue = 0;
      _analogWrite(currentValue);
    }
 void LED_ESP32::updateBaseFreq(uint32_t freq){
      _BASE_FREQ = freq;
      _DUTY_MAX  = _BASE_FREQ / _MAX_VALUE;
      if(_isWorking) set(currentValue);
    }
 void LED_ESP32::updateMaxValue(uint32_t valueMax){
      _MAX_VALUE = valueMax;
      _DUTY_MAX  = _BASE_FREQ / _MAX_VALUE;
      if(_isWorking) set(currentValue);
    }
 void LED_ESP32::_analogWrite(uint32_t value) {
      uint32_t duty = _DUTY_MAX * min(value, _MAX_VALUE);
      ledcWrite(_CHANNEL, duty);
    }
