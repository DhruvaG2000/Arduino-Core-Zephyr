#include "Common.h"

/* C++ prototypes */
long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

uint16_t makeWord(uint16_t w) { return w; }
uint16_t makeWord(uint8_t h, uint8_t l) { return (h << 8) | l; }

void pinMode(pin_size_t pinNumber, PinMode pinMode) {
  if (pinNumber >= 100) {
    pinNumber -= 100;
    if (pinMode == INPUT) {
      gpio_pin_configure(DEVICE_DT_GET(DT_NODELABEL(gpio1)), pinNumber,
                         GPIO_INPUT);
    } else {
      gpio_pin_configure(DEVICE_DT_GET(DT_NODELABEL(gpio1)), pinNumber,
                         GPIO_OUTPUT);
    }
  } else if (pinNumber < 100) {
    if (pinMode == INPUT) {
      gpio_pin_configure(DEVICE_DT_GET(DT_NODELABEL(gpio0)), pinNumber,
                         GPIO_INPUT);
    } else {
      gpio_pin_configure(DEVICE_DT_GET(DT_NODELABEL(gpio0)), pinNumber,
                         GPIO_OUTPUT);
    }
  }
}

void digitalWrite(pin_size_t pinNumber, PinStatus status) {
  if (pinNumber >= 100) {
    pinNumber -= 100;
    if (status == HIGH) {
      gpio_pin_set(DEVICE_DT_GET(DT_NODELABEL(gpio1)), pinNumber,
                   GPIO_ACTIVE_HIGH);
    } else if (status == LOW) {
      gpio_pin_set(DEVICE_DT_GET(DT_NODELABEL(gpio1)), pinNumber,
                   GPIO_ACTIVE_LOW);
    }
  } else if (pinNumber < 100) {
    if (status == HIGH) {
      gpio_pin_set(DEVICE_DT_GET(DT_NODELABEL(gpio0)), pinNumber,
                   GPIO_ACTIVE_HIGH);
    } else if (status == LOW) {
      gpio_pin_set(DEVICE_DT_GET(DT_NODELABEL(gpio0)), pinNumber,
                   GPIO_ACTIVE_LOW);
    }
  }
}

PinStatus digitalRead(pin_size_t pinNumber) {
  if (pinNumber >= 100) {
    pinNumber -= 100;
    return (gpio_pin_get(DEVICE_DT_GET(DT_NODELABEL(gpio1)), pinNumber) == 1)
               ? HIGH
               : LOW;
  } else if (pinNumber < 100) {
    return (gpio_pin_get(DEVICE_DT_GET(DT_NODELABEL(gpio0)), pinNumber) == 1)
               ? HIGH
               : LOW;
  }
}

void delay(unsigned long ms) { k_sleep(K_MSEC(ms)); }

void delayMicroseconds(unsigned int us) { k_sleep(K_USEC(us)); }