#ifndef FIRE_IO_H
#define FIRE_IO_H
//contains IO, like printing macros and functions

#include <stdio.h>
#include "FireStream.h"

//declaration for inclusion in firestream file
struct FireStream;
typedef struct FireStream FireStream;



//prints the binary reprsentation of the stream.
void FireIO_print_binary(FireStream* stream);

#endif
