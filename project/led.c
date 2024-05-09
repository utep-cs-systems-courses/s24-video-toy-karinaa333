#include <msp430.h>
#include "led.h"
#include "switches.h"

unsigned char red_on = 0;
unsigned char green_on = 0;

void led_init() {
  P1DIR |= LEDS ;
  led_update();
}

void led_update() {
  char ledFlags = 0;
  if (red_on) {
    ledFlags |= LED_RED;
  }
  
  if (green_on) {
    ledFlags |= LED_GREEN;
  }
  
  P1OUT &= ~(LEDS);  // clear bits
  P1OUT |= ledFlags;     
}
