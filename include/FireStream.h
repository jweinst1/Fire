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

// make macro for literal and not ptr stream
#define FireStream_MAKE_L(stream, size) do { \
                stream.items = malloc(size); \
                stream.cap = size; \
                stream.len = 0; \
                stream.end = stream.items + stream.cap; \
                stream.itemEnd = stream.items; \
} while(0)

// macro for expanding stream
#define FireStream_EXPAND(stream, newSize) do { \
                stream->items = realloc(stream->items, newSize); \
                stream->cap = newSize; \
                stream->end = stream->items + newSize; \
                stream->itemEnd = stream->items + stream->len; \
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
                *((type*)stream->itemEnd) = *value; \
                stream->len += sizeof(type); \
                stream->itemEnd = stream->items + stream->len; \
} while(0)




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

typedef struct FireStream FireStream;

#endif
