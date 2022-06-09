#include "Wire.h"

void arduino::ZephyrI2C::begin() {
	const struct device *dev = DEVICE_DT_GET_ANY(adi_adxl372);
}