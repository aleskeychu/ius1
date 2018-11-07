#include "aduc812.h"
#include "max.h"

static unsigned char old_led = 0;

void leds( unsigned char on ) {
    write_max( SV, on );     
    old_led = on;
}