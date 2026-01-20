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

# Build and Upload Commands – Explanation

This document explains the **commands used to compile, convert, and upload** the ATmega328P LED blinking program, and what each command does internally.

---

## 1. Compiling C Code (ELF File Generation)

### Command

```
avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -Os -o blink.elf main.c
```

### Explanation

* **avr-gcc**: AVR version of the GNU C compiler.
* **-mmcu=atmega328p**: Specifies the target microcontroller so the compiler uses the correct registers and instruction set.
* **-DF_CPU=16000000UL**: Defines the CPU clock frequency (16 MHz) for delay calculations and timing-related code.
* **-Os**: Optimizes the code for **small size**, which is important for microcontrollers with limited flash memory.
* **-o blink.elf**: Names the output file as `blink.elf`.
* **main.c**: The C source file containing the LED blinking logic.

The output **ELF file** contains machine code, symbol tables, and debugging information.

---

## 2. Converting ELF to HEX File

### Command

```
avr-objcopy -O ihex blink.elf blink.hex
```

### Explanation

* **avr-objcopy**: Utility used to convert object file formats.
* **-O ihex**: Specifies the Intel HEX output format.
* **blink.elf**: Input ELF file.
* **blink.hex**: Output HEX file.

The **HEX file** is the final firmware format that can be flashed into the ATmega328P’s program memory.

---

## 3. Uploading the Program to ATmega328P

### Command

```
avrdude -D -p atmega328p -c arduino -P COM13 -b 115200 -U flash:w:blink.hex
```

### Explanation

* **avrdude**: Tool used to program AVR microcontrollers.
* **-D**: Disables chip erase (faster upload).
* **-p atmega328p**: Specifies the target microcontroller.
* **-c arduino**: Uses the Arduino bootloader protocol.
* **-P COM13**: Serial port connected to the Arduino Uno (Windows).
* **-b 115200**: Baud rate used by the bootloader.
* **-U flash:w:blink.hex**: Writes the HEX file into the flash memory.

After this step, the program starts executing and the **built-in LED on PB5 begins blinking**.

---

## 4. Automated Build Using Make

### Command

```
make
```

### Explanation

* Automatically compiles the source file.
* Generates the ELF and HEX files without typing individual commands.

---

## 5. Uploading Using Make

### Command

```
make upload
```

### Explanation

* Uploads the generated HEX file to the ATmega328P using `avrdude`.
* Requires the board to be connected via USB.

---

## 6. Cleaning Build Files

### Command

```
make clean
```

### Explanation

* Deletes generated `.elf` and `.hex` files.
* Keeps the project directory clean.

---

## 7. One-Step Build, Upload, and Clean

### Command

```
make build
```

### Explanation

* Compiles the program
* Uploads it to the microcontroller
* Cleans temporary files

This provides a **single-command workflow** for development.

---

## Summary

These commands demonstrate a **low-level, professional AVR development workflow** using:

* Direct register-level programming
* Command-line toolchains
* Automated builds via Makefile

This approach avoids the Arduino IDE and gives full control over the ATmega328P hardware.


## Notes

* Delay in the programs is software-based (using loops) and may vary slightly depending on compiler optimizations.
* This project is intended to demonstrate different programming methods for ATmega328P and low-level register control.

## License

This project is open-source and free to use for learning and experimentation.
