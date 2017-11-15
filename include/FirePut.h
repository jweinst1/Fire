#ifndef FIRE_PUT_H
#define FIRE_PUT_H
//header that contains binary methods to put new objects onto the stream

#include <stdio.h>
#include <stdint.h>

#include "FireStreamDef.h"
#include "FireTypes.h"

struct PutParams
{
        FireType type;
        size_t total;
        int amount;
};

typedef struct PutParams PutParams;


//overall function that handles the put instruction in compiled code.
void FirePut_put(FireStream* stream, unsigned char** code);

#endif
