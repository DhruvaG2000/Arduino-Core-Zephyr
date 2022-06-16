#include "Common.h"

/* C++ prototypes */
long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

uint16_t makeWord(uint16_t w) { return w; }
uint16_t makeWord(uint8_t h, uint8_t l) { return (h << 8) | l; }

/*
* A build error on this line means your board is unsupported.
* See the sample documentation for information on how to fix this.
*/
static struct gpio_dt_spec pin;

void pinMode(pin_size_t pinNumber, PinMode pinMode)
{
  pin = { .port = (&__device_dts_ord_9), .pin = pinNumber, .dt_flags = 1, };
  if (pinNumber == LED_BUILTIN)
  {
    if (pinMode == OUTPUT)
    {
      gpio_pin_configure_dt(&pin, GPIO_OUTPUT);
    }
    if (pinMode == INPUT)
    {
      gpio_pin_configure_dt(&pin, GPIO_INPUT);
    }
  }
}

void digitalWrite(pin_size_t pinNumber, PinStatus status)
{
  if (pinNumber == LED_BUILTIN)
  {
    if (status == HIGH)
    {
      gpio_pin_set_dt(&pin, GPIO_ACTIVE_HIGH);
    }
    if (status == LOW)
    {
      gpio_pin_set_dt(&pin, GPIO_ACTIVE_LOW);
    }
  }
}

void delay(unsigned long ms)
{
    k_sleep(K_MSEC(ms));
}

void delayMicroseconds(unsigned int us)
{
  k_sleep(K_USEC(us));
}