#ifndef FIRE_MAP_H
#define FIRE_MAP_H

#include <stdio.h>
#include <math.h>
#include "Utils.h"
#include "FireTypes.h"

// contains Mapping macros for Fire language

//quick macro for comparing byte types.
#define FireMap_IS_TYPE(ptr, type) (*(unsigned char*)ptr == type)

#define FireMap_ADD(stream, number) do { \
                void* reader = stream->items; \
                void* mapper = stream->items; \
                while (reader != stream->itemEnd) { \
                        if(FireMap_IS_TYPE(reader, FireStream_TYPE_NUM)) { \
                                reader++; \
                                *(unsigned char*)(mapper++) = FireStream_TYPE_NUM; \
                                *(double*)mapper = *(double*)reader + number; \
                                reader += sizeof(double); mapper += sizeof(double); \
                        } \
                } \
} while(0)

#define FireMap_SUB(stream, number) do { \
                void* reader = stream->items; \
                void* mapper = stream->items; \
                while (reader != stream->itemEnd) { \
                        if(FireMap_IS_TYPE(reader, FireStream_TYPE_NUM)) { \
                                reader++; \
                                *(unsigned char*)(mapper++) = FireStream_TYPE_NUM; \
                                *(double*)mapper = *(double*)reader - number; \
                                reader += sizeof(double); mapper += sizeof(double); \
                        } \
                } \
} while(0)

#define FireMap_MUL(stream, number) do { \
                void* reader = stream->items; \
                void* mapper = stream->items; \
                while (reader != stream->itemEnd) { \
                        if(FireMap_IS_TYPE(reader, FireStream_TYPE_NUM)) { \
                                reader++; \
                                *(unsigned char*)(mapper++) = FireStream_TYPE_NUM; \
                                *(double*)mapper = *(double*)reader * number; \
                                reader += sizeof(double); mapper += sizeof(double); \
                        } \
                } \
} while(0)

#define FireMap_DIV(stream, number) do { \
                void* reader = stream->items; \
                void* mapper = stream->items; \
                while (reader != stream->itemEnd) { \
                        if(FireMap_IS_TYPE(reader, FireStream_TYPE_NUM)) { \
                                reader++; \
                                *(unsigned char*)(mapper++) = FireStream_TYPE_NUM; \
                                *(double*)mapper = *(double*)reader / Utils_NO_ZERO(number); \
                                reader += sizeof(double); mapper += sizeof(double); \
                        } \
                } \
} while(0)

#define FireMap_REM(stream, number) do { \
                void* reader = stream->items; \
                void* mapper = stream->items; \
                while (reader != stream->itemEnd) { \
                        if(FireMap_IS_TYPE(reader, FireStream_TYPE_NUM)) { \
                                reader++; \
                                *(unsigned char*)(mapper++) = FireStream_TYPE_NUM; \
                                *(double*)mapper = *(double*)reader % Utils_NO_ZERO(number); \
                                reader += sizeof(double); mapper += sizeof(double); \
                        } \
                } \
} while(0)

#define FireMap_FLOOR(stream, number) do { \
                void* reader = stream->items; \
                void* mapper = stream->items; \
                while (reader != stream->itemEnd) { \
                        if(FireMap_IS_TYPE(reader, FireStream_TYPE_NUM)) { \
                                reader++; \
                                *(unsigned char*)(mapper++) = FireStream_TYPE_NUM; \
                                *(double*)mapper = floor(*(double*)reader); \
                                reader += sizeof(double); mapper += sizeof(double); \
                        } \
                } \
} while(0)

// temporary print, will be moved to IO dedicated header
#define FireMap_PRINT(stream) do { \
                void* reader = stream->items; \
                while (reader != stream->itemEnd) { \
                        if(FireMap_IS_TYPE(reader, FireStream_TYPE_NUM)) { \
                                reader++; \
                                printf("%f, ", *(double*)reader); \
                                reader += sizeof(double); \
                        } \
                        else break; \
                } \
                puts("~"); \
} while(0)



#endif
