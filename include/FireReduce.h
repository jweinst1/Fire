#ifndef FIRE_REDUCE_H
#define FIRE_REDUCE_H
//header that defines reducing macros

#include "FireTypes.h"
#include "Utils.h"

#define FireReduce_ADD(stream) do { \
                void* reductionReader = stream->items; \
                void* reductant = stream->items; \
                if(*(unsigned char*)reductant == FireStream_TYPE_NUM) { \
                        reductionReader += sizeof(double) + 1; \
                        reductant++; \
                        while (stream->itemEnd != reductionReader) { \
                                if(*(unsigned char*)reductionReader == FireStream_TYPE_NUM) { \
                                        reductionReader++; \
                                        *(double*)reductant += *(double*)reductionReader; \
                                        reductionReader += sizeof(double); \
                                } \
                        } \
                        stream->itemEnd = reductant + sizeof(double); \
                } \
} while(0)

#define FireReduce_SUB(stream) do { \
                void* reductionReader = stream->items; \
                void* reductant = stream->items; \
                if(*(unsigned char*)reductant == FireStream_TYPE_NUM) { \
                        reductionReader += sizeof(double) + 1; \
                        reductant++; \
                        while (stream->itemEnd != reductionReader) { \
                                if(*(unsigned char*)reductionReader == FireStream_TYPE_NUM) { \
                                        reductionReader++; \
                                        *(double*)reductant -= *(double*)reductionReader; \
                                        reductionReader += sizeof(double); \
                                } \
                        } \
                        stream->itemEnd = reductant + sizeof(double); \
                } \
} while(0)

#define FireReduce_MUL(stream) do { \
                void* reductionReader = stream->items; \
                void* reductant = stream->items; \
                if(*(unsigned char*)reductant == FireStream_TYPE_NUM) { \
                        reductionReader += sizeof(double) + 1; \
                        reductant++; \
                        while (stream->itemEnd != reductionReader) { \
                                if(*(unsigned char*)reductionReader == FireStream_TYPE_NUM) { \
                                        reductionReader++; \
                                        *(double*)reductant *= *(double*)reductionReader; \
                                        reductionReader += sizeof(double); \
                                } \
                        } \
                        stream->itemEnd = reductant + sizeof(double); \
                } \
} while(0)

#define FireReduce_DIV(stream) do { \
                void* reductionReader = stream->items; \
                void* reductant = stream->items; \
                if(*(unsigned char*)reductant == FireStream_TYPE_NUM) { \
                        reductionReader += sizeof(double) + 1; \
                        reductant++; \
                        while (stream->itemEnd != reductionReader) { \
                                if(*(unsigned char*)reductionReader == FireStream_TYPE_NUM) { \
                                        reductionReader++; \
                                        *(double*)reductant /= Utils_NO_ZERO(*(double*)reductionReader); \
                                        reductionReader += sizeof(double); \
                                } \
                        } \
                        stream->itemEnd = reductant + sizeof(double); \
                } \
} while(0)

#endif
