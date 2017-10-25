#ifndef FIRE_MAP_H
#define FIRE_MAP_H

#include <stdio.h>
#include <math.h>
#include "Utils.h"

// contains Mapping macros for Fire language

#define FireMap_ADD(stream, number) do { \
                double* iLst = stream->items; \
                while(iLst != stream->itemEnd) { \
                        *iLst += number; \
                        iLst++; \
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