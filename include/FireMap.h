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
                double* iLst = stream->items; \
                while(iLst != stream->itemEnd) { \
                        *iLst -= number; \
                        iLst++; \
                } \
} while(0)

#define FireMap_MUL(stream, number) do { \
                double* iLst = stream->items; \
                while(iLst != stream->itemEnd) { \
                        *iLst *= number; \
                        iLst++; \
                } \
} while(0)

#define FireMap_DIV(stream, number) do { \
                double* iLst = stream->items; \
                while(iLst != stream->itemEnd) { \
                        *iLst /= Utils_NO_ZERO(number); \
                        iLst++; \
                } \
} while(0)

#define FireMap_REM(stream, number) do { \
                double* iLst = stream->items; \
                while(iLst != stream->itemEnd) { \
                        *iLst %= Utils_NO_ZERO(number); \
                        iLst++; \
                } \
} while(0)

#define FireMap_FLOOR(stream) do { \
                double* iLst = stream->items; \
                while(iLst != stream->itemEnd) { \
                        *iLst = floor(*iLst); \
                        iLst++; \
                } \
} while(0)



#define FireMap_PRINT(stream) do { \
                double* iLst = stream->items; \
                printf("%c ", '['); \
                while(iLst != stream->itemEnd) { \
                        if(!Utils_DBL_IS_INT(*iLst)) printf("%f ", *iLst++); \
                        else printf("%d ", (int)*iLst++); \
                } \
                puts("]"); \
} while(0)

#endif
