#include <stdlib.h>

#include "draw.h"

void draw_line(screen s, int x0, int y0, int x1, int y1, int value) {
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);

	int x_step = x0 < x1 ? 1 : -1;
	int y_step = y0 < y1 ? 1 : -1;

	int error = (dx > dy ? dx : -dy) / 2;
	int original_error;

	while (1) {
		plot(s, x0, y0, value);
		if (x0 == x1 && y0 == y1) {
			return;
		}
		original_error = error;
		if (original_error > -dx) {
			error -= dy;
			x0 += x_step;
		}
		if (original_error < dy) {
			error += dx;
			y0 += y_step;
		}
	}
}
