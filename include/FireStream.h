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


#define FireStream_MAKE(stream, size) do { \
                stream->items = malloc(size); \
                stream->cap = size; \
                stream->len = 0; \
                stream->end = stream->items + stream->cap; \
                stream->itemEnd = stream->items; \
                stream->type = StreamType_UnTyped; \
} while(0)

// make macro for literal and not ptr stream
#define FireStream_MAKE_L(stream, size) do { \
                stream.items = malloc(size); \
                stream.cap = size; \
                stream.len = 0; \
                stream.end = stream.items + stream.cap; \
                stream.itemEnd = stream.items; \
                stream.type = StreamType_UnTyped; \
} while(0)

// macro that takes a void* data, and some n bytes to make into a new stream
// onto the FireStream* stream.
#define FireStream_MAKE_FROM(stream, data, n) do { \
                stream->items = malloc(n); \
                memcpy(stream->items, data, n); \
                stream->cap = n; \
                stream->len = 0; \
                stream->end = stream->items + stream->cap; \
                stream->itemEnd = stream->items; \
                stream->type = StreamType_UnTyped; \
} while(0)

// macro for expanding stream
#define FireStream_EXPAND(stream, newSize) do { \
                stream->items = realloc(stream->items, newSize); \
                stream->cap = newSize; \
                stream->end = stream->items + newSize; \
                stream->itemEnd = stream->items + stream->len; \
} while(0)

// macro for moving the end marker in the stream back, primarily for reducing
#define FireStream_SHORTEN(stream, endMark) do { \
                if(endMark < stream->len) { \
                        stream->itemEnd = stream->items + endMark; \
                        stream->len = endMark; \
                } \
} while(0)

//macro for writing some pointer without a specified type to the stream
#define FireStream_WRITE_N(stream, value, n) do { \
                if(n < (stream->cap - stream->len)) { \
                        memcpy(stream->itemEnd, value, n); \
                        stream->len += n; \
                        stream->itemEnd = stream->items + stream->len; \
                } else { \
                        FireStream_EXPAND(stream, (stream->cap + n * 2)); \
                        memcpy(stream->itemEnd, value, n); \
                        stream->len += n; \
                        stream->itemEnd = stream->items + stream->len; \
                } \
} while(0)

//expression for the amount of space remaining in the stream
#define FireStream_SPACE_T(stream, type) ((stream->cap * sizeof(type)) - (stream->len * sizeof(type)))

#define FireStream_LENGTH_T(stream, type) (stream->len / sizeof(type))

//casts the buffer of the stream toward relevant type
#define FireStream_ITEMS_T(stream, type) ((type*)stream->items)

//gets an item in the stream with specified type
#define FireStream_GET_T(stream, type, ind) ((type*)stream->items)[ind]

//writes a typed value pointer to stream
#define FireStream_WRITE_T(stream, type, value) do { \
                if(sizeof(type) > (stream->cap - stream->len)) FireStream_EXPAND(stream, (stream->cap + sizeof(type) * 2)); \
                *((type*)stream->itemEnd) = *(type*)value; \
                stream->len += sizeof(type); \
                stream->itemEnd = stream->items + stream->len; \
} while(0)

//macro specifically for writing numbers to stream
#define FireStream_WRITE_NUM(stream, value) do { \
                if(sizeof(double) > (stream->cap - stream->len)) FireStream_EXPAND(stream, (stream->cap + sizeof(double) * 2)); \
                *((double*)stream->itemEnd) = *(double*)value; \
                stream->len += sizeof(double); \
                stream->itemEnd = stream->items + stream->len; \
} while(0)

//writes a single byte to stream
//does not use pointer, uses raw byte value
#define FireStream_PUT(stream, byte) do { \
                if(sizeof(unsigned char) > (stream->cap - stream->len)) FireStream_EXPAND(stream, (stream->cap + sizeof(unsigned char) * 2)); \
                *((unsigned char*)stream->itemEnd) = byte; \
                stream->len += sizeof(unsigned char); \
                stream->itemEnd = stream->items + stream->len; \
} while(0)

// makes a copy of stream at ptr streamSrc to stream at ptr streamDst
// streamDst must not have an already allocated items ptr.
#define FireStream_COPY(streamDst, streamSrc) do { \
                streamDst->cap = streamSrc->cap; \
                streamDst->len = streamSrc->len; \
                streamDst->items = malloc(streamSrc->cap); \
                memcpy(streamDst->items, streamSrc->items, streamSrc->cap); \
                streamDst->end = streamDst->items + streamDst->cap; \
                streamDst->itemEnd = streamDst->items + streamDst->len; \
                streamDst->type = streamSrc->type; \
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
                stream->len = 0; \
                stream->itemEnd = stream->items; \
} while(0)


enum StreamType
{
        StreamType_UnTyped
};

typedef enum StreamType StreamType;

struct FireStream
{
        void* items;
        void* itemEnd;
        void* end;
        size_t len;
        size_t cap;
        StreamType type;
};

typedef struct FireStream FireStream;

#endif
