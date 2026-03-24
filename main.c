#include <stdio.h>
#include <stdint.h>
#include "helper.h"


int main(void) {
    uint8_t memory[4096];
    uint8_t display[16][32];
    uint16_t v[16] = {0};
    uint16_t I;
    uint16_t PC;

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 32; j++) {
            display[i][j] = 0;
        }
    }    
    PC = 0x200;
    I = 0x200;

    FILE *f = fopen("instructions.txt", "r");

    char buf[256];

    while (fgets(buf, sizeof(buf), f)) {
        if (buf[0] == '6') {
            uint8_t x = (hexchar_to_uint8(buf[2]) << 4)
                | hexchar_to_uint8(buf[3]);
            uint8_t n = buf[1] - '0';
            set(v, n, x);
        }
        printf("%s", buf);
    }

    printf("%d %d %d %d", v[0], v[1], v[2], v[3]);
 
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 32; j++) {
            if (display[i][j] == 1) {
                printf("\u2588\u2588");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}
