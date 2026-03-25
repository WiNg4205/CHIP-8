#include <ctype.h>
#include "helper.h"
#include <stdio.h>

void set(uint16_t* v, uint8_t n, uint8_t x) {
    v[n] = x;
}

void add(uint16_t* v, uint8_t n, uint8_t x) {
    v[n] += x;
}

void setXY(uint16_t* v, uint8_t x, uint8_t y) {
    v[x] = v[y];
}

uint8_t hexchar_to_uint8(char c) {
  if (isdigit(c)) return c - '0';
  return toupper(c) - 'A' + 10;
}

