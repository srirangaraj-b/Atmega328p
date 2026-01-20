# ATmega328P LED Blinking Project

This project demonstrates blinking the **built-in LED** of an Arduino Uno (connected to **PB5**) using three different approaches: **C**, **Assembly (ASM)**, and a **combination of C and Assembly**.

## Overview

The Arduino Uno’s built-in LED is connected to **Port B, Pin 5 (PB5)**. The programs in this repository toggle the LED on and off at a regular interval, showing different ways of programming the ATmega328P microcontroller.

The project includes:

1. **C Program**: Blinks the LED using pure C with direct register manipulation.
2. **Assembly Program**: Blinks the LED using AVR assembly instructions.
3. **Mixed C + Assembly Program**: Uses a combination of C and inline assembly for LED control.

## Prerequisites

To compile and upload the programs to the ATmega328P, you need the following tools installed:

* **AVR-GCC**: The GNU Compiler Collection for AVR microcontrollers.
  [Installation guide](https://www.microchip.com/en-us/tools-resources/develop/microchip-studio)

* **AVR-AS / ASM**: The AVR assembler to compile assembly code. Usually included with AVR-GCC.

* **AVRDUDE**: For uploading the compiled program (.hex) to the Arduino Uno.
  [Installation guide](https://www.nongnu.org/avrdude/)

* **Arduino Uno or any ATmega328P-based board**

## Usage

1. **Connect your Arduino Uno** to your computer via USB.
2. Open a terminal in the project directory.
3. Compile the program:

### For C program:

```bash
avr-gcc -mmcu=atmega328p -Os -o blink_c.elf blink.c
avr-objcopy -O ihex blink_c.elf blink_c.hex
```

### For Assembly program:

```bash
avr-as -mmcu=atmega328p -o blink.o main.asm
```

### For C + Assembly program:

```bash
avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -Os -o blink.elf main.c
avr-objcopy -O ihex blink.elf blink.hex
```

4. Upload the compiled program to the Arduino Uno:

```bash
avrdude -D -p atmega328p -c arduino -P COM13 -b 115200 -U flash:w:blink.hex
```

> Replace `COM13` with your board’s serial port and `.hex` file with the respective program.

5. Observe the **built-in LED blinking** on PB5.

## Notes

* Delay in the programs is software-based (using loops) and may vary slightly depending on compiler optimizations.
* This project is intended to demonstrate different programming methods for ATmega328P and low-level register control.

## License

This project is open-source and free to use for learning and experimentation.
