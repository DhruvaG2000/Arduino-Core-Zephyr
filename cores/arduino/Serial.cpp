#include "Serial.h"

using namespace arduino;

UART::UART(int tx, int rx, int rts, int cts) {

}

void UART::begin(unsigned long baudrate, uint16_t config) {

}

void UART::begin(unsigned long baudrate) {

}

int UART::read() {

return 0;

}

size_t UART::write(uint8_t c) {
return 0;
}

size_t UART::write(const uint8_t* c, size_t len) {
    return 0;
}

UART _UART1_(SERIAL1_TX, SERIAL1_RX, NC, NC);