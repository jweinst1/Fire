#ifndef FIRE_CODE_GEN_H
#define FIRE_CODE_GEN_H
//This header contains tools to generate bytecode directly from source code

#include <stdlib.h>
#include <ctype.h>
#include "ByteBuffer.h"

enum GenState
{
        GenState_AccProc,
        GenState_AccVal
};

typedef enum GenState GenState;

#define CodeGen_ADV_WS(chPtr) while(isspace(*chPtr)) chPtr++

#define CodeGen_ADV_SPC(chPtr) while(*chPtr++ == ' ')

//advance until newline
#define CodeGen_ADVU_NL(chPtr) while(*chPtr != '\n') chPtr++;

//arrow
#define CodeGen_IS_AR(chPtr) (chPtr[0] == '-' && chPtr[1] == '>')

//number start
#define CodeGen_IS_NS(chPtr) (isdigit(*chPtr) || *chPtr == '-')

//increments char* until arrow is found
#define CodeGen_ADV_AR(chPtr) while(!CodeGen_IS_AR(chPtr)) chPtr++

#define CodeGen_ADV_NS(chPtr) while(!CodeGen_IS_NS(chPtr)) chPtr++

//parse out stream start, move ptr to first char after '['
#define CodeGen_ADV_SS(chPtr) while(isspace(*chPtr) || *chPtr != '[') chPtr++





//point to delegate gen to seperate generators
void CodeGen_GetStart(char* srcCode, ByteBuffer* buffer);

//large overhead function to generate bytecode
void CodeGen_Generate(char* srcCode, ByteBuffer* buffer);

#endif
