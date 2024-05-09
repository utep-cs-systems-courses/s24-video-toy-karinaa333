#include <msp430.h>
#include "libTimer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "drawing.h"

short drawPos[2] = {screenWidth/2 + 1, screenHeight/2};
short controlPos[2] = {screenWidth/2, screenHeight/2};
short rowLimits[2] = {1, screenHeight};
short colLimits[2] = {1, screenWidth};

void update_draw() {
  for (char axis = 0; axis < 2; axis ++)
    if (drawPos[axis] != controlPos[axis]) /* position changed? */
      goto redraw;
  return;/* nothing to do */

 redraw:

  for (char axis = 0; axis < 2; axis++) {
    drawPos[axis] = controlPos[axis];
    drawBox(drawPos[0], drawPos[1], 10, COLOR_GREEN); /* draw */
  }
}

void drawBox(u_char acol, u_char arow, u_char size, u_int color) {
  u_char max_col = acol + size;
  u_char max_row = arow + size;
  for (u_char col = acol - size; col < max_col; col++) {
    for (u_char row = arow - size; row < max_row; row++) {
      drawPixel(col, row, color);
    }
  }
}
