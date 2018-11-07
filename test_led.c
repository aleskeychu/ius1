#include "aduc812.h"
#include "led.h"
#include "max.h"


void delay ( unsigned long ms ) {
    volatile unsigned long i, j;
    for( j = 0; j < ms; j++ ) {
        for( i = 0; i < 50; i++ );
    }   
}


unsigned char left_circular_shift(unsigned char x, int n) {
  return (x << n) | (x >> (8 - n));
}

unsigned char invert(unsigned char c) {
  return 255-c;
}

unsigned char read_dip() {
    return invert( read_max(EXT_LO));
}

void main( void ) {
    const unsigned char leds_init = 0x3;
    unsigned char leds_var = 0;
    unsigned char dip = 0;
    while( 1 ) {
        delay(100);
        dip = read_dip();
        if (dip == 0xAA) {
            leds_var = left_circular_shift(leds_var, 1);
        } else {
            leds_var = invert(dip);
        }
        leds(leds_var);
    }
}    
