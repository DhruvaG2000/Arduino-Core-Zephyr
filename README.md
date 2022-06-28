# Arduino-Core-Zephyr

Arduino Core API module for zephyr leverages the power of Zephyr under an Arduino-C++ style abtraction layer thus helping zephyr new-comers to start using it without worrying about learning about new APIs and libraries. Visit this project's [official blog](https://dhruvag2000.github.io/Blog-GSoC22/) for documentation.

## Pre-Requisites

- Clone ArduinoCore-API into a directory of your choice using
```sh
git clone git@github.com:arduino/ArduinoCore-API
```
- Currently ``WCharacter.h`` is causing errors while building and needs to be deleted from `ArduinoAPI.h` (it is unused in this port.) We are looking into resolving the issue.

## Setup

- Navigate to zephyr root and edit the `west.yml` file and add the following under `projects`:
```
      # Arduino API repository.
    - name: Arduino-Core-Zephyr
      path: modules/lib/Arduino-Zephyr-API
      revision: main
      url: https://github.com/DhruvaG2000/Arduino-Core-Zephyr
```
- run `west update` to pull this repo to your local machine.
- Create a symlink to ``ArduinoCore-API/api`` in this repo's ``core/arduino`` folder using the command ``ln -s /home/$USER/Projects/ArduinoCore-API/api cores/arduino/.``
- Copy the desired examples in ``zephyr/samples``.
- To pristine build an ``arduino-blinky`` example use the command ``west build  -p -b arduino_nano_33_ble samples/arduino-blinky``.

**Outdated instructions:**
1. Clone this repo in ``zephyrproject/modules/lib``
2. Create a symlink to ``ArduinoCore-API/api`` in this repo's ``core/arduino`` folder using the command ``ln -s /home/dhruva/Projects/ArduinoCore-API/api cores/arduino/.``
3. Copy the desired examples in ``zephyre/samples``.
4. For example, to build an ``arduino-blinky`` example use the command ``west build  -p -b arduino_nano_33_ble samples/basic/arduino-blinky -DZEPHYR_EXTRA_MODULES=/home/$USER/zephyrproject/modules/lib/Arduino-Core-Zephyr``
5. To flash the built firmware to the arduino nano ble sense 33, ``west flash --bossac=/home/$USER/.arduino15/packages/arduino/tools/bossac/1.9.1-arduino2/bossac``. The path to bossac may vary according to your arduino IDE install location. You may choose to manually install and specify bossac as well.
