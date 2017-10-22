#ifndef FIRE_STREAM_H
#define FIRE_STREAM_H

#include <stdlib.h>
#include <string.h>

//meant to fit 100 8-bit integers by default
#define FireStream_DEFAULT_SIZE 800


#define FireStream_MAKE(stream, size) do { \
                stream->items = malloc(size); \
                stream->cap = size; \
                stream->len = 0; \
                stream->end = stream->items + stream->cap; \
                stream->itemEnd = stream->items; \
} while(0)

// macro for expanding stream
#define FireStream_EXPAND(stream, newSize) do { \
                stream->items = realloc(stream->items, newSize); \
                stream->cap = newSize; \
                stream->end = stream->items + newSize; \
                stream->itemEnd = stream->items + stream->len; \
} while(0)

//macro for writing some pointer and its type to the stream
#define FireStream_WRITE(stream, value, n) do { \
                if(stream->itemEnd != stream->end) { \
                        memcpy(stream->itemEnd, value, n); \
                        stream->len += n; \
                        stream->itemEnd = stream->items + stream->len; \
                } \
} while(0)

//expression for the amount of space remaining in the stream
#define FireStream_SPACE(stream, type) ((stream->cap * sizeof(type)) - (stream->len * sizeof(type)))

#define FireStream_LENGTH(stream, type) (stream->len / sizeof(type))

//casts the buffer of the stream toward relevant type
#define FireStream_ITEMS(stream, type) ((type*)stream->items)

//gets an item in the stream with specified type
#define FireStream_GET(stream, type, ind) ((type*)stream->items)[0]




enum StreamType
{
        StreamType_Number
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

typedef FireStream FireStream;

void FireStream_map();

#endif
