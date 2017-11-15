#ifndef FIRE_STREAM_H
#define FIRE_STREAM_H


#include "FireStreamCore.h"
#include "FireTypes.h"
#include "FireIO.h"
#include "FirePut.h"




//main function responsible for executing byte code
void FireStream_execute(FireStream* stream, unsigned char* code);



#endif
