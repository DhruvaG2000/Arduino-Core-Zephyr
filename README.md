# Arduino-Core-Zephyr

Arduino Core API module for zephyr

## Setup

1. Clone this repo in ``zephyrproject/modules/lib``
2. Copy the desired examples in ``zephyre/samples``.
3. For example, to build an ``arduino-blinky`` example use the command ``west build  -p -b arduino_nano_33_ble samples/basic/arduino-blinky -DZEPHYR_EXTRA_MODULES=/home/$USER/zephyrproject/modules/lib/Arduino-Core-Zephyr``
4. To flash the built firmware to the arduino nano ble sense 33, ``west flash --bossac=/home/$USER/.arduino15/packages/arduino/tools/bossac/1.9.1-arduino2/bossac``. The path to bossac may vary according to your arduino IDE install location. You may choose to manually install and specify bossac as well.
