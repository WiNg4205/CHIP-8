# CHIP-8 Instruction Checklist

## Flow / Control
- [ ] `00E0` – Clear the screen
- [ ] `00EE` – Return from subroutine
- [ ] `1NNN` – Jump to address `NNN`
- [ ] `2NNN` – Call subroutine at `NNN`
- [ ] `3XNN` – Skip next instruction if `VX == NN`
- [ ] `4XNN` – Skip next instruction if `VX != NN`
- [ ] `5XY0` – Skip if `VX == VY`
- [ ] `9XY0` – Skip if `VX != VY`

## Assignment / Math
- [x] `6XNN` – Set `VX = NN`
- [ ] `7XNN` – Add `NN` to `VX`
- [ ] `8XY0` – `VX = VY`
- [ ] `8XY1` – `VX = VX | VY`
- [ ] `8XY2` – `VX = VX & VY`
- [ ] `8XY3` – `VX = VX ^ VY`
- [ ] `8XY4` – `VX += VY`, VF = carry
- [ ] `8XY5` – `VX -= VY`, VF = NOT borrow
- [ ] `8XY6` – `VX >>= 1`, VF = least significant bit
- [ ] `8XY7` – `VX = VY - VX`, VF = NOT borrow
- [ ] `8XYE` – `VX <<= 1`, VF = most significant bit

## Memory / Index
- [ ] `ANNN` – Set index `I = NNN`
- [ ] `BNNN` – Jump to `NNN + V0`
- [ ] `CXNN` – `VX = random & NN`
- [ ] `FX29` – Set `I` to location of sprite for digit `VX`
- [ ] `FX33` – Store BCD of `VX` in memory at `I`
- [ ] `FX55` – Store `V0`–`VX` in memory starting at `I`
- [ ] `FX65` – Read `V0`–`VX` from memory starting at `I`

## Input / Timers
- [ ] `EX9E` – Skip if key in `VX` is pressed
- [ ] `EXA1` – Skip if key in `VX` is not pressed
- [ ] `FX07` – Set `VX = delay timer`
- [ ] `FX0A` – Wait for keypress, store in `VX`
- [ ] `FX15` – Set delay timer = `VX`
- [ ] `FX18` – Set sound timer = `VX`

## Display
- [ ] `DXYN` – Draw sprite at (`VX`, `VY`) with height `N`