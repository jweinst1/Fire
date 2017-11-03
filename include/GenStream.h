#ifndef FIRE_GENSTREAM_H
#define FIRE_GENSTREAM_H
//generating file for stream instructions/segments, e.g [1 to 5]

#include <stdlib.h>
#include "ByteBuffer.h"

#define GenStreamCheck_DONE(gsc) (gsc.foundOp && gsc.foundVal)


struct GenStreamCheck
{
        int foundOp;
        int foundVal;
};

typedef struct GenStreamCheck GenStreamCheck;

void GenStream_gen(char** srcCode, ByteBuffer* bbuf);

#endif
