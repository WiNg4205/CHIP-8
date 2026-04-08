#include <ctype.h>
#include "helper.h"
#include <stdio.h>

void set(uint16_t* v, uint8_t n, uint8_t x) {
    v[x] = n;
}

void add(uint16_t* v, uint8_t n, uint8_t x) {
    v[x] += n;
}

void setXY(uint16_t* v, uint8_t x, uint8_t y) {
    v[x] = v[y];
}

// e.g. for hexadecimal 0xABCD (A is index 0, B is index 1 and so on..)
uint8_t get_hex_digit(uint16_t val, int index) {
  if (index < 0 || index > 3) {
    printf("value is out of range");
    return 0;
  }
  // formula to isolate the value (each hexdigit is 4 bits)
  return (val >> (12 - index * 4)) & 0xF;
}