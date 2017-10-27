#ifndef FIRE_STREAM_H
#define FIRE_STREAM_H

#include <stdlib.h>
#include <string.h>

#include "FireMap.h"

/*****Fire Stream Header******/
// Expandable buffer stream optimized for map, reduce and filter.
// FireStream can be shortened by simply moving end of buffer back and rewriting data, or expanded.
// FireStreams can be iterated over very quickly

//meant to fit 100 8-bit integers by default
#define FireStream_DEFAULT_SIZE 800

// Byte->type codes


#define FireStream_TYPE_NUM 1



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

// macro for expanding stream
#define FireStream_EXPAND(stream, newSize) do { \
                size_t ilen = stream->itemEnd - stream->items; \
                stream->items = realloc(stream->items, newSize); \
                stream->cap = newSize; \
                stream->end = stream->items + newSize; \
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

// unchecked method of simply adding a byte to the current itemEnd ptr.
#define FireStream_PUT(stream, byte) *(unsigned char*)(stream->itemEnd++) = byte

#define FireStream_PUSH_NUM(stream, numPtr) do { \
                FireStream_EXPAND_IF(stream, sizeof(double) + 1); \
                FireStream_PUT(stream, FireStream_TYPE_NUM); \
                *(double*)(stream->itemEnd) = *(double*)numPtr; \
                stream->itemEnd += sizeof(double); \
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





struct FireStream
{
        void* items;
        void* itemEnd;
        void* end;
        size_t cap;
};

typedef struct FireStream FireStream;

#endif
