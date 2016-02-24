#include <math.h>

#include "draw.h"
#include "png.h"

#define WIDTH 10000
#define NUM_POINTS 10000
#define TWO_PI 6.28318531

// Points will look something like this:
//       9  8  7
//    10         6
//   11           5
//   12           4
//   13           3
//    14         2
//      15  0  1

int main() {
	screen s = make_screen(WIDTH, WIDTH);
	int points[NUM_POINTS + 1][2];
	int i, j;
	for (i = 0; i <= NUM_POINTS; i++) {
		points[i][0] =
		WIDTH / 2 +
		(int) ((WIDTH / 2 - 1) * sin(TWO_PI * i / NUM_POINTS));
		points[i][1] =
		WIDTH / 2 +
		(int) ((WIDTH / 2 - 1) * cos(TWO_PI * i / NUM_POINTS));
	}
	for (
		i = NUM_POINTS / 4, j = NUM_POINTS / 2;
		i < NUM_POINTS / 2; i++, j += 2
		) {
		draw_line(
			s, points[i][0], points[i][1], points[j][0], points[j][1],
			rgb((unsigned char) i, 255, 255)
			);
	}
	for (j = 0; i < 3 * NUM_POINTS / 4; i++, j += 2) {
		draw_line(
			s, points[i][0], points[i][1], points[j][0], points[j][1],
			rgb((unsigned char) i, 255, 255)
			);
	}
	for (; i <= NUM_POINTS; i++, j++) {
		draw_line(
			s, points[i][0], points[i][1], points[j][0], points[j][1],
			rgb(255, (unsigned char) i, 255)
			);
	}
	for (i = NUM_POINTS / 4 - 1, j = NUM_POINTS / 2 - 1; i >= 0; i--, j--) {
		draw_line(
			s, points[i][0], points[i][1], points[j][0], points[j][1],
			rgb(255, (unsigned char) i, 255)
			);
	}
	make_png("heart.png", s, PNG_RGB);
}

