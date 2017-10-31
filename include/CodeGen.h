#ifndef FIRE_CODE_GEN_H
#define FIRE_CODE_GEN_H
//This header contains tools to generate bytecode directly from source code

#include <ctype.h>
#include "ByteBuffer.h"

#define CodeGen_ADV_WS(chPtr) while(isspace(*chPtr++))

//arrow
#define CodeGen_IS_AR(chPtr) (chPtr[0] == '-' && chPtr[1] == '>')

//number start
#define CodeGen_IS_NS(chPtr) (isdigit(*chPtr) || *chPtr == '-')

//increments char* until arrow is found
#define CodeGen_PRS_AR(chPtr) while(!CodeGen_IS_AR(chPtr)) chPtr++;

enum GenState
{
        GenState_Start,
        GenState_AccNum,
        GenState_AccArr
};

typedef enum GenState GenState;

//large overhead function to generate bytecode
void CodeGen_Generate(char* srcCode, ByteBuffer* buffer);

#endif
