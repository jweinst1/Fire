#ifndef FIRE_INSTRUCTIONS_H
#define FIRE_INSTRUCTIONS_H
// this header contains instruction codes that are named

// WARNING max instruction is 255
enum Instruction
{
        Instruction_Null,
        Instruction_Print,
        Instruction_Put
};

typedef enum Instruction Instruction;
#endif
