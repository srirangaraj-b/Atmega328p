.global toggle_led   ; Function visible to C

.equ PORTB, 0x05
.equ LED, 5

toggle_led:
    in r16, PORTB      ; Read current PORTB
    ldi r17, (1<<LED)
    eor r16, r17       ; Toggle the LED bit
    out PORTB, r16
    ret
