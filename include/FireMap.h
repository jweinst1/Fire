#ifndef FIRE_MAP_H
#define FIRE_MAP_H

#include <stdio.h>

// contains Mapping macros for Fire language

#define FireMap_Add(stream, number) do { \
                long* iLst = stream->items; \
                while(iLst != stream->itemEnd) { \
                        *iLst += number; \
                        iLst++; \
                } \
} while(0)

#define FireMap_Print(stream) do { \
                long* iLst = stream->items; \
                puts("[ "); \
                while(iLst != stream->itemEnd) printf("%ld ", *iLst++); \
                puts("]"); \
} while(0)

#endif
