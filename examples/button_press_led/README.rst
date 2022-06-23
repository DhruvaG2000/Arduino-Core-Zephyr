Button Press LED
######

Overview
********

This Arduino sample turns ON BUILTIN LED if button pressed using the `ArduinoAPI`.

Requirements
************

Your board must:

#. Have an LED connected via a GPIO pin (these are called "User LEDs" on many of
   Zephyr's :ref:`boards`).
#. Have the LED configured using the ``led0`` devicetree alias.
#. A button connected to pin D9

Building and Running
********************

Build and flash Blinky as follows,

```sh
$> west build  -p -b arduino_nano_33_ble samples/button_press_led -DZEPHYR_EXTRA_MODULES=/home/$USER/zephyrproject/modules/lib/Arduino-Core-Zephyr

$> west flash --bossac=/home/$USER/.arduino15/packages/arduino/tools/bossac/1.9.1-arduino2/bossac
```


Tips:

- See :dtcompatible:`gpio-leds` for more information on defining GPIO-based LEDs
  in devicetree.

- If you're not sure what to do, check the devicetrees for supported boards which
  use the same SoC as your target. See :ref:`get-devicetree-outputs` for details.

- See :zephyr_file:`include/zephyr/dt-bindings/gpio/gpio.h` for the flags you can use
  in devicetree.

- If the LED is built in to your board hardware, the alias should be defined in
  your :ref:`BOARD.dts file <devicetree-in-out-files>`. Otherwise, you can
  define one in a :ref:`devicetree overlay <set-devicetree-overlays>`.
