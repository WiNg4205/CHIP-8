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

        // Commands in the format 8XY? where '?' is a digit
        } else if (get_hex_digit(instr, 0) == 0x8) {
            uint8_t x = get_hex_digit(instr, 1);
            uint8_t y = get_hex_digit(instr, 2);

            // 8XY0: VX = VY
            if (get_hex_digit(instr, 3) == 0x0) {
                v[x] = v[y];

            // 8XY1: VX = VX | VY
            } else if (get_hex_digit(instr, 3) == 0x1) {
                v[x] = v[x] | v[y];

            // 8XY2: VX = VX & VY
            } else if (get_hex_digit(instr, 3) == 0x2) {
                v[x] = v[x] & v[y];

            // 8XY3: VX = VX ^ VY
            } else if (get_hex_digit(instr, 3) == 0x3) {
                v[x] = v[x] ^ v[y];

            // 8XY4: VX += VY
            } else if (get_hex_digit(instr, 3) == 0x4) {
                v[x] += v[y];

            // 8XY5: VX -= VY
            } else if (get_hex_digit(instr, 3) == 0x5) {
                v[x] -= v[y];

            // 8XY6: VX = VX >>= 1
            } else if (get_hex_digit(instr, 3) == 0x6) {
                v[x] >>= 1;
            
            // 8XY7: VX = VY - VX
            } else if (get_hex_digit(instr, 3) == 0x7) {
                v[x] = v[y] - v[x];
            
            // 8XYE: VX <<= 1
            } else if (get_hex_digit(instr, 3) == 0xE) {
                v[x] <<= 1;
            }
        }
        PC += 2;
    }

    printf("%d %d %d %d", v[0], v[1], v[2], v[3]); // expected output: 255 0 255 180
 
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
