#include <stdint.h>

#define F_CPU 16000000UL

#define CYCLES_PER_LOOP 10UL

#define DELAY_COUNT (F_CPU / 1000UL / CYCLES_PER_LOOP)

#define DDRB (*(volatile uint8_t*)0x24)

#define LED 5

static inline void delay_ms(uint16_t ms); //static means it only visible in this program only
                                          //inline means suggest the complier to insert the function directly where it calls to stop delays


extern void toggle_led(void); // Declare the assembly function

int main(void) {
    DDRB |= (1 << LED);  // Set PB5 as output

    while (1) {
        toggle_led();        // Call the assembly function
        delay_ms(1000);
    }

}

static inline void delay_ms(uint16_t ms){
    for(uint16_t i = 0; i<ms; i++){
        for(uint16_t j=0; j<DELAY_COUNT; ++j){
            __asm__ __volatile__("nop");
        }
    }
}
