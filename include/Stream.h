#ifndef FIRE_STREAM_H
#define FIRE_STREAM_H

#include <stdlib.h>
#include <string.h>

//meant to fit 100 8-bit integers by default
#define FireStream_DEFAULT_SIZE 800


#define FireStream_CONSTRUCT(stream, stype) do { \
                stream->type = stype; \
                stream->cap = FireStream_DEFAULT_SIZE; \
                stream->items = malloc(stream->cap); \
                stream->len = 0; \
} while(0)

//doubles in size
#define FireStream_EXPAND(stream) stream->items = realloc(stream->items, (stream->cap *= 2))

#define FireStream_EXPAND_TO(stream, newSize) stream->items = realloc(stream->items, newSize)

#define FireStream_SPACE(stream, type) ((stream->cap * sizeof(type)) - (stream->len * sizeof(type)))



enum StreamType
{
        StreamType_Number
};

typedef enum StreamType StreamType;

struct FireStream
{
        void* items;
        size_t len;
        size_t cap;
        StreamType type;
};

typedef FireStream FireStream;

#endif
