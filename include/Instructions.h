#ifndef FIRE_INSTRUCTIONS_H
#define FIRE_INSTRUCTIONS_H
// this header contains instruction codes that are named

// WARNING max instruction is 255
enum Instruction
{
        Instruction_Null,
        Instruction_Print,
        Instruction_Reduce_Add,
        Instruction_Reduce_Sub,
        Instruction_Reduce_Mul,
        Instruction_Reduce_Div,
        Instruction_Push_Number,
        Instruction_Push_ZRange,
        Instruction_Map_Add,
        Instruction_Map_Sub,
        Instruction_Map_Mul,
        Instruction_Map_Div,
        Instruction_Map_Rem,
        Instruction_Map_Floor,
        Instruction_Map_Sin,
        Instruction_Map_Cos,
        Instruction_Map_Log,
        Instruction_Map_Exp,
        Instruction_Filt_Eq,
        Instruction_Filt_Neq,
        Instruction_Filt_Lt,
        Instruction_Filt_Gt,
        Instruction_Set_Zrange

};

typedef enum Instruction Instruction;
#endif
