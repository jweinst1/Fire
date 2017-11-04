#ifndef FIRE_GENREDUCE_H
#define FIRE_GENREDUCE_H
//header that generates reduction byte code instructions

#include "ByteBuffer.h"
#include "Instructions.h"

int GenReduce_gen(char** srcCode, ByteBuffer* bbuf);

#endif
