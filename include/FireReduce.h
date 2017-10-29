#ifndef FIRE_REDUCE_H
#define FIRE_REDUCE_H
//header that defines reducing macros

#include "FireTypes.h"

#define FireReduce_ADD(stream) do { \
                void* reader = stream->items; \
                void* reductant = stream->items; \
                if(*(unsigned char*)reductant == FireStream_TYPE_NUM) { \
    \
                } \
} while(0)

#endif
