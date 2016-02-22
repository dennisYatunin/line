#include "screen.h"
#include "png.h"

int main() {
	screen s = make_screen(100, 100);
	plot(s, 0, 0, rgb(0, 255, 0));
	plot(s, 0, 1, rgb(255, 255, 255));
	plot(s, 1, 0, rgb(255, 255, 255));
	plot(s, 1, 1, rgb(255, 255, 255));
	plot(s, 5, 5, rgb(255, 255, 255));
	plot(s, 9, 9, rgb(255, 255, 255));
	plot(s, 99, 99, rgb(255, 255, 0));
	//plot(s, 499, 499, rgb(255, 0, 0));
	make_png("test.png", s, PNG_RGB);
}

