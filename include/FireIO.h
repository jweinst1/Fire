#ifndef FIRE_IO_H
#define FIRE_IO_H
//contains IO, like printing macros and functions

#include <stdio.h>
#include "FireStream.h"

//declaration macro for inclusion in firestream file
FireStream_DECLARE



//prints the binary reprsentation of the stream.

static inline void
FireIO_print_binary(FireStream* stream)
{
        for(unsigned char* ptr = stream->items; ptr != stream->itemEnd; ptr++) printf("%u", *ptr);
}

static inline void
FireIO_print_binary_lines(FireStream* stream)
{
        for(unsigned char* ptr = stream->items; ptr != stream->itemEnd; ptr++) printf("%u\n", *ptr);
}

int FireIO_print_stream(FireStream* stream);

#endif
