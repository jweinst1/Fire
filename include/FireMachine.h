#ifndef FIRE_MACHINE_H
#define FIRE_MACHINE_H
//vm header for Fire language

#include "FireStream.h"
#include "Instructions.h"

#define FireMachine_MAKE_L(fm) do { \
                FireStream_MAKE_L(fm.stream, FireStream_DEFAULT_SIZE); \
                fm.err = 0; \
} while(0)

// Byte Code
// 0 end of code
// 1 add number to stream


struct FireMachine
{
        FireStream stream;
        unsigned char err;
};

typedef struct FireMachine FireMachine;

void FireMachine_run(FireMachine* fmach, unsigned char* bytes);

#endif
