#ifndef FIRE_INT_H
#define FIRE_INT_H
//header that defines FireInt

#include "FireStreamDef.h"
#include "FireStreamCore.h"



static inline void
FireStream_int_push(FireStream* stream, long num)
{
        FireStream_write_u8(stream, FireType_Int);
        FireStream_write_i64(stream, num);
}

#endif
