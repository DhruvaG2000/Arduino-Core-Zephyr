#pragma once

#include "ArduinoAPI.h"
#include "HardwareI2C.h"
#include "Print.h"
#include <zephyr/drivers/i2c.h>
#include <zephyr/device.h>

typedef void (*voidFuncPtrParamInt)(int);

namespace arduino {

class ZephyrI2C : public HardwareI2C {
public:
  virtual void begin();
  virtual void end();
  virtual void begin(uint8_t address);
  virtual void setClock(uint32_t freq);

  virtual void beginTransmission(uint8_t address);
  virtual uint8_t endTransmission(bool stopBit);
  virtual uint8_t endTransmission(void);

  virtual size_t requestFrom(uint8_t address, size_t len, bool stopBit);
  virtual size_t requestFrom(uint8_t address, size_t len);

  virtual void onReceive(void (*)(int));
  virtual void onRequest(void (*)(void));

  virtual size_t write(uint8_t data);
  virtual size_t write(int data) { return write((uint8_t)data); };
  virtual size_t write(const uint8_t *buffer, size_t size);
  using Print::write;
  virtual int read();
  virtual int peek();
  virtual void flush();
  virtual int available();
};

} // namespace arduino

extern arduino::ZephyrI2C Wire;

typedef arduino::ZephyrI2C TwoWire;