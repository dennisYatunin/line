#include "screen.h"
#include <stdint.h>
#include <stdlib.h>

void* xmalloc(uint32_t size) {
	void* pointer = malloc(size);
	if (pointer == NULL) {
		perror("memory allocation");
		exit(EXIT_FAILURE);
	}
	return pointer;
}

void* xcalloc(uint32_t size) {
	void* pointer = calloc(size, 1);
	if (pointer == NULL) {
		perror("memory allocation");
		exit(EXIT_FAILURE);
	}
	return pointer;
}

/* ========================================================================== */

uint32_t rgb(uint8_t r, uint8_t g, uint8_t b) {
	return r << 16 | g << 8 | b;
}

uint32_t rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
	return r << 24 | g << 16 | b << 8 | a;
}

screen make_screen(uint32_t width, uint32_t height) {
	screen s = (screen) xmalloc(3 * sizeof(uint32_t));
	s->width = width;
	s->height = height;
	s->data = (uint32_t *) xcalloc(width * height * sizeof(uint32_t));
	return s;
}

void plot(screen s, uint32_t x, uint32_t y, uint32_t value) {
	s->data[y * s->width + x] = value;
}
