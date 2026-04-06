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
