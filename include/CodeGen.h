#ifndef FIRE_CODE_GEN_H
#define FIRE_CODE_GEN_H
//This header contains tools to generate bytecode directly from source code

#include <ctype.h>
#include "ByteBuffer.h"

#define CodeGen_ADV_WS(chPtr) while(isspace(*chPtr++))

#define CodeGen_IS_AR(chPtr) (chPtr[0] == '-' && chPtr[1] == '>')

#endif
