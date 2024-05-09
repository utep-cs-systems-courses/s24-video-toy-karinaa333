#include <msp430.h>
#include "libTimer.h"
#include "lcdutils.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "drawing.h"
#include "state_machines.h"

void main(void) {
  led_init();
  configureClocks();
  enableWDTInterrupts();
  switch_init();
  lcd_init();
  buzzer_init();

  or_sr(0x08);

  clearScreen(COLOR_BLUE);
  while(1) {
    if (redrawScreen) {
      redrawScreen = 0;
      update_draw();
    }
    P1OUT &= ~LEDS;
    or_sr(0x10);
    P1OUT |= LEDS;
  }
}
