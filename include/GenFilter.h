#ifndef FIRE_GENFILTER_H
#define FIRE_GENFILTER_H
//functions that handle code generation for filtering

#include <ctype.h>
#include "ByteBuffer.h"
#include "Instructions.h"


int GenFilter_gen(char** srcCode, ByteBuffer* buf);

#endif
