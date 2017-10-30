#ifndef FIRE_IO_H
#define FIRE_IO_H
//contains IO, like printing macros and functions

#include <stdio.h>
#include "Utils.h"

#define FireIO_PRINT(stream) do { \
                void* reader = stream->items; \
                printf("%c", '['); \
                while (reader != stream->itemEnd) { \
                        if(FireMap_IS_TYPE(reader, FireStream_TYPE_NUM)) { \
                                reader++; \
                                if(Utils_DBL_IS_INT(*(double*)reader)) printf("%ld ", ((long)*(double*)reader)); \
                                else printf("%f ", *(double*)reader); \
                                reader += sizeof(double); \
                        } \
                        else break; \
                } \
                puts("]"); \
} while(0)

#endif
