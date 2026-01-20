MCU = atmega328p
F_CPU = 16000000UL
BAUD = 115200
PORT = COM13
SRC = main.c
TARGET = blink

CC = avr-gcc
OBJ = avr-objcopy
AVRDUDE = avrdude

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os 

all: $(TARGET).hex

$(TARGET).elf: $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

$(TARGET).hex: $(TARGET).elf
	$(OBJ) -O ihex $< $@

upload: $(TARGET).hex
	$(AVRDUDE) -D -p $(MCU) -c arduino -P $(PORT) -b $(BAUD) -U flash:w:$<

clean:
	del $(TARGET).elf $(TARGET).hex

build:
	make
	make upload 
	make clean
	cls

#avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -Os -o blink.elf main.c
#avr-objcopy -O ihex blink.elf blink.hex
#avrdude -D -p atmega328p -c arduino -P COM13 -b 115200 -U flash:w:blink.hex
