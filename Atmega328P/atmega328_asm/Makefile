MCU = atmega328p
BAUD = 115200
PORT = COM13
SRC = main.asm
TARGET = blink
VER = avr5
ADDR = 0x000

ASM = avr-as
LD = avr-ld
OBJ = avr-objcopy
AVRDUDE = avrdude

all: $(TARGET).hex

$(TARGET).o: $(SRC)
	$(ASM) -mmcu=$(MCU) -o $@ $<

$(TARGET).elf: $(TARGET).o
	$(LD) -m $(VER) -Ttext=$(ADDR) $< -o $@

$(TARGET).hex: $(TARGET).elf
	$(OBJ) -O ihex $< $@


upload: $(TARGET).hex
	$(AVRDUDE) -D -p $(MCU) -c arduino -P $(PORT) -b $(BAUD) -U flash:w:$<

clean:
	del $(TARGET).elf $(TARGET).hex $(TARGET).o
	

build:
	make
	make upload 
	make clean
	cls

#avr-as -mmcu=atmega328p -o blink.o main.asm  

#avr-ld -m avr5 -Ttext=0x0000 -o blink.elf blink.o

#avr-objcopy -O ihex blink.elf blink.hex    

#avrdude -D -p atmega328p -c arduino -P COM13 -b 115200 -U flash:w:blink.hex

