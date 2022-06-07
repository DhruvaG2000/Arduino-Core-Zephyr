#include "ArduinoAPI.h"

int main(void)
{
	// init();
	// initVariant();

#if defined(SERIAL_CDC)
  PluggableUSBD().begin();
  _SerialUSB.begin(115200);
#endif

	setup();

	for (;;) {
		loop();
		// if (arduino::serialEventRun) arduino::serialEventRun();
	}

	return 0;
}