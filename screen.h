#ifndef SCREEN_H
#define SCREEN_H
#include <stdint.h>

typedef struct screen_struct {
	uint32_t *data;
	uint32_t width;
	uint32_t height;
} *screen;

uint32_t rgb(uint8_t r, uint8_t g, uint8_t b);

uint32_t rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

screen make_screen(size_t width, size_t height);

void plot(screen s, uint32_t x, uint32_t y, uint32_t value);

#endif
