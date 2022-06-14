#include "Wire.h"

void arduino::ZephyrI2C::begin() {
  // const struct device *dev = DEVICE_DT_GET_ANY(adi_adxl372);
  printk("IIC begin\n");
}

void arduino::ZephyrI2C::begin(uint8_t slaveAddr) {}

void arduino::ZephyrI2C::end() {}

void arduino::ZephyrI2C::setClock(uint32_t freq) {}

void arduino::ZephyrI2C::beginTransmission(uint8_t address) {}

uint8_t arduino::ZephyrI2C::endTransmission(bool stopBit) { return 2; }

uint8_t arduino::ZephyrI2C::endTransmission(void) {
  return endTransmission(true);
}

size_t arduino::ZephyrI2C::requestFrom(uint8_t address, size_t len,
                                       bool stopBit) {

  return len;
}

size_t arduino::ZephyrI2C::requestFrom(uint8_t address, size_t len) {
  return requestFrom(address, len, true);
}

size_t arduino::ZephyrI2C::write(uint8_t data) { return 1; }

size_t arduino::ZephyrI2C::write(const uint8_t *buffer, size_t size) {
  return size;
}

int arduino::ZephyrI2C::read() { return 0; }

int arduino::ZephyrI2C::available() { return 1; }

int arduino::ZephyrI2C::peek() { return 1; }

void arduino::ZephyrI2C::flush() {}

void arduino::ZephyrI2C::onReceive(voidFuncPtrParamInt cb) {}
void arduino::ZephyrI2C::onRequest(voidFuncPtr cb) {}

arduino::ZephyrI2C Wire;