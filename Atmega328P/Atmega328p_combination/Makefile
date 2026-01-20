MCU = atmega328p
BAUD = 115200
PORT = COM13

C_SRC = main.c
ASM_SRC = blink.S
TARGET = blink
VER = avr5
ADDR = 0x0000

CC = avr-gcc
ASM = avr-as
LD = avr-ld
OBJCPY = avr-objcopy
AVRDUDE = avrdude


OBJ = main.o blink.o


all: $(TARGET).hex


main.o: $(C_SRC)
	$(CC) -mmcu=$(MCU) -c $< -o $@


blink.o: $(ASM_SRC)
	$(ASM) -mmcu=$(MCU) -o $@ $<


$(TARGET).elf: $(OBJ)
	$(CC) -mmcu=$(MCU) -o $@ $(OBJ)


$(TARGET).hex: $(TARGET).elf
	$(OBJCPY) -O ihex $< $@


upload: $(TARGET).hex
	$(AVRDUDE) -D -p $(MCU) -c arduino -P $(PORT) -b $(BAUD) -U flash:w:$<


clean:
	del $(TARGET).elf $(TARGET).hex $(OBJ)


build:
	make all
	make upload
	make clean
	cls
