#ifndef FIRE_STREAM_CORE_H
#define FIRE_STREAM_CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

#include "FireStreamDef.h"
#include "Instructions.h"

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
                return 0; \
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


// returns the length in bytes of the elements in the stream.
static inline size_t
FireStream_len(FireStream* stream)
{
        return stream->itemEnd - stream->items;
}

// returns the space remaining in the stream.
static inline size_t
FireStream_space(FireStream* stream)
{
        return stream->end - stream->itemEnd;
}

// Checks if the stream can fit some size of data.
static inline int
FireStream_fits(FireStream* stream, size_t size)
{
        return FireStream_space(stream) > size;
}

// Resets the write head of the stream to the beginning, allowing reusage of existing memory.
// This saves reallocation of memory during mapping, filtering, etc.
static inline void
FireStream_reset(FireStream* stream)
{
        stream->itemEnd = stream->items;
}

static inline void
FireStream_nullify(FireStream* stream)
{
        for(unsigned char* ptr = stream->items; ptr != stream->end; ptr++) *ptr = 0;
}

// expands the stream to a newsize, returns 0 if realloc failure
int FireStream_expand(FireStream* stream, size_t newSize);

//expands to twice the current size.
int FireStream_expand_2x(FireStream* stream);

static inline void
FireStream_expand_if(FireStream* stream, size_t size)
{
        if(FireStream_space(stream) < size) FireStream_expand(stream, stream->cap + size);
}

static inline void
FireStream_shorten(FireStream* stream, size_t size) {
        if(size < FireStream_len(stream)) stream->itemEnd = stream->items + size;
}

// creates a stream from a pointer using default size.
void FireStream_make(FireStream* stream);

//creates a stream with custom size.
void FireStream_make_size(FireStream* stream, size_t size);

//frees a stream and sets the buffer to zero and NULL
void FireStream_free(FireStream* stream);

static inline int
FireStream_is_empty(FireStream* stream)
{
        return stream->items == stream->itemEnd;
}

//returns percentage of capacity used, for optimization
static inline double
FireStream_cap_used(FireStream* stream)
{
        return (double)(stream->itemEnd - stream->items)/(double)(stream->cap);
}

//**** Write Methods *****

//function to write any type, given some known size and address
//works for buffers, arrays, anything that can be memcpyed


void FireStream_write(FireStream* stream, unsigned char* bytes);












#endif
