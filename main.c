#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
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
    PC = 0x200; // 512 bytes to store other data
    I = 0x200;

    FILE *f = fopen("instructions.txt", "r");

    char buf[256];

    uint8_t instruction_no = 0x000;
    while (fgets(buf, sizeof(buf), f)) {
        uint16_t instr = (uint16_t) strtoul(buf, NULL, 16); // parse hex from file
        memory[PC+instruction_no] = (instr >> 8) & 0xFF; // high byte
        memory[PC+instruction_no+1] = instr & 0xFF; // low byte
        instruction_no += 2;
    }

    uint16_t instr;
    while ((instr = (memory[PC] << 8) | memory[PC + 1]) != 0x00) { // if instruction is not empty
        printf("Instruction: 0x%04X\n", instr);
        // 6XNN: Set VX = NN
        if (get_hex_digit(instr, 0) == 0x6) {
            uint8_t n = instr & 0xFF;
            uint8_t x = get_hex_digit(instr, 1);
            v[x] = n;

        // 7XNN: Add NN to VX
        } else if (get_hex_digit(instr, 0) == 0x7) {
            uint8_t n = instr & 0xFF;
            uint8_t x = get_hex_digit(instr, 1);
            v[x] += n;

        // 8XY0: VX = VY
        } else if (get_hex_digit(instr, 0) == 0x8 && get_hex_digit(instr, 3) == 0) {
            uint8_t x = get_hex_digit(instr, 1);
            uint8_t y = get_hex_digit(instr, 2);
            v[x] = v[y];
        }
        PC += 2;
    }

    printf("%d %d %d %d", v[0], v[1], v[2], v[3]); // expected output: 0 0 180 180
 
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
