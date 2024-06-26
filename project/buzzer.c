#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

const short int song_a[4] = {500, 1000, 1500, 2000};

void buzzer_init() {
  /*
    Direct timer A output "TA0.1" to P2.6.
    According to table 21 from data sheet:
      P2SEL2.6, P2SEL2.7, and P2SEL.7 must be zero
      P2SEL.6 must be 1
    Also: P2.6 direction must be output
  */
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
  buzzer_set_period(song_a[0]);
}

void buzzer_set_period(short cycles) {
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}
