# Bare Metal AVR tutorial
This is a set of examples of bare metal code for AVR based micro controllers, these are used by arduinos and several other embeded development boards

## Building instructions
To build you must have an avr tool chain as well as the avr library installed

To build examples for arduino nano the following recipe can be used

```
$ avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o led.o led.c
$ avr-gcc -mmcu=atmega328p led.o -o led
$ avr-objcopy -O ihex -R .eeprom led led.hex
$ avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 57600 -U flash:w:led.hex
```
