#ifndef FIRE_STREAM_CORE_H
#define FIRE_STREAM_CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "FireStreamDef.h"

// macro calculates the length of stream
#define FireStream_LEN(stream) (stream->itemEnd - stream->items)

// macro calculates remaining space in stream
#define FireStream_SPACE(stream) (stream->end - stream->itemEnd)

//checks if some size fits into stream.
#define FireStream_FITS(stream, pushSize) ((stream->end - stream->itemEnd) > pushSize)

//resets stream to write at beginning
#define FireStream_RESET(stream) stream->itemEnd = stream->items

//macro to check if realloc returns null, exits program if null pointer found
#define FireStream_reall_check(ptr, newSize) if((ptr = realloc(ptr, newSize)) == NULL) { \
                fprintf(stderr, "Memory error: Memory alloc for size %lu failed, out of memory.\n", newSize); \
                exit(1); \
}

//macro for seeing ratio of space used, for optimization.
#define FireStream_SPACE_USED(stream) (double)(stream->itemEnd - stream->items)/(double)(stream->cap)

//complete macro for condition stream expansion
// @addspace = additional space added besides pushSize
// @pushSize = size of object being added to stream.
#define FireStream_EXPAND_IF(stream, pushSize, addSpace) do { \
                if((stream->end - stream->itemEnd) < pushSize) { \
                        size_t ilen = stream->itemEnd - stream->items; \
                        stream->cap += pushSize + addSpace; \
                        if((stream->items = realloc(stream->items, stream->cap)) == NULL) { \
                                fprintf(stderr, "Memory error: Memory alloc for size %lu failed, out of memory.\n", stream->cap); \
                                exit(1); \
                        } \
                        stream->end = stream->items + stream->cap; \
                        stream->itemEnd = stream->items + ilen;  \
                } \
} while(0)

//macro to set all stream bytes to null.
#define FireStream_NULLIFY(stream) for(unsigned char* ptr = stream->items; ptr != stream->end; ptr++) *ptr = 0

#define FireStream_SHORTEN(stream, newSize) if(newSize < (stream->itemEnd - stream->items)) stream->itemEnd = stream->items + newSize

//creates a new stream in current scope with cap = bufSize
#define FireStream_MAKE(name, bufSize) \
        FireStream name; \
        if((name.items = malloc(bufSize)) == NULL) { \
                fprintf(stderr, "Memory error: Memory alloc for size %lu failed, out of memory.\n", (unsigned long)bufSize); \
                exit(1); \
        } \
        name.cap = bufSize; \
        name.end = name.items + name.cap; \
        name.itemEnd = name.items

#define FireStream_FREE(stream) do { \
                free(stream->items); \
                stream->items = NULL; \
                stream->end = NULL; \
                stream->itemEnd = NULL; \
                stream->cap = 0; \
} while(0)

#define FireStream_IS_EMPTY(stream) stream->items == stream->itemEnd

#define FireStream_IS_FULL(stream) stream->itemEnd == stream->end



#endif
