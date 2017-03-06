# ESP32 LEDC Wrapper Library
Wrapper library for the [ESP32 LEDC implementation ](https://github.com/espressif/arduino-esp32/blob/master/cores/esp32/esp32-hal-ledc.h) in the arduino core.

## Install
Copy the contents of the folder inside your arduino library
```
git clone https://github.com/jrodrigoc/ESP32-LEDC
mv ESP32-LEDC ~/sketchbook/libraries/
```

## Sample code
```
#include <LED_ESP32.h>
#include <LED_ESP32.h>
LED_ESP32 led1(5,0);
int increase = 5;
int val = 0;
void setup() {
  led1.setup();
}

void loop() {
  led1.set(val);
  val = val + increase;
  if(val<=0 || val>= 255) {
    increase = -increase;
  }
  delay(50);
}
```

## Docs
### Init
```
LED_ESP32 led(uint8_t pin, uint8_t channel, uint32_t valueMax, uint32_t freq , uint8_t precision)
```
**pin**: GPIO

**channel**: 0-16

**valueMax**: maximum accepted value. Defaults to 255

**freq**: Frequency. Defaults to 5000Hz

**precision**: precission for LEDC timer. Defaults to 13 bit

### led.set(uint32_t value)

**value**: 0 - valueMax. The max value is set either through the init function or the *updateMaxValue()* method.

### led.updateMaxValue(uint32_t valueMax)
**valueMax**: Sets the maximum value. This method updates the current brightness.

### led.updateBaseFreq(uint32_t freq)
**freq**: Updates base frequency. This method updates the current brightness.

### led.on()
Sets the pin to the max value (3.3V).

### led.off()
Sets the pin to the lowest possible value, 0. (0V)
