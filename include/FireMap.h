#ifndef FIRE_MAP_H
#define FIRE_MAP_H

#include <stdio.h>

// contains Mapping macros for Fire language

#define FireMap_ADD(stream, number) do { \
                long* iLst = stream->items; \
                while(iLst != stream->itemEnd) { \
                        *iLst += number; \
                        iLst++; \
                } \
} while(0)

#define FireMap_PRINT(stream) do { \
                long* iLst = stream->items; \
                printf("%c ", '['); \
                while(iLst != stream->itemEnd) printf("%ld ", *iLst++); \
                puts("]"); \
} while(0)

#endif
