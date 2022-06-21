#include "ArduinoAPI.h"
#include "HardwareSerial.h"

#ifdef __cplusplus

namespace arduino {

class UART : public HardwareSerial {
	public:
		UART(int tx, int rx, int rts = -1, int cts = -1);
		UART(PinName tx, PinName rx, PinName rts = NC, PinName cts = NC) : _tx(tx), _rx(rx), _rts(rts), _cts(cts) {}
		UART() {
			is_usb = true;
		}
		void begin(unsigned long);
		void begin(unsigned long baudrate, uint16_t config);
		void end();
		int available(void);
		int peek(void);
		int read(void);
		void flush(void);
		size_t write(uint8_t c);
		size_t write(const uint8_t*, size_t);
		using Print::write; // pull in write(str) and write(buf, size) from Print
		operator bool();
		operator mbed::FileHandle*();	// exposes the internal mbed object

#if defined(SERIAL_CDC)
		uint32_t baud();
		uint8_t stopbits();
		uint8_t paritytype();
		uint8_t numbits();
		bool dtr();
		bool rts();
#endif

	private:
		void on_rx();
		void block_tx(int);
		bool _block;
		// See https://github.com/ARMmbed/mbed-os/blob/f5b5989fc81c36233dbefffa1d023d1942468d42/targets/TARGET_NORDIC/TARGET_NRF5x/TARGET_NRF52/serial_api.c#L76
		const size_t WRITE_BUFF_SZ = 32;
		mbed_serial* _serial = NULL;
		mbed_usb_serial* _usb_serial = NULL;
		PinName _tx, _rx, _rts, _cts;
		RingBufferN<256> rx_buffer;
		uint8_t intermediate_buf[4];
		bool is_usb = false;
};
}

extern arduino::UART _UART1_;

#endif