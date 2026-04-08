#include <stdint.h>
#ifndef HELPER_H
#define HELPER_H

void set(uint16_t* v, uint8_t n, uint8_t x);
void add(uint16_t* v, uint8_t n, uint8_t x);
void setXY(uint16_t* v, uint8_t x, uint8_t y);
uint8_t get_hex_digit(uint16_t val, int index);

#endif
