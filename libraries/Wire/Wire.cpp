#include "Wire.h"

int arduino::ZephyrI2C::write_bytes(const struct device *i2c_dev,
		       uint8_t *data, uint32_t num_bytes)
{
	struct i2c_msg msgs[2];

	/* Data to be written, and STOP after this. */
	msgs[1].buf = data;
	msgs[1].len = num_bytes;
	msgs[1].flags = I2C_MSG_WRITE | I2C_MSG_STOP;

	return i2c_transfer(i2c_dev, &msgs[0], 2, _address);
}

void arduino::ZephyrI2C::begin() {
  i2c_dev = DEVICE_DT_GET(DT_NODELABEL(i2c0));
}

void arduino::ZephyrI2C::begin(uint8_t slaveAddr) {

}

void arduino::ZephyrI2C::end() {}

void arduino::ZephyrI2C::setClock(uint32_t freq) {}

void arduino::ZephyrI2C::beginTransmission(uint8_t address) { // TODO for ADS1115
  _address = address;
  usedTxBuffer = 0;
}

uint8_t arduino::ZephyrI2C::endTransmission(bool stopBit) {
  uint8_t ret = write_bytes(i2c_dev, txBuffer, sizeof(txBuffer));
  if (ret) {
    return 1; // fail
  }
  return 0;
}

uint8_t arduino::ZephyrI2C::endTransmission(void) { // TODO for ADS1115
  return endTransmission(true);
}

size_t arduino::ZephyrI2C::requestFrom(uint8_t address, size_t len,
                                       bool stopBit) {

  return len;
}

size_t arduino::ZephyrI2C::requestFrom(uint8_t address, size_t len) { // TODO for ADS1115
  return requestFrom(address, len, true);
}

size_t arduino::ZephyrI2C::write(uint8_t data) {  // TODO for ADS1115 
  return 1; }

size_t arduino::ZephyrI2C::write(const uint8_t *buffer, size_t size) {
  return size;
}

int arduino::ZephyrI2C::read() { return 0; }

int arduino::ZephyrI2C::available() { // TODO for ADS1115 
  return 1; 
  }

int arduino::ZephyrI2C::peek() { return 1; }

void arduino::ZephyrI2C::flush() {}

void arduino::ZephyrI2C::onReceive(voidFuncPtrParamInt cb) {}
void arduino::ZephyrI2C::onRequest(voidFuncPtr cb) {}

arduino::ZephyrI2C Wire;