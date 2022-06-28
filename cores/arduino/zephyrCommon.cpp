#include "Arduino.h"

void delay(unsigned long ms)
{
    k_sleep(K_MSEC(ms));
}

void delayMicroseconds(unsigned int us)
{
  k_sleep(K_USEC(us));
}