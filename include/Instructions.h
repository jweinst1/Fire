#ifndef FIRE_INSTRUCTIONS_H
#define FIRE_INSTRUCTIONS_H
// this header contains instruction codes that are named

enum Instruction
{
        Instruction_Null,
        Instruction_Print,
        Instruction_Reduce_Add,
        Instruction_Reduce_Sub,
        Instruction_Reduce_Mul,
        Instruction_Reduce_Div
};

typedef enum Instruction Instruction;
#endif
