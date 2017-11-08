#ifndef FIRE_STREAM_H
#define FIRE_STREAM_H

#include <stdlib.h>
#include <string.h>

#include "FireTypes.h"
#include "FireMap.h"
#include "FireFilter.h"
#include "FireReduce.h"
#include "FireIO.h"

/*****Fire Stream Header******/
// Expandable buffer stream optimized for map, reduce and filter.
// FireStream can be shortened by simply moving end of buffer back and rewriting data, or expanded.
// FireStreams can be iterated over very quickly

//meant to fit 100 8-bit integers by default
#define FireStream_DEFAULT_SIZE 800






// calculates the length of stream
#define FireStream_LEN(stream) (stream->itemEnd - stream->items)

// calculates remaining space in stream
#define FireStream_SPACE(stream) (stream->end - stream->itemEnd)


#define FireStream_MAKE(stream, size) do { \
                stream->items = malloc(size); \
                stream->cap = size; \
                stream->end = stream->items + stream->cap; \
                stream->itemEnd = stream->items; \
} while(0)

// make macro for literal and not ptr stream
#define FireStream_MAKE_L(stream, size) do { \
                stream.items = malloc(size); \
                stream.cap = size; \
                stream.end = stream.items + stream.cap; \
                stream.itemEnd = stream.items; \
} while(0)

// macro that takes a void* data, and some n bytes to make into a new stream
// onto the FireStream* stream.
#define FireStream_MAKE_FROM(stream, data, n) do { \
                stream->items = malloc(n); \
                memcpy(stream->items, data, n); \
                stream->cap = n; \
                stream->end = stream->items + stream->cap; \
                stream->itemEnd = stream->items; \
} while(0)

// like other MAKE macros, this initializes a zero range stream
#define FireStream_MAKE_ZRNG(stream, endMark) do { \
                stream->cap = endMark * (sizeof(double) + 1) + 100; \
                stream->items = malloc(stream->cap); \
                stream->end = stream->items + stream->cap; \
                stream->itemEnd = stream->items; \
                for (double i = 0; i < endMark; i++) { \
                        FireStream_PUT_LNUM(stream, i); \
                } \
} while(0)

// like other MAKE macros, this initializes a stream of all the same numbers
#define FireStream_MAKE_SNUM(stream, endMark) do { \
                stream->cap = endMark * (sizeof(double) + 1) + 100; \
                stream->items = malloc(stream->cap); \
                stream->end = stream->items + stream->cap; \
                stream->itemEnd = stream->items; \
                for (double i = 0; i < endMark; i++) { \
                        FireStream_PUT_LNUM(stream, endMark); \
                } \
} while(0)

// pushes a range of numbers to the stream.
// end is a pointer to a number
#define FireStream_PUSH_ZRNG(stream, end) do { \
                for (double i = 0; i < *(double*)end; i++) FireStream_PUSH_LNUM(stream, i); \
} while(0)

// macro for expanding stream
#define FireStream_EXPAND(stream, newSize) do { \
                size_t ilen = stream->itemEnd - stream->items; \
                stream->items = realloc(stream->items, newSize); \
                stream->cap = newSize; \
                stream->end = stream->items + (size_t)newSize; \
                stream->itemEnd = stream->items + ilen; \
} while(0)

// macro that always expands if not enough space to double the size
#define FireStream_EXPAND_IF(stream, space) if(space > (stream->end - stream->itemEnd)) FireStream_EXPAND(stream, stream->cap + space * 2)

// macro for moving the end marker in the stream back, primarily for reducing
#define FireStream_SHORTEN(stream, endMark) do { \
                if(endMark < FireStream_LEN(stream)) { \
                        stream->itemEnd = stream->items + endMark; \
                } \
} while(0)

// Sets the stream to a new range of numbers, expanding if needed and using pre-existing memory
#define FireStream_SET_ZRNG(stream, endMark) do { \
                FireStream_EXPAND_IF(stream, ((size_t)endMark * (sizeof(double) + 1))); \
                stream->itemEnd = stream->items; \
                for (double i = 0; i < endMark; i++) { \
                        FireStream_PUT_LNUM(stream, i); \
                } \
} while(0)

#define FireStream_SET_RNG(stream, startMark, endMark) do { \
                FireStream_EXPAND_IF(stream, ((endMark-startMark) * (sizeof(double) + 1))); \
                stream->itemEnd = stream->items; \
                for (double i = startMark; i < endMark; i++) { \
                        FireStream_PUT_LNUM(stream, i); \
                } \
} while(0)

// unchecked method of simply adding a byte to the current itemEnd ptr.
#define FireStream_PUT(stream, byte) *(unsigned char*)(stream->itemEnd++) = byte

// writes one number to the end of the stream, expanding if needed
#define FireStream_PUSH_NUM(stream, numPtr) do { \
                FireStream_EXPAND_IF(stream, sizeof(double) + 1); \
                FireStream_PUT(stream, FireStream_TYPE_NUM); \
                *(double*)(stream->itemEnd) = *(double*)numPtr; \
                stream->itemEnd += sizeof(double); \
} while(0)

// writes a literal double to the end of the stream
#define FireStream_PUSH_LNUM(stream, num) do { \
                FireStream_EXPAND_IF(stream, sizeof(double) + 1); \
                FireStream_PUT(stream, FireStream_TYPE_NUM); \
                *(double*)(stream->itemEnd) = num; \
                stream->itemEnd += sizeof(double); \
} while(0)

// unchecked method of putting number with preceding byte marker onto stream
#define FireStream_PUT_LNUM(stream, num) do { \
                FireStream_PUT(stream, FireStream_TYPE_NUM); \
                *(double*)(stream->itemEnd) = num; \
                stream->itemEnd += sizeof(double); \
} while(0)

// pads the stream with n null bytes (0 bytes)
// n is a literal integer
#define FireStream_PAD_NULL(stream, n) do { \
                FireStream_EXPAND_IF(stream, n); \
                for (size_t i = 0; i < n; i++) *(unsigned char*)(stream->itemEnd++) = 0; \
} while(0)






// makes a copy of stream at ptr streamSrc to stream at ptr streamDst
// streamDst must not have an already allocated items ptr.
#define FireStream_COPY(streamDst, streamSrc) do { \
                streamDst->cap = streamSrc->cap; \
                streamDst->items = malloc(streamSrc->cap); \
                memcpy(streamDst->items, streamSrc->items, streamSrc->cap); \
                streamDst->end = streamDst->items + streamDst->cap; \
                streamDst->itemEnd = streamDst->items + streamDst->len; \
} while(0)

// frees memory in a stream.
#define FireStream_FREE(stream) do { \
                free(stream->items); \
                stream->items = NULL; \
                stream->end = NULL; \
                stream->itemEnd = NULL; \
} while(0)

// clears the entire buffer by 0 setting data, but does not destroy or deallocate
#define FireStream_CLEAR(stream) do { \
                unsigned char* dataPtr = stream->items; \
                while(dataPtr != stream->itemEnd) *dataPtr++ = 0; \
                stream->itemEnd = stream->items; \
} while(0)


#define FireStream_reall_check(ptr, newSize) if((ptr = realloc(ptr, newSize)) == NULL) { \
                return 0; \
}


// struct to represent Fire's Stream

struct FireStream
{
        void* items;
        void* itemEnd;
        void* end;
        size_t cap;
};

typedef struct FireStream FireStream;


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

static inline int
FireStream_expand_if(FireStream* stream, size_t size)
{
        if(FireStream_space(stream) < size) FireStream_expand(stream, size);
}

// expands the stream to a newsize, returns 0 if realloc failure
int FireStream_expand(FireStream* stream, size_t newSize);

//expands to twice the current size.
int FireStream_expand_2x(FireStream* stream);

// creates a stream from a pointer using default size.
void FireStream_make(FireStream* stream);

//creates a stream with custom size.
void FireStream_make_size(FireStream* stream, size_t size);

void FireStream_free(FireStream* stream);

#endif
