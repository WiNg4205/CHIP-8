#include <ctype.h>
#include "helper.h"
#include <stdio.h>


// e.g. for hexadecimal 0xABCD (A is index 0, B is index 1 and so on..)
uint8_t get_hex_digit(uint16_t val, int index) {
  if (index < 0 || index > 3) {
    printf("value is out of range");
    return 0;
  }
  // formula to isolate the value (each hexdigit is 4 bits)
  return (val >> (12 - index * 4)) & 0xF;
}