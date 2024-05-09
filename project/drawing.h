#ifndef drawing_included
#define drawing_included

void update_draw();
void drawBox(u_char acol, u_char arow, u_char size, u_int color);

extern short drawPos[2], controlPos[2], rowLimits[2], colLimits[2];

#endif // included
