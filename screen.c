#include <stdlib.h>

#include "screen.h"

uint32_t rgb(uint8_t r, uint8_t g, uint8_t b) {
	return r << 16 | g << 8 | b;
}

uint32_t rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
	return r << 24 | g << 16 | b << 8 | a;
}

screen make_screen(size_t width, size_t height) {
	screen s = (screen) malloc(3 * sizeof(uint32_t));
	if (s == NULL) {
		perror("memory allocation");
		exit(EXIT_FAILURE);
	}
	s->width = (uint32_t) width;
	s->height = (uint32_t) height;
	s->data = (uint32_t *) calloc(width, height * sizeof(uint32_t));
	if (s == NULL) {
		perror("memory allocation");
		exit(EXIT_FAILURE);
	}
	return s;
}

void plot(screen s, uint32_t x, uint32_t y, uint32_t value) {
	s->data[(uint64_t)y * s->width + x] = value;
}
